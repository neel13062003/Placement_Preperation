//https://www.hackerrank.com/contests/aa-1695400090/challenges/ab-10-4/submissions/code/1367948204

#include <iostream>
using namespace std;

void generateLexicographicalNumbers(int current, int n) {
    if (current > n) {
        return;
    }
    cout << current << " "; 
    generateLexicographicalNumbers(current * 10, n); // Go deeper into the tree
    if (current % 10 != 9) {  //stop to 9
        generateLexicographicalNumbers(current + 1, n); // Go to the next sibling
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        generateLexicographicalNumbers(1, n);
        cout << endl;
    }
    return 0;
}

