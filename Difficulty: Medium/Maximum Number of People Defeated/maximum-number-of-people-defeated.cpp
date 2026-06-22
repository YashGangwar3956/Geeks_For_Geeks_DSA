class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
          int i = 1;
        int sum = 0;
        int cnt = 0;
        while(true){
            sum+=i*i;
            if(p>=sum){
                cnt++;
            }else{
                break;
            }
        i++;
        }
    return cnt;
    }
};
