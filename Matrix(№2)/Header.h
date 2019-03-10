#pragma once

#include <iostream>
#include <iomanip>

class matrix
{
	double **matr;
	int column;
	int row;
public:
	matrix(int row, int col)
	{
		column = col;
		this->row = row;

		matr = new double*[row];
		for (int i = 0; i < row; i++)
		{
			matr[i] = new double[column];
		}

		for (int i = 0; i < row; i++)
			for (int j = 0; j < row; j++)
				matr[i][j] = 0;
	}

	virtual ~matrix()
	{
		for (auto i = 0; i < row; i++)
			delete[] matr[i];
		delete[] matr;
	}

	matrix(matrix const& m)
	{
		column = m.column;
		row = m.row;

		matr = new double*[row];
		for (auto i = 0; i < row; i++)
		{
			matr[i] = new double[column];
		}

		for (auto i = 0; i < row; i++)
			for (auto j = 0; j < column; j++)
				matr[i][j] = m.matr[i][j];
	}

	matrix(matrix&& m) noexcept
	{
		column = m.column;
		row = m.row;
		matr = m.matr;
		m.column = 0;
		m.row = 0;
		m.matr = nullptr;
	}

	matrix& operator=(matrix const& m);
	matrix& operator+=(matrix const& m);
	matrix operator+(matrix const& m);
	matrix& operator-=(matrix const& m);
	matrix operator-(matrix const& m);
	matrix& operator*=(matrix const& m);
	matrix operator*(matrix const& m);
	matrix& operator*=(double x);
	matrix operator*(double x);
	matrix operator-();

	friend std::istream& operator>>(std::istream& in, matrix& m);
	friend std::ostream& operator<<(std::ostream& out, const matrix& m);
};
