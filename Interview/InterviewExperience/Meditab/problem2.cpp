//Code: Neel Soni
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &word) {
    int left = 0;
    int right = word.length() - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int countPalindromicWords(const string &sentence) {
    istringstream iss(sentence);
    string word;
    int count = 0;

    while (iss >> word) {
        if (isPalindrome(word)) {
            count++;
        }
    }

    return count;
}

int main() {
    string sentence;
    getline(cin, sentence);

    for(int i=0;i<sentence.size();i++){
        if(sentence[i]>='A' && sentence[i]<='Z') sentence[i] += 'a' - 'A';;
    }

    int palindromicCount = countPalindromicWords(sentence);
    cout << "Output: " << palindromicCount << endl;

    return 0;
}
