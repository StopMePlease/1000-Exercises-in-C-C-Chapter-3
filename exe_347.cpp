/*
	Exe_347: Đếm số lượng giá trị "Yên Ngựa" trong ma trận thực. 1 phần tử gọi là Yên Ngựa khi nó lớn nhất trên dòng và hỏ nhất trên trên cột
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

bool MaxRow(int a[][100], int dong, int n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if(a[dong][i] > x)
		{
			return false;
		}
	}
	return true;
}

bool MaxCol(int a[][100], int m, int cot, int x)
{
	for(int i = 0; i < m; i++)
	{
		if(a[i][cot] < x)
		{
			return false;
		}
	}
	return true;
}

int Result(int a[][100], int m, int n)
{				
	int dem = 0;
	for(int i = 0; i < m; i++)
	{					
		for(int j = 0; j < n; j++)
		{				
			if(MaxRow(a, i, n, a[i][j]) && MaxCol(a, m, j, a[i][j]))
			{
				dem++;
			}
		}	
	}	
	return dem;
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
	int kq = Result(a, m, n);
	cout << kq;
	
	return 0;
}