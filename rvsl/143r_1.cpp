/*
По умолчанию C++ обрабатывает любой конструктор как оператор неявного преобразования. Рассмотрим следующую программу.
Хотя функция makeNegative() ожидает объект класса Drob, мы передаем ей целочисленный литерал 7.
Поскольку у класса Drob есть конструктор, который может принимать одно целочисленное значение
(конструктор по умолчанию), то компилятор выполнит неявную конвертацию литерала 7 в объект класса Drob.
Это делается путем выполнения копирующей инициализацией параметра d функции makeNegative() с помощью
конструктора Drob(int, int).

Результат выполнения программы выше:
Copy constructor worked here!
-7/1

Неявное преобразование работает для всех видов инициализации (прямой, uniform и копирующей).
Конструкторы, которые используются в неявных преобразованиях, называются конструкторами преобразования
(или конструкторами конвертации). До C++11 конструкторами преобразования могли быть конструкторы только
с одним параметром. Однако в C++11 это ограничение было снято (наряду с добавлением uniform инициализации),
и конструкторы, имеющие несколько параметров, также уже могут быть конструкторами преобразования.
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

	friend std::ostream& operator<<(std::ostream& out, const Drob &d1);
        int getNumerator() { return m_numerator; }
        void setNumerator(int numerator) { m_numerator = numerator; }
};

std::ostream& operator<<(std::ostream& out, const Drob &d1)
{
	out << d1.m_numerator << "/" << d1.m_denominator;
	return out;
}

Drob makeNegative(Drob d)
{
    d.setNumerator(-d.getNumerator());
    return d;
}

int main()
{
    std::cout << makeNegative(7); // передаем целочисленное значение

    return 0;
}
