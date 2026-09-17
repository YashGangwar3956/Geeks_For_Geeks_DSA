/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
  void traverse(Node* root,vector<int>&inorder){
         if(!root)return;
         traverse(root->left,inorder);
         inorder.push_back(root->data);
         traverse(root->right,inorder);
     }
    int absDiff(Node *root) {
        // code here
        vector<int>v;
                traverse(root,v);
                int ans=INT_MAX;
                for(int i=1;i<v.size();i++){
                    ans=min(ans,v[i]-v[i-1]);
                }
                return ans;
    }
};