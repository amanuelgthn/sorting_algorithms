#include"sort.h"
/**
 *selection_sort-function that sorts array in ascending order
 *@array:array to be sorted
 *@size:size of the array to be sorted
 **/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, index;
	int tmp;

	for (; i < size; i++)
	{
		tmp = array[i];
		index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < tmp)
			{
				tmp = array[j];
				index = j;
			}
		}
		if (index != i)
		{
			array[index] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
