/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=-1,p=-1;
    
    void dfs(TreeNode* root,int x,int d,int pa){
        if(!root)return;
        if(root->val==x){ans=d;p=pa;return;}
        dfs(root->left,x,d+1,root->val);
        dfs(root->right,x,d+1,root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,0,-1);
        int op1=ans,pa1=p;
        dfs(root,y,0,-1);
        int op2=ans,pa2=p;
        return op1==op2 and pa1 != pa2;
    }
};
