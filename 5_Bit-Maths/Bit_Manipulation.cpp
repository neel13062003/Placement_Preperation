//https://www.geeksforgeeks.org/bits-manipulation-important-tactics/
//https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
//https://www.geeksforgeeks.org/bitwise-hacks-for-competitive-programming/
//https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/


// a << n  =  a * 2^n;   
// a >> n  =  a/ 2^n; 

#include <bits/stdc++.h>
using namespace std;

//1=Count Set Bits(Numeber of Set Bits)
int CountSetBits(int N){
    int count=0;
    while(N!=0){
        if(n&1==1){
            count++;                                                                                                                                                                                                                                                              
        }
        n=n>>1;
    }
    return count;
}

//2=Direct XOR of all numbers from 1 to n
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

//3=count 
int countValues (int n)
{
    int countV = 0;
 
    // Traverse all numbers from 0 to n and
    // increment result only when given condition
    // is satisfied.
    for (int i=0; i<=n; i++ )
        if ((n+i) == (n^i) )
            countV++;
 
    return countV;
}
//Best Way  O(logn)
int countValues(int n)
{
    // unset_bits keeps track of count of un-set
    // bits in binary representation of n
    int unset_bits=0;
    while (n)
    {
        if ((n & 1) == 0)
            unset_bits++;
        n=n>>1;
    }
 
    // Return 2 ^ unset_bits
    return 1 << unset_bits;
}
 
//Bitwise Pair wise & then  xor
//https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/

******
(x & y) ? cout <<"True " : cout <<"False ";                  any common 1 bit then  true (  x bianry and with y binary return decimal value of bianry)
(x && y) ? cout <<"True " : cout <<"False ";             if any 0 bit then logical end become false so both false answer true

//4=Getting the lowest set bit of a number:
int lowest_set_bit(int num)
{
    int ret = num & (-num);
    return ret;
}


//5=2'S complement
void 2's()
{
    int num = 4;
    int twos_complement = ~num;          //1's
    cout << "This is two's complement " << twos_complement << endl;
    cout << "This is also two's complement " << (~num+1) << endl;
    return 0;
}


//6=Checking if bit at nth position is set or unset: 
bool at_position(int num, int pos)
{
    bool bit = num & (1 << pos);
    return bit;
}


//7= toggle , flip given bits
void toggle(int& num, int pos) { 
    num ^= (1 << pos); 
}


//8=clear bit
void unset(int &num,int pos)
{
    //Second step is to bitwise and this  number with given number
    num &= (~(1 << pos));
}

//9=set bit
void set(int & num,int pos)
{
     // First step is shift '1', second
     // step is bitwise OR
     num |= (1 << pos);
}


//10= Checking if given 32 bit integer is power of 2 
int isPowerof2(int x)
{
    return (x && !(x & x-1));
    //if(x&x-1 == 0) set
}

//11) Find the last set bit
int lastSetBit(int n){
    return log2(n & -n)+1;
}

//12 Find log base 2 of 32 bit integer 
int log2(int x)
{
    int res = 0;
    while (x >>= 1)
        res++;
    return res;
}

//13=count set bits in (Brian Kernighan’s algorithm.)
unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;



    int count = 0;
    while (x)
    {
        x &= (x-1);
        count++;
    }
    return count;
}
 
//https://www.geeksforgeeks.org/case-conversion-lower-upper-vice-versa-string-using-bitwise-operators-cc/
//14=convert lowert ot higher
if we clear 5th bit of lower case convert into uppercase
void convert(){
    // Convert a lowercase character to uppercase
    char c = 'a'; // lowercase 'a' has ASCII code 97 (0b01100001)
    c &= ~(1 << 5); // set the 5th bit from the right to 0
    // now c has ASCII code 65 (0b01000001), which is uppercase 'A'

    // Convert an uppercase character to lowercase
    char d = 'B'; // uppercase 'B' has ASCII code 66 (0b01000010)
    d |= (1 << 5); // set the 5th bit from the right to 1
    // now d has ASCII code 98 (0b01100010), which is lowercase 'b' 
}

//Odd-Even
bool isEven(int number) {
    return (number & 1) == 0;
}

//Ascii vALUES
A ----> 65
B ----> 66
..etc

a ----> 97
b ----> 98 


char c  = 'c'  if subtract 32 become lower and adding become upper


//15=iS power of 2
bool isPowerOfTwo(int x)
{
     // First x in the below expression is
     // for  the case when x is 0
     return x && (!(x & (x - 1)));
}

