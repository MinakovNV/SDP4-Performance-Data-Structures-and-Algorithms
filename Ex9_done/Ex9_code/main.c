/*
* exercise37.c
*
*  Created on: Jan 17, 2012
*      Author: nancy
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#define DEBUG		0

#define DATA_FILE	"data.txt"	// Name of a data file containing the data to search (short ints)
#define INPUT_SIZE	7			// big enough for a short int with an optional sign

#define ASCENDING	1				// sort in ascending order
#define DESCENDING	2			// sort in descending order

/*********
* bubble_sort - sorts an array into ascending order using the (inefficient)
* 				 bubble sort algorithm.  The array is sorted in place (the
* 				 caller's array is changed).
*
* input:
* 		array - an array of short integer numbers to sort
* 		array_size - the number of items in array
*
* output:
* 		array is modified (sorted)
*
* return value: none
**********/


void bubble_sort( int data[], const int size, int direction) {
    int tmp;		// temporary value storage
    int i, j;
    bool swap;

#if DEBUG > 0
    printf("Debug: entering bubble_sort, sort direction %s, size %d\n", direction == ASCENDING ? "ascending" : "descending", size);
#endif
#if DEBUG > 1
    printf("Debug: sorting...");
	for (i = 0; i<size; i++) {
		printf("  %d", data[i]);
	}
	printf("\n");
#endif

    // Starting from the beginning of the array, go through every item in the array...
    for (i = 0; i<size; i++) {

        // the item at i is the current item, now search the entire array, starting
        // at the beginning, looking for the first value that is greater than or less
        // than (depending on direction) the current item.  Once found, swap them.
        for (j = 0; j<size; j++) {
#if DEBUG > 2
            printf("Debug: comparing %d and %d\n", data[j], data[i]);
#endif
            if (direction == ASCENDING) {
                if (data[j] < data[i])
                    swap = true;
                else
                    swap = false;
            }
            else {		// direction is DESCENDING
                if (data[j] > data[i])
                    swap = true;
                else
                    swap = false;
            }
            if (swap) {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }

#if DEBUG > 1
    printf("Debug: sorted...");
	for (i = 0; i<size; i++) {
		printf("  %d", data[i]);
	}
	printf("\n");
#endif
#if DEBUG > 0
    printf("Debug: leaving bubble_sort\n");
#endif

    return;
}

/*********
* binary_search - Uses a binary search algorithm to search for an item in
* 				   an array.  The array is assumed to be sorted in
* 				   ascending order.
*
* input:
* 		search_value - the value to search for
* 		array - an array of int
* 		array_size - the number of items in array
*
* output: none
*
* return value: true if the item was found, else false
**********/
bool binary_search(const int search_value, const  int *array[], const int array_size) {
    int low = 0;
    int high = array_size - 1;
    int mid;

   // array[0] = -32768;


#if DEBUG > 0
    printf("Debug: entering binary_search, looking for %d\n", search_value);
#endif

    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] < search_value) {
            low = mid + 1;
        }
        else if (array[mid] > search_value) {
            high = mid - 1;
        }
        else {
#if DEBUG > 0

            printf("Debug: leaving binary_search (found)\n");
#endif
            return true;
        }
    }

#if DEBUG > 0
    printf("Debug: leaving binary_search (not found)\n");
#endif

    return false;
}

/*********
* main - Read data from a file, sort that data into ascending order and use a binary
*		  search to find two values in the data, where one value is in the data and
*		  one value is not.  Correct output indicates that one data value was found.
*		  In addition, the largest number in the data file is displayed.
*
* input:  none
* output: none
*
* return value: 1 if there was an error, else 0
**********/


int main(void) {

    FILE *file;
    char input[INPUT_SIZE];
    const int num_items = 25;

#if DEBUG > 0
    printf("\nDebug: Reading data from %s\n", DATA_FILE);
#endif

    // open data file for reading
    file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file %s for reading\n", DATA_FILE);
        return 1;
    }

    // get the first line in the file
    if (fgets(input, INPUT_SIZE, file) == NULL) {
        fprintf(stderr, "Unable to read from %s\n", DATA_FILE);
        return 1;
    }

#if DEBUG > 1
    printf("Debug: read first line of input: %s", input);
#endif

    // the first line is an integer representing the number of lines of data to sort
    if (sscanf(input, "%d", &num_items) != 1) {
        fprintf(stderr, "Invalid count of data items in first line of %s\n", DATA_FILE);
        fclose(file);
        return 1;
    }

#if DEBUG > 1
    printf("Debug: num_items %d\n", num_items);
#endif

    int data[25];

    // (scanf returns the number of items it parses.  If the values and types are not
    // what it is expecting ("%hd" indicates exactly one short integer) it will return
    // the number of values it was able to parse, which will not match the number of
    // values specified in the format string ("%hd").  In this case, if the format
    // of the input is what we are expecting, scanf will return 1.
    //
    // while we are not at the end of the file and we have valid data on an input line...
    int i = 0;
    while (fgets(input, INPUT_SIZE, file) != NULL && sscanf(input, "%d", &data[i]) == 1) {
#if DEBUG > 1
        printf("Debug: parsed %d from %s", data[i], input);
#endif
        i++;
    }

    // make sure our data matches up with what we expect
    if (num_items != i) {
        fprintf(stderr, "Number of data lines in %s (%d) is less than specified in first line in %s (%d)\n", DATA_FILE, i, DATA_FILE, num_items);
        fclose(file);
        return 1;
    }

    // done with the input file
    fclose(file);

#if DEBUG > 0
    printf("Debug: Done reading data from %s; %d records read\n", DATA_FILE, num_items);
#endif

    int found = 0;
    bubble_sort(data, 25, ASCENDING);

    if (!binary_search(data[num_items - 1], data, num_items))
        found++;
    if (!binary_search(data[num_items - 10], data, num_items))
        found++;

    printf("Found %d item(s) in array\n", found);
    printf("Highest item value %d\n", data[0]);
  //  for (int j=0; j<25; j++){
    //    printf("%d ", data[j]);
    //}
  //  system("pause");

    return 0;
}
