//https://www.geeksforgeeks.org/minimum-operation-make-elements-equal-array/

// CPP program to find the minimum number of
// operations required to make all elements
// of array equal
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int minOperation(int arr[], int n) {
	// Insert all elements in hash.
	unordered_map<int, int> hash;
	for (int i=0; i<n; i++) {
		if (hash.find(arr[i]) != hash.end()) {
			hash[arr[i]]++;
		} else {
			hash[arr[i]] = 1;
		}
	}

	// find the max frequency
	int max_count = 0;
	for (auto it : hash) {
		max_count = max(max_count, it.second);
	}

	// return result
	return (n - max_count);
}

/* Driver program to test above function */
int main() {
	int arr[] = {1, 5, 2, 1, 3, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minOperation(arr, n) << endl;
	return 0;
}
//This code is contributed by NarasingaNikhil