//16 Find XOR of all subsets of a set = important
We can do it in O(1) time. 
The answer is always 0 if the given set has more than one element.
 For sets with a single element, the answer is the value of the single element. 



//Built in functions
*** four important built-in functions = Time complexity : O(log2(n))  Auxiliary Space: O(1)  ***
1. __builtin_popcount(n)
 This function is used to count the number of one’s(set bits) in an integer. 
2 . __builtin_parity(x)
This function is used to check the parity of a number. This function returns true(1) if the number has odd parity else it returns false(0) for even parity. 
Example: 
3.__builtin_clz(x)
This function is used to count the leading zeros of the integer. Note : clz = count leading zero’s. 
Example: It counts number of zeros before the first occurrence of one(set bit). 
4.__builtin_ctz(x)
This function is used to count the trailing zeros of the given integer. Note : ctz = count trailing zeros. 
Example: Count no of zeros from last to first occurrence of one(set bit). 


//17=sum of subset of array
So at last for any value of n and array elements, 
we can simple say that the final sum will be 2n-1 times the bitwise OR of all the inputs.

// Returns sum of XORs of all subsets
int xorSum(int arr[], int n){
    int bits = 0;
    // Finding bitwise OR of all elements
    for (int i=0; i < n; ++i)
        bits |= arr[i];
    int ans = bits * pow(2, n-1); 
    return ans;
}

//18 = sum of all subsequenc of subset
// https://www.geeksforgeeks.org/find-sum-sum-sub-sequences/
// So, the sum of all sub-sequence will be (sum of all the elements) * 2n-1.
int sum(int arr[], int n)
{
  int ans = 0;
 
  // Finding sum of the array.
  for (int i = 0; i < n; i++)
    ans += arr[i];
 
  return ans * pow(2, n - 1);
}

//19=The Quickest way to swap two numbers:
a ^= b;
b ^= a; 
a ^= b;

//20=chekc all bits are alternative or not
 bool allBitsAreSet(int n)
{
    // if true, then all bits are set
    if (((n + 1) & n) == 0)
        return true;
 
    // else all bits are not set
    return false;
}
 
//21
string intToBinary(int num) {
    string binary = "";
    while (num > 0) {
        if (num & 1) {
            binary = "1" + binary; // append '1' to the binary string
        } else {
            binary = "0" + binary; // append '0' to the binary string
        }
        num >>= 1; // shift the bits to the right by one position
    }
    return binary;
}


//22
int binaryToInt(string binary) {
    int num = 0;
    for (char c : binary) {
        num <<= 1; // shift the bits to the left by one position
        if (c == '1') {
            num |= 1; // set the least significant bit to 1
        }
    }
    return num;
}


//23  = msb
 
int setBitNumber(int n)
{
  //this will be the answer going to return
  //This will work for 64-bit if using with long long
  //while in-built functions overflow
    int ans = 1;
    while (n) {
        ans *= 2;
        n /= 2;
    }
    ans/=2;
    return ans;
}

//sqyare of numbers
 while (temp) {
        if (temp & 1) {
            // result=result+(num*(2^power))
            result += (num << power);
        }
        power++;
 
        // temp=temp/2
        temp = temp >> 1;
    }

//25Count toggle Bit: 
 // Function to find number of bits needed to be flipped to convert A to B
int countBitsFlip(int a, int b){
    int c=a^b;
    int count=0;
    while(c>0){
        c=(c&(c-1));
        count++;
    }
    return count;
}

//26
// count if n=10 from 1 to n b/w all set bits. 
int countSetBits(int n){
    if(n<2)
        return n;
        int x=log2(n);
        
        return (x*pow(2,x-1))+(n+1-pow(2,x))+countSetBits(n-pow(2,x));
}

//27 Generate All Subset in Sequence
 //Generate All Power Set
vector<string> AllPossibleStrings(string s){
		    //Generate All Power Set
    		int n = s.size();
    	    int subset = (1<<n);
    	    vector<string> ans;
    	    for(int i=1;i<subset;++i){
    	        string a = "";
    	        for(int j=0;j<n;++j){
    	            if(i & (1<<j)) a.push_back(s[j]);
    	        }
    	        ans.push_back(a);
    	    }
    	    sort(ans.begin(),ans.end());
    	    return ans;
		}

//27-Set Bit Position
int findPosition(int n) {
        
    // code here
    if(N==0) return -1;
    if(N&(N-1)) return -1;
    return log2(N)+1;
}