#pragma once
class MatrixXnX
{
public:
	MatrixXnX(const int dim);
	int size = 0;

	void setElement(const int i, const int j, const int value);
	int element(const int i, const int j) const;
	void fillRandomElements(const int minVal, const int maxVal);
	int sumPrincipalDiag() const;
	int sumSecondaryDiag() const;
	int productPrincipalDiag() const;
	int productSecondaryDiag() const;
	int sumRow(const int iRow) const;
	int minColumn(const int iCol) const;
	int maxColumn(const int iCol) const;
	void garbageCleaner();
private:
	int Matrix[3][3];
};