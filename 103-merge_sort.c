#include "sort.h"
#include <stdio.h>
/**
 * output_data - print data
 * @msg: message
 * @a: array
 * @from: from
 * @to: to
 * Return: no return
 */
void output_data(char *msg, int *a, int from, int to)
{
	char *sep;
	int i;

	printf("[%s]: ", msg);
	sep = "";

	for (i = from; i <= to; i++)
	{
		printf("%s%d", sep, a[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * jux - Auxiliar function for
 * Merge sort algorithm
 * @a: array
 * @low: low index
 * @middle: middle
 * @high: high index
 * @buff: buffer
 * Return: no return
 */
void jux(int *a, int low, int middle, int high, int *buff)
{
	int lo, lm, i;

	lo = i = low;
	lm = middle + 1;

	printf("Merging...\n");
	output_data("left", a, low, middle);
	output_data("right", a, middle + 1, high);

	while (lo <= middle && lm <= high)
	{
		if (a[lo] < a[lm])
			buff[i++] = a[lo++];
		else
			buff[i++] = a[lm++];
	}

	while (lo <= middle)
		buff[i++] = a[lo++];

	while (lm <= high)
		buff[i++] = a[lm++];

	for (i = low; i <= high; i++)
		a[i] = buff[i];

	output_data("Done", a, low, high);
}
/**
 * mergesort -Auxiliar function for
 * Merge sort algorithm
 * @array: array
 * @low: low index
 * @high: high index
 * @buffer: buffer
 * Return: no return
 */
void mergesort(int *array, int low, int high, int *buffer)
{
	int midle;

	if (low < high)
	{
		midle = (low + high - 1) / 2;
		mergesort(array, low, midle, buffer);
		mergesort(array, midle + 1, high, buffer);
		jux(array, low, midle, high, buffer);
	}
}
/**
 * merge_sort -Sorts an arrayof integers
 * in ascending order using the
 * Merge sort algorithm
 * @array: array
 * @size: size
 * Return: no return
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	mergesort(array, 0, size - 1, buffer);
	free(buffer);
}
