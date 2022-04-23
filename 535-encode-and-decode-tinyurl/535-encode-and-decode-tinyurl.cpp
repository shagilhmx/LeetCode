class Solution {
    private:
        char getRandom() {
            int minUpCharRange = 'A';
            int maxUpCharRange = 'Z';
            int minCharRange = 'a';
            int maxCharRange = 'z';
            int minRange = '0';
            int maxRange = '9';
            
            int random[3];
            
            random[0] = (int)(rand() % (maxUpCharRange - minUpCharRange) + minUpCharRange);
            random[1] = (int)(rand() % (maxCharRange - minCharRange) + minCharRange);
            random[2] = (int)(rand() % (maxRange - minRange) + minRange);
            
            int choice = (int) rand() % (2 - 0) + 0;
            
            return (char)(random[choice]);
        }
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string, string> mpp;
    string tinyUrl = "http://tinyurl.com/";
    string encode(string longUrl) {
        
        while(tinyUrl.length() < 25) {
            tinyUrl += getRandom();
        }
        
        mpp[tinyUrl] = longUrl;
        cout<<tinyUrl<<endl;
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));