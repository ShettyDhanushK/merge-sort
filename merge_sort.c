#include <stdio.h>                              //Header File

void printArray(int arr[], int N)               //Prints the Array
{
    for(int i = 0; i < N; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r)      //l-> left-most element of the array, m -> mid element of the array and r -> right-most element
{
    int i, j, k;                                //counters. i-> left array, j -> right array, k -> original array
    int n1 = m - l + 1;                         // Index of the elements to the left of mid including mid.
    int n2 = r - m;                             // Index of the elements to the right of mid.

    int L[n1], R[n2];                           //Intialising the two temporary arrays for storing the left and the right elements from the mid.

    for(i = 0; i < n1; i++)                     //Storing the left elements from the mid of the arr to the array L.
    {
        L[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++)                     //Storing the right elements from the mid of the arr to the array R.
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;                                      //updating all the counters to their intial values.
    j = 0;
    k = l;
    while(i < n1 && j < n2)                     //The real merge takes place in this while loop
    {
        if(L[i] <= R[j])                        //if the element at left array is greater than element at right array.
        {
            arr[k] = L[i];                      //the element is placed at it's correct positon in the original array.
            i++;                                //i is incremented.
        }
        else                                    //if the element at right is greater than element at left.
        {
            arr[k] = R[j]; 
            j++;                                //j is incremented.
        }
        k++;                                    // k is incremented.
    }

    while(i < n1)                               //Copying all the remaining elements in the left array to the original array.
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)                               //Copying all the remaining elements in the right array to the original array.
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)        // Here the array is divided into halves recursively, and merged resulting in the array to be sorted.
{
    if(l < r)                                  //if the array has more than one element
    {
        int mid = l + (r - l) / 2;             //calculating the middle element.
        
        mergeSort(arr, l, mid); 
        mergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = {20, 4, 18, 0, 7};              //An array to work with.
    int N = sizeof(arr) / sizeof(arr[0]);       //Size of the array.

    printf("Array before Sorting - ");
    printArray(arr, N);

    mergeSort(arr, 0, N-1);

    printf("Array after Sorting - ");
    printArray(arr, N);

    return 0;
}

//Time Complexity = O(N*Log(N))