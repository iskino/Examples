#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int a,b;
	
	cout << "Enter a and b(v.2):";
	cin  >> a >> b;
	
	while (a != 0 && b != 0){
		if (a > b) a = a - b;
		else b = b - a;
		
		cout << "a = " << a << endl; 
		cout << "b = " << b << endl;
			
		_getch();
	}
	
	cout << "gsd is " << (a + b);
	
	return 0;
}