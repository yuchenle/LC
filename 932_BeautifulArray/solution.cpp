#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:

    bool verify(vector<int>& arr, int &ret_i, int &ret_k, int &ret_j) {
        int length = arr.size();
        for (int i = 0; i < length; ++i) {
            for (int j = length - 1; j > i; --j) {
                for (int k = i+1; k < j; ++k) {
                    if (2*arr[k]==arr[i]+arr[j]) {
                        ret_i = i;
                        ret_k = k;
                        ret_j = j;
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void swap(vector<int>& arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    inline string arrToString(vector<int>& arr, int n) {
        string str="";
        for (int i = 0; i < n; ++i) {
            str += arr[i];
        }
        return str;
    }

    vector<int> beautifulArray(int n) {
        unordered_map<string, int> setVisited;

        vector<int> ret1(n,0);
        string val = "";
        for (int i =0; i < n; ++i) {
            ret1[i]=i+1;
            val += std::to_string(i+1);
        }

        setVisited[val]=1;

        while(1) {
            int temp_i,temp_k,temp_j;
            if (verify(ret1, temp_i, temp_k, temp_j)==false) {
                swap(ret1,temp_i, temp_k);
                string str1 = arrToString(ret1,n);
                if (setVisited.find(str1) != setVisited.end()) {
                    swap(ret1, temp_k, temp_j);
                    string str1 = arrToString(ret1,n);
                    if (setVisited.find(str1) != setVisited.end()) {
                        swap(ret1, temp_i, temp_j);
                    }
                }
                setVisited[str1]=1;
            } else {
                return ret1;
            }
        }
        return ret1;
    }
};

int main() {
    Solution s = Solution();
    auto res = s.beautifulArray(100);
    for (auto elem : res) {
        printf(" %d ", elem);
    }

    printf("\n");

    return 0;
}