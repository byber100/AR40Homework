// 0222Homework.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> Arr = std::vector<int>(5);

    Arr[0] = 3;
    Arr[1] = 2;
    Arr[2] = 1;
    Arr[3] = 4;
    Arr[4] = 5;

    int Cnt = Arr.size();
    for (size_t i = 0; i < Cnt; i++)
    {
        for (size_t j = 0; j < Cnt - (i+1); j++)
        {
            int iValue = Arr[i];
            int jValue = Arr[j+1];

            if (Arr[j] > Arr[j+1])
            {
                int Value = Arr[j + 1];
                Arr[j + 1] = Arr[j];
                Arr[j] = Value;
            }
        }
    }

    for (size_t i = 0; i < Cnt; i++)
    {
        std::cout << Arr[i] << std::endl;
    }

}
