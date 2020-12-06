#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix()
{

	//cout << 200;
}
Matrix::Matrix(int rowA, int columnA, float** dataA)
{
	this->row = rowA;
	this->column = columnA;
	data = dataA;
	data[row][0]++;
	//cout << 300;
}
Matrix::Matrix(int rowA, int columnA)
{
	this->row = rowA;
	this->column = columnA;
	data = new float* [rowA + 1];
	for (int i = 0; i < rowA + 1; i++)
	{
		data[i] = new float[columnA];
	}
	data[row][0] = 1;
	//cout << 300;
}
Matrix::~Matrix()
{
	if (data[row][0] == 1)
	{
		for (int i = 0; i < row+1; i++)
		{
			delete[] data[i];
		}
		delete data;
	}
	else
		data[row][0]--;
}
void Matrix::operator=(const Matrix& A)
{
	row = A.row;
	column = A.column;
	data = A.data;
	data[row][0]++;
	//cout << 100;
}
void operator<<(std::ostream& os, const Matrix& a)
{
	for (int i = 0; i < a.row; i++)
	{
		for (int j = 0; j < a.column; j++)
		{
			if ((j == a.column - 1) && (i != a.row-1))
			{
				cout << a.data[i][j] << " " << endl;
			}
			else if((j == a.column - 1) && (i == a.row - 1))
			{
				cout << a.data[i][j];
			}
			else
			{
				cout << a.data[i][j] << " ";
			}
		}
	}

}
Matrix Matrix::operator*(const Matrix& mat)
{
	
	if (mat.row == column)
	{
		//mat.judge = 0; 
		Matrix matC(row, mat.column);
		for (int m = 0; m < row; m++)
		{
			for (int s = 0; s < mat.column; s++)
			{
				matC.data[m][s] = 0;//变量使用前记得初始化,否则结果具有不确定性  
				for (int n = 0; n < column; n++)
				{
					matC.data[m][s] += data[m][n] * mat.data[n][s];
				}
			}
		}
		matC.data[row][0]++;
		return matC;
	}
	else
	{
		cout << "Wrong input!" << endl;
	}
	
}

Matrix Matrix::operator*(const float num)
{
	Matrix matC(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matC.data[i][j] = data[i][j];
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matC.data[i][j] *= num;
		}
	}
	matC.data[row][0]++;
	return matC;
}
Matrix operator* (float num, const Matrix& mat)
{
	Matrix matC(mat.row, mat.column);
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.column; j++)
		{
			matC.data[i][j] = mat.data[i][j];
		}
	}
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.column; j++)
		{
			matC.data[i][j] *= num;
		}
	}
	matC.data[mat.row][0]++;
	return matC;
}


