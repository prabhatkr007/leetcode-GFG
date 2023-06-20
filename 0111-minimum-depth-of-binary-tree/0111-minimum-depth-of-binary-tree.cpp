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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int leftdepth = minDepth(root -> left);
        int rightdepth = minDepth(root -> right);
        
       
        if(root -> left == NULL){
            return rightdepth +1;
        }
        
         if(root -> right == NULL){
            return leftdepth +1;
        }
        
        return min(leftdepth, rightdepth) +1;
        
       
        
    }
};