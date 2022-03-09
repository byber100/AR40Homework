#include "GameEngineWindow.h"


// Static Var
GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow(); // 싱글톤 생성자

// Static Func
LRESULT CALLBACK WndProc
//  프로세스를 작업하기 위한 윈도우의 메세지 처리
//  반복문의 반복현상을 최소화하여 특정 메세지에만
//  반복명령을 1회 실행해줌
//  이것으로 실시간 처리에 대한 연산과부화 억제 => 최적화
(HWND hWnd, UINT message, WPARAM wParam, LPARAM IParma)
{
	return DefWindowProc(hWnd, message, wParam, IParma); // 기본 윈도창으로 리턴
}

// constructor destructor
GameEngineWindow::GameEngineWindow()
{
}

GameEngineWindow::~GameEngineWindow()
{
}


//member Func
void GameEngineWindow::CreateGameWindow(HINSTANCE _hInst)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _hInst;
	wcex.hIcon = nullptr;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"GameEngineWindowClass";
	wcex.hIconSm = nullptr;

	RegisterClassExW(&wcex);

	hWnd_ = CreateWindowW(L"GameEngineWindowClass", L"packman", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);

	if (!hWnd_)
	{
		return;
	}
}

void GameEngineWindow::ShowGameWindow()
{
	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_);
}