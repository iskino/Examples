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
};

std::ostream& operator<< (std::ostream &out, const Point &point)
{
    // поскольку operator<< является другом класса Point, то мы имеем прямой доступ к членам Point
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

    return out;
}

int main()
{
    Point point1(3.0, 4.7, 5.0);
    Point point2(9.0, 10.5, 11.0);

    std::cout << point1 << " " << point2 << '\n';

    return 0;
}
// Результат: Point(3, 4.7, 5) Point(9, 10.5, 11)
