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