#pragma once

// 분류 :
// 용도 :
// 설명 :
class AntarcticGame
{
private:	// member Var

public:		
	AntarcticGame(); // default constructor 디폴트 생성자
	~AntarcticGame(); // default destructor 디폴트 소멸자

public:		// delete constructor
	AntarcticGame(const AntarcticGame& _other) = delete; // default Copy constructor 디폴트 복사생성자
	AntarcticGame(AntarcticGame&& _other) noexcept; // default RValue Copy constructor 디폴트 RValue 복사생성자

public:		//delete operator
	AntarcticGame& operator=(const AntarcticGame& _other) = delete; // default Copy operator 디폴트 대입 연산자
	AntarcticGame& operator=(const AntarcticGame&& _other) = delete; // default RValue Copy operator 디폴트 RValue 대입연산자

public:		//member Func
};

