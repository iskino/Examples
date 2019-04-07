/*
Здесь мы объявили функцию reset(), которая принимает объект класса Anything и
устанавливает m_value значение 0. Поскольку reset() не является членом
класса Anything, то в обычной ситуации reset() не имел бы доступа к
закрытым членам Anything. Однако, поскольку эта функция является дружественной
классу Anything, она имеет доступ к закрытым членам Anything.

Обратите внимание, мы должны передавать объект Anything в reset() в качестве параметра.
Это связано с тем, что reset() не является методом класса. Он не имеет указателя this *
и кроме как передачи объекта, он не сможет взаимодействовать с классом.
*/
class Anything
{
private:
    int m_value;
public:
    Anything() { m_value = 0; }
    void add(int value) { m_value += value; }

    // Делаем функцию reset() дружественной классу Anything
    friend void reset(Anything &anything);
};

// reset() теперь является другом класса Anything
void reset(Anything &anything)
{
    // И мы имеем доступ к закрытым членам объектов класса Anything
    anything.m_value = 0;
}

int main()
{
    Anything one;
    one.add(4); // добавляем 4 к m_value
    reset(one); // сбрасываем m_value к 0

    return 0;
}
