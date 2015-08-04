#include <iostream>

using namespace std;

int linearSearch(int array[], int size, int searchValue)
{	
	
	for(int i = 0; i < size; i++)
	{
		if (searchValue == array[i])
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int a[] = {15, 23, 24, 32, 7};

	// ideally user inputs a number
	int searchValue = 24;

	// can not do this in linearSearch function because of pointer issues
	// so you will have to do it here first
	// c / c++ doesn't stor array size or length in memory so you will have to compute it by total byte size divided by element byte size
	int size = (sizeof(a)/sizeof(searchValue)); 

	int result = linearSearch(a, size, searchValue); 

	if(result>-1)
	{
		cout << "The number " << searchValue << " was found in " << result << endl;
	}
	else
	{
		cout << "The number " << searchValue << " was not found. " << endl;
	}
}