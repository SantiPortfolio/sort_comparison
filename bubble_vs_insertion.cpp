#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


using namespace std;

namespace arraySpace{
    int randArray[40000];
    int sortedArray[40000];
}

int randArr()
{
    //* Generate an array of 40,000 random integers
    //* make a timer to time how long the random ints take to be loaded into the array
    //* in ms


    cout<<"Loading random array"<<endl;

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (int i = 0; i < 40000; i++)
    {
        arraySpace::randArray[i] = rand();
    }

    cout<<"Random array loaded"<<endl;
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    //* convert to ms
    cpu_time_used = cpu_time_used * 1000;

    printf("Time taken to load array: %f\n", cpu_time_used);


    return 0;
}

int bubblesort()
{
    //* Sort the array using bubble sort
    //* make a timer to time how long the bubble sort takes to sort the array

    cout<<"Sorting array with bubble sort"<<endl;

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (int i = 0; i < 40000; i++)
    {
        arraySpace::randArray[i] = rand();
    }

    for (int i = 0; i < 40000; i++)
    {
        for (int j = 0; j < 40000 - i - 1; j++)
        {
            if (arraySpace::randArray[j] > arraySpace::randArray[j + 1])
            {
                int temp = arraySpace::randArray[j + 1];
                arraySpace::randArray[j + 1] = arraySpace::randArray[j];
                arraySpace::randArray[j] = temp;
            }
        }
    }

    cout<<"Array sorted with bubble sort"<<endl;
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    //* convert to ms
    cpu_time_used = cpu_time_used * 1000;
    printf("Time taken to sort array: %f\n", cpu_time_used);

    return 0;
}

int insertionsort()
{
    //* Sort the array using insertion sort
    //* make a timer to time how long the insertion sort takes to sort the array

    cout<<"Sorting array with insertion sort"<<endl;

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (int i = 0; i < 40000; i++)
    {
        arraySpace::randArray[i] = rand();
    }

    for (int i = 1; i < 40000; i++)
    {
        int temp = arraySpace::randArray[i];
        int j = i - 1;
        while (j >= 0 && arraySpace::randArray[j] > temp)
        {
            arraySpace::randArray[j + 1] = arraySpace::randArray[j];
            j--;
        }
        arraySpace::randArray[j + 1] = temp;
    }

    cout<<"Array sorted with insertion sort"<<endl;
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    //* convert to ms and round to full number
    cpu_time_used = cpu_time_used * 1000;
    printf("Time taken to sort array: %f\n", cpu_time_used);

    arraySpace::sortedArray[40000] = arraySpace::randArray[40000];

    return 0;
}

int binarySearch()
{
    //* Search the array using binary search
    //* make a timer to time how long the binary search takes to search the array

    cout<<"Searching array with binary search"<<endl;

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int low = 0;
    int high = 40000;
    int mid = (low + high) / 2;
    int search = arraySpace::sortedArray[mid];

    while (low <= high)
    {
        if (arraySpace::sortedArray[mid] < search)
        {
            low = mid + 1;
        }
        else if (arraySpace::sortedArray[mid] == search)
        {
            cout<<"Element found at index "<<mid<<endl;
            break;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }

    if (low > high)
    {
        cout<<"Element not found"<<endl;
    }

    cout<<"Array searched with binary search"<<endl;
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    //* convert to ms and round to full number
    cpu_time_used = cpu_time_used * 1000;
    printf("Time taken to search array: %f\n", cpu_time_used);

    return 0;

}

int linearsearch()
{
    //* Search the array using linear search
    //* make a timer to time how long the linear search takes to search the array

    cout<<"Searching array with linear search"<<endl;

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int search = arraySpace::randArray[40000];

    for (int i = 0; i < 40000; i++)
    {
        if (arraySpace::randArray[i] == search)
        {
            cout<<"Element found at index "<<i<<endl;
            break;
        }
    }

    cout<<"Array searched with linear search"<<endl;
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    //* convert to ms and round to full number
    cpu_time_used = cpu_time_used * 1000;
    printf("Time taken to search array: %f\n", cpu_time_used);

    return 0;

}

int main()
{
    randArr();
    bubblesort();
    insertionsort();
    linearsearch();
    binarySearch();
}