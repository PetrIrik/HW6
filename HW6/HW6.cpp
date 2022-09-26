#include <iostream>
#include<locale>
#include <cctype>   
#include <cstdlib>  
#include <sstream> 
#include "Card.h"
#include "Player.h"
#include "House.h"

bool is_number(const std::string& sValue) {
    return !sValue.empty() && sValue.find_first_not_of("-0123456789") == std::string::npos;
}


int GetInput(const std::string& sInfo, const std::string& sError) {
    bool bCorrect = false;
    std::string sValue;

    do {
        std::cin.clear();
        std::cin.sync();

        std::cout << sInfo;
        std::getline(std::cin, sValue);

        if (bCorrect = is_number(sValue)) {
            break;
        }

        std::cerr << sError << std::endl;
    } while (!bCorrect);

    return std::atoi(sValue.c_str());
}

std::ostream& endll(std::ostream& out)
{
    return out << std::endl << std::endl;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int a = GetInput("Введите целочисленное значение N=","Ошибка! Повторите ввод!\n");

    std::cout << "Вы ввели " << a << std::endl;

    std::cout << "\nЗадание 2"<<std::endl;
    std::cout << "first" << endll << "lust";


    Player Human("Player");
    House Ai;

    Card* pCard1 = new Card(Value::TWO, Suit::HEARTS);
    Card* pCard2 = new Card(Value::SEVEN, Suit::DIAMONDS);

    Human.Add(pCard1);
    Human.Add(pCard2);

    std::cout << Human << std::endl;

    Card* pCard3 = new Card(Value::ACE, Suit::SPADES);
    Card* pCard4 = new Card(Value::JACK, Suit::CLUBS);

    Ai.Add(pCard3);
    Ai.Add(pCard4);

    Ai.FilpFirstCard();

    std::cout << Ai << std::endl;

    Human.Clear();

    delete pCard1;
    delete pCard2;
    delete pCard3;
    delete pCard4;

    return 0;
}


