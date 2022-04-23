class Solution {
private:
    unordered_map<string,string> code2url,url2code;
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
public:
    string getCode(){
        string ans="";
        for(int i=0;i<6;i++){
            ans+=chars[rand()%62];
        }
        return "http://tinyurl.com/"+ans;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(url2code.count(longUrl)) return url2code[longUrl];
        string code = getCode();
        while(code2url.count(code)) code = getCode();
        code2url[code]=longUrl;
        url2code[longUrl]=code;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return code2url[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));