- 他把每筆資料都包成一個node=一個node有data和指向下/上一個的node指標
- 她的特點
	- 記憶體空間不連續
	- 不用事先定義大小
	- 插入刪除中間資料時只要移動該筆資料的上/下一個指向其他node的指標即可，不用像array還要搬動其他筆資料
	- 但只在已經知道位置時，修改才會比較快(插入與刪除已知位置的元素很方便)
		- 在中間刪除、增加資料可以分兩個階段
			- 尋找階段:從 Head 開始走訪，找到目標位置，通常是`O(n)`
			- 修改階段:找到位置後，修改指標即可，通常是`O(1)`不像陣列要搬動其他資料
			- 從兩階段可以看出來優是在修改不是在找，因此速度快的前提建立在已經找到要的資料
	- 隨機存取不會比較快，畢竟他要從head開始往後找
- 似乎很少看到他
	- 因為有[[Vector]]她記憶體連續(這樣找資料可能比不連續的Linked List快)，又可以不用事先定義大小
	- Linked List每個詰點都要自己一行行手動建立
	- Linked List每筆資料的大小都比較大畢竟他包含data和指向其他資料的指標
	- 大部分時候，我們不需要頻繁在中間插入或刪除
		- 通常是遍歷、新增資料到最後面、頻繁讀取
- Linked List適合
	- 要大量在中間插入、刪除情境
		- 例如播放清單建立

#  Singly Linked List
- 單向的，顧名思義她的node只存一個指向下一個node的指標
- 最後一筆資料指向null
- 在c++中`forward_list`是Singly Linked List的應用
## Singly Linked List 練習
- 製作一個簡單的任務管理系統
- 可以新增任務、完成任務、刪除任務，以及查看目前所有任務
- 每個node要存的資料有
	-` int id`任務編號
	- `string title`任務名稱
	- `bool completed`任務是否完成
	- `* next `指向下個任務
- 需實作的功能
	- `addTask()`在尾端新增任務
	- `displayTasks()`顯示所有任務
	- `findTask()`根據 ID 搜尋任務
	- `completeTask(id)`將指定任務標記為完成
	- `insertTaskAfter(id)`在指定任務後面插入新任務
	- `deleteTask(id)`刪除指定任務
- 挑戰
	- 試著把node封裝在class，盡量不在main新增或直接操作node
### 直接在main操作做node寫法
```c++
#include<iostream>
#include<string>
#include <format>

struct Tasks
{
    int id;
    std::string title;
    bool completed;

    Tasks *next;
};

int main()
{
    //create
    Tasks *head = new Tasks{0, "Learn Pointer", false, nullptr};
    Tasks *second= new Tasks{1, "Practice Linked List", false, nullptr};
    Tasks *third = new Tasks{2, "Review Big-O", false, nullptr};

    head->next = second;
    second->next = third;

    //output
    Tasks *curTask = head;
    Tasks *nextTask = head;
    while (curTask != nullptr)
    {
        std::cout<< std::format
        (
            "id: {}  task name: {}\n", curTask->id, curTask -> title
        );

        nextTask = curTask -> next;
        delete(curTask);
        curTask = nextTask;
    }
    
}
```
### 嘗試封裝並提供對外操作

