// Перевод из нижнего регистра в верхний и наоборот

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    char symbol;
    cout << "symbol: ";
    cin  >> symbol;
    
    if (static_cast<int>(symbol) < 97) {
        cout << static_cast<char>(symbol + 32);
    }
    else {
        cout << static_cast<char>(symbol - 32);
    }
    return 0;
}
