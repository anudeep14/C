/*
bubble sort : repeatedly sort adjacent elements if they are in wrong order
time complexity : O(n^2)
space complexity : O(1)
not recommended for large data sets as huge time complexity
 */

 #include <stdio.h>

 void ascendingBubbleSort(int arr[], int size)
 {
    for(int i = 0 ; i < size-1 ; ++i)
    {
        for(int j = 0 ; j < size - i - 1 ; ++j)
        {
            //to sort in ascending order
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
 }

 void descendingBubbleSort(int arr[], int size)
 {
    for(int i = 0 ; i < size-1 ; ++i)
    {
        for(int j = 0 ; j < size - i - 1 ; ++j)
        {
            //to sort in descending order
            if(arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
 }

 int main()
 {
    int arr[10] = {1,3,2,5,8,6,9,7,4,10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    ascendingBubbleSort(arr, arrSize);

    descendingBubbleSort(arr,arrSize);

    return 0;
 }