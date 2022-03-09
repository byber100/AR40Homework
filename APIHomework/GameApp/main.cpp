#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

int __stdcall WinMain // WinAPI�� ������ �Լ�
	//  stdcall == Callback
	//	callback�� fastcall�� ��������
	//  ���� ��� ������Ʈ�� �����ؼ� ����ó���� �� �� �ְ� �����.
	(_In_ HINSTANCE hInstance, // ���� �ν��Ͻ�
		_In_opt_ HINSTANCE hPrevInstance, // ���� �ν��Ͻ�
		_In_ char* IpCmdLine,
		_In_ int nCmdShow)
{
	GameEngineWindow::GetInst().CreateGameWindow(hInstance);
	GameEngineWindow::GetInst().ShowGameWindow();
}