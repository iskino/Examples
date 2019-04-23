/*
Сначала инициализируется анонимный объект Drob, который приводит к вызову конструктора Drob(int, int).
Затем этот анонимный объект используется для инициализации объекта sixSeven класса Drob.
Реальный результат:
6/7
Почему наш конструктор копирования не сработал?
Дело в том, что инициализация анонимного объекта, а затем использование этого объекта для
прямой инициализации уже не анонимного объекта выполняется в два этапа (первый — создание анонимного объекта,
второй — вызов конструктора копирования). Однако конечный результат, по сути,
идентичен простому выполнению прямой инициализации, которая занимает всего лишь один шаг.
По этой причине в таких случаях компилятору разрешается отказаться от вызова конструктора копирования
и просто выполнить прямую инициализацию. Этот процесс называется элизия (elision).
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
	Drob(const Drob &drob) :
		m_numerator(drob.m_numerator), m_denominator(drob.m_denominator)
	{
		// Нет необходимости выполнять проверку denominator здесь, так как эта проверка уже осуществляется в конструкторе класса Drob
		std::cout << "Copy constructor worked here!\n"; // просто чтобы доказать, что это работает
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
	Drob sixSeven(Drob(6, 7));
	std::cout << sixSeven;
	return 0;
}
