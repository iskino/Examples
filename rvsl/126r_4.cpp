/*
Дружественные методы.
Хотя это может показаться несколько сложным, но этот танец нужен только потому,
что мы пытаемся сделать всё в одном файле. Лучшим решением было бы поместить
каждое определение класса в отдельный заголовочный файл с определениями методов
в соответствующих файлах .cpp (детальнее об этом здесь).
Таким образом, все определения классов стали бы видны сразу во всех файлах .cpp,
и никакого танца с перемещениями не понадобилось бы!
*/
class Values; // предварительное объявление класса Values

class Display
{
private:
	bool m_displayIntFirst;

public:
	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

	void displayItem(Values &value); // предварительное объявление выше требуется для этой строчки
};

class Values // полное определение класса Values
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

	// Делаем метод Display::displayItem другом класса Values
	friend void Display::displayItem(Values& value);
};

// Теперь мы можем определить Display::displayItem, которому требуется увидеть полное определение класса Values
void Display::displayItem(Values &value)
{
	if (m_displayIntFirst)
		std::cout << value.m_intValue << " " << value.m_dValue << '\n';
	else // или выводим сначала double
		std::cout << value.m_dValue << " " << value.m_intValue << '\n';
}

int main()
{
    Values value(7, 8.4);
    Display display(false);

    display.displayItem(value);

    return 0;
}
