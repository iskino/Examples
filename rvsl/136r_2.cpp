// Перегрузим операторы сравнения >, <, >= и <=:
#include <iostream>

class Dollars
{
private:
    int m_dollars;

public:
    Dollars(int dollars) { m_dollars = dollars; }

    friend bool operator> (const Dollars &d1, const Dollars &d2);
    friend bool operator<= (const Dollars &d1, const Dollars &d2);

    friend bool operator< (const Dollars &d1, const Dollars &d2);
    friend bool operator>= (const Dollars &d1, const Dollars &d2);
};

bool operator> (const Dollars &d1, const Dollars &d2)
{
    return d1.m_dollars > d2.m_dollars;
}

bool operator>= (const Dollars &d1, const Dollars &d2)
{
    return d1.m_dollars >= d2.m_dollars;
}

bool operator< (const Dollars &d1, const Dollars &d2)
{
    return d1.m_dollars < d2.m_dollars;
}

bool operator<= (const Dollars &d1, const Dollars &d2)
{
    return d1.m_dollars <= d2.m_dollars;
}

int main()
{
    Dollars ten(10);
    Dollars seven(7);

    if (ten > seven)
        std::cout << "Ten dollars are greater than seven dollars.\n";
    if (ten >= seven)
        std::cout << "Ten dollars are greater than or equal to seven dollars.\n";
    if (ten < seven)
        std::cout << "Seven dollars are greater than ten dollars.\n";
    if (ten <= seven)
        std::cout << "Seven dollars are greater than or equal to ten dollars.\n";


    return 0;
}
/*
Всё просто.
Но, как вы уже могли бы заметить, операторы > и <= являются логическими противоположностями,
поэтому одного из них можно было бы определить через второй. Та же ситуация и с < и >=.
Но, поскольку определения функций перегрузки столь просты, а операторы в строчке объявления
функции так хорошо сочетаются с операторами в строчке возврата результата, мы решили этого не делать.
*/
