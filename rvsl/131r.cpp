/*
Класс Values отслеживает минимальное и максимальное значения. Мы перегрузили оператор плюс
(+) 3 раза для выполнения операции сложения двух объектов класса Values и
операций сложения целочисленного значения и одного объекта Values.

Результат выполнения программы выше:

Result: (4, 17)

Мы получили минимальное и максимальное значения из всех, которые указали в vFinal.
Рассмотрим детальнее, как обрабатывается строчка Values vFinal = v1 + v2 + 6 + 9 + v3 + 17;:

  приоритет оператора + выше приоритета оператора =, и ассоциативность оператора + слева направо,
  поэтому сначала вычисляется v1 + v2. Это приводит к вызову operator+(v1, v2), которое возвращает Values(7, 14);

  затем следующей выполняется операция Values(7, 14) + 6. Это приводит к
  вызову operator+(Values(7, 14), 6), которое возвращает Values(6, 14);

  тогда выполняется Values(6, 14) + 9, которое возвращает Values(6, 14);

  затем Values(6, 14) + v3 возвращает Values(4, 14);

  и, наконец, Values(4, 14) + 17 возвращает Values(4, 17). Это и является нашим конечным результатом,
  который присваивается vFinal.

Другими словами, выражение выше обрабатывается как Values vFinal = (((((v1 + v2) + 6) + 9) + v3) + 17),
причем каждая последующая операция сложения возвращает объект Values, который становится левым операндом
для следующего оператора +.

Примечание: Мы определили operator+(int, Values) вызовом operator+(Values, int) (смотрите код).
Это может быть менее эффективным, чем полная отдельная реализация (за счет дополнительного вызова функции),
но, таким образом, наш код короче и проще в поддержке + мы уменьшили дублирование кода. Когда это возможно,
то определяйте перегруженный оператор вызовом другого перегруженного оператора (как в нашем примере выше)!
*/
class Values
{
private:
	int m_min; // минимальное значение, которое обнаружили до сих пор
	int m_max; // максимальное значение, которое обнаружили до сих пор

public:
	Values(int min, int max)
	{
		m_min = min;
		m_max = max;
	}

	int getMin() { return m_min; }
	int getMax() { return m_max; }

	friend Values operator+(const Values &v1, const Values &v2);
	friend Values operator+(const Values &v, int value);
	friend Values operator+(int value, const Values &v);
};

Values operator+(const Values &v1, const Values &v2)
{
	// Определяем минимальное значение между v1 и v2
	int min = v1.m_min < v2.m_min ? v1.m_min : v2.m_min;

	// Определяем максимальное значение между v1 и v2
	int max = v1.m_max > v2.m_max ? v1.m_max : v2.m_max;

	return Values(min, max);
}

Values operator+(const Values &v, int value)
{
	// Определяем минимальное значение между v и value
	int min = v.m_min < value ? v.m_min : value;

	// Определяем максимальное значение между v и value
	int max = v.m_max > value ? v.m_max : value;

	return Values(min, max);
}

Values operator+(int value, const Values &v)
{
	// вызываем operator+(Values, int)
	return v + value;
}

int main()
{
	Values v1(11, 14);
	Values v2(7, 10);
	Values v3(4, 13);

	Values vFinal = v1 + v2 + 6 + 9 + v3 + 17;

	std::cout << "Result: (" << vFinal.getMin() << ", " << vFinal.getMax() << ")\n";

	return 0;
}
