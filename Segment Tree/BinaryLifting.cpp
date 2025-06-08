#include <bits/stdc++.h>
using namespace std;
// Binary Lifting is a technique used to efficiently find the Lowest Common Ancestor (LCA) of two nodes in a tree.
// It allows us to preprocess the tree in such a way that we can answer LCA queries in logarithmic time.
// This implementation assumes a tree represented as an adjacency list, where each node has a unique identifier.    

class BinaryLifting {
    vector<vector<int>> binaryParents;

public:
    BinaryLifting(int n) {
        binaryParents.resize(n, vector<int>(32, -1));
    }

    void generateBinaryParents(int node, vector<pair<int, int>> adj[], int par) {
        binaryParents[node][0] = par;
        for (int i = 1; i < 32; ++i) {
            if (binaryParents[node][i - 1] != -1)
                binaryParents[node][i] = binaryParents[binaryParents[node][i - 1]][i - 1];
            else
                break;
        }
        for (auto nbr : adj[node]) {
            if (nbr.first == par) continue;
            generateBinaryParents(nbr.first, adj, node);
        }
    }

    int getIthAncestor(int node, int i) {
        for (int bit = 0; bit < 32; ++bit) {
            if (i & (1 << bit)) {
                node = binaryParents[node][bit];
                if (node == -1) break;
            }
        }
        return node;
    }

    int getLCA(int node1, int node2) {
        if (node1 == node2) return node1;

        for (int i = 31; i >= 0; --i) {
            if (binaryParents[node1][i] != -1 && binaryParents[node1][i] != binaryParents[node2][i]) {
                node1 = binaryParents[node1][i];
                node2 = binaryParents[node2][i];
            }
        }
        return binaryParents[node1][0];
    }

    int getLCAForDifferentLength(int node1, int node2, vector<int>& dist) {
        if (dist[node1] > dist[node2]) {
            node1 = getIthAncestor(node1, dist[node1] - dist[node2]);
        } else {
            node2 = getIthAncestor(node2, dist[node2] - dist[node1]);
        }
        return getLCA(node1, node2);
    }
};
