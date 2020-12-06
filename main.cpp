#include <iostream>
#include "Matrix.h"
using namespace std;

float tran(string s);

int main()
{
	int mode;
	int judge = 0;
	int row;
	int column;
	int row1;
	int column1;
	float num;
	cout << "Select your mode:\n  1. C = A * B\n  2. C = A * b\n  3. C = a * B\n  4. Exit." << endl;
	cin >> mode;
	if (mode == 1)
	{
		cout << "Input contents of matrix A and B: " << endl;
		cout << "rows of A: ";
		cin >> row;
		cout << "columns of A: ";
		cin >> column;
		cout << "elements of matrix A: " << endl;
		//下面创建字符串矩阵
		string** stop = new string * [row];
		for (int i = 0; i < row; i++)
		{
			stop[i] = new string[column];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cin >> stop[i][j];
				for (int k = 0; k < stop[i][j].length(); k++)
				{
					if ((stop[i][j][k] < '0' || stop[i][j][k] > '9') && stop[i][j][k] != '.' && stop[i][j][k] != ' ' && stop[i][j][k] != '-')
					{
						//judge = 1;
					}
				}
			}
		}
		//下面创建data
		float** da = new float* [row + 1];
		for (int i = 0; i < row + 1; i++)
		{
			da[i] = new float[column];
		}
		if (judge == 0)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					da[i][j] = tran(stop[i][j]);
				}
			}
		}
		cout << "rows of B: ";
		cin >> row1;
		cout << "columns of B: ";
		cin >> column1;
		cout << "elements of matrix B: " << endl;
		//下面创建字符串矩阵
		stop = new string * [row1];
		for (int i = 0; i < row1; i++)
		{
			stop[i] = new string[column1];
		}
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < column1; j++)
			{
				cin >> stop[i][j];
				for (int k = 0; k < stop[i][j].length(); k++)
				{
					if ((stop[i][j][k] < '0' || stop[i][j][k] > '9') && stop[i][j][k] != '.' && stop[i][j][k] != ' ' && stop[i][j][k] != '-')
					{
						//judge = 1;
					}
				}
			}
		}
		//下面创建data
		float** da1 = new float* [row1 + 1];
		for (int i = 0; i < row1 + 1; i++)
		{
			da1[i] = new float[column1];
		}
		if (judge == 0)
		{
			for (int i = 0; i < row1; i++)
			{
				for (int j = 0; j < column1; j++)
				{
					da1[i][j] = tran(stop[i][j]);
				}
			}
		}
		Matrix A(row, column, da);
		Matrix B(row1, column1, da1);
		Matrix C;
		C = A * B;
		cout << "\n" << "[" << C;
		cout << "]";
	}
	else if (mode == 2)
	{
		cout << "Input contents of matrix A: " << endl;
		cout << "rows of A: ";
		cin >> row;
		cout << "columns of A: ";
		cin >> column;
		cout << "elements of matrix A: " << endl;
		//下面创建字符串矩阵
		string** stop = new string * [row];
		for (int i = 0; i < row; i++)
		{
			stop[i] = new string[column];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cin >> stop[i][j];
				for (int k = 0; k < stop[i][j].length(); k++)
				{
					if ((stop[i][j][k] < '0' || stop[i][j][k] > '9') && stop[i][j][k] != '.' && stop[i][j][k] != ' ' && stop[i][j][k] != '-')
					{
						//judge = 1;
					}
				}
			}
		}
		//下面创建data
		float** da = new float* [row + 1];
		for (int i = 0; i < row + 1; i++)
		{
			da[i] = new float[column];
		}
		if (judge == 0)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					da[i][j] = tran(stop[i][j]);
				}
			}
		}
		cout << "Input the number to be multiplied:" << endl;
		cin >> num;
		Matrix A(row, column, da);
		Matrix C;
		C = A * num;
		cout << "\n" << "[" << C;
		cout << "]";
	}
	else if (mode == 3)
	{
		cout << "Input the number to be multiplied:" << endl;
		cin >> num;
		cout << "Input contents of matrix B: " << endl;
		cout << "rows of B: ";
		cin >> row;
		cout << "columns of B: ";
		cin >> column;
		cout << "elements of matrix B: " << endl;
		//下面创建字符串矩阵
		string** stop = new string * [row];
		for (int i = 0; i < row; i++)
		{
			stop[i] = new string[column];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cin >> stop[i][j];
				for (int k = 0; k < stop[i][j].length(); k++)
				{
					if ((stop[i][j][k] < '0' || stop[i][j][k] > '9') && stop[i][j][k] != '.' && stop[i][j][k] != ' ' && stop[i][j][k] != '-')
					{
						//judge = 1;
					}
				}
			}
		}
		//下面创建data
		float** da = new float* [row + 1];
		for (int i = 0; i < row + 1; i++)
		{
			da[i] = new float[column];
		}
		if (judge == 0)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					da[i][j] = tran(stop[i][j]);
				}
			}
		}

		Matrix B(row, column, da);
		Matrix C;
		C = num * B;
		cout << "\n" << "[" << C;
		cout << "]";
	}
	else if (mode == 4)
	{
		exit(0);
	}
	else
	{
		cout << "Wrong input.";
	}

}


float tran(string s)//输入字符串转换成数字
{
	int integ = 0;
	float dec = 0;
	float res = 0;
	int round = 1;
	int poi = 0, neg = 0;
	for (char c : s)
	{
		if (c == '-')
		{
			neg = 1;
			continue;
		}
		if (c == '.')
		{
			poi = 1;
			continue;
		}
		if (poi == 0)
		{
			integ *= 10;
			integ += (c - '0');
		}
		else
		{
			dec += (c - '0') * pow(0.1, round);
			round++;
		}
	}
	if (neg == 0)
	{
		res = integ + dec;
	}
	else
	{
		res = -1 * (integ + dec);
	}
	return res;
}