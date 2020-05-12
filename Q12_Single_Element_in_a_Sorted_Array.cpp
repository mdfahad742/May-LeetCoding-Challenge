// Tricky
// Idea - if mid is odd then and f1 is true, then the element must lie in the right half and vice versa.

// O(Log N)
class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int l=0,n=a.size(),r=n-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            bool f1=0,f2=0;
            if(mid>=1 && a[mid-1]==a[mid])f1=1;
            if(mid+1<n && a[mid+1]==a[mid])f2=1;
            
            if(!f1 && !f2)return a[mid];
            
            if(f1){
                if(mid&1)l=mid+1;
                else r=mid-1;
            }
            else if(f2){
                if(mid&1)r=mid-1;
                else l=mid+1;
            }
            
        }
        return -1;
        
    }
};
