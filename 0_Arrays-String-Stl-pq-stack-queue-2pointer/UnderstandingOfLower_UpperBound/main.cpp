// lower_bound and upper_bound in vector

#include <algorithm> // for lower_bound, upper_bound and sort
#include <iostream>
#include <vector> // for vector

using namespace std;

int main()
{
	int gfg[] = { 5, 5, 5, 6, 6, 6, 7, 7 };
	vector<int> v(gfg, gfg + 8); // 5 5 5 6 6 6 7 7

    auto lower = lower_bound(v.begin(), v.end(), 6) - v.begin();
    auto upper = upper_bound(v.begin(), v.end(), 6) - v.begin();

    // Print the results
    cout << "lower_bound for 6 at index " << lower << '\n';
    cout << "upper_bound for 6 at index " << upper << '\n';
	return 0;
}

//output = 3  6
