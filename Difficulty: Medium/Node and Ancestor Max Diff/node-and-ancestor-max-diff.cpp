/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
   int solve(Node* root,int &ans)
   {
       if(!root) return INT_MAX;
       int l = solve(root->left,ans);
       int r = solve(root->right,ans);
       int mn = min(l,r);
       ans = max(ans,root->data - mn);
       return min(mn,root->data);
   }
    int maxDiff(Node* root) {
        // code here
        int ans = -1e9;
        solve(root,ans);
        return ans;
    }
};