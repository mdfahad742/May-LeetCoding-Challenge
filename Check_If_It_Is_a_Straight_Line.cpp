#define ff first
#define ss second

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int n=c.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].ff=c[i][0];
            v[i].ss=c[i][1];
        }
        sort(v.begin(),v.end());
        
        double m=(v[0].ss-v[1].ss)/(1.0*(v[0].ff-v[1].ff));
        cout<<m<<endl;
        for(int i=2;i<n;i++){
            double m1=(v[0].ss-v[i].ss)/(1.0*(v[0].ff-v[i].ff));
            if(m1!=m)return 0;
        }
        return 1;
    }
};
