#pragma once
#include <Windows.h>

// �з� :
// �뵵 :
// ���� : ������ â�� ���� Ŭ����
class GameEngineWindow
{
private:	// �̱���
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
	GameEngineWindow(); // default constructor ����Ʈ ������
	~GameEngineWindow(); // default destructor ����Ʈ �Ҹ���

public:		// delete constructor
	GameEngineWindow(const GameEngineWindow& _other) = delete; // default Copy constructor ����Ʈ ���������
	GameEngineWindow(GameEngineWindow&& _other) noexcept = delete; // default RValue Copy constructor ����Ʈ RValue ���������

public:		//delete operator
	GameEngineWindow& operator=(const GameEngineWindow& _other) = delete; // default Copy operator ����Ʈ ���� ������
	GameEngineWindow& operator=(GameEngineWindow&& _other) noexcept = delete; // default RValue Copy operator ����Ʈ RValue ���Կ�����

public:		//member Func
};

