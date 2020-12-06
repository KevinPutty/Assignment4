#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix
{
private:
	int row;
	int column;
	float** data;




public:
	Matrix();
	Matrix(int rowA, int columnA, float** dataA);
	Matrix(int rowA, int columnA);
	void operator=(const Matrix& A);
	~Matrix();
	friend void operator<<(std::ostream& os, const Matrix& a);
	Matrix operator*(const Matrix& mat);
	Matrix operator*(const float num);
	friend Matrix operator*(float num, const Matrix& mat);
};

#endif
