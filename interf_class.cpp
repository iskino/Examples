/*
Реализация интерфейсных классов и примеры полиморфизма
*/

#include <iostream>

struct Eye {
    virtual void open() = 0;
    virtual void look() = 0;
    virtual void close() { return eye_close(); }

private:
    virtual void eye_close() = 0;
};

struct Mouth {
    virtual void open(int) = 0; // не есть хорошо
    virtual void eat() = 0;
    virtual void say() = 0;
    virtual void close() { return mouth_close(); }

private:
    virtual void mouth_close() = 0;
};

class Cyclope : public Eye, Mouth {
    //Eye
    void open() { std::cout << "eye open" << std::endl; }
    void look() { std::cout << "eye look" << std::endl; }
    void eye_close() { std::cout << "eye close" << std::endl; }

    //Mouth
    void open(int) { std::cout << "mouth open" << std::endl; }
    void eat() { std::cout << "mouth eat" << std::endl; }
    void say() { std::cout << "mouth say" << std::endl; }
    void mouth_close() { std::cout << "mouth close" << std::endl; }
};

void look_for_banana(Eye *eye) {
    eye->open();
    eye->look();
    eye->close();
}

void eat_banana(Mouth *mouth) {
    mouth->open(0);
    mouth->eat();
    mouth->say();
    mouth->close();
}

int main() {
    Cyclope *cyclope = new Cyclope;

    look_for_banana(cyclope);
    eat_banana(cyclope);

    delete cyclope;

    return 0;
}
