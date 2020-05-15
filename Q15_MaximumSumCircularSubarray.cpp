// NICE QUESTION
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n=A.size(),sum=0;
        
        int sum_so_far=0,ans1=INT_MIN;
        for(int i=0;i<n;i++){
            sum_so_far+=A[i];
            // cout<<sum_so_far<<endl;
            ans1=max(ans1,sum_so_far);
            if(sum_so_far<0)sum_so_far=0;
        }
        
        for(int i=0;i<n;i++){A[i]=-A[i];sum+=(-A[i]);}
        
        sum_so_far=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            sum_so_far+=A[i];
            // cout<<sum_so_far<<endl;
            ans=max(ans,sum_so_far);
            if(sum_so_far<0)sum_so_far=0;
        }
        
        if(ans1<0)return ans1;
        
        return (sum+ans>ans1)?(sum+ans):ans1;
    }
};
