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
    


        std::cout << "\x1b[31m������ ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m�� �׸��� Ű�ڵ� : 1 (1)" << std::endl; // ����
        std::cout << "\x1b[33m��Ȳ�� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m�� �׸��� Ű�ڵ� : 2 (10)" << std::endl; // ��Ȳ(����� �ڵ带 ��Ȳ���� ����)
        std::cout << "\x1b[93m����� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m�� �׸��� Ű�ڵ� : 4 (100)" << std::endl; // �����(���� ��������� ǥ��)
        std::cout << "\x1b[32m�ʷϻ� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m�� �׸��� Ű�ڵ� : 8 (1000)" << std::endl; // �ʷ�
        std::cout << "\x1b[34m�Ķ��� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m�� �׸��� Ű�ڵ� : 16 (10000)" << std::endl; // �Ķ�
        std::cout << "\x1b[94m  ���� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m�� �׸��� Ű�ڵ� : 32 (100000)" << std::endl; // ����(���� �Ķ����� ǥ��)
        std::cout << "\x1b[35m����� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m�� �׸��� Ű�ڵ� : 64 (1000000)" << std::endl; // ����
        std::cout << "���α׷� ���� : 64 (10000000)" << std::endl;
        
        //0111 1111
        //0000 1001

        int keycode = 0;
        std::bitset<8> set("11111111");

        std::vector<int> output;
        int temp;
        bool bOngoing = true;

        do{
            std::cout << "@---------------------------------@" << std::endl;
            std::cout << "Ű�ڵ带 �Է��ϼ���                            (�Է� ����(1 + 2 + 8 = 11)" << std::endl;
            std::cout << "�Է� : ";

            std::cin >> keycode;
            


            std::bitset<32> KBinary(keycode);


            for (int i = 0; i < set.size(); i++)
            {
                if (set[i] && KBinary[i]) {
                    temp = (1 << i);
                    std::cout << temp << " "; // ���� 1 (0001)  ���� ����Ʈ �����ڸ� ���� i�� �ű�°�
                    output.push_back(temp);
                }

            }
            std::cout << std::endl;
            for (int element : output)
            {
                switch (element)
                {
                case 1: 
                    std::cout << "\x1b[31m������ ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 2:
                    std::cout << "\x1b[33m��Ȳ�� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 4:
                    std::cout << "\x1b[93m����� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 8:
                    std::cout << "\x1b[32m�ʷϻ� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 16: 
                    std::cout << "\x1b[34m�Ķ��� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;

                    break;
                case 32:
                    std::cout << "\x1b[94m  ���� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 64:
                    std::cout << "\x1b[35m����� ���" << "\u25A0\u25A0\u25A0\u25A0\u25A0" << "\x1b[0m" << std::endl;
                    break;
                case 128:
                    std::cout << "���α׷� ���� : 128  (10000000)" << std::endl << std::endl;
                    bOngoing = false;
                    break;
                default:
                    break;
                }
            }
            output.clear();

            std::cout << std::endl;

        } while (bOngoing);


    // ���� ����
    std::cout << "\x1b[0m";
   

    return 0;
}

        /*
        * ��� ����� �׸��� Ű�ڵ� : 1 (1)
        * ������ ����� �׸��� Ű�ڵ� : 2 (10)
        * ȸ�� ����� �׸��� Ű�ڵ� : 4 (100)
        * ����� ����� �׸��� Ű�ڵ� : 8 (1000)
        * ���� ����� �׸��� Ű�ڵ� : 16 (10000)
        * ����Ÿ�� ����� �׸��� Ű�ڵ� : 32 (100000)
        * ���α׷� ���� : 64 (1000000)
        *
        * ���α׷��� �����ϸ� �Ʒ��� ���� ���ÿ�
        *
        *
        * ȭ�鿡 �׸��� �׸��� ���α׷��Դϴ�.
        * �й� : 349218347(�����й�)
        * �̸� : �����̸�
        *
        * ȭ�鿡 �׸� ��ü�ڵ带 �Է��ϼ��� :
        */
        //std::cout << "\x1b[37m��� ���\x1b[0m�� �׸��� Ű�ڵ� : 1 (1)" << std::endl;
        //std::cout << "\x1b[31m������ ���\x1b[0m�� �׸��� Ű�ڵ� : 2 (10)" << std::endl;
        //std::cout << "\x1b[90mȸ�� ���\x1b[0m�� �׸��� Ű�ڵ� : 4 (100)" << std::endl;
        //std::cout << "\x1b[93m����� ���\x1b[0m�� �׸��� Ű�ڵ� : 8 (1000)" << std::endl;
        //std::cout << "\x1b[33m���� ���\x1b[0m�� �׸��� Ű�ڵ� : 16 (10000)" << std::endl;
        //std::cout << "\x1b[35m����Ÿ�� ���\x1b[0m�� �׸��� Ű�ڵ� : 32 (100000)" << std::endl;