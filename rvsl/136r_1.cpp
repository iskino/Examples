// Перегрузим операторы равенства == и != для класса Car:
#include <iostream>
#include <string>

class Car
{
private:
    std::string m_company;
    std::string m_model;

public:
    Car(std::string company, std::string model)
        : m_company(company), m_model(model)
    {
    }

    friend bool operator== (const Car &c1, const Car &c2);
    friend bool operator!= (const Car &c1, const Car &c2);
};

bool operator== (const Car &c1, const Car &c2)
{
    return (c1.m_company == c2.m_company &&
            c1.m_model== c2.m_model);
}

bool operator!= (const Car &c1, const Car &c2)
{
    return !(c1== c2);
}

int main()
{
    Car mustang("Ford", "Mustang");
    Car logan("Renault", "Logan");

    if (mustang == logan)
        std::cout << "Mustang and Logan are the same.\n";

    if (mustang != logan)
        std::cout << "Mustang and Logan are not the same.\n";

    return 0;
}
/*
Всё просто. Поскольку результат выполнения оператора != является прямо противоположным
результату выполнения оператора ==, то мы определили оператор != используя уже перегруженный
оператор == (уменьшив, таким образом, количество кода, сложность и возможность возникновения ошибок).
*/
