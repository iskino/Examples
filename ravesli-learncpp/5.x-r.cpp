#include <iostream>
#include <cstdlib> // для функций srand() и rand()
#include <ctime> // для функции time()

// Генерируем случайное число между min и max
// Предполагается, что srand() уже вызывали
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // равномерно распределяем выбор случайного числа из диапазона
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

// возвращаем true, если пользователь выиграл, false - если проиграл
bool playGame(int guesses, int number)
{
    // Цикл работы с догадками пользователя
    for (int count = 1; count <= guesses; ++count)
    {
        std::cout << "Guess #" << count << ": ";
        int guess;
        std::cin >> guess;

        if (guess > number)
            std::cout << "Your guess is too high.\n";
        else if (guess < number)
            std::cout << "Your guess is too low.\n";
        else // догадка == число
            return true;
    }

    return false;
}

bool playAgain()
{
    // Продолжаем спрашивать пользователя, хочет ли они поиграть еще раз до тех пор, пока он не нажмет 'y' или 'n'
    char ch;
    do
    {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> ch;
    } while (ch != 'y' && ch != 'n');

    return (ch == 'y');
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // в качестве стартового числа используем системные часы
    rand(); // сбрасываем первый результат, так как функция rand() не особо хорошо рандомизирует первое случайное число в Visual Studio

    const int guesses = 7; // у пользователя есть 7 попыток

    do
    {
        int number = getRandomNumber(1, 100); // число, которое пользователь должен угадать

        std::cout << "Let's play a game.  I'm thinking of a number.  You have " << guesses << " tries to guess what it is.\n";

        bool won = playGame(guesses, number);
        if (won)
            std::cout << "Correct!  You win!\n";
        else
            std::cout << "Sorry, you lose.  The correct number was " << number << "\n";

    }
    while (playAgain());

    std::cout << "Thank you for playing.\n";
    return 0;
}
