#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    if (!(cin >> n >> k >> m)) return 0;

    vector<bool> bad(n + 1, false);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        bad[x] = true;
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    long long MOD = 1000000007;
    long long current_sum = 1;

    for (int i = 1; i <= n; i++) {
        if (i > k) {
            current_sum = (current_sum - dp[i - k - 1] + MOD) % MOD;
        }

        if (bad[i]) {
            dp[i] = 0;
        } else {
            dp[i] = current_sum;
        }

        current_sum = (current_sum + dp[i]) % MOD;
    }

    cout << dp[n] << "\n";

    return 0;
}

