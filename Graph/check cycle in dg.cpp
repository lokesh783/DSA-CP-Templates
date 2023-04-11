        for(auto vec: p) {
            g[vec[1]].push_back(vec[0]);
            inDeg[vec[0]]++;
        }

        queue<int> q;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!inDeg[i]) q.push(i);
        }
        cnt  = q.size();
        while(!q.empty()) {
            auto node = q.front();q.pop();

            for(auto nbr: g[node]) {
                inDeg[nbr] --;
                if(inDeg[nbr] == 0) {
                    q.push(nbr);
                    cnt ++;
                }
            }
        }
