class Solution {
  public:
    int transform(string &A, string &B) {
        // code here
        unordered_map<char,int>unm;
        for(int i=0;i<A.length();i++){
            unm[A[i]]++;
        }
        for(int i=0;i<B.length();i++){
            unm[B[i]]--;
        }
        for(auto i:unm){
            if(i.second!=0)return -1;
        }
        int i=A.length()-1;
        int j=B.length()-1;
        int count=0;
        while(i>=0 && j>=0){
            if(A[i]==B[j]){
                i--;
                j--;
            }
            else{
                count++;
                i--;
            }
        }
        return count;
    }
};
