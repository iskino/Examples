/*
Когда вы передаете или возвращаете объект класса по значению, то в этом процессе используется копирующая инициализация.
Здесь функция makeNegative принимает объект класса Drob по значению и возвращает его так же по значению.
Результат выполнения программы выше:

Copy constructor worked here!
Copy constructor worked here!
-6/7

Первый вызов конструктора копирования выполнится при передаче sixSeven в качестве аргумента
в параметр d функции makeNegative(). Второй вызов выполнится при возврате объекта из makeNegative()
обратно в main(). Т.е. объект sixSeven копируется дважды.
*/
#include <cassert>
#include <iostream>

class Drob
{
private:
	int m_numerator;
	int m_denominator;

public:
    // Конструктор по умолчанию
    Drob(int numerator=0, int denominator=1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }

        // Конструктор копирования
	Drob(const Drob &copy) :
		m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
	{
		// Нет необходимости выполнять проверку denominator здесь, так как она осуществляется в конструкторе по умолчанию
		std::cout << "Copy constructor worked here!\n"; // просто чтобы доказать, что это работает
	}

	friend std::ostream& operator<<(std::ostream& out, const Drob &d1);
        int getNumerator() { return m_numerator; }
        void setNumerator(int numerator) { m_numerator = numerator; }
};

std::ostream& operator<<(std::ostream& out, const Drob &d1)
{
	out << d1.m_numerator << "/" << d1.m_denominator;
	return out;
}

Drob makeNegative(Drob d) // правильно было бы здесь использовать константную ссылку
{
    d.setNumerator(-d.getNumerator());
    return d;
}

int main()
{
    Drob sixSeven(6, 7);
    std::cout << makeNegative(sixSeven);

    return 0;
}
