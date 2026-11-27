- 物件活多久
- 常見有兩種
- 可以看[[建立物件與智慧指標]]
## 區域物件
- 離開區域就會自動銷毀，不需要你手動 delete
```c++
void createCharacter()
{
    Character warrior("Warrior");
} // 離開函式，warrior 自動銷毀
```

## 動態配置物件
- 用new動態配置的物件，離開不會自動銷毀要自己手動delete，或交給智慧指標管理
```c++
void createCharacter()
{
    Character* warrior = new Character("Warrior");

    delete warrior;
}
```

## 相關
[[物件的擁有關係（Ownership）]]
[[RAII]]