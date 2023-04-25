#include"sort.h"
/**
 * sort_quick - function that sorts an array of integers in ascending order
 *              using the Quick sort algorithm.
 * @array: The array to be sorted
 * @low: The starting index of the array or subarray to be sorted
 * @high: The ending index of the array or subarray to be sorted
 */
void sort_quick(int *array, int low, int high)
{
	int print_index = high;
	if (low < high)
	{
		int pivot = array[high];
		int i = low - 1, tmp, j;
		for (j = low; j <= high - 1; j++)
		{
			if (array[j] <= pivot)
			{
				i++;
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, print_index);
		sort_quick(array, low, i);
		sort_quick(array, i + 2, high);
	}
}
/**
 * quick_sort - function that sorts an array of integers in ascending order
 *             using the Quick sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort_quick(array, 0, size - 1);
}
