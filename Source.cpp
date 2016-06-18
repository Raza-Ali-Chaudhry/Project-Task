#include <iostream>
#include <conio.h>
#include "matrix.h"
using namespace std;
int main()
{
	int i = 0;
	Matrix<int> m(3, 3);
	for (int i = 0; i < 3;i++)
		for (int j = 0; j < 3;j++)
			m.set(i, j, 0);
	m += 3;
	cout << m;
	_getch();
}
