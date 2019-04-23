/*
Лучшее решение — использовать ключевое слово delete (добавленное в C++11) для удаления этого конструктора:
После удаления функции, любое её использование вызовет ошибку компиляции.

Обратите внимание, конструктор копирования и перегруженные операторы также могут быть удалены с
помощью delete для предотвращения их использования.
*/
#include <string>
#include <iostream>

class SomeString
{
private:
	std::string m_string;

public:
        SomeString(char) = delete; // любое использование этого конструктора приведет к ошибке

        // ключевое слово explicit делает этот конструктор закрытым для выполнения любых неявных конвертаций
	explicit SomeString(int a) // выделяем строку размером a
	{
		m_string.resize(a);
	}

	SomeString(const char *string) // выделяем строку для хранения значения типа string
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const SomeString &s);

};

std::ostream& operator<<(std::ostream& out, const SomeString &s)
{
	out << s.m_string;
	return out;
}

int main()
{
	SomeString mystring('a'); // ошибка компиляции, поскольку SomeString(char) удален
	std::cout << mystring;
	return 0;
}
