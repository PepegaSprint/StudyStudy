#include "MatrixXnX.h"

#include<cstdlib>

int MatrixXnX::element(const int i, const int j) const
{
	return Matrix[i][j];
}

void MatrixXnX::setElement(const int i, const int j, const int value)
{
	Matrix[i][j] = value;
}

MatrixXnX::MatrixXnX(int dim)
{
	int** ptrarray = new int* [dim];
	for (int count = 0; count < dim; count++)
		ptrarray[count] = new int[dim];
	size = dim;
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			setElement(i, j, (rand() % (maxVal - minVal + 1) + minVal));
		}
	}
}

int MatrixXnX::sumPrincipalDiag() const
{
	int buf = 0;
	for (int i = 0; i < size; i++)
	{
		buf = buf + element(i, i);
	}
	return buf;
}

int MatrixXnX::sumSecondaryDiag() const
{
	int buf = 0;
	for (int i = 0; i < size; i++)
	{
		buf = buf + element(i, size -1 - i);
	}
	return buf;
}

int MatrixXnX::productPrincipalDiag() const
{
	int buf = 1;
	for (int i = 0; i < size; i++)
	{
		buf = buf * element(i, i);
	}
	return buf;
}

int MatrixXnX::productSecondaryDiag() const
{
	int buf = 1;
	for (int i = 0; i < size; i++)
	{
		buf = buf * element(i, size - 1 - i);
	}
	return buf;
}

int MatrixXnX::sumRow(const int iRow) const
{
	int buf = 0;
	for (int i = 0; i < size; i++)
	{
		buf = buf + element(iRow, i);
	}
	return buf;
}

int MatrixXnX::minColumn(const int iCol) const
{
	int min = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		if (min > element(i, iCol))  min = element(i, iCol);
	}
	return min;
}

int MatrixXnX::maxColumn(const int iCol) const
{
	int max = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		if (max < element(i, iCol))  max = element(i, iCol);
	}
	return max;
}
void MatrixXnX::garbageCleaner()
{
	for (int count = 0; count < size; count++)
		delete[]Matrix[count];
}