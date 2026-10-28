#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        int n = nums.size();
        unordered_set<int> mySet;


        for(int i = 0; i < n; i++)
        {
            if(mySet.count(nums[i]))//先檢查set是否有該值
            {
                return true;//有回傳true
            }
            mySet.insert(nums[i]);//沒有則把該值插入set
        }

        return false;
    }
};

int main()
{
    Solution s;

    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 3, 4, 3};

    cout << s.hasDuplicate(nums1) << endl;
    cout << s.hasDuplicate(nums2) << endl;

    return 0;
}