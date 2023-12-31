#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		unsigned int x = i;
		int y = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < y)
				y = array[j], x = j;
		}
		if (x != i)
		{
			array[x] = array[i];
			array[i] = y;
			print_array(array, size);
		}
	}
}
