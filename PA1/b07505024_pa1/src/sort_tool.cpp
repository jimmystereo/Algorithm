// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2021/02/26 Hsien-Chia Chen]
// **************************************************************************

#include "sort_tool.h"
#include <iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int> &data)
{
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for (int i = 1; i < data.size(); i++)
    {
        int marker = i - 1;
        int current_value = data[i];
        while (data[marker] > data[marker + 1] && marker >= 0)
        {
            data[marker + 1] = data[marker];
            data[marker] = current_value;
            marker--;
        }
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int> &data)
{
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int> &data, int low, int high)
{
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    if (low < high)
    {
        int marker = Partition(data, low, high);
        QuickSortSubVector(data, low, marker - 1);
        QuickSortSubVector(data, marker + 1, high);
    }
}

int SortTool::Partition(vector<int> &data, int low, int high)
{
    // Function : Partition the vector
    // TODO : Please complete the function
    // Hint : Textbook page 171

    int pivot = data[high];
    //marker is the rightest of the smaller part
    int marker = low - 1;
    for (int i = low; i < high; i++)
    {
        //i is the current index being sort
        if (data[i] <= pivot)
        { //marker becomes the leftest of the bigger part
            marker++;
            //swap
            int tmp = data[marker];
            data[marker] = data[i];
            data[i] = tmp;
            //marker turns back to the rightest of the smaller part
        }
    }
    //swap pivot with marker
    int tmp = data[marker + 1];
    data[marker + 1] = pivot;
    data[high] = tmp;
    return marker + 1;
}

// Merge sort method
void SortTool::MergeSort(vector<int> &data)
{
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int> &data, int low, int high)
{
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if (high == low)
    {
        return;
    }
    int middle1 = (high + low) / 2;
    int middle2 = middle1 + 1;
    MergeSortSubVector(data, low, middle1);
    MergeSortSubVector(data, middle2, high);
    Merge(data, low, middle1, middle2, high);
}

// Merge
void SortTool::Merge(vector<int> &data, int low, int middle1, int middle2, int high)
{
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    int right_index = middle2;
    int left_index = low;
    vector<int> combined(data.size());
    int combined_index = low;
    while (left_index <= middle1 && right_index <= high)
    {
        if (data[left_index] < data[right_index])
        {
            combined[combined_index] = data[left_index];
            combined_index++;
            left_index++;
        }
        else
        {
            combined[combined_index] = data[right_index];
            combined_index++;
            right_index++;
        }
    }
    if (left_index > middle1)
    {
        for (int i = right_index; i <= high; i++)
        {
            combined[combined_index] = data[i];
            combined_index++;
        }
    }
    else
    {
        for (int i = left_index; i <= middle1; i++)
        {
            combined[combined_index] = data[i];
            combined_index++;
        }
    }
    for (int i = low; i <= high; i++)
    {
        data[i] = combined[i];
    }
}

// Heap sort method
void SortTool::HeapSort(vector<int> &data)
{
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    int tmp = 0;
    for (int i = data.size() - 1; i >= 1; i--)
    {
        tmp = data[i];
        data[i] = data[0];
        data[0] = tmp;
        heapSize--;
        MaxHeapify(data, 0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int> &data, int root)
{
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code heref
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    int largest;
    if (left <= heapSize && data[left] > data[root])
    {
        largest = left;
    }
    else
    {
        largest = root;
    }
    if (right <= heapSize && data[right] > data[largest])
    {
        largest = right;
    }
    if (largest != root)
    {
        int tmp = data[root];
        data[root] = data[largest];
        data[largest] = tmp;
        MaxHeapify(data, largest);
    }
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int> &data)
{
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
    for (int i = heapSize / 2; i >= 1; i--)
    {
        MaxHeapify(data, i);
    }
}
