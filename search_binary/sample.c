#include <iostream>
#include <algorithm> // for sorting

using namespace std;
/*
	make array
	sort if from lowest to greatest
	

 */
int binarySearch(int array[], int size, int searchValue)
{	
	int low = 0;
	int high = size - 1;
	int mid;

	while(low <= high)
	{	
		mid = (low+high)/2; // automatically truncates fraction/decimal because mid is an INTEGER

		if(searchValue == array[mid])
		{
			return mid;
		}
		else if(searchValue > array[mid])
		{
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}


	return -1;
}

int main()
{
	int a[] = {15, 23, 24, -32, 7, 89, 64};

	// ideally user inputs a number
	int searchValue = 24;

	int size = (sizeof(a)/sizeof(a[0])); //get size of a array by dividing its size by element's size

	sort(a, a + size); // sorts a[] to [-32, 7, 15, 23, 24, 64, 89]

	int result = binarySearch(a, size, searchValue); 

	if(result > -1)
	{
		cout << "The number " << searchValue << " was found in " << result << endl;
	}
	else
	{
		cout << "The number " << searchValue << " was not found. " << endl;
	}
}