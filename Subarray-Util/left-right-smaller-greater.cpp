// This file provides code for next-smaller-left and other similar utils
// it store indexes for smallers and largers

#include "bits/stdc++.h"
using namespace std;

vector<int> NSL(int m, vector<int> &arr)
{
    stack<pair<int, int>> st;

    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        if (st.empty())
        {
            st.push({arr[i], i});
        }
        else
        {
            while (st.size() && st.top().first >= arr[i])
                st.pop();
            ans.push_back(st.size() ? st.top().second : -1);
            st.push({arr[i], i});
        }
    }
    return ans;
}

vector<int> NSR(int m, vector<int> &arr)
{
    stack<pair<int, int>> st;

    vector<int> ans;
    for (int i = m; i >= 0; i--)
    {
        if (st.empty())
        {
            st.push({arr[i], i});
        }
        else
        {
            while (st.size() && st.top().first >= arr[i])
                st.pop();
            ans.push_back(st.size() ? st.top().second : m);
            st.push({arr[i], i});
        }
    }
    return ans;
}