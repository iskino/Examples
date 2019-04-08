#include <iostream>

class Dollars
{
private:
	int m_dollars;

public:
	Dollars(int dollars) { m_dollars = dollars; }

	int getDollars() const { return m_dollars; }
};

// Примечание: Эта функция не является ни методом класса, ни дружественной классу Dollars!
Dollars operator+(const Dollars &d1, const Dollars &d2)
{
	// используем конструктор Dollars и operator+(int, int)
        // здесь нам не нужен прямой доступ к закрытым членам класса Dollars
	return Dollars(d1.getDollars() + d2.getDollars());
}

int main()
{
	Dollars dollars1(7);
	Dollars dollars2(9);
	Dollars dollarsSum = dollars1 + dollars2;
	std::cout << "I have " << dollarsSum.getDollars() << " dollars." << std::endl;

	return 0;
}
