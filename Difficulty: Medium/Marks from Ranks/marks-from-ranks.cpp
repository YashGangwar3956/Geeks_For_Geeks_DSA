class Solution {
  public:
    virtual vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank){
      map<int, pair<int, int>> lim_st_pos;

      vector<int> rng;
      int init=0;
      for(int i=0; i<l.size(); i++){
        int key=r[i]-l[i]+1;
        lim_st_pos[init+key] = {l[i], init+1};
        rng.push_back(init+key);

        init+=key;
      }



      vector<int> ans;

      for(int rk: rank){
        int ind = lower_bound(rng.begin(), rng.end(), rk) - rng.begin();
        int key = rng[ind];

        auto [st, pos] = lim_st_pos[key];
        int req = rk-pos;

        ans.push_back(st+req);

      }


      return ans;


    }
};