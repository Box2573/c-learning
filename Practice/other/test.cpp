#include<iostream>
#include<memory>//要用智慧指標要引入memory

// class Test
// {
//     public:
//         Test()
//         {
//             std::cout << "這裡是建構子[建立] Test 物件誕生了！\n";
//         }

//         ~Test()
//         {
//             std::cout << "這裡是解構子[解構] Test 被自動釋放了！\n";
//         }

//         void doSomething()
//         {
//             std::cout << "!!! 程式運作中 !!!\n";
//         }

// }; 

void add (int &x)
{
    x += 100;
}


int main()
{
    // std::cout << "--- 主程式開始 ---\n\n";
    // //此用{}故意製造一個範圍
    // {
    //   std::cout << "進入了大括號範圍內...\n";  
    //   std::unique_ptr<Test> ptr = std::make_unique<Test>();    
    //   //unique_ptr<Test> ptr:宣告一個獨佔擁有Test的智慧物件
    //   //make_unique<Test>():建立(new)Test物件並把他給智慧指標管理

    //     ptr -> doSomething();

    //   std::cout << "即將離開大括號範圍...\n";

    // }//智慧指標在這個}後超出範圍觸發回收

    // std::cout << "\n已經離開大括號範圍了!\n";
    // std::cout << "--- 主程式結束 ---\n";

    int a = 0;
    add (a);
    std::cout << a << "\n";

    return 0;
}