/*
Как работает статический и динамический полиморфизм
*/

#include <cmath>

class Regular_Polygon {
    const int n;
public:
    Regular_Polygon(int n_) : n(n_) {}
    ~Regular_Polygon() {}

    virtual int area(int a) {
        /// @TODO 1 / 4 * n * n ^ 2 * cot(pi / n);
        return 0;
    }

    int perimeter (int a) {
        return n * a;
    }
};

class Square : public Regular_Polygon {
public:
    Square() : Regular_Polygon(4) {}
    ~Square();

    int area(int a) {
        return a * a;
    }

    int perimeter(int a) {
        return a + a + a + a;
    }
};

class Triangle : public Regular_Polygon {
public:
    Triangle() : Regular_Polygon(3) {}
    ~Triangle();

    int area(int a) {
        return a * a * std::sqrt(3) / 4; // round
    }

    int perimeter(int a) {
        return a + a + a;
    }
};

int main() {
    Regular_Polygon *s = new Square;

    s->area(10);
    s->perimetr(10);

    delete s;

    Triangle *t = new Triangle;

    t->area(10);
    t->perimetr(10);

    delete t;

    return 0;
}
