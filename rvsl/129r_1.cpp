/*
Рассмотрим реальный пример, где нужно отсортировать массив из 10 000 элементов.
Воспользуемся алгоритмом сортировки методом выбора.
*/
#include <iostream>
#include <array>
#include <chrono> // для функций из std::chrono

const int g_arrayElements = 10000;  // общее количество всех элементов массива

class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void sortArray(std::array<int, g_arrayElements> &array)
{

	// Перебираем каждый элемент массива
	// (кроме последнего, он уже будет отсортирован к тому времени, когда мы до него доберемся)
	for (int startIndex = 0; startIndex < g_arrayElements - 1; ++startIndex)
	{
		// В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации
		// Начнём с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)

		int smallestIndex = startIndex;

		// Затем ищем элемент меньше нашего smallestIndex в оставшейся части массива
		for (int currentIndex = startIndex + 1; currentIndex < g_arrayElements; ++currentIndex)
		{
			// Если нашли элемент, который меньше нашего наименьшего элемента
			if (array[currentIndex] < array[smallestIndex])
				// то записываем/запоминаем его
				smallestIndex = currentIndex;
		}

		// smallestIndex теперь наименьший элемент в оставшейся части массива
		// Меняем местами наше стартовое наименьшее значение с тем, которое мы обнаружили
		std::swap(array[startIndex], array[smallestIndex]);
	}
}

int main()
{
	std::array<int, g_arrayElements> array;
	for (int i = 0; i < g_arrayElements; ++i)
		array[i] = g_arrayElements - i;

	Timer t;

	sortArray(array);

	std::cout << "Time taken: " << t.elapsed() << '\n';

	return 0;
}
