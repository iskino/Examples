#include<iostream>
#include<conio.h>

using namespace std;

const int N = 2;
const int M = 3;
const int K = 3;
const int L = 2;

int main()
{	
/*	int N;
	
	cout << "N = ";
	cin >> N;
	
	cout << "Videlenie pamyati iz kuchi!";
	
	_getch();
	
	int *p = new int[N];
	
	for (int i(0);i < N;i++){
		*(p+i) = N - i; 
	
		cout << "p[" << i << "] = " << *(p+i) << endl;
	}
	
	cout << "Ochishenie pamyati!";
	
	_getch();
	
	delete []p;
	
	_getch();
	
	cout << "Vse!";
*/
	
//	cout << p << ' ' << &p << endl;

	cout << "\t\t***Massivi***\n";

// Выделение памяти из кучи под динамические двумерные массивы
	
	int **mtx1 = new int *[N];
	int **mtx2 = new int *[K];
	int **res = new int *[N];
	
	for (int i(0); i < N; i++)
		mtx1[i] = new int[M];
	
	for (int i(0); i < K; i++)
		mtx2[i] = new int[L];
	
	for (int i(0); i < N; i++)
		res[i] = new int[L];
	
// Инициализация матриц
	
	cout << "Vvedi matrix 1:\n";
	
	for (int i(0); i < N; i++){
		for (int j(0); j < M; j++){
			cin >> mtx1[i][j];
		}
	}

	cout << "Vvedi matrix 2:\n";
	
	for (int i(0); i < K; i++){
		for (int j(0); j < L; j++){
			cin >> mtx2[i][j];
		}
	}
	
	for (int i(0); i < N; i++){
		for (int j(0); j < L; j++){
			*(*(res + i) + j) = 0;
		}
	}

/*	int b[N][M] = {{1,2,4},{2,0,3}};
	int d[K][L] = {{2,5},{1,3},{1,1}};
	int r[N][L] = {{0,0},{0,0}};
*/	
	cout << "  (M dolzno ravno K, r budet iz N i L)\n\n";

// Перемножение матриц
	
	for (int i(0); i < N; i++){
		for (int j(0); j < L; j++){
			for (int p(0); p < M; p++)
				*(*(res + i) + j) += *(*(mtx1 + i) + p) * *(*(mtx2 + p) + j);
		}
	}	

// Вывод реультата: должно быть 8 15 7 13 для массивов b, d
	
	for (int i(0); i < N; i++){
		for (int j(0); j < L; j++)
			cout << *(*(res + i) + j) << ' ';
		cout << endl;
	}

// Удаление динамич. массивов из памяти

	for (int i(0); i < N; i++)
		delete [] mtx1[i];
	
	delete [] mtx1;
	
	for (int i(0); i < K; i++)
		delete [] mtx2[i];
	
	delete [] mtx2;
	
	for (int i(0); i < N; i++)
		delete [] res[i];
		
	delete [] res;
	
/*	for (int i(0);i < N;i++){
		for (int j(0);j < M;j++)
		cout << &b[i][j] << ": " << b[i][j] << endl;
	}
*/	
	
	return 0;
}