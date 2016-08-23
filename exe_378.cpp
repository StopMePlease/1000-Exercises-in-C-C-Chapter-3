/*
	Exe_378: Tìm chữ số xuất hiện nhiều nhất trong ma trận nguyên
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
	int temp[10] = {0};

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			//====
			int temp_a = a[i][j];
			while(temp_a)
			{
				temp[temp_a % 10] += 1;
				temp_a /= 10;
			}
			//====
		}
	}

	int max = temp[0];

	for(int i = 0; i < 10; i++)
	{
		if(temp[i] > max)
		{
			max = temp[i];
		}
	}

	for(int i = 0; i < 10; i++)
	{
		if(temp[i] == max)
		{
			cout << setw(5) << i;
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