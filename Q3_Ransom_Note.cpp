class Solution {
public:
    bool canConstruct(string r, string s) {
        int n1=r.length(),n2=s.length();
        unordered_map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        bool f=1;
        for(auto ch:r){
            int ans=mp[ch];
            if(ans>=1)mp[ch]--;
            else {f=0;break;}
        }
        return f;
    }
};
