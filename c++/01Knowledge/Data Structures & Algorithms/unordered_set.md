- c++的hash table實作讓你不用親自寫雜湊函數，也不必自己處理碰撞等底層工作
- 容器裡面的元素是唯一的，具有不重複的特性，而且是無排序的容器
- 容器裡面元素的值是不可修改，但容器可以插入或刪除元素
- 資料插入和查詢的時間複雜度很低，為常數級別O(1)
- 代價是消耗較多的記憶體，空間複雜度較高，無自動排序功能

初始化方法跟vector差不多只寫基本操作
``` c++
#include <iostream>
#include <unordered_set>

using namespace std;

int main()

{

    unordered_set<int> test;//初始化    

    test.insert(1);//插入元素

    test.insert(4);

    test.insert(3);

    test.insert(4);

  

    //輸出看一下因為沒有順序無法用test[i]取得某個位置的值

    for(int num : test)//每次從 test 取出一個元素，將它放進變數 num，執行一次迴圈內容，直到遍歷完所有元素

    {//如果今天不曉得值的類型是整數還是什麼可以用auto讓他自己判斷auto num : test

        cout << num <<endl ;

    }

  

    cout << test.count(3) <<endl; //判斷某個元素是否存在，有回傳1，沒有則0

  
  

    return 0;

}

```

可以看到我輸出該集合得到以下結果他不會照我insert的順序去輸出，也不會輸出重複的東西
```
3
4
1
```
