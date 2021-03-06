#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// number of times to run the test
#define TES 1000

// number of numbers in each array
#define NUM 1000

// inclusive [min, max] for number range
#define MIN -1000
#define MAX 1000

// random function
#define RAND(x,y) (rand() % (MAX + 1 - MIN) + MIN)

// how big our stack will be
#define STACK_SIZE 1000

// struct for a stack request
typedef struct partition_struct {
    int l;
    int r;
} Partition;

// stack
typedef struct stack_struct {
    Partition request[STACK_SIZE];
    int next;
} Stack;

// push
void push(Stack *stack, Partition request)
{
    if (!stack)
        return;

    stack->request[stack->next].l = request.l;
    stack->request[stack->next].r = request.r;

    stack->next++;
    return;
}

// pop
void pop(Stack *stack, int *l, int *r)
{
    if (stack->next == 0)
        return;

    *l = stack->request[stack->next - 1].l;
    *r = stack->request[stack->next - 1].r;

    stack->next--;
    return;
}

// is full
int is_full(Stack *stack)
{
    return stack->next == STACK_SIZE;
}

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

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    return;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];

    int i = l - 1;

    for (int j = l; j <= r - 1; j++)
        if (arr[j] < pivot)
            swap(&arr[j], &arr[++i]);

    swap(&arr[r], &arr[++i]);
    return i;
}

void quicksort(int arr[], int l, int r)
{
    Stack *stack = calloc(1, sizeof(Stack));
    
    Partition first_req = {l, r};
    push(stack, first_req);

    while (stack->next) {
        int lp = 0;
        int rp = 0;
        pop(stack, &lp, &rp);

        if (lp > rp)
            continue;

        int p = partition(arr, lp, rp);

        Partition r1 = {lp, p - 1};
        Partition r2 = {p + 1, rp};

        push(stack, r1);
        push(stack, r2);
    }

    free(stack);
    return;
}

int main(void) {
    // initiate tests
    for (int i = 0; i < TES; i++)
    {
        printf("Starting tests...\n\n");
        /* create random array */
        int arr[NUM];
        srand(time(NULL));
        make_array(arr);

        printf("START: ");
        print_array(arr);

        quicksort(arr, 0, NUM - 1);

        printf("  END: ");
        print_array(arr);
        printf("\n");

        if (!is_sorted(arr)) {
            fprintf(stderr, "Test failed...program will prematurely abort\n");
            exit(-1);
        }
    }

    printf("All tests passed\n");
    return 0;
}
