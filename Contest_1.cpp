#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
void solve() {
    vector<int> a(7);
    int total_sum = 0;
    for (int i = 0; i < 7; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }
    int max_val = *max_element(a.begin(), a.end());
    cout << 2 * max_val - total_sum << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
