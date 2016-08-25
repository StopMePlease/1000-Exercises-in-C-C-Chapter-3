/*
	Exe_419: Sắp xếp các giá trị chẵn tăng dần, lẻ giảm trong ma trận nguyên
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

void HoanVi(int &a, int &b)
{
	int temp = a; 
	a = b;
	b = temp;
}

void Result(int a[][100], int m, int n)
{	
	int temp[100] = {0};
	int k = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			temp[k] = a[i][j];
			k++;
		}
	}

	for(int i = 0; i < k; i++)
	{
		if(temp[i] % 2 == 0)
		{
			for(int j = i + 1; j < k; j++)
			{
				if(temp[j] % 2 == 0)
				{
					if(temp[i] > temp[j])
					{
						HoanVi(temp[i], temp[j]);
					}
				}
			}
		}
		else if(temp[i] % 2 != 0)
		{
			for(int j = i + 1; j < k; j++)
			{
				if(temp[j] % 2 != 0)
				{
					if(temp[i] < temp[j])
					{
						HoanVi(temp[i], temp[j]);
					}
				}
			}
		}
	}

	for(int i = 0; i < k; i++)
	{
		cout << setw(5) << temp[i];
		if(n % (i + 1) == 0)
		{
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