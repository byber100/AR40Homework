#pragma once

// �з� :
// �뵵 :
// ���� :
class AntarcticGame
{
private:	// member Var

public:		
	AntarcticGame(); // default constructor ����Ʈ ������
	~AntarcticGame(); // default destructor ����Ʈ �Ҹ���

public:		// delete constructor
	AntarcticGame(const AntarcticGame& _other) = delete; // default Copy constructor ����Ʈ ���������
	AntarcticGame(AntarcticGame&& _other) noexcept; // default RValue Copy constructor ����Ʈ RValue ���������

public:		//delete operator
	AntarcticGame& operator=(const AntarcticGame& _other) = delete; // default Copy operator ����Ʈ ���� ������
	AntarcticGame& operator=(const AntarcticGame&& _other) = delete; // default RValue Copy operator ����Ʈ RValue ���Կ�����

public:		//member Func
};

