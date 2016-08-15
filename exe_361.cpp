/*
	Exe_361: Liệt kê các dòng trong ma trận thực thõa mãn đồng thời các điều kiện sau: dòng chứa giá trị âm, giá trị dương, và giá trị 0
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
		int check1 = 0;
		int check2 = 0;
		int check3 = 0;
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] < 0)
			{
				check1 = 1;
			}
			else if(a[i][j] > 0)
			{
				check2 = 1;
			}
			else if(a[i][j] == 0)
			{
				check3 = 1;
			}
		}
		if(check1 == 1 && check2 == 1 && check3 == 1)
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