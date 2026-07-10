#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> a;
int max_xor = 0;

void find_max(int idx, int count, int current_xor) {
    if (count == k) {
        max_xor = max(max_xor, current_xor);
        return;
    }
    if (idx == n || count + (n - idx) < k) {
        return;
    }
    find_max(idx + 1, count + 1, current_xor ^ a[idx]);
    find_max(idx + 1, count, current_xor);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n >> k) {
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        find_max(0, 0, 0);
        cout << max_xor << "\n";
    }

    return 0;
}

