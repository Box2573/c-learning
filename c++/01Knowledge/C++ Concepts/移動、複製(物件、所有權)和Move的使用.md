- 我們可以把一個物件的內容複製給另一個物件，但不同類別的複製行為可能有不同問題
- 例如我有個warrior是character物件，那在character有一個attack，character負責銷毀她
>Character 內部使用原始指標管理 Attack，預設複製只會複製指標地址，導致
>兩個 Character 可能共同指向同一個物件，導致 Double Delete
```c++
class Character
{
    private:
        Attack *attack;
        std::string name;

    public:
         Character(Attack *attack, std::string name):
            attack(attack),
            name(name)
        {
           
        }
        virtual ~Character()
        {
            delete attack;
        }
};

```
## Copy Constructor（複製建構子）
**建立新物件時，使用另一個已存在的物件作為來源**
- 如果我已經有一個warrior了，今天又新增一個another並直接把wairrior指定為她的來源，導致兩個character都以為自己要負責管理attack
- 如果character今天被銷毀就可能發生 Double Delete
```cpp
Character warrior(new Sword(), "Warrior");
Character another = warrior;
```
- 這樣構成複製建構子，等於再類別內宣告複製建構子時該做什麼，如果沒有打複製建構子行為編譯器會提供一個預設的`Character(const Character& other);`
	- 可以再複製時執行行為
	- `Character another = warrior;`寫法=`Character another(warrior);`
```c++
class Character
{
public:
    Character(std::string name)//普通建構子
    {
        std::cout << name << " created\n";
    }

    Character(const Character& other)//複製建構子
    {
        std::cout << "Character copied\n";
    }
};
```
- 來看複製建構子寫法
	- `Character` 建構子名稱
	- `const Character&` 要接收的物件，回傳一個character物件的參考，並不允許修改(const)
	- `other` 來源物件
## Copy Assignment Operator（複製賦值運算子）
**將一個已存在物件的內容，複製賦值(=的方式)給另一個已存在的物件**
- 今天我已經存在另一個character叫mage，我可能因為某些原因例如她轉職就直接把他變成warrior
	- 他跟複製建構子差別在於，複製建構子是在物件建立時就把另一個物件複製給他
- 一樣mage和warrior現在持有同個attack物件銷毀時會觸發Double Delete
```c++
Character warrior;
Character mage;

mage = warrior;
```
- 一樣這個做法也有一個寫法
```c++
Character& operator=(const Character& other);
```
- 寫法如下
	- `Character&` 回傳左側物件的參考從上面例子`mage = warrior`看就是mage這樣才可以達到連續賦值例如a=b=c
		- 先把c給b再把b存下來再給a再把a存下來
	- `operator=` 定義=要執行的行為
	- `const Character&` 要接收的物件，回傳一個character物件的參考，並不允許修改(const)

##  = delete（禁止使用函式）
- 為了避免Double Delete可以用=delete去禁止複製建構子、複製複執行運算子
```c++
Character(const Character&) = delete;
Character& operator=(const Character&) = delete;
```
- 可以看成當執行到複製建構子、複製複執行運算子時會直接報錯不免未來在執行程式時直接當機
- 如果只打一個例如我只打複製建構子=delete那複製複執行運算子就還可以用

## 避免double delete 
### 方法1 : Move Constructor 和 Move Assignment
- C++ 的物件移動機制，無論使用 Raw Pointer、智慧指標，甚至**一般物件**，都可以用
- 寫法如下複製建構子、複製複執行運算子很像
```c++
Character(Character&& other);
Character& operator=(Character&& other);
```
- Move Constructor：透過來源物件建立新物件，並轉移資源。
- Move Assignment Operator：將來源物件的資源轉移給已存在的物件。
- 常搭配`std::move(ptr);`使用，表示告知這個物件可以當成**可移動的來源**，他是使用Move Constructor
- 但如果自己沒有寫Move Constructor或Move Assignment實作他還是沒辦法轉移
	- 例如下面的copy constructor實作
```c++
Character(Character&& other)
    : currentAttack(other.currentAttack)
{
    other.currentAttack = nullptr;//清空來源物件的指標
}
```
- : currentAttack(other.currentAttack)這是建構子初始化列表寫法可以看[[一些名詞解釋(類別、物件、變數、方法、建構子、、指標)]]的建構子那裡也寫到該寫法
- 實際運用如下
```c++
Character warrior("Warrior");

// Move Constructor
Character mage(std::move(warrior));

Character archer("Archer");

// Move Assignment
archer = std::move(mage);
```
>move不是指標專用，一般物件也可以當一個物件即將把自己的資料或資源交給另一個物件，而且後續不再需要保留原本的值時，就可以考慮使用 Move
- 例如下面建構子我在建構該class時傳入一個name為string但如果直接接收`name(name)`他會產生一次複製，可以理解為
	- `myName`接收原本字串持有的資源
	- 不需要重新複製整份字串內容
	- `name` 仍然是一個有效的 `std::string` 物件，但移動後的值不應假設為原本的內容
```c++
Character(std::unique_ptr<Attack> attackMethod, std::string name):
    attack(std::move(attackMethod)),
    myName(std::move(name))
{
}
```

### 方法2 : 智慧指標
- 傳統指標會複製指標地址，因此如果兩個物件都認為自己擁有指標物件，銷毀時就可能發生 Double Delete
- 因此可以改用[[建立物件與智慧指標]]
- 如果上面例子character採用智慧指標保存attack
	- 那就不用擔心double delete
	- Character 的預設複製建構子與複製賦值運算子也會因為成員不可複製而無法使用
		- 不用自己再寫禁止這兩個複製操作
```c++
std::unique_ptr<Attack> attack;
```
- 智慧指標轉移時可以直接用`std::move(ptr);`不用自己再寫Move Constructor 和 Move Assignment，智慧指標通常有提供
	- 無論是方法1還是方法2用的`std::move(ptr);`都是一樣的