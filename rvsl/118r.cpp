// Объект defl класса Thing будет искать конструктор по умолчанию. Если его не будет, то компилятор выдаст ошибку
#include <string>
#include <iostream>

class Thing
{
private:
	std::string m_color = "blue";
	double m_radius = 20.0;

public:
        // Конструктор по умолчанию без параметров (color и radius используют значения по умолчанию)
	Thing()
	{
	}

        // Конструктор с параметром color (для radius предоставлено значение по умолчанию)
	Thing(const std::string &color):
		m_color(color)
	{
	}

        // Конструктор с параметром radius (для color предоставлено значение по умолчанию)
	Thing(double radius):
		m_radius(radius)
	{
	}

        // Конструктор с параметрами color и radius
	Thing(const std::string &color, double radius):
		m_color(color), m_radius(radius)
	{
	}

	void print()
	{
		std::cout << "color: " << m_color << " and radius: " << m_radius << '\n';
	}
};

int main()
{
	Thing defl;
	defl.print();

	Thing red("red");
	red.print();

	Thing thirty(30.0);
	thirty.print();

	Thing redThirty("red", 30.0);
	redThirty.print();

	return 0;
}
