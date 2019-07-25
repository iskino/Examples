#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int a,b,lcm;
	
	cout << "Enter a and b(v.2):";
	cin  >> a >> b;
	
	lcm = a * b; //НОК - формула: lcm = (a * b) / gsd(a,b);
	
	while (a != 0 && b != 0){
		if (a > b) a = a - b;
		else b = b - a;
	}
	
	cout << "gsd is " << (a + b) << endl;
	cout << "lcm is " << lcm / (a + b);
	
	return 0;
}