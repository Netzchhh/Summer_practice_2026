#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;
    
    if (2 * a <= b) {
        cout << n * a << "\n";
    } else {
        long long pairs = n / 2;
        long long remainder = n % 2;
        cout << pairs * b + remainder * a << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

