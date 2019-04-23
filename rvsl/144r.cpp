/*
Перегрузка оператора присваивания (=) довольно-таки проста и выполняется через метод класса, но есть один нюанс.
Однако в случаях, когда используется динамическое выделение памяти, то самоприсваивание может быть даже опасным.

Результат выполнения программы выше:
6/7

До этого момента всё просто. Функция перегрузки operator= возвращает скрытый указатель *this
(т.е. текущий объект) и мы даже можем связать выполнение нескольких операций присваивания вместе:
int main()
{
    Drob d1(6,7);
    Drob d2(8,3);
    Drob d3(10,4);

    d1 = d2 = d3; // цепочка операций присваивания

    return 0;
}
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
		// Нет необходимости выполнять проверку denominator здесь, так как эта проверка уже осуществлена в конструкторе по умолчанию
		std::cout << "Copy constructor worked here!\n"; // просто чтобы доказать, что это работает
	}

        // Перегрузка оператора присваивания
        Drob& operator= (const Drob &drob)
        {
             // выполняем копирование значений
             m_numerator = drob.m_numerator;
             m_denominator = drob.m_denominator;

             // возвращаем текущий объект, чтобы мы могли связать в цепочку выполнение нескольких операций присваивания
             return *this;
        }

	friend std::ostream& operator<<(std::ostream& out, const Drob &d1);

};

std::ostream& operator<<(std::ostream& out, const Drob &d1)
{
	out << d1.m_numerator << "/" << d1.m_denominator;
	return out;
}

int main()
{
    Drob sixSeven(6, 7);
    Drob d;
    d = sixSeven; // вызывается перегруженный оператор присваивания
    std::cout << d;

    return 0;
}
