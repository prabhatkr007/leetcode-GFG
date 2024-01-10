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
    void traversal(TreeNode* root, vector<int> &ans){
        
        if(root == NULL) return;
        
        if(root-> left == NULL && root-> right == NULL){
            ans.push_back(root-> val);
            return;
        }
        
        traversal(root-> left, ans);
        traversal(root-> right, ans);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> lefnodes1, leafnodes2;
        
        traversal(root1, lefnodes1);
        traversal(root2, leafnodes2);
        
        return lefnodes1 == leafnodes2;
        
    }
};
