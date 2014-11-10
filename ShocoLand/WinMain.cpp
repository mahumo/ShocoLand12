#include "MainWrapper.h"
//#include <Windows.h>
//#include <tchar.h>


// メッセージのコールバック
LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch( message ){
	case WM_KEYUP: switch( wParam ){ case VK_ESCAPE: DestroyWindow( hWnd ); PostQuitMessage( 0 ); break; }	break;
	case WM_DESTROY:PostQuitMessage( 0 );	break;
	case WM_DISPLAYCHANGE:  break;
	default: return DefWindowProc( hWnd, message, wParam, lParam );
	}
	return 0;
}

int APIENTRY _tWinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPTSTR, _In_ int )
{
	MainWrapper mainWrapper;
	return mainWrapper.Run( hInstance, WndProc );
}
