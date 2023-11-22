#include "sort.h"
/**
*swap - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int i;

	i = array[item1];
	array[item1] = array[item2];
	array[item2] = i;
}

/**
 *partition - partition sorting scheme
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */

int partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 *quicks - quicksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */

void quicks(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = partition(array, first, last, size);

		quicks(array, first, position - 1, size);
		quicks(array, position + 1, last, size);
	}
}

/**
 *quick_sort - sorts an array of integers in ascending order
 *@array: array
 *@size: array size
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicks(array, 0, size - 1, size);
}
