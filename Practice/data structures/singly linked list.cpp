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

class TasksList
{
    /*
        TODO
        addTask()在尾端新增任務 [o]
        displayTasks()顯示所有任務[o]
        findTask()根據 ID 搜尋任務[o]
        completeTask(id)更改指定任務的completed[o]
        insertTaskAfter(id)在指定任務後面插入新任務[]
        deleteTask(id)刪除指定任務[]
    */
    private:
        Tasks *head = new Tasks{0, "This is head", false, nullptr};//我想保留一個head永遠的head
        Tasks *tail;//用來在尾端新增節點    

    public:
        TasksList()
        {
            tail = head;//初始化tail指向head
        }
        ~TasksList()
        {
            //delete pointers
            delete head;

            Tasks *next = head -> next;
            while (next != nullptr)
            {
                Tasks *temp = next;
                next = next -> next;
                delete temp;     
            }

        }

        void addTasks(std::string titleNam)
        {
            //新增任務, id採自動增加
            tail -> next = new Tasks{tail -> id + 1, titleNam, false, nullptr};
            //把當前任務變成新增的那個
            tail = tail->next;
        }

        void displayTasks()
        {
            Tasks *next = head -> next;
    
            while (next != nullptr)
            {
                std::cout << std::format(
                    "id: {}, task name: {}, completed: {}\n", next -> id, next -> title, next -> completed
                );

                next = next -> next;        
            }
        }

        void findTask(int id)
        {
            Tasks *next = head -> next;

            while (next != nullptr)
            {
                if(next -> id == id)
                {
                   std::cout << std::format(
                    "已找到任務: id: {}, task name: {}, completed: {}\n", next -> id, next -> title, next -> completed
                    );

                    return;
                }
                else
                {
                    next = next -> next;
                }
            }
            
            std::cout << "該任務不存在\n";

        }

        void completeTask(int id)
        {
            Tasks *next = head -> next;

            while (next != nullptr)
            {
                if(next -> id == id)
                {
                    next -> completed = !(next -> completed);

                   std::cout << std::format(
                     "已把任務{} 狀態改為{}", next -> title, next -> completed ? "true" : "false"
                    );

                    return;
                }
                else
                {
                    next = next -> next;
                }
            }   

            std::cout << "該任務不存在\n";
        }

        void insertTaskAfter(int id, std::string titleNam)
        {
            Tasks *next = head -> next;

            while (next != nullptr)
            {
                if(next -> id == id)
                {
                    Tasks *temp = next;
                    next -> next = new Tasks{next->id + 1, titleNam, false, temp -> next};
                }
                else
                {
                    next = next -> next;
                }
            }

            std::cout << "該任務不存在\n";
        }
};

int main()
{
    TasksList tasksList;

    int caseId;
    

    while(true)
    {
        std::cout << std::format(
            "\n輸入要執行的行為\n"
            "0.新增任務\n"
            "1.顯示所有任務\n"
            "2.透過id找任務\n"
            "3.更改任務狀態\n"
            "4.插入任務\n"
            "5.刪除指定任務\n"
            "6.退出\n"
        );

        std::cin >> caseId;

        switch (caseId)
        {
            case 0://新增節點
            {
                //輸入任務
                //先不做輸入驗證假設我是使用者知道正確格式畢竟這不是練習目的
                std::string titleNam;
                std::cout << "輸入任務名稱: ";
                std::cin >> titleNam;
                tasksList.addTasks(titleNam);
                break;
            }
            case 1://顯示所有任務
                 tasksList.displayTasks();
                 break;
            case 2: //find task by id
            {//如果要在switch使用宣告變數要加上{}限制她的生命週期在這個{}內，避免沒進到該case但switch結束後還是呼叫了該變數的解構子
                int id;
                std::cout << "輸入任務id: ";
                std::cin >> id;
                tasksList.findTask(id);
                break;
            }
            case 3: //completeTask
            {
                int id;
                std::cout << "輸入任務id: ";
                std::cin >> id;
                tasksList.completeTask(id);
                break;
            }
            case 4: //insert
                break;
            case 5: //delete
                break;
            case 6://end
                return 0;
        }
    }

}