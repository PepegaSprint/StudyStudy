#include "Matrix3x3.h"
#include<cstdlib>

int Matrix3x3::element(const int i, const int j) const
{
	return Matrix[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value)
{
	Matrix[i][j] = value;
}

Matrix3x3::Matrix3x3()
{
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			setElement(i,j,0);
		}
	}
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j< 3; j++)
		{
			setElement(i, j, (rand()%(maxVal-minVal+1)+minVal));
		}
	}
}

int Matrix3x3::sumPrincipalDiag() const
{
	int buf = 0;
	for (int i = 0; i<3; i++)
	{
		buf = buf + element(i, i);
	}
	return buf;
}

int Matrix3x3::sumSecondaryDiag() const
{
	int buf = 0;
	for (int i = 0; i<3; i++)
	{
		buf = buf + element(i, 2-i);
	}
	return buf;
}

int Matrix3x3::productPrincipalDiag() const
{
	int buf = 1;
	for (int i = 0; i<3; i++)
	{
		buf = buf * element(i, i);
	}
	return buf;
}

int Matrix3x3::productSecondaryDiag() const
{
	int buf = 1;
	for (int i = 0; i<3; i++)
	{
		buf = buf * element(i, 2 - i);
	}
	return buf;
}

int Matrix3x3::sumRow(const int iRow) const
{
	int buf = 0;
	for (int i = 0; i<3; i++)
	{
		buf = buf + element(iRow, i);
	}
	return buf;
}

int Matrix3x3::minColumn(const int iCol) const
{
	int min = INT_MAX;
	for (int i = 0;i<3; i++)
	{
		if (min > element(i, iCol))  min = element(i, iCol);
	}
	return min;
}

int Matrix3x3::maxColumn(const int iCol) const
{
	int max = INT_MIN;
	for (int i = 0; i<3; i++)
	{
		if (max < element(i, iCol))  max = element(i, iCol);
	}
	return max;
}

