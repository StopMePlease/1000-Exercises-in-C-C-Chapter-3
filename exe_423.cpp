/*
Exe_423: Hãy sắp xếp các giá trị phần tử trong mảng tăng dần theo hình xoắn trôn ốc
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
		for(int j = i + 1; j < k; j++)
		{
			if(temp[i] > temp[j])
			{
				HoanVi(temp[i], temp[j]);
			}
		}
	}

	int temp2 = k;
	k = 0;
	int j = 0;

	while (true)
	{
		if(temp2 == k)
		{
			break;
		}

		for(int i = j; i < n; i++) //j = 0
		{
			a[j][i] = temp[k];
			k++;
		}
		for(int i = j + 1; i < m - 1; i++)
		{
			a[i][n - 1] = temp[k];
			k++;
		}
		for(int i = n - 1; i >= j; i--)
		{
			a[m - 1][i] = temp[k];
			k++;
		}
		for(int i = m - 2; i >= j + 1; i--)
		{
			a[i][j] = temp[k];
			k++;
		}

		m--;
		n--;
		j++;
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
	Output(a, m, n);
	return 0;
}