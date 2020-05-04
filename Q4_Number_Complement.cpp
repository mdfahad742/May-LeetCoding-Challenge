class Solution {
public:
    int findComplement(int num) {
        int ans=0,c=0,x=num;
        while(x>0){
            c++;
            x>>=1;
        }
        // cout<<c<<endl;
        for(int i=0;i<c;i++){
            if(num&(1<<i)){}
            else {
                ans+=1<<i;
            }
        }
        return ans;
    }
};
