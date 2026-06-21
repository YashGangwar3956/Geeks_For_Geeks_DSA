class Solution {
  public:
    string chooseSwap(string &s) {
        vector<int> freq(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        
        int c=0,i=0;// c is smallest optimal character you can swap with
        char swap1=' ',swap2=' ';
        while(i<n){
            if(s[i]-'a'>c){
                if(freq[c]>0){
                    swap1='a'+c;
                    swap2=s[i];
                    break;
                }
                c++;
            }
            else{
                c=s[i]-'a'+1;
                i++;
            }
        }
        if(swap1!=' '){
            for(int i=0;i<n;i++){
                if(s[i]==swap1)
                    s[i]=swap2;
                else if(s[i]==swap2)
                    s[i]=swap1;
            }
        }
        return s;
    }
};