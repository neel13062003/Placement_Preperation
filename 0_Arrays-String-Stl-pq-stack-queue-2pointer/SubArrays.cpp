#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout << "**********SubArray**********" << endl;
    int n;
    cout<<"Enter How Many Elements You Want To Enter"<<endl;
    cin>>n;

    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    //Print All Subarrya
    cout<<"Print All SubArray"<<endl;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<vec[k];
            }
            cout<<endl;
        }
    }

    int maxSum=INT_MIN;
    //Finding MaxSubArray = BruteForceApprach
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
                int sum=0;
            for(int k=i;k<=j;k++){
                sum+=vec[k];
            }
            maxSum = max(sum,maxSum);
        }
    }

    cout<<"Max Sum is {O(n^3)} = " <<maxSum<<endl;

    /*----------------------------------------------------------------------*/
    int currSum[n+1];
    currSum[0]=0;

    for(int i=1;i<=n;i++){
        currSum[i]=currSum[i-1]+vec[i-1];
    }

    int maxSum2=INT_MIN;
    for(int i=1;i<=n;i++){
        int sum2=0;
        for(int j=0;j<i;j++){
            sum2 =  currSum[i]-currSum[j];
            maxSum2 =max(sum2,maxSum2);
        }
    }

    cout<<"Max Sum is {O(n^2)} = " <<maxSum2<<endl;
     /*----------------------------------------------------------------------*/

    //Kadane's Algorithm
    int currentSum3=0;
    int maxSum3 = INT_MIN;

    for(int i=0;i<n;i++){
        currentSum3 +=vec[i];
        if(currentSum3<0) currentSum3=0;
        maxSum3 =max(maxSum3,currentSum3);
    }

    cout<<"Max Sum is {O(n)} = " <<maxSum3<<endl;
    /*----------------------------------------------------------------------*/
    return 0;
}
