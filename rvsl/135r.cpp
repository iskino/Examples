//В следующем примере рассмотрим перегрузку унарных операторов минус (–) и НЕ (!) для класса Something:
#include <iostream>

class Something
{
private:
	double m_a, m_b, m_c;

public:
	Something(double a = 0.0, double b = 0.0, double c = 0.0) :
		m_a(a), m_b(b), m_c(c)
	{
	}

	// Конвертируем объект класса Something в отрицательный
	Something operator- () const
	{
		return Something(-m_a, -m_b, -m_c);
	}

	// Возвращаем true, если используются значения по умолчанию, в противном случае - false
	bool operator! () const
	{
		return (m_a == 0.0 && m_b == 0.0 && m_c == 0.0);
	}

	double getA() { return m_a; }
	double getB() { return m_b; }
	double getC() { return m_c; }
};

int main()
{
	Something something; // используем конструктор по умолчанию со значениями 0.0, 0.0, 0.0

	if (!something)
		std::cout << "Something is null.\n";
	else
		std::cout << "Something is not null.\n";

	return 0;
}
/*
Здесь перегруженный оператор НЕ (!) возвращает true, если в Something используются
значения по умолчанию (0.0, 0.0, 0.0). Результат выполнения программы выше:

Something is null.

Если же задать любые ненулевые значения для объекта класса Something:
Something something(23.11, 37.1, 20.12);

То результатом будет: Something is not null.

Перегрузка унарного оператора плюс (+) для класса Something:
Есть два решения. Первое:

Something Something::operator+ () const
{
    return Something(m_a, m_b, m_c);
}

Второе:

Something Something::operator+ () const
{
    return *this;
}

Это работает, так как Something, который мы возвращаем, является текущим объектом.
