#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

int __stdcall WinMain // WinAPI의 진입점 함수
	//  stdcall == Callback
	//	callback은 fastcall의 일종으로
	//  스택 대신 레지스트로 전달해서 빠른처리를 할 수 있게 만든다.
	(_In_ HINSTANCE hInstance, // 현재 인스턴스
		_In_opt_ HINSTANCE hPrevInstance, // 이전 인스턴스
		_In_ char* IpCmdLine,
		_In_ int nCmdShow)
{
	GameEngineWindow::GetInst().CreateGameWindow(hInstance);
	GameEngineWindow::GetInst().ShowGameWindow();
}