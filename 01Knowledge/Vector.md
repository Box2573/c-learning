- 她的大小不用一開始就定義
- 有很多很用的函式例如可以
	- 直接用size()取得大小
	- 可以直接在尾端插入push_back(val)
	- 可以再指定位置插入insert(pos, val)
	- 刪除特定位置元素erase(pos)
	- 查看是否為空用empty()會回傳true or false
	- 要引入vector標頭檔
- 如果要比較size()他是回傳無號整數跟有號整數比較可能會有問題
	- 可以用`size_t`而不是用int去宣告
```c++
	for (std::size_t i = 0; i < pets.size(); i++)
```
- 下面例子
	- vector是存pet的記憶體位置
	- 如果寫`vector<Pet> *petShop;`會變成宣告一個變數去紀錄一個vector位置而該位置是存pet不是pet的位置
	```c++
int main ()
{
    Cat myCat("Mimi");
    Dog myDog("Bobo");
    vector<Pet*> petShop;

    petShop.push_back(&myCat);
    petShop.push_back(&myDog);

    for(Pet *pet : petShop)//petshop裡面存的是pet的記憶體位址因此要存取這裡的變數也要是記憶體位置
    {
        pet -> eat();
        cout << "名稱:" << pet -> getName() << " 飢餓度: " << pet -> getHungry() << endl;
    }

    return 0;
}
	```