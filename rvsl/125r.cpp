/*
При определении статического члена s_initializer вызовется конструктор по умолчанию _nested()
(так как s_initializer является объектом класса _nested). Мы можем использовать этот конструктор
 для инициализации любых статических переменных-членов класса Something.
 Самое крутое здесь – это то, что весь код инициализации скрыт внутри исходного класса со статическим членом.
*/
#include <iostream>
#include <vector>

class Something
{
private:
	static std::vector<char> s_mychars;

public:
	class _nested // определяем вложенный класс с именем _nested
	{
	public:
		_nested() // конструктор _nested инициализирует нашу статическую переменную-член
		{
			s_mychars.push_back('o');
			s_mychars.push_back('a');
			s_mychars.push_back('u');
			s_mychars.push_back('i');
			s_mychars.push_back('e');
		}
	};

	// статический метод для вывода s_mychars
	static void getSomething() {
		for (auto const &element : s_mychars)
			std::cout << element << ' ';
	}
private:
	static _nested s_initializer; // используем статический объект класса _nested для гарантии того, что конструктор _nested выполнится
};

std::vector<char> Something::s_mychars; // определяем нашу статическую переменную-член
Something::_nested Something::s_initializer; // определяем наш статический s_initializer, который вызовет конструктор _nested для инициализации s_mychars

int main() {
	Something::getSomething();
	return 0;
}

// Результат: o a u i e
