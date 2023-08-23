/*
number = 2 3 5 7 11 13 17
index  = 1 2 3 4 56 78 910
4=index  8=n how many prime number in between come! = 7 11 13
*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if (n <= 1)
        return false;

    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0)
            return false;
    }
    return true;
}

vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    for (int num = 2; num * num <= n; ++num) {
        if (primes[num]) {
            for (int multiple = num * num; multiple <= n; multiple += num) {
                primes[multiple] = false;
            }
        }
    }

    vector<int> prime_numbers;
    for (int num = 2; num <= n; ++num) {
        if (primes[num]) {
            prime_numbers.push_back(num);
        }
    }

    return prime_numbers;
}

int main() {
    vector<int> prime_list = sieve_of_eratosthenes(100);

    vector<pair<string, int>> v;
    int count = 1;
    for (int i = 0; i < prime_list.size(); i++) {
        string temp = to_string(prime_list[i]);
        v.push_back({temp, count});
        count++;
    }

    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ": " << v[i].first << "->" << v[i].second << endl;
    }

    cout << " " << endl;
    int index, n;
    cout<<"Enter Index & Enter n"<<endl;
    cin >> index >> n;
    int countDigit = 0;
    for (int i = index - 1; i < n; i++) {
        cout << v[i].second << ": " << v[i].first << endl;
        countDigit++;
    }
    cout << "Answers: -> " << countDigit << endl;

    return 0;
}
