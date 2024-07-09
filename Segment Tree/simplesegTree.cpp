#include "bits/stdc++.h"
using namespace std;


class STree{
private:
    int MN = INT_MIN;
    int MX = INT_MAX;
    vector<int> tree;
    int n;

    int sum(int v, int tl, int tr, int l, int r) {
        // tl = treeLeft, that ranges 0 to n-1 in normal case
        // 0,n-1 means it have sum of all the elements
        if(tl>tr) return 0;
        if(l>tr || r<tl) return 0;
        if(l<=tl && r>=tr) return tree[v];

        int treeMid = (tl + tr)/2;
        return sum(v*2, tl, treeMid, l, r) + sum(v*2 + 1, treeMid + 1, tr, l, r);

    }

    void buildTree(vector<int>& a, int tl, int tr, int v = 1) {
        if (tl > tr) return;
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }

        int mid = (tl + tr) / 2;
        buildTree(a, tl, mid, v * 2);
        buildTree(a, mid + 1, tr, v * 2 + 1);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }

    void update(int idx, int val, int v, int tl, int tr) {
        if (tl > tr) return;
        if (idx < tl || idx > tr) return; 
        if (tl == tr) {
            tree[v] = val;
            return;
        }
        int tmid = (tl + tr) / 2;
        update(idx, val, v * 2, tl, tmid);
        update(idx, val, v * 2 + 1, tmid + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }

public:
    STree(int sz, vector<int>& vec) {
        n = sz;
        tree.assign(sz * 4, 0);
        buildTree(vec, 0, n - 1);
    }

    int getSum(int l, int r){
        return sum(1, 0, n-1, l, r);
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, n - 1);
    }
};
  
