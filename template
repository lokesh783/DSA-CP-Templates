// Lokesh Bhai aaj phodega
// Jai maa Bhavani
// Jai ekling ji
// Baujiraj ki daya se
// search - ctrl f
// select - ctrl sft l
#include <bits/stdc++.h>

// policy DS headers
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
#define f(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)

// vectors
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vpii vector<pair<int, int>>
#define vvpii vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mxe(v) *max_element(all(v))
#define mne(v) *min_element(all(v))

// maps
#define mpii map<int, int>

// sets
#define sti set<int>

#define yup cout << "YES";
#define shit cout << "NO";
#define el endl;
#define do2 cout <<
#define lo cin >>

// variables
#define SIZE 300001
int mod = 1e9 + 7;
int fact[SIZE];

int findPower(int n, int times) { if(times == 0) return 1; int ans = findPower(n, times>>1); ans = (ans * ans) % mod; if(times & 1) ans = (ans * n) % mod; return ans; }
int GCD(int a, int b) {if (a == 0) return b; return GCD(b % a, a); }
int LCM(int a, int b) {if(!a || !b) return 1; int val = GCD(a, b); return (a * b) / val;}
void inA(int arr[], int n) { f(i, 0, n) cin >> arr[i]; }
void inV(vector<int> &arr, int n) { f(i, 0, n) cin >> arr[i]; }
void buildFactArray() { fact[0] = 1; f(i,1,SIZE) fact[i] = (fact[i-1]*i) % mod;}
int modInverse(int A, int M) { return findPower(A, M - 2); }

int npr(int n, int r) {
    int num = fact[n], den = fact[r];
    return (num * modInverse(den, mod)) % mod;
}

void apna_ans_aayega()
{
    int n;cin>>n;
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int kitni_baar = 1;
    cin >> kitni_baar;
    while (kitni_baar--)
    {
        apna_ans_aayega();
    }
    return 0;
}
