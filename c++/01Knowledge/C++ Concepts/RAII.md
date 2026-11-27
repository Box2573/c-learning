- 全名為**Resource Acquisition Is Initialization**
	- 直接從英文看就是資源獲取即初始化
- 把資源的取得與物件的生命週期綁定，讓物件建立時取得資源，物件銷毀時自動釋放資源
- 基本概念如下
1. **建立物件**
	1. 取得需要的資源，例如記憶體、檔案或鎖，可以透過constructor
2. **物件存在期間**
	1. 使用並管理這些資源
3. **物件銷毀**
	1. 透過 Destructor 自動釋放資源
- 智慧指標就是RAII的案例
```c++
{
    auto sword = std::make_unique<Sword>();

} // unique_ptr 銷毀，Sword 自動釋放
```
## RAII 的優點
- 不容易忘記釋放資源。
- 即使函式提前 return，物件離開作用域時仍會自動釋放資源。
- 發生例外時，堆疊解退也會呼叫物件的 Destructor。
- 將資源管理責任集中在物件本身。

[[Object Lifetime]]
[[物件的擁有關係（Ownership）]]
[[建立物件與智慧指標]]