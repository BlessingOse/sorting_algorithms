#include "sort.h"
#include <stdio.h>
/**
 * output_bitonic - prints the array modified by
 * bitonic algorithm
 *
 * @arr: input array
 * @i: first index
 * @limit: last index
 * Return: no return
 */
void output_bitonic(int *arr, int i, int limit)
{
	char *sep;

	for (sep = ""; i < limit; i++)
	{
		printf("%s%d", sep, arr[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * order_up - sorts the array in UP mode
 *
 * @arr: input array
 * @low: first index
 * @high: last index
 * Return: no return
 */
void order_up(int *arr, int low, int high)
{
	int i, j, max;

	for (i = low; i < high; i++)
	{
		max = i;

		for (j = i + 1; j < high; j++)
		{
			if (arr[max] > arr[j])
				max = j;
		}

		if (max != i)
		{
			arr[i] = arr[i] + arr[max];
			arr[max] = arr[i] - arr[max];
			arr[i] = arr[i] - arr[max];
		}
	}
}

/**
 * order_down - sorts the array in DOWN mode
 *
 * @arr: input array
 * @low: first index
 * @high: last index
 * Return: no return
 */
void order_down(int *arr, int low, int high)
{
	int i, j, max;

	for (i = low; i < high; i++)
	{
		max = i;

		for (j = i + 1; j < high; j++)
		{
			if (arr[max] < arr[j])
				max = j;
		}

		if (max != i)
		{
			arr[i] = arr[i] + arr[max];
			arr[max] = arr[i] - arr[max];
			arr[i] = arr[i] - arr[max];
		}
	}
}

/**
 * repeat - recursive function that executes the bitonic sort
 * algorithm
 *
 * @arr: input array
 * @low: first index
 * @high: last index
 * @bool: UP or DOWN
 * @size: size of the array
 * Return: no return
 */
void repeat(int *arr, int low, int high, int bool, size_t size)
{
	char *option;

	if (high - low < 2)
		return;

	option = (bool == 0) ? "UP" : "DOWN";
	printf("Merging [%d/%ld] (%s):\n", high - low, size, option);
	output_bitonic(arr, low, high);

	if (high - low == 2)
		return;

	repeat(arr, low, (high + low) / 2, 0, size);
	order_up(arr, low, (high + low) / 2);
	printf("Result [%d/%ld] (%s):\n", ((high + low) / 2) - low, size, "UP");
	output_bitonic(arr, low, (high + low) / 2);

	repeat(arr, (high + low) / 2, high, 1, size);
	order_down(arr, (high + low) / 2, high);
	printf("Result [%d/%ld] (%s):\n", high - ((high + low) / 2), size, "DOWN");
	output_bitonic(arr, (high + low) / 2, high);
}

/**
 * bitonic_sort - first function that executes the bitonic_sort
 * algorithm
 *
 * @array: input array
 * @size: size of the array
 * Return: no return
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	repeat(array, 0, size, 0, size);
	order_up(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	output_bitonic(array, 0, size);
}
