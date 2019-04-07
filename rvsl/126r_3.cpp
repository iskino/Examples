/*
Дружественные классы.
Поскольку класс Display является другом класса Values,
то любой из членов Display имеет доступ к private членам Values.
Результат выполнения программы выше:
8.4 7
Несколько дополнительных примечаний о дружественных классах:

  Во-первых, даже несмотря на то, что Display является другом Values,
  Display не имеет прямой доступ к указателю this * объектов Values.

  Во-вторых, даже если Display является другом Values, это не означает,
  что Values также является другом Display. Если вы хотите сделать оба класса дружественными,
  то каждый из них должен указать в качестве друга противоположный класс.
  Наконец, если класс A является другом B, а B является другом C, то это не означает, что A является другом C.
*/
class Values
{
private:
    int m_intValue;
    double m_dValue;
public:
    Values(int intValue, double dValue)
    {
        m_intValue = intValue;
        m_dValue = dValue;
    }

    // Делаем класс Display другом класса Values
    friend class Display;
};

class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItem(Values &value)
    {
        if (m_displayIntFirst)
            std::cout << value.m_intValue << " " << value.m_dValue << '\n';
        else // или сначала выводим double
            std::cout << value.m_dValue << " " << value.m_intValue << '\n';
    }
};

int main()
{
    Values value(7, 8.4);
    Display display(false);

    display.displayItem(value);

    return 0;
}
