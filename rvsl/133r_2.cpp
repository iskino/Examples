#include <iostream>

class Point
{
private:
    double m_x, m_y, m_z;

public:
    Point(double x=0.0, double y=0.0, double z=0.0): m_x(x), m_y(y), m_z(z)
    {
    }

    friend std::ostream& operator<< (std::ostream &out, const Point &point);
    friend std::istream& operator>> (std::istream &in, Point &point);
};

std::ostream& operator<< (std::ostream &out, const Point &point)
{
    // поскольку operator<< является другом класса Point, то мы имеем прямой доступ к членам Point
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

    return out;
}

std::istream& operator>> (std::istream &in, Point &point)
{
    // поскольку operator>> является другом класса Point, то мы имеем прямой доступ к членам Point
    // обратите внимание, параметр point (объект класса Point) должен быть не константным, чтобы мы имели возможность изменить члены класса
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;

    return in;
}

int main()
{
    std::cout << "Enter a point: \n";

    Point point;
    std::cin >> point;

    std::cout << "You entered: " << point << '\n';

    return 0;
}

// Предположим, что пользователь введет 4.0, 5.5 и 8.37, тогда результат программы:
// You entered: Point(4, 5.5, 8.37)
