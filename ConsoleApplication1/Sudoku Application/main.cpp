#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

int WINAPI WinMain(HINSTANCE hInstance, 
				   HINSTANCE hPrevInstance, 
				   LPSTR lpCmdLine, 
					int nCmdShow);

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);