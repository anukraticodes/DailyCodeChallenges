class Solution {
public:
    string pushDominoes(string dom) {
        unordered_set<int> currSt, vis;
        int n= dom.size();
        vector<int> force(n, 0);
        for(int i=0;i<n;i++) {
            if (dom[i]!='.') {
                currSt.insert(i);
                dom[i] == 'L'? force[i]-- : force[i]++;
                vis.insert(i); // force is finalized for i
            }
        }
        while (!currSt.empty()) {
            unordered_set<int> nxt;
            for(auto ele:currSt) {
                if(force[ele] == 0) continue;
                int idx = ele + (force[ele]>0?1:-1); // next index based on force
                if(idx>=0 && idx<n && !vis.count(idx)) { // if force is not finalized on idx, update the force.
                    force[idx] += force[ele];
                    nxt.insert(idx);
                }
            }
            // Mark all the index for next batch as visited as force is finalized for these
            for(auto ele:nxt) {
                vis.insert(ele);
            }
            currSt = nxt;
        }
        string res;
        for(int i=0;i<n;i++) {
            char ch;
            if(force[i] == 0) {
                ch = '.';
            } else if(force[i]>0) {
                ch = 'R';
            } else {
                ch = 'L';
            }
            res.push_back(ch);
        }
        return res;
    }
};