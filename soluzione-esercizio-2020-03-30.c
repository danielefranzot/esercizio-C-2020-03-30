/*
 * soluzione-esercizio-2020-03-30.c
 *
 *
 *      Author: Daniele Franzot

 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

unsigned long* fibonacci_array(unsigned int n);
unsigned long fibonacci(unsigned int n);
unsigned long * copy_array(unsigned long src_array [], unsigned int array_dimension);
unsigned long * complete_reverse_long(unsigned long src_array [], unsigned int array_len);
void bubble_sort(unsigned long * array,unsigned int array_dimension);

int main(int argc, char **argv) {

	printf("%lu \n\n", fibonacci(39));

	unsigned long *array_fib;

	array_fib = fibonacci_array(39);

	unsigned long *array_fib_copy;

	array_fib_copy = copy_array(array_fib,40);

	array_fib_copy = complete_reverse_long(array_fib_copy,40);

	bubble_sort(array_fib_copy,40);

	if(memcmp(array_fib,array_fib_copy,40))
		printf("non sono uguali, %d",memcmp(array_fib,array_fib_copy,40));
	else
		printf("i due array sono uguali , %d",memcmp(array_fib,array_fib_copy,40));
	return 0;
}

unsigned long fibonacci(unsigned int n) {
	if (n == 1)
		return 1;
	else if (n == 0)
		return 0;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned long* fibonacci_array(unsigned int n) {
	unsigned long *result_array;

	result_array = calloc(n + 1, sizeof(unsigned long));
	if (result_array == NULL) {
		perror("calloc error!");
		exit(EXIT_FAILURE);
	}

	for (unsigned int i = 0; i < n + 1; i++) {
		result_array[i] = fibonacci(i);
	}

	return result_array;
}

unsigned long * copy_array(unsigned long src_array [] /* long * src_array */, unsigned int array_dimension) {

	if (src_array == NULL)
		return NULL;

	unsigned long * result;
	result = malloc(array_dimension * sizeof(long));

	if (result == NULL) {
		return NULL;
	}

	memcpy(result, src_array, array_dimension * sizeof(long));

	return result;
}

void swap_long(unsigned long *x, unsigned long *y) {
	unsigned long t = *x;
	*x = *y;
	*y = t;
}

unsigned long * reverse_long(unsigned long src_array[], unsigned int i, unsigned int j)
{
	while (i < j)
		swap_long(&src_array[i++], &src_array[--j]);

	return src_array;
}

unsigned long * complete_reverse_long(unsigned long src_array[], unsigned int array_len) {
	return reverse_long(src_array, 0, array_len);
}

void bubble_sort(unsigned long * array,unsigned int array_dimension) {

	int n = array_dimension;
	int newn;
	do {
		newn = 0;
		for (int i = 1; i < n; i++) {
			if (array[i-1] > array[i]) {
				swap_long(&array[i-1], &array[i]);
				newn = i;
			}

		}

		n = newn;

	} while (n > 1);
}
