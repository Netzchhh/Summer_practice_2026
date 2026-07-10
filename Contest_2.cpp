#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    if (!(cin >> s >> t)) return 0;

    if (s.length() != t.length()) {
        cout << -1 << "\n";
        return 0;
    }

    string needle = s;
    string haystack = t + t;
    haystack.pop_back();

    int n = needle.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && needle[i] != needle[j]) {
            j = pi[j - 1];
        }
        if (needle[i] == needle[j]) {
            j++;
        }
        pi[i] = j;
    }

    int j = 0;
    for (int i = 0; i < haystack.length(); i++) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = pi[j - 1];
        }
        if (haystack[i] == needle[j]) {
            j++;
        }
        if (j == n) {
            cout << i - n + 1 << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}

