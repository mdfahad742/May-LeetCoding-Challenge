// O(N*26) - Sliding Window Technique (Standard)

#define ff first
#define ss second
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(s.size()<p.size())return {};
        
        map<char,int> mp1;
        map<char,int> mp2;
        for(auto ch:p)mp1[ch]++;
        
        
        for(int i=0;i<p.size();i++)mp2[s[i]]++;
        
        
        
        vector<int> v;
        bool f1=1;
        for(auto it:mp1){
            if(mp2[it.ff]!=it.ss){
                f1=0;
                break;
            }
        }
        if(f1)v.push_back(0);
        
        for(int i=p.size();i<s.size();i++){
            mp2[s[i-p.size()]]--;
            mp2[s[i]]++;
            bool f=1;
            for(auto it:mp1){
                if(mp2[it.ff]!=it.ss){
                    f=0;
                    break;
                }
            }
            if(f)v.push_back(i-p.size()+1);
        }
        
        return v;
    }
};
