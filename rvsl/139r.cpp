#include <iostream>
#include <cassert> // для assert()

class Matrix
{
private:
    double data[5][5];
public:
    Matrix()
    {
        // Устанавливаем всем элементам массива значение 0.0
        for (int row=0; row < 5; ++row)
            for (int col=0; col < 5; ++col)
                data[row][col] = 0.0;
    }

    double& operator()(int row, int col);
    const double& operator()(int row, int col) const;
    void operator()();
};

double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);

    return data[row][col];
}

const double& Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);

    return data[row][col];
}

void Matrix::operator()()
{
    // Сбрасываем значения всех элементов массива на 0.0
    for (int row=0; row < 5; ++row)
        for (int col=0; col < 5; ++col)
            data[row][col] = 0.0;
}

int main()
{
    Matrix matrix;
    matrix(2, 3) = 3.6;
    matrix(); // выполняем сброс
    std::cout << matrix(2, 3);

    return 0;
} // Результат: 0
