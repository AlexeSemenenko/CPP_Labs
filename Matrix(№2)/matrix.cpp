#include "Header.h"

matrix& matrix::operator=(matrix const& m)
{
	if (this == &m)
		return *this;

	for (auto i = 0; i < row; i++)
		delete[] matr[i];
	delete[] matr;

	row = m.row;
	column = m.column;
	matr = new double*[row];
	for (auto i = 0; i < row; i++)
		matr[i] = new double[column];

	for (auto i = 0; i < row; i++)
		for (auto j = 0; j < column; j++)
			matr[i][j] = m.matr[i][j];

	return *this;

}

matrix& matrix::operator+=(matrix const& m)
{
	if (row != m.row || column != m.column)
		throw std::exception("Error! Incorrect size of matrixes. To add the dimensions must be the same");

	for (auto i = 0; i < row; i++)
		for (auto j = 0; j < column; j++)
			matr[i][j] += m.matr[i][j];

	return *this;
}

matrix matrix::operator+(matrix const& m)
{
	matrix a(*this);

	a += m;

	return a;
}

matrix& matrix::operator-=(matrix const& m)
{
	if (row != m.row || column != m.column)
		throw std::exception("Error! Incorrect size of matrixes. To sub the dimensions must be the same");

	for (auto i = 0; i < row; i++)
		for (auto j = 0; j < column; j++)
			matr[i][j] -= m.matr[i][j];

	return *this;
}

matrix matrix::operator-(matrix const& m)
{
	matrix a(*this);

	a -= m;

	return a;
}

matrix& matrix::operator*=(matrix const& m)
{
	matrix a(row, m.column);

	if (column != m.row)
		throw std::exception("Error! Incorrect size of matrixes. To mult number of columns in the 1st matrix should be the same as number of rows in the 2nd matrix");

	for (auto i = 0; i < row; i++)
		for (auto j = 0; j < m.column; j++)
			for (auto k = 0; k < column; k++)
				a.matr[i][j] += matr[i][k] * m.matr[k][j];

	*this = a;

	return *this;
}

matrix matrix::operator*(matrix const& m)
{
	matrix a(*this);

	a *= m;

	return a;
}

matrix& matrix::operator*=(const double x)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matr[i][j] *= x;

	return *this;
}

matrix matrix::operator*(const double x)
{
	matrix a(*this);

	a *= x;
	return a;
}

matrix matrix::operator-()
{
	matrix a(*this);

	a *= (-1);
	return a;
}

std::istream& operator>>(std::istream& in, matrix& m)
{
	for (auto i = 0; i < m.row; i++)
		for (auto j = 0; j < m.column; j++)
		{
			std::cout << "Element in " << i + 1 << " row and " << j + 1 << " column ";
			in >> m.matr[i][j];
		}

	return in;
}

std::ostream& operator<<(std::ostream& out, const matrix& m)
{
	std::cout << "Your matrix is: " << std::endl;
	for (auto i = 0; i < m.row; i++)
	{
		for (auto j = 0; j < m.column; j++)
		{
			out << std::setw(5) << m.matr[i][j];
		}
		out << std::endl;
	}

	return out;
}