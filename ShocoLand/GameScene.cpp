#include "GameScene.h"
#include "MDTextureLoadWrapper.h"
#include "TiledMap.h"
#include "SampleScene.h"
// ふぁあああ
int GameScene::Initialize()
{	
	fps.SetFps( 60.0f );
	mainCamera.SetViewport( 800, 600 );
	mainCamera.SetupMatrix( MDVector3( 0, 0, 0 ), MDVector3( 0, 0, 10 ) );

	help2D.Initialize();																// 2D描画準備

	writer.CreateWriteTextFormat( L"メイリオ", 16 );				// TextFont
	writer.CreateColorBrush( MDColorF( 1, 1, 1 ) );					// TextBrush Color
	
	int i = 0;
	for(  const auto& b : { L"Resource/tw1.png", L"Resource/tw2.png" } )
	{
		bitmap[i].Create(b);
		i++;
	}

	back = MDGameObj2D( { 0, 0 }, bitmap[2].GetImageSize() );
	stage = MDGameObj2D( { 400, 500 }, { 200, 20 }, { 0, 0 } );
	player = MDGameObj2D( { 300, 100 }, bitmap[0].GetImageSize());

	circle0 = MDGameObj2D( { 50, 100 }, bitmap[1].GetImageSize());
	circle1 = MDGameObj2D( { 400, 100 }, { 25, 25 } );


	map.Initialize();

	return MDSceneStay::FUNC_END;
}
int GameScene::Update()
{ 
	float ClearColor[]  { 0.5f, 0.5f, 0.5f, 1 };
	// 画面クリア、深度クリア
	CoreD3D::GetDeviceContext()->ClearRenderTargetView( CoreD3D::GetRenderTV(), ClearColor );
	CoreD3D::GetDeviceContext()->ClearDepthStencilView( CoreD3D::GetDepthSV(), D3D10_CLEAR_DEPTH, 1.0f, 0 );
	
	// 3D 描画

	// レンダーターゲットセット
	ID3D11RenderTargetView* rtv[1] = { CoreD3D::GetRenderTV() };
	CoreD3D::GetDeviceContext()->OMSetRenderTargets( 1, rtv, CoreD3D::GetDepthSV() );				
	
	// 2D描画
	help2D.BeginDraw();
	//help2D.FillRect( stage.pos, stage.size );

//	help2D.BitMap( &bitmap[2], back.pos, { 0, 0, back.size.x/2, back.size.y/2 },1 );
	//help2D.BitMap( &bitmap[0], player.pos, { 0, 0, player.size.x,  player.size.y },1 );
	//help2D.BitMap( &bitmap[1], circle0.pos, { 0, 0, circle0.size.x, circle0.size.y }, 0.5f);

	map.Draw( help2D );
	//help2D.FillRect( player.pos, player.size );
	//help2D.FillEllipse( circle0.pos, circle0.size.x );
	//help2D.FillEllipse( circle1.pos, circle1.size.x );

	writer.TextWrite( fps.GetFps(),MDVector2(0,0) );
	help2D.EndDraw();

	
	//CoreD2D::GetDeviceContext()->CreateBitmapFromDxgiSurface(CoreD2D::dev2D->buffer->GetSurface(), CoreD2D::dev2D->buffer->GetOptions())
	
	CoreD3D::Present();	// 描画終了

	if( MDCollision2D::RectHit( circle0, player ) )
	{
		ErrMsg( L"当たってるよ(*´ω｀*)" );
	}
	//if( MDCollision2D::CircleHit( circle0, circle1 ) )
	//{
	//	//ErrMsg( L"当たってるよ(*´ω｀*)" );
	//}
	/*if( MDCollision2D::RectToCircleHit( player, circle0 ) )
	{
		
		ErrMsg( L"当たってるよ(*´ω｀*)" );
	}*/

	// 入力処理
	// PUSH は押した時 詳しくは ヘッダーを見よう
	if( MDInput::Instance()->GetKeyState( KEYS_ENTER ) == PUSH )
	{
		// シーン移行方法
		MDSceneManager::Instance()->PushScene( new SampleScene );
	}

	auto&  play = player;

	// 入力処理
	if( MDInput::Instance()->GetKeyState( KEYS_UP ) == DOWN )
	{
		play.pos.y = play.pos.y - 1;
	}
	else if( MDInput::Instance()->GetKeyState( KEYS_DOWN ) == DOWN )
	{
		play.pos.y = play.pos.y + 1;
	}
	else if( MDInput::Instance()->GetKeyState( KEYS_LEFT ) == DOWN )
	{
		play.pos.x = play.pos.x - 1;
	}
	else if( MDInput::Instance()->GetKeyState( KEYS_RIGHT ) == DOWN )
	{
		play.pos.x = play.pos.x + 1;
	}


	// FPS 更新
	fps.WaitFrame();
	return MDSceneStay::FUNC_PROCESS;
}
int GameScene::Release()
{
	//SafeDelete( &world);
	return MDSceneStay::FUNC_END;
}

