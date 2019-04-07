/*
Функцию можно перегрузить таким образом, чтобы иметь константную и неконстантную версию одной и той же функции.
Константная версия функции будет вызываться для константных объектов, а неконстантная версия
будет вызываться для неконстантных объектов.
*/
#include <string>

class Anything
{
private:
    std::string m_value;

public:
    Anything(const std::string &value="") { m_value= value; }

    const std::string& getValue() const { return m_value; } // getValue() для константных объектов
    std::string& getValue() { return m_value; } // getValue() для неконстантных объектов
};

int main()
{
	Anything anything;
	anything.getValue() = "Hello!"; // вызывается неконстантный getValue()

	const Anything anything2;
	anything2.getValue(); // вызывается константный getValue()

	return 0;
}
