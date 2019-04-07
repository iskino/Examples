#include <iostream>

class Anything
{
private:
    static int s_idGenerator;
    int m_id;

public:
    Anything() { m_id = s_idGenerator++; } // увеличиваем значение идентификатора для следующего объекта

    int getID() const { return m_id; }
};

// Мы определяем и инициализируем s_idGenerator несмотря на то, что он объявлен как private
// Это нормально, поскольку определение не подпадает под действия спецификаторов доступа
int Anything::s_idGenerator = 1; // начинаем наш ID-генератор со значения 1

int main()
{
    Anything first;
    Anything second;
    Anything third;

    std::cout << first.getID() << '\n';
    std::cout << second.getID() << '\n';
    std::cout << third.getID() << '\n';
    return 0;
}

// Результат: 1, 2, 3
