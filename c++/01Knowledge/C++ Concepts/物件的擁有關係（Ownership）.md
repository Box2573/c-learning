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
- player不一定負責銷毀該物件，如果該物件被銷毀可能指向null
- 不算完全持有該物件只能算裝備該物件
- 用指標才能實現多型[[繼承與類別外定義與多型與抽象類別]]
```c++
class Player
{
private:
    Weapon* weapon;
};
```