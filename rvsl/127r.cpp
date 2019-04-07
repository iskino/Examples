#include <iostream>

class Dollars
{
private:
    int m_dollars;

public:
    Dollars(int dollars) { m_dollars = dollars; }

    int getDollars() const { return m_dollars; }
};

Dollars add(const Dollars &d1, const Dollars &d2)
{
    return Dollars(d1.getDollars() + d2.getDollars()); // возвращаем анонимный объект Dollars
}

int main()
{
    std::cout << "I have " << add(Dollars(7), Dollars(9)).getDollars() << " dollars." << std::endl; // выводим анонимный объект Dollars

    return 0;
}
