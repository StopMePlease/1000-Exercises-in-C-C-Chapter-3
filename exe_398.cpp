/*
	Exe_398: Dịch phải xoay vòng theo chiều kim đồng hồ các giá trị nằm trên biên trong ma trận
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
	int temp = a[0][0];

	int i = 0, j = 0;
	int check = 0;

	while (true)
	{		
		if(j == 0 && i < m)
		{
			a[i][j] = a[i + 1][j];
			i++;
			check++;
		}
		else if(i == m && j < n)
		{
			a[i - 1][j] = a[i - 1][j + 1];
			j++;
			check++;
		}
		else if(i > 0 && j == n)
		{
			if(i == m)
			{
				i -= 1;
			}

			a[i][j - 1] = a[i - 1][j - 1];
			i--;
			check++;
		}
		else if(i == 0 && j > 0)
		{
			if(i == -1)
			{
				i = 0;
			}

			a[i][j - 1] = a[i][j - 2];
			j--;
			check++;
		}
		//=====
		if(check == (2 * (m + n) - 3))
		{
			break;
		}
	}

	a[0][1] = temp;
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
	cout << endl;
	Output(a, m, n);

	return 0;
}