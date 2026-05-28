/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
   void solve(Node* root,map<int,int>&col,int c){
       if(!root)return;
       col[c]+=root->data;
       solve(root->left,col,c-1);
       solve(root->right,col,c+1);
   }
    vector<int> verticalSum(Node* root) {
        // code here
        map<int,int>col;
        solve(root,col,0);
        vector<int>ans;
        for(auto i:col){
            ans.push_back(i.second);
        }
        return ans;
    }
};