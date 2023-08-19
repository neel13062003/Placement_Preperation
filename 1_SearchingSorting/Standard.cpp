/*Brocode  = https://www.youtube.com/@BroCodez  = For Visualization */ 

{TimeComplexity , Space Complexity}

Implace(Both same element then it take part in sort ot not if not then it call)

1)D. Merge sort(N) = https://practice.geeksforgeeks.org/problems/merge-sort/1
2)D. Quick Sort(I) = https://practice.geeksforgeeks.org/problems/quick-sort/1

1)Heap Sort = https://youtu.be/mgUiY8CVDhU
{ Heap Sort: Actually not implace
  In-Place: Yes (for the sorting operation), but uses additional memory for heap construction.}

2)Bubble Sort (I)   = https://practice.geeksforgeeks.org/problems/bubble-sort/1       "https://youtu.be/Dv4qLJcxus8"
3)Insertion Sort(I) = https://practice.geeksforgeeks.org/problems/insertion-sort/1    "https://youtu.be/8mJ-OhcfpYg" 
4)Selection Sort(I) = https://practice.geeksforgeeks.org/problems/selection-sort/1    "https://youtu.be/EwjnF7rFLns"



*** Space ***
O(n) = { Linear Space} Merge Sort
O(1) = {Constant Space} Bubble Sort,Insertion Sort,Selection Sort

QuickSort = Implace, bubble sort take space

*** Time Complexity ***  
O(n2) = Bubble Sort,Insertion Sort,Selection Sort 
O(nlogn) = merge sort every situation
O(nlogn) & O(n2) = selection sort worst in already sorted 
O(nlogn) = HeapSort
O(logn) = count sort 


/*Internally Built with */
sort(arr,arr+n,cmp);
sort(arr,arr+n)

sort(vec.begin(),vec.end(),cmp);
sort(vec.begin(),vec.end());


//STL() function theroy

write name of all sorting alogorithm with internally sort() stl bukitl on

ChatGPT
    The C++ STL sort() function internally uses a variant of the Introsort algorithm, which combines different sorting 
algorithms for efficient performance. However, the specific algorithms used internally by sort() may vary across 
different C++ implementations. Here are some common sorting algorithms that may be used internally by sort():

1) QuickSort: A fast comparison-based sorting algorithm that recursively partitions the array based on a pivot 
    element.

2) Insertion Sort: A simple sorting algorithm that iteratively builds a sorted portion of the array by inserting each
   element into its correct position.

3) HeapSort: A comparison-based sorting algorithm that builds a binary heap data structure and repeatedly extracts the
  maximum element to place it in its correct sorted position. {When to solve maxi-mini problem like priority_Queue its aplication}

4) Merge Sort: A divide-and-conquer sorting algorithm that recursively divides the array into two halves, sorts them 
  separately, and then merges the sorted halves.

5) Introsort: A hybrid sorting algorithm that starts with QuickSort and switches to HeapSort if the recursion depth 
  exceeds a certain threshold, ensuring worst-case O(n log n) time complexity.

These are some of the common sorting algorithms that can be used internally by sort(). However, the choice of 
algorithm may depend on various factors such as the size of the input, the distribution of the elements, and the 
specific implementation of the C++ compiler or library.



/*When To Use Which Algo*/
Give me condtion where to use which sorting algoeithm
ChatGPT
The choice of a sorting algorithm depends on various factors, including the characteristics of the input data and the desired properties of the sorting process. Here are some conditions where different sorting algorithms are commonly used:

QuickSort:

QuickSort is often preferred when average-case performance is important.
It performs well on average and in many practical scenarios.
It is efficient for large datasets and has good cache performance.
QuickSort is suitable when the input data is random or uniformly distributed.
Merge Sort:

Merge Sort is stable and guarantees a worst-case time complexity of O(n log n).
It is preferred when worst-case performance is important.
Merge Sort is suitable for sorting linked lists or when the data is stored in external memory (such as external hard drives) where random access is costly.
HeapSort:

HeapSort guarantees a worst-case time complexity of O(n log n).
It is suitable when the worst-case performance is important, and the stability of the sorting algorithm is not a concern.
HeapSort is efficient when only a small portion of the sorted result is needed at a time.
Insertion Sort:

Insertion Sort is simple to implement and efficient for small input sizes or "partially" sorted data.
It performs well when the input is almost sorted or has a small number of inversions.
Insertion Sort is often used as a building block in more advanced sorting algorithms.
Radix Sort:

Radix Sort is suitable when sorting integers or fixed-length strings with a limited range of values.
It performs well when the number of digits or characters in the input is small.
Radix Sort is commonly used in applications where sorting keys are represented as integers or strings.
TimSort:

TimSort is a hybrid sorting algorithm derived from Merge Sort and Insertion Sort.
It is used in various programming languages and libraries as the default sorting algorithm (e.g., Pythons sorted() function).
TimSort combines the advantages of both Merge Sort and Insertion Sort, making it suitable for a wide range of scenarios.
Its important to note that the choice of sorting algorithm may also depend on other factors such as memory constraints, stability requirements, and specific optimization considerations for the target platform or application. Therefore, it's recommended to analyze the specific requirements and characteristics of the data before selecting a sorting algorithm.


1)D. Search Rotated Array  = https://leetcode.com/problems/search-in-rotated-sorted-array/ 
1)D. Search Rotated Array-II  = https://leetcode.com/problems/search-in-rotated-sorted-array-ii/ 
3)D. Search Space = https://practice.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1
4)D. Search Space = https://practice.geeksforgeeks.org/problems/1a31d09f7b8e9c0633339df07858deb3a728fe19/1
5)D. Search Space = https://leetcode.com/problems/koko-eating-bananas/