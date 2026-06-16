class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &q) {
        // code here
         vector<int> ans;
        int XOR = 0;
        for(int i = q.size()-1; i >= 0; i--)
        {
            int op_type = q[i][0];
            int val     = q[i][1];
            if(op_type == 0)
            {
                ans.push_back(val^XOR);
            }
            else
            {
                XOR = XOR^val;  
            }
        }
        ans.push_back(0^XOR);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
