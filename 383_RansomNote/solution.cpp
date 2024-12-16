#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int length1 = ransomNote.size();
        int length2 = magazine.size();

        int magaChars[26] = {0};
        for (int i = 0; i < length2; ++i) {
            magaChars[magazine[i]-'a']++;
        }
    }
};

int main() {

}