/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original == NULL){
            return NULL;
        }
        
        if(original == target) return cloned;
        
        TreeNode* temp1 =  getTargetCopy(original -> left, cloned-> left, target);
        if(temp1) return temp1;
        TreeNode* temp2 =  getTargetCopy(original -> right, cloned-> right, target);
        
        if(temp2) return temp2;
        else return NULL;
        
        
    }
};