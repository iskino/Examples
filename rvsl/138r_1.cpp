/*
Можно также просто возвращать весь массив (m_array) и использовать оператор [] для доступа к его элементам:
*/
#include <iostream>

class IntArray
{
private:
    int m_array[10];

public:
    int* getArray() { return m_array; }
};

int main()
{
    IntArray array;
    array.getArray()[4] = 5;

    return 0;
}
// Но можно сделать еще проще, перегрузив оператор индексации.
