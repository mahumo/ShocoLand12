#pragma once
#include "MDUncopyable.h"
#include "MDCore.h"
#include "MDTypedefs.h"
#include <memory>

class CoreD2D : private MDUncopyable
{
private:
	struct MD2D
	{
		ComPtr<ID2D1Factory1>					factory;
		ComPtr<ID2D1Device>						device;
		ComPtr<ID2D1DeviceContext>			deviceContext;
		ComPtr<ID2D1Bitmap1>					buffer;
		MDVector2 dpi;
	};

public:
	CoreD2D() = default;
	~CoreD2D() = default;

	HRESULT Initialize( ComPtr<IDXGIDevice1>& device, ComPtr<IDXGISwapChain1>& swapChain );
	static IDWriteFactory* GetWriteFactory(){ return writeFactory.Get(); }
	static ID2D1DeviceContext* GetDeviceContext(){ return dev2D->deviceContext.Get(); }
private:
	// �f�o�C�X��ˑ�
	HRESULT Create2DFactory();
	// �f�o�C�X�ˑ�
	HRESULT Create2DDevice( ComPtr<IDXGIDevice1>& device );
	HRESULT Create2DDeviceContext();
	// ���L�T�[�t�F�[�X���쐬
	HRESULT CreateDXGISurface( ComPtr<IDXGISwapChain1>& swapChain,ComPtr<IDXGISurface>&	surface );
	HRESULT Create2DBackBuffer( ComPtr<IDXGISurface>& surface );

	HRESULT CreateWriteFactory();

//private:
public:
	/* 
		ID2D1HwndRenderTarget	�͊ȒP��2D�@�\�𗘗p�o����悤�A���������ȒP�����@�\�����Ȃ��炵��
		2D 3D�̋��L���o���邩�́A����ł͂悭�킩��Ȃ�
	*/
	static std::unique_ptr<MD2D> dev2D;
	static ComPtr<IDWriteFactory>	writeFactory;
};
