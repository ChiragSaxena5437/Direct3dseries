#include <Windows.h>
#include "WindowsMessageMap.h"
#include <sstream>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static WindowsMessageMap mm;
	OutputDebugString( mm (msg, lParam, wParam).c_str());


	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(1); // I am keeping it as 1 not 0 and certainly not "69"
		break;

	case WM_KEYDOWN:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "Respects");
		}
		break;

	case WM_KEYUP:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "DangerFeild");
		}
		break;
	case WM_CHAR://message for text input case: sensitive
	{

		static std::string title;
		title.push_back((char)wParam);
		SetWindowText(hWnd, title.c_str());

	}
	case WM_LBUTTONDOWN:
	{
		POINTS pt = MAKEPOINTS(lParam);
		std::ostringstream oss;
		oss << "(" << pt.x << "," << pt.y << ")";
		SetWindowText(hWnd, oss.str().c_str());
	}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain
(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow
)

{
	const auto pClassName = "Hw3D";
	//register window class
	//for now I have forced all strings to be wide strings by prefixing with L
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);								  
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;		//proc=procedure
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	const auto forhWndname = "Happy Hard Window";
	RegisterClassEx(&wc);
	HWND hWnd = CreateWindowEx
	(
		0, pClassName,
		forhWndname,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);
	//show window
	ShowWindow(hWnd, SW_SHOW);

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}

	else
	{
		return msg.wParam;
	}

}