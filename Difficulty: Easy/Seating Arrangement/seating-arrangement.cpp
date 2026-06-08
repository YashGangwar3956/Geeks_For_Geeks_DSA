class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
          int count=0;
        
        int n=seats.size();
        
        if(k<=0) return true;
        
        if(n==1&&seats[0]==1&&k!=0) return false;
        bool l=true;
        bool r=true;
        for(int i=0;i<n;i++){
            l=true;
            r=true;
            if(i-1>=0&&seats[i-1]!=0) l=false;
            if(i+1<n&&seats[i+1]!=0) r=false;
            
            if(l&&r&&seats[i]!=1) {
                count++;
                i++;
                
            }
        }
        
        if(count>=k) return true;
        
        return false;
        
    }
};