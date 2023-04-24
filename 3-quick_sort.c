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
    if (low < high)
    {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (array[j] <= pivot)
            {
                i++;
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                print_array(array, high + 1);
            }
        }

        int tmp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = tmp;
        print_array(array, high + 1);

        int pi = i + 1;

        sort_quick(array, low, pi - 1);
        sort_quick(array, pi + 1, high);
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
