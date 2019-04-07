/*
В отличие от функций, которые не могут быть вложены внутри друг друга,
в C++ пользовательские типы данных могут быть определены (вложены) внутри класса.
Для этого нужно просто определить пользовательский тип внутри класса под соответствующим спецификатором доступа.
*/
#include <iostream>

class Fruit
{
public:
	// Мы переместили FruitList внутрь класса под спецификатор доступа public
	enum FruitList
	{
		AVOCADO,
		BLACKBERRY,
		LEMON
	};

private:
	FruitList m_type;

public:


	Fruit(FruitList type) :
		m_type(type)
	{
	}

	FruitList getType() { return m_type;  }
};

int main()
{
	// Доступ к FruitList осуществляется через Fruit
	Fruit avocado(Fruit::AVOCADO);

	if (avocado.getType() == Fruit::AVOCADO)
		std::cout << "I am an avocado!";
	else
		std::cout << "I am not an avocado!";

	return 0;
}
