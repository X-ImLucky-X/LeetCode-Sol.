class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        if(n==1){
            return "1";
        }
        for(int i = 1 ; i<n ; i++){
            s = Giver(s);
        }
        return s;
    }

private:
    string Giver(string s){
        int j = 0;
        string st = "";
        //loop to give string
        while(j<s.length()){
            int count = 1; 
            char num;
            

            while((j+1 <s.length()) && (s[j] == s[j+1])){
                count++;
                j++;
                
            }

            num = s[j];
            st += to_string(count) + num; 
            j++;
        }
        return st;
    }
};