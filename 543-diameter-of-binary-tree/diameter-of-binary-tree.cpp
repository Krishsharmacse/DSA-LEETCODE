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
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        if((root->left==nullptr)&&(root->right==nullptr)){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if((root==nullptr)){
            return 0;
        }
         if((root->left==nullptr)&&(root->right==nullptr)){
            return 0;
        }
        int leftans = diameterOfBinaryTree(root->left);
        int rightans = diameterOfBinaryTree(root->right);
        int mid=height(root->left)+height(root->right);
        if(root->left!=NULL){
            mid++;
        }
        if(root->right!=NULL){
            mid++;
        }
        int maxi=max(leftans,max(rightans,mid));
        return maxi;
    }
};