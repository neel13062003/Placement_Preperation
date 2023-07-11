#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse
// the given 2D arr[][]
void reverseArray(int arr[2][2])
{

    // Traverse each row of arr[][]
    for (int i = 0; i < 2; i++) {

        // Initialise start and end index
        int start = 0;
        int end = 1;

        // Till start < end, swap the element
        // at start and end index
        while (start < end) {

            // Swap the element
            swap(&arr[i][start],
                 &arr[i][end]);

            // Increment start and decrement
            // end for next pair of swapping
            start++;
            end--;
        }
    }

    // Print the arr[][] after
    // reversing every row
    /*for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }*/
}



int main()
{
    int t;
    cin>>t;
    while(t--){
        int p=0;
        int arr[2][2];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cin>>arr[i][j];
            }
        }
        if(arr[0][0]<arr[0][1]   &&  arr[1][0]<arr[1][1]   &&  arr[0][0]<arr[1][0]   &&  arr[1][0]<arr[1][1]   ){
            p=1;
        }
        int deg = 3;    // more rotations with 90, 180, 270 degree's.
        while(deg --) {
            for(int i = 0; i < 2; i ++) {
                for(int j = i; j < 2; j ++) {            //or j=0;i<i;j++ both are equal.
                    swap(arr[i][j], arr[j][i]);     // transpose of matrix.
                }
            }
            /*for(int i = 0; i < 2; i ++) {
                reverse(arr[i].begin(),arr[i].end());       // reverse each row.
            }*/
            reverseArray(arr);
            if(arr[0][0] < arr[0][1]   && arr[1][0] < arr[1][1]   && arr[0][0]<arr[1][0]   && arr[1][0]<arr[1][1]   ){
                p=1;
            }
        }/*
        if(   arr[0][0]>arr[0][1]  && arr[1][0]>arr[1][1]   && arr[0][0]<arr[1][0]   && arr[1][0]<arr[1][1]      ){
            p=1;
        }
        if(  arr[0][0]>arr[0][1]   && arr[1][0]>arr[1][1]   && arr[0][0]>arr[1][0]   &&  arr[1][0]>arr[1][1]    ){
            p=1;
        }
        if(  arr[0][0]<arr[0][1]   && arr[1][0]<arr[1][1]   && arr[0][0]>arr[1][0]  && arr[1][0]>arr[1][1]    ){
            p=1;
        }*/

        if(p==0){
            cout<<"NO"<<endl;
        }else{
           cout<<"YES"<<endl;
        }
    }
    return 0;
}
