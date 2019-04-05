/*
Мы фактически вместили три строчки в одно выражение! Теперь рассмотрим это детальнее:
  -сначала вызывается operation.add(7), который добавляет 7 к нашему m_value;
  -затем add() возвращает *this, что является ссылкой на объект operation;
  -затем вызов operation.sub(5) вычитает 5 из m_value и возвращает operation;
  -multiply(3) умножает m_value на 3 и возвращает operation, который уже игнорируется;
  -однако, поскольку каждая функция модифицировала operation, то m_value объекта operation
   теперь содержит значение ((0 + 7) — 5) * 3), которое равно 6.

   Указатель *this является скрытым параметром, который неявно добавляется к каждому методу класса.
   В большинстве случаев нам не нужно обращаться к нему напрямую, но при необходимости это можно сделать.
   Стоит отметить, что this является константным указателем — вы можете изменить значение исходного объекта,
   но вы не можете указать this указывать на что-то другое!

   Если у вас есть функции, которые возвращают void – возвращайте *this вместо void, таким образом
   вы сможете соединять несколько методов в одну «цепочку». Это чаще всего используется
   при перегрузке операторов в классах.
*/
class Mathem
{
private:
    int m_value = 0;

public:
    Mathem(int value=0);

    Mathem& add(int value);
    Mathem& sub(int value);
    Mathem& divide(int value);

    int getValue() { return m_value; }
};

Mathem::Mathem(int value): m_value(value)
{
}

Mathem& Mathem::add(int value)
{
    m_value += value;
    return *this;
}

Mathem& Mathem::sub(int value)
{
    m_value -= value;
    return *this;
}

Mathem& Mathem::divide(int value)
{
    m_value /= value;
    return *this;
}

int main()
{
    Mathem operation;
    operation.add(7).sub(5).multiply(3);

    std::cout << operation.getValue() << '\n'; // Результат: 6
    return 0;
}
