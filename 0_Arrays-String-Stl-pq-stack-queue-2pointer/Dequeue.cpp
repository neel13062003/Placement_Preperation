#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> q = { 1,2,3,4 };

    // Push an element at the back of the deque
    q.push_back(5);

    // Push an element at the front of the deque
    q.push_front(0);

    // Pop an element from the back of the deque
    q.pop_back();

    // Pop an element from the front of the deque
    q.pop_front();

    // Get the back element of the deque
    int back = q.back();

    // Get the front element of the deque
    int front = q.front();

    // Output the elements of the deque
    for (int x : q) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Back element: " << back << endl;
    cout << "Front element: " << front << endl;

    return 0;
}
