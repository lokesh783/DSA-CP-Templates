#include "bits/stdc++.h"
using namespace std;


int mod = 1e9+7;

vector<vector<int>> mat_mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    int l = a.size(), m=a[0].size(), n=b[0].size();
    vector<vector<int>> ans(l,vector<int>(n));
    for(int i=0;i<l;i++) {
        for(int j=0;j<n;j++) {
            int t = 0;
            for(int k=0;k<m;k++) {
                t = (t + (a[i][k] * b[k][j]) % mod)% mod;
            }
            ans[i][j] = t;
        }
    }
    return ans;
}
vector<vector<int>> solve(vector<vector<int>> &a, int n) {
    if(n==0) {
        return {{1,0},{0,1}};
    }
    if(n==1) {
        return a;
    }

    vector<vector<int>> temp(2, vector<int>(2,0));
    vector<vector<int>> ans = solve(a, n/2);
    temp = mat_mul(ans, ans);
    if(n % 2 == 0) return temp;

    ans = mat_mul(temp, a);
    return ans;
}

int find_fib_in_logn(int n) {
    vector<vector<int>> a = {{1,1},{1,0}};
    a = solve(a, n);
    cout << "r";
    vector<vector<int>> lO = {{2,1}};
    vector<vector<int>> ans = mat_mul(lO, a);

    return ans[0][0]+ans[0][1];

}
