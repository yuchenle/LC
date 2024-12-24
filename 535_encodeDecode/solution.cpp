#include <map>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
    int counter;
    unordered_map<string, string> mm;
public:
    Solution() :  counter(0) {}

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string str = "http://tinyurl.com/";
        str += std::to_string(counter);
        mm[str] = longUrl;
        return str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        // printf("decode, shortUrl is %s\n", shortUrl.c_str());
        assert(mm.find(shortUrl) != mm.end());
        return mm[shortUrl];
    }
};

int main() {
    Solution s = Solution();
    string str = "https://leetcode.com/problems/design-tinyurl";
    string shortened = s.encode(str);
    printf("shortened is %s\n", shortened.c_str());
    printf("converting to the original string, which is %s\n", s.decode(shortened).c_str());
    return 0;
}
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));