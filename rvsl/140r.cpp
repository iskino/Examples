/*
Здесь есть две вещи, на которые следует обратить внимание:
  В качестве функции перегрузки используется метод operator int(). Обратите внимание, между словом
  operator и типом, в который мы хотим выполнять конвертацию (в данном случае, тип int), находится пробел.
  Функция перегрузки не имеет типа возврата. C++ предполагает, что вы будете возвращать корректный тип.

Таким образом мы можем напрямую конвертировать центы в доллары:
*/
#include <iostream>

class Dollars
{
private:
	int m_dollars;
public:
	Dollars(int dollars = 0)
	{
		m_dollars = dollars;
	}

	// Перегрузка операции преобразования значения типа Dollars в значение типа int
	operator int() { return m_dollars; }

	int getDollars() { return m_dollars; }
	void setDollars(int dollars) { m_dollars = dollars; }
};

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents=0)
    {
        m_cents = cents;
    }

     // Выполняем конвертацию Cents в Dollars
     operator Dollars() { return Dollars(m_cents / 100); }
};

void printDollars(Dollars dollars)
{
    std::cout << dollars; // dollars неявно конвертируется в int здесь
}

int main()
{
    Cents cents(700);
    printDollars(cents); // cents неявное конвертируется в Dollars здесь

    return 0;
}
/*
Результат выполнения программы выше:
7
Всё логично: 700 центов = 7 долларов!

Теперь мы можем явно конвертировать объект класса Dollars в тип int:
  Dollars dollars(9);
  int d = static_cast<int>(dollars);
*/
