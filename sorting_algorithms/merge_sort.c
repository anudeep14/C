/*
merge sort : divide the input into smallest chunks possible, and merge back by sorting the smaller chunks
time complexity : O()
space complexity : O()
*/
#include <stdio.h>

void ascendingMerge(int arr[], int left, int mid, int right)
{
   int l1, l2, i;
   int b[right+1];

   for(l1 = left, l2 = mid + 1, i = left; l1 <= mid && l2 <= right; ++i) {
      if(arr[l1] <= arr[l2])
         b[i] = arr[l1++];
      else
         b[i] = arr[l2++];
   }

   while(l1 <= mid)
      b[i++] = arr[l1++];

   while(l2 <= right)
      b[i++] = arr[l2++];

   for(i = left; i <= right; i++)
      arr[i] = b[i];
}

void descendingMerge(int arr[], int left, int mid, int right)
{
   int l1, l2, i;
   int b[right+1];

   for(l1 = left, l2 = mid + 1, i = left; l1 <= mid && l2 <= right; ++i) {
      if(arr[l1] >= arr[l2])
         b[i] = arr[l1++];
      else
         b[i] = arr[l2++];
   }

   while(l1 <= mid)
      b[i++] = arr[l1++];

   while(l2 <= right)
      b[i++] = arr[l2++];

   for(i = left; i <= right; i++)
      arr[i] = b[i];
}

void ascendingMergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        ascendingMergeSort(arr, left, mid);
        ascendingMergeSort(arr, mid+1, right);
        ascendingMerge(arr, left, mid, right);
    }
}

void descendingMergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        descendingMergeSort(arr, left, mid);
        descendingMergeSort(arr, mid+1, right);
        descendingMerge(arr, left, mid, right);
    }
}
 void printArray(int arr[], int size)
{
    for(int i = 0 ; i < size ; ++i)
        printf("%d\t",arr[i]);
    printf("\n");
}

int main()
{
    int arr[10] = {1,3,2,5,8,6,9,7,4,10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, arrSize);

    ascendingMergeSort(arr, 0, arrSize - 1);
    printArray(arr, arrSize);

    descendingMergeSort(arr, 0, arrSize - 1);
    printArray(arr, arrSize);

    return 0;
}