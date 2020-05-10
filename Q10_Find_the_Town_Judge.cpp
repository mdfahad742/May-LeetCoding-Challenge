class Solution {
public:
    int findJudge(int N, vector<vector<int>>& v) {
        map<int,set<int>> mp;
        map<int,set<int>> mp1;
        int n=v.size();
        if(n==0 && N==0)return -1;
        if(N==1 && n==0) return 1;
        
        
        for(int i=0;i<n;i++){
            mp[v[i][1]].insert(v[i][0]);
            mp1[v[i][0]].insert(v[i][1]);
        }
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second.size()<<endl;
            if(it.second.size()==(N-1))if(mp1.find(it.first)==mp1.end())return it.first;
        }
        return -1;
    }
};
