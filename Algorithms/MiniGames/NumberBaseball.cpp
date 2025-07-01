/*
 숫자 야구 만들기

1. 컴퓨터가 랜덤으로 기억한 3자리 숫자를 정확하게 맞추면 되는 게임이다. 단 숫자는 자연수이고 중복되지 않는다.
2. 사용자가 3자리 숫자를 입력하면 컴퓨터는 기억한 숫자와 비교한다.
- 중복된 숫자가 하나도 없으면 아웃,
- 중복된 숫자가 같은 자리에 있으면 스트라이크,
- 다른 자리에 숫자가 있으면 볼

예> 컴퓨터가 기억한 숫자가 	(1, 4, 6)일 때
플레이어가 물어본 숫자가   	(2, 3, 5)라면 숫자가 중복되지 않아 아웃입니다.
(1, 3, 5)라면 중복된 숫자 1이 자리가 같으니(둘 다 첫번째 자리) 1스트라이크 입니다.
(2, 6, 7)이라면 중복된 숫자 6이 있지만 자리가 다르니 1볼 입니다.
(1, 6, 7)이라면 중복된 숫자 1의 자리가 같고 6은 자리가 다르니 1스트라이크 1볼 입니다.
*/

#include <iostream>
#include <stdint.h> // stdint 의 자료형은 플랫폼이 다르더라도 각 자료형이 사용하는 bit 수를 사용하도록 보장합니다.
#include <random>
#include <chrono>

using namespace std;

struct GameState 
{
	uint8_t bGameLoop : 1;
	uint8_t bInputLoop : 1;
};

void ShuffleArray(int32_t* IntArr, uint8_t Size)
{
	unsigned int Seed = (unsigned int)chrono::system_clock::now().time_since_epoch().count(); // 현재 시간을 기준으로 Seed 생성

	default_random_engine Rng(Seed); // Seed 기반으로 random number generator를 초기화.

	// 피셔-예이츠 셔플
	//	- 유한한 수열을 무작위로 섞는 알고리즘.
	//	- 배열의 마지막 요소부터 시작하여 각 요소를 무작위로 선택된 요소와 교환하는 방식.
	for (int32_t i = Size - 1; i > 0; i--)
	{
		uniform_int_distribution<int32_t> Dist(0, i); // [0, i] 사이에서 랜덤 인덱스를 하나 뽑기
		int32_t j = Dist(Rng);

		swap(IntArr[i], IntArr[j]);
	}
}

int main()
{
	// uint8_t bGameLoop : 1; // 구조체안에 없으면 bit level 컨트롤 불가

	GameState state;
	state.bGameLoop = 1;
	state.bInputLoop = 1;

	while (state.bGameLoop)
	{
		// 1.
		int32_t Numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

		ShuffleArray(Numbers, 9);

		int32_t Answer[3] = { Numbers[0], Numbers[1], Numbers[2] };

		// DEBUG
		cout << "[ ";
		for (int i = 0; i < 3; i++)
		{
			cout << (int)Answer[i] << " ";
		}
		cout << "]";

		cout << "컴퓨터가 숫자를 선택했습니다.\n";

		// 2.
		while (state.bInputLoop)
		{
			cout << "---\n";
			cout << "세 자리 숫자를 입력하세요 (1~9, 중복 없이)\n: ";

			// 1)
			int32_t Input[3];
			cin >> Input[0] >> Input[1] >> Input[2];

			// 2)
			int32_t Strike = 0;
			int32_t Ball = 0;

			for (int32_t i = 0; i < 3; i++)
			{
				for (int32_t j = 0; j < 3; j++)
				{
					if (Answer[i] == Input[j])
					{
						if (i == j)
						{
							Strike++;
						}
						else
						{
							Ball++;
						}
					}
				}
			}

			// 3)
			cout << "\n==========\n";
			for (int i = 0; i < Strike; i++)
			{
				cout << " ★ ";
			}

			cout << "\n----------\n";

			for (int i = 0; i < Ball; i++)
			{
				cout << " ☆ ";
			}

			cout << "\n==========\n";

			
			if (Strike == 3)
			{
				cout << "3 스트라이크!\n";
				cout << "게임을 종료합니다.\n\n";

				state.bGameLoop = 0;
				state.bInputLoop = 0;
			}
			else if (Strike == 0 && Ball == 0)
			{
				cout << "아웃!\n";
				cout << "\n";
			}
			else
			{
				cout << Strike << " 스트라이크\n";
				cout << Ball << " 볼 \n";
				cout << "\n";
			}
		}
	}
}

// memo 1
//	1. 컴퓨터가 중복되지 않는 숫자를 3개 기억한다.
//	2. 플레이어가 숫자를 맟출 때 까지
//		1) 플래이어의 숫자 3개 입력을 받는다.
//		2) 숫자가 얼마나 중복되는지 검사한다.
//		3) 결과를 출력한다
