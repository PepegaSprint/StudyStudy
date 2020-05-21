#include<chrono>
#include<cstdlib>
#include <cstddef>
#include <iostream>

using namespace std;


class Stack
{
public:
	struct Elem
	{
		int* data;
		Elem* pre;
		Elem(int* Val)
		{
			data = Val;
		}
	};
	Stack()
	{
		NumOfElements = 0;
	}

	bool MyEmpty()
	{
		if (NumOfElements == 0)
			return true;
		return false;
	}
	void KPop()
	{
		Elem* a = Tail;
		Tail = Tail->pre;
		delete a;
		NumOfElements--;
	}
	void Push(int* val)
	{
		Elem* a = new Elem(val);
		if (NumOfElements == 0)
			Tail = a;
		else
		{
			a->pre = Tail;
			Tail = a;
		}
		NumOfElements++;
	}
	int* Back()
	{
		return Tail->data;
	}

private:
	int NumOfElements;
	Elem* Tail;
};


void quickSort(int* pFirst, int start, int end)
{
	int* tempStart = pFirst;
	int* tempMid = pFirst;
	int* tempEnd = pFirst;
	int x;
	int tempswap;
	for (int l = 0; l < start; l++)
		tempStart++;

	for (int l = 0; l < end; l++)
		tempEnd++;
	x = (end + start) / 2;

	for (int l = 0; l < x; l++)
		tempMid++;
	int a = *tempMid;
	do
	{
		while (*tempStart < a)
			tempStart++;
		while (a < *tempEnd)
			tempEnd--;
		if (tempStart <= tempEnd)
		{
			tempswap = *tempStart;
			*tempStart = *tempEnd;
			*tempEnd = tempswap;

			tempStart++;
			tempEnd--;
		}
	} while (tempStart <= tempEnd);

	if (tempEnd - pFirst > start)
		quickSort(pFirst, start, tempEnd - pFirst);

	if (tempStart - pFirst < end)
		quickSort(pFirst, tempStart - pFirst, end);
}

int search(int* pb, int* pe, int Value)
{
	while (pb != pe)
	{
		if (*pb == Value)
		{
			return(*pb);
		}
		pb++;
	}
	return(-1);
}

void quickSortNotRecursive(int* pFirst, int start, int end)
{
	int tempswap;
	int* Start = pFirst;
	int* End = pFirst;
	int x;
	for (int l = 0; l < start; l++)
		Start++;
	for (int l = 0; l < end; l++)
		End++;
	Stack stack = Stack();

	stack.Push(Start);
	stack.Push(End);
	while (!stack.MyEmpty())
	{
		int* tempEnd = stack.Back();
		stack.KPop();
		int* tempStart = stack.Back();
		stack.KPop();
		int* pStart = tempStart;
		int* pEnd = tempEnd;
		int* tempMid = tempStart;
		x = (tempEnd - tempStart) / 2;
		for (int l = 0; l < x; l++)
			tempMid++;
		int a = *tempMid;
		do
		{
			while (*tempStart < a)
				tempStart++;
			while (a < *tempEnd)
				tempEnd--;
			if (tempStart <= tempEnd)
			{
				tempswap = *tempStart;
				*tempStart = *tempEnd;
				*tempEnd = tempswap;

				tempStart++;
				tempEnd--;
			}
		} while (tempStart <= tempEnd);

		if (tempStart < pEnd)
		{
			stack.Push(tempStart);
			stack.Push(pEnd);
		}
		if (tempEnd > pStart)
		{
			stack.Push(pStart);
			stack.Push(tempEnd);
		}
	}
}



int BSearch(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (true)
	{
		mid = (left + right) / 2;
		if (key < arr[mid])
			right = mid - 1;
		else if (key > arr[mid])
			left = mid + 1;
		else
			return mid;
		if (left > right)
			return -1;
	}
}

int BSearchRecursive(int arr[], int left, int right, int key)
{
	if (right >= left)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == key)
			return mid;
		else if (key < arr[mid])
			return BSearchRecursive(arr, left, mid - 1, key);
		else
			return BSearchRecursive(arr, mid + 1, right, key);
	}
	return -1;
}

int main()
{
	int i;
	const int n = 100;
	const int N = 100;
	int Array[n];
	int arr[N];
	int arr1[N];
	int* pb = &Array[0];
	int* pe = &Array[n - 1];
	int* pb2 = &arr[0];
	int* pb3 = &arr1[0];

	for (i = 0; i < n; i++)
		Array[i] = (rand() % (201) - 100);

	cout << endl;

	for (i = 0; i < n; i++)
		cout << Array[i] << " ";
	cout << endl;

	auto t1 = chrono::steady_clock::now();
	cout << endl << search(pb, pe, 250) << endl;
	auto t2 = chrono::steady_clock::now();
	auto dt = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
	cout << endl << "time1  " << dt.count() << " ns" << endl;

	for (i = 0; i < N; i++)
		arr[i] = (rand() % (201) - 100);
	for (i = 0; i < N / 2; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << endl << "Quick sorted Array" << endl;
	auto t5 = chrono::steady_clock::now();
	quickSort(pb2, 0, N - 1);
	cout << endl << endl << BSearch(arr, 0, 99, -96);
	auto t6 = chrono::steady_clock::now();
	auto dt3 = chrono::duration_cast<chrono::nanoseconds>(t6 - t5);
	cout << endl << "time2  " << dt3.count() << " ns" << endl;
	for (i = 0; i < N / 2; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << endl << endl;

	for (i = 0; i < N; i++)
		arr1[i] = (rand() % (201) - 100);
	for (i = 0; i < N / 2; i++)
		cout << arr1[i] << " ";
	cout << endl;

	cout << endl << "Quick sorted Array without recursive" << endl;
	quickSortNotRecursive(pb3, 0, N - 1);
	cout << endl << endl << BSearchRecursive(arr1, 0, 99, -100) << endl << endl;
	for (i = 0; i < N / 2; i++)
		cout << arr1[i] << " ";
	cout << endl;
	return(0);
}