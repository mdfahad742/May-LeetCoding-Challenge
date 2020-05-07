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
    
    void depth(TreeNode* root,int x,int d,int pa){
        if(!root)return;
        if(root->val==x){ans=d;p=pa;return;}
        depth(root->left,x,d+1,root->val);
        depth(root->right,x,d+1,root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        depth(root,x,0,-1);
        int op1=ans,pa1=p;
        depth(root,y,0,-1);
        int op2=ans,pa2=p;
        return op1==op2 and pa1 != pa2;
    }
};
