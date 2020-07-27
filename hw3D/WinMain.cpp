#include <Windows.h>


int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow
	)
{
	const auto pClassName = L"Hw3D";
	//register window class
	//for now I have forced all strings to be wide strings by prefixing with L
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);								  
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	const auto forhWndname = L"Happy Hard Window";
	RegisterClassEx(&wc);
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		forhWndname,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);
	//show window
	ShowWindow(hWnd, SW_SHOW);

	while (true);
	return 0;
}