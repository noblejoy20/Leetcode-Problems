class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.length()<str2.length()) swap(str1,str2);
        if(str1.substr(0,str2.length())!=str2) return "";
        for(int i=str2.length();i>0;i--){
            
            if(str2.length()%i!=0) continue;
            string temp=str2.substr(0,i);
            int j=0;
            while(j+temp.length()<=str1.length() && str1.substr(j,temp.length())==temp){
                j=j+temp.length();
            }

            if(j>=str1.length()) return temp;

        }
        return "";
    }
};