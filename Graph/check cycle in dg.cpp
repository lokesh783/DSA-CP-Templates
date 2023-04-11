    bool checkCycleInDG(int node, vector<vector<int>>& g, int par) {
        vis[node] = 1;

        for(auto nebors: g[node]) {
            if(nebors == par) continue;
            if(vis[nebors]) return false;

            bool temp = checkCycleInDAG(nebors, g, node);
            if(!temp) return false;
        }
        return true;
    }
