#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int lengthName = name.size();
        int lengthTyped = typed.size();
        if (lengthTyped < lengthName) {
            return false;
        }
        bool ret = true;

        int name_p = 0;
        int typed_p = 0;
        while(name_p < lengthName && typed_p < lengthTyped) {
            char prev_char;
            if (name[name_p] == typed[typed_p]) {
                prev_char = name[name_p];
                name_p++;
                typed_p++;
            } else if (typed[typed_p] == prev_char) {
                typed_p++;
            } else {
                ret = false;
                break;
            }
        }
        if (name_p != lengthName)
            ret = false;
        for (int i = typed_p; i < lengthTyped; ++i) {
            if (typed[i]==name[lengthName-1]) {
                continue;
            } else {
                ret = false;
                break;
            }
        }
        printf("type_p = %d, name_p = %d\n", typed_p, name_p);
        // while(typed_p < )
        return ret;
    }
};

int main() {
    Solution s = Solution();
    string name = "alex";
    string typed = "aaleexa";
    cout<<s.isLongPressedName(name,typed)<<endl;
    return 0;
}