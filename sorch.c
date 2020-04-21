#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// number of times to run the test
#define TES 10

// number of numbers in each array
#define NUM 10

// inclusive [min, max] for number range
#define MIN 0
#define MAX 10

// random function
#define RAND(x,y) (rand() % (MAX + 1 - MIN) + MIN)

// creates our array
void make_array(int arr[])
{
    for (int i = 0; i < NUM; i++)
        arr[i] = RAND(MIN, MAX);
    return;
}

// prints the array
void print_array(int arr[])
{
    for (int i = 0; i < NUM; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return;
}

// checks if the array is sorted. 1 if sorted, 0 otherwise
int is_sorted(int arr[])
{
    for (int i = 0; i < NUM - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;
    return 1;
}

int main(void)
{
    // randomize
    srand(time(NULL));

    // initiate tests
    printf("Starting Tests...\n\n");
    for (int i = 0; i < TES; i++)
    {
        /* create random array */
        int arr[NUM];
        make_array(arr);

        printf("START: ");
        print_array(arr);

        // sort the array here

        printf("  END: ");
        print_array(arr);
        printf("\n");

        if (!is_sorted(arr)) {
            fprintf(stderr, "Test failed...program will prematurely abort\n");
            exit(-1);
        }
    }

    printf("Smoke test passed. Please verify results manually.\n");
    return 0;
}
