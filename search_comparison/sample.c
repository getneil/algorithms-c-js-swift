#include <iostream>
#include <algorithm> // for sorting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int linearSearch(int array[], int size, int searchValue)
{	
	int cost = 0;
	for(int i = 0; i < size; i++)
	{
		cost++;
		if (searchValue == array[i])
		{
			break;
		}
	}

	return cost;
}

int binarySearch(int array[], int size, int searchValue)
{	
	int low = 0;
	int high = size - 1;
	int mid;
	int cost = 0;

	while(low <= high)
	{	
		mid = (low+high)/2; // automatically truncates fraction/decimal because mid is an INTEGER
		
		cost += 3; // 1 iteration + 1 add + 1 divide

		if(searchValue == array[mid])
		{
			break;
		}
		else if(searchValue > array[mid])
		{
			low = mid + 1;
			cost++;
		}
		else
		{
			high = mid - 1;
			cost++;
		}
	}
	return cost;
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// A utility function to print an array
void printArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// A function to generate a random permutation of arr[]
void randomize ( int arr[], int n )
{
    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand ( time(NULL) );
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
}

void populateArray(int array[], int size, bool sorted)
{	
	for(int i=1; i<= size; i++){
		array[i-1] = i;
	}

	if(sorted == false){
		randomize(array, size);
	}

}

int main()
{
	int sizeOfArray = 100;
	int a[sizeOfArray]; //make sure to declare sizeOfArray before the array
	int b[sizeOfArray];

	// ideally user inputs a number
	
	int linearCost = 0;
	int binaryCost = 0;
	
	populateArray(a,sizeOfArray,true);

	int size = (sizeof(a)/sizeof(a[0])); //get size of a array by dividing its size by element's size

	sort(a, a + size); // sorts a[] to [-32, 7, 15, 23, 24, 64, 89]

	// SET A TEST
	int totalCost = 0;
	linearCost = 0;
	for(int i = 0; i<sizeOfArray; i++){
		int searchValue = i+1;
		totalCost += linearSearch(a, size, searchValue );
	}
	linearCost = totalCost / sizeOfArray;
	cout << "SET A: linear search " << linearCost << endl;

	totalCost = 0;
	binaryCost = 0;
	for(int i = 0; i<sizeOfArray; i++){
		int searchValue = i+1;
		totalCost += binarySearch(a, size, searchValue );
	}
	binaryCost = totalCost / sizeOfArray;
	cout << "SET A: binary search " << binaryCost << endl;

	return 0;
}

/*
notes / results

it would be unfair for linear search to be compared only to search for value in the extreme limits to emphasize that binary is faster

a balanced test would be

set A:
both will be given multiple sorted array from (0 to 100),(0 to 1000) and (0 to 100,000)
then all numbers will be tested in that range 
and results will be averaged

set B:
both will be given multiple unsorted array with sizes varrying from 100, 1000 and 100,000
but it will also consider the cost for binary sorting the unsorted array


RESULTS BY COST:
				linear 		binary
set A @ 100		50			22
set A @ 1k    	500    		34
set A @ 100k    7,050		61

				linear 		binary + sorting
set B @ 100		50 			22 + sorting cost
set B @ 1k 		500			34 + sorting cost
set B @ 100k	7,050		61 + sorting cost
* yes linear will just be the same even if you shuffle the array
 
RESULTS BY TIME: ( should remove the cost increment)

 */