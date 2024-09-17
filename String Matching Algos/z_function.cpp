#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string &s) {
    int n = s.size(), l=0, r=0;

    vector<int> z(n, 0);
    for(int i=1;i<n;i++) {
        if(i<r) z[i] = max(z[i-l], r-l);
        while(i+z[i] < n && s[i+z[i]] == s[z[i]]) z[i]++;

        if(i+z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    return z;
}