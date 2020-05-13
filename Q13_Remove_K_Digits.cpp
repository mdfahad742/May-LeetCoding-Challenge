class Solution {
public:
    string removeKdigits(string s, int k) {
        
        vector<vector<int> > v(10);
        int n=s.size();
        
        for(int i=0;i<n;i++){
            v[s[i]-'0'].push_back(i);
        }
        
        int len=n-k;
        string ans="";
        int ind=-1;
        while(len>0){
            // cout<<len<<endl;
            for(int i=0;i<=9;i++){
                // auto it2=it.second;
                // int pos=*(it2.begin());
                int pos=(upper_bound(v[i].begin(),v[i].end(),ind))-v[i].begin();
                
                
                if(pos==v[i].size())continue;
                pos=v[i][pos];
                // cout<<i<<" "<<pos<<" "<<len<<endl;
                // ind=pos;
                if(pos>ind && n-pos>=len){
                    ind=pos;
                    if(s[ind]=='0' && ans.size()==0){len--;break;}
                    ans+=s[ind];
                    len--;
                    break;

                }
                // len--;
            }
        }
        if(ans.size()==0)return "0";
        
        
        return ans;
    }
};
