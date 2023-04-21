#include"sort.h"
/**
*bubble_sort-function that sorts an array of integers in Bubble sort(ascending)
*@array:array to be sorted
*@size:size of an array
**/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int tmp;

	for (; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (j + 1 < size && array[j] > array[j+1])
			{
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
				print_array(array, size);
				
			}
		}
	}
}		
