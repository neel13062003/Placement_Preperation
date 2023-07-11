//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        int largest = i;     // Initialize largest as root
        int left = 2 * i + 1;    // left = 2*i + 1
        int right = 2 * i + 2;     // right = 2*i + 2

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is not root
        if (largest != i)
        {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // Index of the last non-leaf node
        int lastNonLeafNode = (n / 2) - 1;

        // Perform heapify from the last non-leaf node up to the root
        for (int i = lastNonLeafNode; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // Build the initial heap
        buildHeap(arr, n);

        // Extract elements from the heap one by one
        for (int i = n - 1; i > 0; i--)
        {
            // Move the current root to the end
            swap(arr[0], arr[i]);

            // Reduce heap size and heapify the root
            heapify(arr, i, 0);
        }
    }
};





//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends