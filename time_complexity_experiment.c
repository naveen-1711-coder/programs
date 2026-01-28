//program to understand time complexity

// 1. O(n^2)

#include <stdio.h>
#include <time.h>

int main()
{
    int number_count, current_element, next_element;
    int is_found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &number_count);

    int numbers[number_count];

    for (current_element = 0; current_element < number_count; current_element++)
    {
        scanf("%d", &numbers[current_element]);
    }

    clock_t start_time, end_time;
    double time_taken;

    start_time = clock();

    for (current_element = 0; current_element < number_count; current_element++)
    {
        for (next_element = current_element + 1; next_element < number_count; next_element++)
        {
            if (numbers[current_element] == numbers[next_element])
            {
                is_found = 1;
                break;
            }
        }
        if (is_found) break;
    }

    end_time = clock();

    time_taken = (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC;

    if (is_found)
    {
        printf("Duplicate found\n");
    }
    else
    {
        printf("No duplicates\n");
    }

    printf("Execution time %f seconds\n", time_taken);
    
    return 0;
}