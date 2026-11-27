假設今天player持有weapon有下面寫法
- player直接包含一個weapon物件
- 今天player被delete該player物件也就沒了
- 同理player生成他就生成不用額外管理
- Player 直接擁有自己的 Weapon 物件
```c++
class Player
{
private:
    Weapon weapon;
};
```
- 另一種
- 記錄的是某個 `Weapon` 物件的記憶體位置
- 不代表擁有物件
- player不一定負責銷毀該物件，如果該物件被銷毀可能只留下記憶體位置，變成懸空指標
- 不算完全持有該物件只能算裝備該物件
> 能夠使用某個物件，不代表你擁有它
- 用指標才能實現多型[[繼承與類別外定義與多型與抽象類別]]
```c++
class Player
{
private:
    Weapon* weapon;
};
```
> 這個物件是誰建立、誰擁有

- 看一個情況
	- Character 持有 Attack 指標但不代表character擁有attack
	- 就算今天warrior不應該直接銷毀attack，畢竟mage還在用
	- 這可以看出來物件所有權歸誰
		- **使用（Use）**：Character 可以透過指標呼叫 Sword 的功能
		- **擁有（Ownership）**：Character 是否負責 Sword 的生命週期，並在適當時機釋放它
```c++
class Character 
{
private:
    Attack* attack;
};

int main()
{
    Attack* sword = new Sword();

    Character warrior(sword);
    Character mage(sword);
}
```
##  可能的設計
### Character 各自擁有 Attack
- 每個角色都有自己的 Attack 實例，Character 負責管理自己的資源。
	- 沒有其他地方負責 `delete`，Sword 就會造成 Memory Leak
```c++
int main()
{
    Attack* swordA = new Sword();
    Attack* swordB = new Sword();

    Character warrior(swordA);
    Character mage(swordB);
}
```
### 由外部管理 Attack
- Character 只使用 Attack，不負責銷毀它
```c++
int main()
{
    Attack* sword = new Sword();

    Character warrior(sword);
    Character mage(sword);
    
    delete(sword);
}
```
### 共享所有權
- 兩個 Character 都持有共享所有權，最後一個持有者離開時才釋放資源
```c++
int main()
{
	auto sword = std::make_shared<Sword>();
	
	Character warrior(sword);
	Character mage(sword);
}
```
> 每個動態資源都應該有明確的管理責任。需要知道誰負責釋放資源，以及資源的生命週期由誰控制

## 相關
[[Object Lifetime]]
[[RAII]]
[[建立物件與智慧指標]]