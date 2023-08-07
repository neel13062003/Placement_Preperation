/*#include <iostream>
#define mod 1000000007
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    printf("%d\n", (1 << n)%mod);
    return 0;
}
*/
#include <iostream>
#define mod 1000000007
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int result = 1;

    for (int i = 0; i < n; i++) {
        result = (result * 2) % mod;
    }

    cout << result << endl;
    return 0;
}

