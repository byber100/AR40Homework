#include "GameEngineWindow.h"


// Static Var
GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow(); // �̱��� ������

// Static Func
LRESULT CALLBACK WndProc
//  ���μ����� �۾��ϱ� ���� �������� �޼��� ó��
//  �ݺ����� �ݺ������� �ּ�ȭ�Ͽ� Ư�� �޼�������
//  �ݺ������ 1ȸ ��������
//  �̰����� �ǽð� ó���� ���� �������ȭ ���� => ����ȭ
(HWND hWnd, UINT message, WPARAM wParam, LPARAM IParma)
{
	return DefWindowProc(hWnd, message, wParam, IParma); // �⺻ ����â���� ����
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