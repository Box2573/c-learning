# Contains Duplicate

## 題目
Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true

Example 2:

Input: nums = [1, 2, 3, 4]

Output: false
### 限制
`0 <= nums.length <= 10^5`

`-10^9 <= nums[i] <= 10^9`

---

## 我的思考

### 暴力破解

想法：

最簡單的就是把每個元素都跟後面的比較一次，例如
nums = [1, 2, 3, 3]
就把1跟2、3、3比一次以此類推，感覺用兩個for即可

code:
```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    if(nums[i] == nums[j])
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution s;

    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 3, 4, 3};
    vector<int> nums3 = {1, 2, 3, 4, 6};

    cout << s.hasDuplicate(nums1) << endl;
    cout << s.hasDuplicate(nums2) << endl;

    return 0;
}
```
時間：

- i要執行n次
- j也執行n次
- 因此執行n*n次也就是n²次也就是O(n²)

空間：
每個變數都只佔用固定大小的記憶體因此是O(1)

### 暴力破解優化
想法:

試想 `i= 1` 此時 `j = 2` 那是不是 `num[1]` 和 `num[2]` 會進行比較，但現在 `i= 2` 此時 `j = 1` 時是不是 `num[2]` 和 `num[1]` 會進行比較那之前在`i = 1` 的時候不就比較過了所以會多比很多次，所以我們應該從 `j = i + 1` 之後再進行比較就好，畢竟比當前j小的i 那時候應該比較過一次了那既然沒有reture true不就代表兩者不同所以不用再比一次

改這裡就好:
```c++
 for(int j = i + 1; j < n; j++)
{
    if(i != j)
    {
        if(nums[i] == nums[j])
        {
            return true;
        }
    }
}
```

時間：
 >巢狀迴圈要算的是「最裡面那段程式總共被執行幾次」，例如這裡i已經被算在j裡面了，從下面表格就可以看到`每執行一次，一定是在某個 i 和某個 j 的組合下發生`
- j則比較複雜，我們可以列出來算一次假設n=5
    - j=i+1，並且j < n 因此執行次數列成表格如下

        | i | j的值 | 執行次數 |
        | :-| :---: | -----: |
        | 0 | 1,2,3,4 | 4 |
        | 1 | 2,3,4 | 3 |
        | 2 | 3,4 | 2 |
        | 3 | 4 | 1 |
        | 4 | 無 | 0 |
    - 可以看到執行次數就是`n-第幾次執行(i)`例如`i=0`第一次執行n-1執行4次，`i=1`第二次執行n-2執行3次，以此類推，因為他每一次都只要i + 1之後進行比較因此執行次數才會是n-第幾次執行
    -可以知道執行次數就是`(n-1) + (n-2) + ... + 2 + 1`
    可以知道總值行次數是`(((n-1) + 1) * (n-1)) / 2`，為什麼是(n-1)因為會有一個執行次數是0整理後得到n(n-1)/2
   

空間：
每個變數都只佔用固定大小的記憶體因此是O(1)

---

### 可以優化嗎？

可以利用什麼資訊？
- 可以用[[unordered_set]]因為他裡面不會存放重複的值，因此可以一邊把vector的值插入unodered_set，並在插入前先檢查該值是否已經存在該set有則回傳true
```c++
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
```


時間：
最多只要跑完一次陣列就可以得到答案因此是O(n)

空間：
如果vector有100個數值而且都不重複那set要insert100個數值有100個空間因此是O(n)
比較像用空間換時間的感覺

---

## 學到的新知識

- 解題網站雖然只給一個class例如
```c++
class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
     {
        
    }
};
```
我們通常都會寫到main()但解題網站自己有main他會去執行Solution class
，不過我們自己再寫還是可以把main寫進去比較好debug跟執行，之後要貼到網站只貼她預設那個class即可

