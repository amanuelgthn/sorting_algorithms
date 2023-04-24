#include"sort.h"
/**
*quick_sort-function that sorts an array of integers in ascending order by qucik sort
*@array:array to be sorted
*@size:size of the array to be sorted
**/
void sort_quick(int *arr, int low, int high)
{
	int pivot = arr[high];
	int j = low, tmp, i;

	if (low >= high)
	{
		print_array(arr,high);
		return;
	}
	for (i = low; i < high; i++)
	{
		if (arr[i] <= pivot)
		{
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
	tmp = arr[high];
	arr[high] = arr[j];
	arr[j] = tmp;
	sort_quick(arr,low,j-1);
	sort_quick(arr,low,j-1);
}	   
void quick_sort(int *array, size_t size)
{
	sort_quick(array, 0, size);
}
