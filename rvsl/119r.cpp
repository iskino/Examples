#include <string>
#include <iostream>

class Employee
{
private:
    int m_id;
    std::string m_name;

public:
    Employee(int id=0, const std::string &name=""):
        m_id(id), m_name(name)
    {
        std::cout << "Employee " << m_name << " created.\n";
    }

    // Используются делегирующие конструкторы для минимизации дублированного кода
    Employee(const std::string &name) : Employee(0, name) { }
};

int main()
{
    Employee a;
    Employee b("Ivan");

    return 0;
}
