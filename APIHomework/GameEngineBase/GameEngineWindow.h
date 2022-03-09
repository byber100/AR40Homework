#pragma once
#include <Windows.h>

// 분류 :
// 용도 :
// 설명 : 윈도우 창을 위한 클래스
class GameEngineWindow
{
private:	// 싱글톤
	static GameEngineWindow* Inst_;

public:
	inline static GameEngineWindow& GetInst()
	{
		return *Inst_;
	}

	static GameEngineWindow& Destroy()
	{
		if (nullptr == Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}

public:
	void CreateGameWindow(HINSTANCE _hInst);
	void ShowGameWindow();

private:
	HWND hWnd_;

public:		
	GameEngineWindow(); // default constructor 디폴트 생성자
	~GameEngineWindow(); // default destructor 디폴트 소멸자

public:		// delete constructor
	GameEngineWindow(const GameEngineWindow& _other) = delete; // default Copy constructor 디폴트 복사생성자
	GameEngineWindow(GameEngineWindow&& _other) noexcept = delete; // default RValue Copy constructor 디폴트 RValue 복사생성자

public:		//delete operator
	GameEngineWindow& operator=(const GameEngineWindow& _other) = delete; // default Copy operator 디폴트 대입 연산자
	GameEngineWindow& operator=(GameEngineWindow&& _other) noexcept = delete; // default RValue Copy operator 디폴트 RValue 대입연산자

public:		//member Func
};

