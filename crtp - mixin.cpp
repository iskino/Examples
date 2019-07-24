/*
паттерн - CRTP
в данном примере прием данного паттерна, который еще называют mixin:

в STL enable_shared_from_this

Исходный код:

struct Author {
    string russian;
    string english;

    Author(const string& rus_, const string& eng_) : russian(rus_), english(eng_) {}

    string formatted() {
        return russian + " (" + english + " )";
    }
};

struct Movie {
    string russian;
    string english;

    Movie(const string& rus_, const string& eng_) : russian(rus_), english(eng_) {}

    string formatted() {
        return russian + " (" + english + " )";
    }
};

*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

template<typename T>
struct Format {
    string formatted() {
        return static_cast<T *>(this)->russian + " (" + static_cast<T *>(this)->english + " )";
    }
};

struct Author : Format<Author> {
    string russian;
    string english;

    Author(const string& rus_, const string& eng_) : russian(rus_), english(eng_) {}


};

struct Movie : Format<Movie> {
    string russian;
    string english;

    Movie(const string& rus_, const string& eng_) : russian(rus_), english(eng_) {}
};

int main()
{
    Author author("St.Spielberg", "St.Spielberg");
    Movie movie("St.Spielberg", "Avatar");

    cout << author.formatted() << endl;
    cout << movie.formatted();

    return 0;
}
