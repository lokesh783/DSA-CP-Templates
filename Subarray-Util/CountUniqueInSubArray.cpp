#include "bits/stdc++.h"
using namespace std;

int countSumOfNumberOfUniqueValuesInAllSubArray(int n, vector<int>&v) {
    map<int, vector<int>> positions;
    for(int i=0;i<n;i++) positions[v[i]].push_back(i);

    int ans = 0;
    for(auto &[num, indexes]: positions) {
        int prev = -1, badOccurences = 0;
        indexes.push_back(n);
        for(auto &currInd: indexes) {
            int totalElementsInCurrentSubArray = (currInd - prev - 1);
            badOccurences += ((totalElementsInCurrentSubArray* (totalElementsInCurrentSubArray+1)) / 2);
            prev = currInd;
        }
        ans += (((n*(n+1))/2) - badOccurences);
    }
    return ans;
}
