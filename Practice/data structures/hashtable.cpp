#include <iostream>
#include <vector>
using namespace std;

class MiniHashSet
{
private:
    int SIZE;
    vector<int> table;//宣告一個當成hash table的集合
    vector<bool> occupied;//用來確認該位置是否被佔用了

public:
    MiniHashSet(int size)
    {
        SIZE = size;
        table.resize(SIZE);//重新定義vector大小
        occupied.resize(SIZE, false);//重新定義vector大小並全部都設為false
    }

    void insert(int key)//用來插入值
    {
        // TODO 1：
        // 3. 如果位置被占用，往下一格尋找，如果已經是最後一個空間例如index已經是10那就找回0，
        //可以把hash table想成一個環那這樣其實又可以用linked list實作
        // 4. 找到空位後存入 key
        int bucket = key % SIZE;    // 計算初始位置

        if(contains(key))//如果已存在，不必重複插入
        {
            return;
        }

        for(int step = 0; step < SIZE; step ++)
        {
            int index = (bucket + step) % SIZE;//這個寫法跟contain那邊一樣都是繞一圈往後找

            if(occupied[index] == false)//找到空位
            {
                //插進去
                table[index] = key;
                occupied[index] = true;//改為有東西了

                return;//把值插進去空位後停止往後搜尋
            }

        }
        

    }

    bool contains(int key)//查詢某個值是否存在
    {
        // TODO 2：
        // 1. 從 key 的初始位置開始，這樣就不用重頭找起，例如20好了，20%11得到9那他有可能會在9的位置
        // 2. 如果找到 key，回傳 true
        // 3. 如果遇到從未使用過的空位，回傳 false，例如有個數45%11也是1此時從1開始往後找找到第4個位置是空的那就可以知道45這個數沒有在此集合
        //但此做法的前提是該集合的數值都無法被刪除這個練習剛好沒有刪除的練習
        // 4. 如果遇到其他數字，繼續往下一格找，這就是有碰撞的時候，如果碰撞例如12、23、34都是1那根據線性探測法處理碰撞他們會
        //分別在1、2、3的位置，因此如果要找例如23有沒有存在就是從23%11 = 1 從1的位置開始往後找

        int bucket = key % SIZE;    
        // if(table[bucket] == key)舊的想法這個沒辦法滿足找到最後一個位置時又回頭檢查第一格並且只檢查SIZE次
        // {
        //     return true;//如果找到 key，回傳 true
        // }
        // else//有數值但不是我們想要的
        // {
        //     for(int i = bucket + 1; i < SIZE; i++)//開始往後檢查
        //     {
        //         if(table[i] == key)
        //         {
        //             return true;//如果找到 key，回傳 true
        //         }
        //         else if (occupied[i] == false)//如果沒東西就表示該數值不存在
        //         {
        //             return false;
        //         }
        //     }
        // }

        for (int step = 0; step < SIZE; step++)//找了SIZE次就停，剛好會是整個集合遍歷一次，例如有四個東西1、2、3、4
        {                                      //我從3開始找3、4就找了兩次了，又回頭找1、2又找了兩次，又回到3時此時找了的次數剛好是4就是整個SIZE 
            int index = (bucket + step) % SIZE;// bucket + step就是我在bucket位置往後走幾步一開始step = 0也就是第一次找不往後走在原地
                                               // % SIZE則是換算成在這個0~SIZE大小的格子的哪格例如10 + 3 = 13超r烏了這張表的大小
                                           // % SIZE = 2所以可以知道走回到了這張表的第2個位置
        
            if (occupied[index] == false)//如果該地方沒東西
            {
                return false;//就表示沒有該值
            }

            if(table[index] == key)
            {
                return true;//如果找到 key，回傳 true
            }
        }   
        return false;
    }
};

bool hasDuplicate(vector<int>& nums)
{
     MiniHashSet set(nums.size());

     for(int i = 0; i < nums.size(); i++)
     {
        if(set.contains(nums[i]))//如果該值存在表示重複
        {
            return true;
        }
       
        set.insert(nums[i]);//不存在就插入
     }

     return false;
}

int main()
{
    MiniHashSet set(11);

    set.insert(12);
    set.insert(23);
    set.insert(34);

    cout << set.contains(12) << endl;  // 預期 1
    cout << set.contains(23) << endl;  // 預期 1
    cout << set.contains(99) << endl;  // 預期 0

    //測試是否可以解決Contains Duplicate
    vector<int> nums1 = {1, 2, 3, 4, 5};//預期 0
    vector<int> nums2 = {1, 2, 3, 4, 3};//預期 1

    cout << "-------Contains Duplicate----------"<<endl;
    cout << hasDuplicate(nums1) << endl;
    cout << hasDuplicate(nums2) << endl;

    return 0;
}