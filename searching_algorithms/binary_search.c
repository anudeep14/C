/*
binary search
mandatory for the input array to be already sorted before search.
*/

#include <stdio.h>

int iterativeBinarySearch(int arr[], int low, int high, int target)
{
    while(low <= high){
        int mid = low + (high - low) / 2;

        if (target == arr[mid])
            return mid;

        if(target <= arr[mid])
            high = mid -1; // target available before mid element, move high to the left
        else
            low = mid + 1; // target available after mid element, move low to right
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int low, int high, int target)
{
    if(low <= high){
        int mid = low + (high - low) / 2;

        if (target == arr[mid])
            return mid;

        if(target <= arr[mid])
            return recursiveBinarySearch(arr, low, mid - 1, target);
        else
            return recursiveBinarySearch(arr, mid + 1, high, target);
    }
    return -1;
}

int main()
{
    int arr[10] = {11,22,33,44,55,66,77,88,99,110};

    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int target = 55;

    int position = iterativeBinarySearch(arr, 0, arrSize - 1, target);

    printf("Target %d is at position %d\n", target, position);

    target = 33;

    int position1 = recursiveBinarySearch(arr, 0, arrSize -1, target);

    printf("Target %d is at position %d\n", target, position1);

    return 0;
}