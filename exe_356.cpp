/*
	Exe_356: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn trong ma trận nguyên
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void Input(int a[][100], int m, int n)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
}

void Output(int a[][100], int m, int n)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << setw(4) << a[i][j] ;
		}
		cout << endl;
	}
}

void Result(int a[][100], int m, int n)
{			
	for(int i = 0; i < m; i++)
	{
		int check = 1;
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] % 2 != 0)
			{
				check = 0;
				break;
			}
		}
		if(check == 1)
		{
			cout << "Row " << i << " : ";
			for(int j = 0 ; j < n; j++)
			{
				cout << setw(5) << a[i][j];
			}
			cout << endl;
		}
	}
}

int main()
{
	int a[100][100];
	int n, m;
	cout << "Input rows: ";
	cin >> m;
	cout << "Input columns: ";
	cin >> n;

	Input(a, m, n);
	Output(a, m, n);
	Result(a, m, n);
	
	return 0;
}