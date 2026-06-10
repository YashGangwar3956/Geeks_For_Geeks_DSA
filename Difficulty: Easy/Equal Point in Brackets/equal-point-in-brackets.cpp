class Solution {
  public:
    int findIndex(string &str) {
        // code here
         int count = 0;
        for(int i=0; i<str.length(); i++){
            char ch = str[i]; 
            if(ch==')') count++;
        }
       return count;
    }
};