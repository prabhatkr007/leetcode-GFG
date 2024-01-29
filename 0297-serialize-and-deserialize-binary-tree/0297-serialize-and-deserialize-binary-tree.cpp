/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        string s = "";
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++ ){
                auto node = q.front();
                q.pop();
                
                if(node == NULL) s.append("#,");
                else{
                    s .append(to_string (node -> val ) + ',');
                    q.push(node -> left);
                    q.push(node -> right);
;                }

            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode* > q;
         q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++ ){
                auto curr_node = q.front();
                q.pop();
                getline(s, str, ',');
               
                
               if(str == "#") {
                   curr_node -> left = NULL;
               }else{
                   
                    TreeNode* node = new TreeNode(stoi(str));
                    curr_node -> left = node;
                   q.push(node);
                   
               }
                getline(s, str, ',');

                 if(str == "#") {
                   curr_node -> right = NULL;
               }else{
                    TreeNode* node = new TreeNode(stoi(str));
                    curr_node -> right = node;
                   q.push(node);
                   
               }
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));