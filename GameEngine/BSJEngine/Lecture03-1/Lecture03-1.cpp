#include <iostream>
#include <string>
#include <bitset>
#include <vector>


enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

int main() 

    {
        //std::cout << "\x1b[033m" << "mfjeifjowiejfowiejf";
    


        std::cout << "\x1b[31m빨강색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m을 그리는 키코드 : 1 (1)" << std::endl; // 빨강
        std::cout << "\x1b[33m주황색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m을 그리는 키코드 : 2 (10)" << std::endl; // 주황(노란색 코드를 주황으로 가정)
        std::cout << "\x1b[93m노란색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m을 그리는 키코드 : 4 (100)" << std::endl; // 노란색(밝은 노란색으로 표현)
        std::cout << "\x1b[32m초록색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m을 그리는 키코드 : 8 (1000)" << std::endl; // 초록
        std::cout << "\x1b[34m파란색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m을 그리는 키코드 : 16 (10000)" << std::endl; // 파랑
        std::cout << "\x1b[94m  남색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m을 그리는 키코드 : 32 (100000)" << std::endl; // 남색(밝은 파랑으로 표현)
        std::cout << "\x1b[35m보라색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m을 그리는 키코드 : 64 (1000000)" << std::endl; // 보라
        std::cout << "프로그램 종료 : 64 (10000000)" << std::endl;
        
        //0111 1111
        //0000 1001

        int keycode = 0;
        std::bitset<8> set("11111111");

        std::vector<int> output;
        int temp;
        bool bOngoing = true;

        do{
            std::cout << "@---------------------------------@" << std::endl;
            std::cout << "키코드를 입력하세요                            (입력 예시(1 + 2 + 8 = 11)" << std::endl;
            std::cout << "입력 : ";

            std::cin >> keycode;
            


            std::bitset<32> KBinary(keycode);


            for (int i = 0; i < set.size(); i++)
            {
                if (set[i] && KBinary[i]) {
                    temp = (1 << i);
                    std::cout << temp << " "; // 숫자 1 (0001)  왼쪽 시프트 연산자를 통해 i번 옮기는것
                    output.push_back(temp);
                }

            }
            std::cout << std::endl;
            for (int element : output)
            {
                switch (element)
                {
                case 1: 
                    std::cout << "\x1b[31m빨강색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 2:
                    std::cout << "\x1b[33m주황색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 4:
                    std::cout << "\x1b[93m노란색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 8:
                    std::cout << "\x1b[32m초록색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 16: 
                    std::cout << "\x1b[34m파란색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;

                    break;
                case 32:
                    std::cout << "\x1b[94m  남색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 64:
                    std::cout << "\x1b[35m보라색 블록" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 128:
                    std::cout << "프로그램 종료 : 128  (10000000)" << std::endl << std::endl;
                    bOngoing = false;
                    break;
                default:
                    break;
                }
            }
            output.clear();

            std::cout << std::endl;

        } while (bOngoing);


    // 색상 리셋
    std::cout << "\x1b[0m";
   

    return 0;
}

        /*
        * 흰색 블록을 그리는 키코드 : 1 (1)
        * 빨강색 블록을 그리는 키코드 : 2 (10)
        * 회색 블록을 그리는 키코드 : 4 (100)
        * 노란색 블록을 그리는 키코드 : 8 (1000)
        * 갈색 블록을 그리는 키코드 : 16 (10000)
        * 마젠타색 블록을 그리는 키코드 : 32 (100000)
        * 프로그램 종료 : 64 (1000000)
        *
        * 프로그램을 시작하면 아래와 같이 쓰시오
        *
        *
        * 화면에 그림을 그리는 프로그램입니다.
        * 학번 : 349218347(본인학번)
        * 이름 : 본인이름
        *
        * 화면에 그릴 물체코드를 입력하세요 :
        */
        //std::cout << "\x1b[37m흰색 블록\x1b[0m을 그리는 키코드 : 1 (1)" << std::endl;
        //std::cout << "\x1b[31m빨강색 블록\x1b[0m을 그리는 키코드 : 2 (10)" << std::endl;
        //std::cout << "\x1b[90m회색 블록\x1b[0m을 그리는 키코드 : 4 (100)" << std::endl;
        //std::cout << "\x1b[93m노란색 블록\x1b[0m을 그리는 키코드 : 8 (1000)" << std::endl;
        //std::cout << "\x1b[33m갈색 블록\x1b[0m을 그리는 키코드 : 16 (10000)" << std::endl;
        //std::cout << "\x1b[35m마젠타색 블록\x1b[0m을 그리는 키코드 : 32 (100000)" << std::endl;