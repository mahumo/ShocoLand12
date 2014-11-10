#pragma once
#include "MDUncopyable.h"
#include "MDCore.h"
#include <memory>

struct WindowInfo;
class CoreD3D : private MDUncopyable
{
private:
	struct MD3D
	{
		ComPtr<ID3D11Device>						device;
		ComPtr<ID3D11DeviceContext>		deviceContext;
		ComPtr<ID3D11RenderTargetView>	renderTV;
		ComPtr<ID3D11DepthStencilView>	depthSV;
		ComPtr<ID3D11Texture2D>				buffer;
		ComPtr<ID3D11Texture2D>				depthTex;
	};
	struct MDDXGI
	{
		ComPtr<IDXGIDevice1>			device;
		ComPtr<IDXGISwapChain1>	swapChain;
	};
	
public:
	CoreD3D() = default;
	~CoreD3D();
	VOID Release();

	HRESULT Initialize( const HWND hWnd, const WindowInfo& info );
	static VOID Present(){ devDXGI->swapChain->Present( 0, 0 ); }
	static ID3D11Device*						GetDevice(){ return dev3D->device.Get(); }
	static ID3D11DeviceContext*			GetDeviceContext(){ return dev3D->deviceContext.Get(); }
	static ID3D11RenderTargetView*	GetRenderTV(){ return dev3D->renderTV.Get(); }
	static ID3D11DepthStencilView*		GetDepthSV(){ return dev3D->depthSV.Get(); }
	static IDXGISwapChain1*				GetSwapChain(){ return devDXGI->swapChain.Get(); }

private:
	// デバイスを作成( おまとめ )
	HRESULT Create( const HWND hWnd, const WindowInfo& info );
	
	// 3Dデバイスを作成
	HRESULT Create3DDevice( IDXGIAdapter*  pAdapter, const D3D_DRIVER_TYPE  driverType, const UINT flags );
	
	// DXGIデバイスを作成
	HRESULT CreateDXGIDevice();
	
	// DXGIアダプタを作成
	HRESULT CreateDXGIAdapter( ComPtr<IDXGIAdapter>& adapter);
	
	// DXGIファクトリを作成
	HRESULT CreateDXGIFactory( ComPtr<IDXGIAdapter>& adapter, ComPtr<IDXGIFactory2>& factory );
	
	// スワップチェインを作成
	HRESULT CreateDXGISwapChain( const HWND hWnd, const WindowInfo& info, ComPtr<IDXGIFactory2>& factory, const UINT samplingCount = 1, const UINT samplingQuality = 0 );
	
	// バックバッファを作成
	HRESULT Create3DBackBuffer();
	
	// レンダーターゲットビューを作成
	HRESULT Create3DRenderTargetView();

	// 深度ステンシルビューを作成
	HRESULT CreateDepthStencilView( const WindowInfo& info );

//private:
public:
	static std::unique_ptr<MD3D> dev3D;
	static std::unique_ptr<MDDXGI> devDXGI;
	D3D_FEATURE_LEVEL FeatureLevel;				// 採用されたDirectXのバージョン
};
