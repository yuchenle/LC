#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
    	unordered_map<int> im;
    	for (int i = 0; i < nums.size(); ++i) {
    		im[nums[i]]++;
    	}
    	for (auto element : im) {
    		if (element.second % 2 != 0)
    			return false;
    	}
    	return true;
    }
};