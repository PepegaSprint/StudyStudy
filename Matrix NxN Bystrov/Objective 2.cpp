#include "MatrixXnX.h"
#include <iostream>
#include<cstdlib>
using namespace std;


int main()
{
	MatrixXnX matrix = MatrixXnX(4);


	matrix.fillRandomElements(-10, 10);
	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
		{
			cout << matrix.element(i, j) << "\t";
		}
		cout << endl;
	}
	cout << endl << "Main diagonal sum equals\t\t" << matrix.sumPrincipalDiag();
	cout << endl << "Secondary diagonal sum equals\t\t" << matrix.sumSecondaryDiag();
	cout << endl << "Main diagonal multiply equals\t\t" << matrix.productPrincipalDiag();
	cout << endl << "Secondary diagonal multiply equals\t" << matrix.productSecondaryDiag();
	cout << endl << "Row 1 sum equals\t\t\t" << matrix.sumRow(0);
	cout << endl << "Column 1 minimum value is\t\t" << matrix.minColumn(0);
	cout << endl << "Column 2 maximum value is\t\t" << matrix.maxColumn(1) << endl;

	matrix.garbageCleaner();
	system("pause");
	return 0;
}