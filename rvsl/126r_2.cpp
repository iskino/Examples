/*
Дружественная функция сразу нескольким классам.
Здесь есть две вещи, на которые следует обратить внимание.
Во-первых, поскольку outWeather является другом для обоих классов,
то он имеет доступ к закрытым членам обоих классов.
Во-вторых, обратите внимание на первую строчку в этом примере.
Это прототип класса, который сообщает компилятору, что мы определим класс Humidity позже.
Без этой строчки компилятор выдал бы ошибку, что не знает, что такое Humidity
при анализе прототипа дружественной функции outWeather() внутри класса Temperature.
Прототипы классов выполняют ту же роль, что и прототипы функций — они сообщают компилятору
об объектах, которые позднее будут определены, но которые сейчас нужно использовать.
*/
class Humidity;

class Temperature
{
private:
    int m_temp;
public:
    Temperature(int temp=0) { m_temp = temp; }

    friend void outWeather(const Temperature &temperature, const Humidity &humidity);
};

class Humidity
{
private:
    int m_humidity;
public:
    Humidity(int humidity=0) { m_humidity = humidity; }

    friend void outWeather(const Temperature &temperature, const Humidity &humidity);
};

void outWeather(const Temperature &temperature, const Humidity &humidity)
{
    std::cout << "The temperature is " << temperature.m_temp <<
       " and the humidity is " << humidity.m_humidity << '\n';
}

int main()
{
    Temperature temp(15);
    Humidity hum(11);

    outWeather(temp, hum);

    return 0;
}
