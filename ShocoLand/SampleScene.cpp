#include "SampleScene.h"
#include "MDTextureLoadWrapper.h"
#include "Solid.h"
#include "Liquid.h"
#include "Normal.h"
#include "GameScene.h"


int SampleScene::Initialize()
{	
	fps.SetFps( 60.0f );
	mainCamera.SetViewport(800, 600);
	mainCamera.SetupMatrix(MDVector3(0, 0, 0), MDVector3(0, 0, 10));
	help2D.Initialize();																// 2D描画準備
	writer.CreateWriteTextFormat( L"メイリオ", 16 );				// TextFont
	writer.CreateColorBrush( MDColorF( 1, 1, 1 ) );		// TextBrush Color
	//m_player = std::make_unique<Player>(std::make_unique<Normal>());
	m_player.reset(new Player(std::make_unique<Normal>()));
	m_player->Inisialize(MDVector2(0, 0));
	bitmap.Create(L"Resource/MochidaA.jpg");
	bitmap2.Create(L"Resource/SAWAGUCHI_b.jpg");
	g_enemy = MDGameObj2D({ 0, 300 }, bitmap.GetImageSize());
	g_player = MDGameObj2D({ 200, 0 }, bitmap2.GetImageSize());
	return MDSceneStay::FUNC_END;

}

int SampleScene::Update()
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

	help2D.BitMap(&bitmap, g_enemy.pos, { 0, 0, g_enemy.size.x, g_enemy.size.y }, 1);
	help2D.BitMap(&bitmap2, g_player.pos, { 0, 0, g_player.size.x, g_player.size.y }, 1);
	m_player->Draw();
	if (MDInput::Instance()->GetKeyState(KEYS_Z) == DOWN)
	{
		m_player->StateChange(std::make_unique<Solid>());
		writer.TextWrite("　・－・　－・－・－　・・－・・　－－・－・　", MDVector2(50, 550));
		m_player->Inisialize(m_player->g_player.pos);
	}
	if (MDInput::Instance()->GetKeyState(KEYS_X) == DOWN)
	{
		m_player->StateChange(std::make_unique<Normal>());
		writer.TextWrite("－・・　・・　　・・－・　・－・　－・－・－　・・－・・　－－・－・　", MDVector2(50, 550));
		m_player->Inisialize(m_player->g_player.pos);
	}
	if (MDInput::Instance()->GetKeyState(KEYS_C) == DOWN)
	{
		m_player->StateChange(std::make_unique<Liquid>());
		writer.TextWrite("　－－・　－・－・－　・・－・・　－－・－・　", MDVector2(50,550));
		m_player->Inisialize(m_player->g_player.pos);
	}
	m_player->Move();
	/*if (MDInput::Instance()->GetKeyState(KEYS_D) == DOWN){
		g_player.pos.x += 5;
	}
	if (MDInput::Instance()->GetKeyState(KEYS_A) == DOWN){
		g_player.pos.x -= 5;
	}
	if (MDInput::Instance()->GetKeyState(KEYS_W) == DOWN){
		g_player.pos.y -= 5;
	}
	if (MDInput::Instance()->GetKeyState(KEYS_S) == DOWN){
		g_player.pos.y += 5;
	}*/

	// 当たり判定
	if (MDCollision2D::RectHit(g_enemy, m_player->g_player))
	{
	}
//
	// Text描画
	writer.TextWrite( fps.GetFps(), { 0, 0 } );
	writer.TextWrite("モールス信号です", MDVector2(0, 20));

	m_player->Update();
	// 2D描画終了
	help2D.EndDraw();
	// 3D描画終了
	CoreD3D::Present();	
	
	// 入力処理
	// PUSH は押した時 詳しくは ヘッダーを見よう
	if( MDInput::Instance()->GetKeyState( KEYS_ENTER ) == PUSH )	
	{
		// シーン移行方法
		MDSceneManager::Instance()->PushScene( new GameScene );
	}
	
	
	// FPS 更新
	fps.WaitFrame();
	return MDSceneStay::FUNC_PROCESS;
}
int SampleScene::Release()
{
	return MDSceneStay::FUNC_END;
}
