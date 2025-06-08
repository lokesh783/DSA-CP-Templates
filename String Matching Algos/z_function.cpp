#include <bits/stdc++.h>
using namespace std;
// Z-function algorithm computes the length of the longest substring starting from each position
// that matches the prefix of the string.
// For a string s, z[i] is the length of the longest substring starting from s[i] that matches the prefix of s.

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;  // [l, r) is the rightmost segment matched with prefix

    for (int i = 1; i < n; i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);  // Reuse previously computed z-values
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;  // Expand match
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];  // Update window
        }
    }
    return z;
}
