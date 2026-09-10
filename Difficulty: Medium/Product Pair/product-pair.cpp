class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_map<int,int>ump;

              for(int i = 0; i< arr.size();i++){
                  if(ump[arr[i]])
                      return true;

                  if(arr[i] == 0){
                      ump[INT_MIN] = 0;
                  }
                  else if(target % arr[i] == 0){
                      ump[target/arr[i]] = arr[i];
                  }
              }
              if(ump[INT_MIN]== target)
                  return true;
              return false;
    }
};