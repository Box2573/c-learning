- 明確型別轉換語法，告訴編譯器：「我想把這個值轉換成指定的型別。」
- 基本語法`static_cast< 目標型別 >(要轉換的值)`
- 隱式轉換也可以用但用static_cast是`明確告知`我要轉換
隱式轉換範例
```c++
int number = 10;
double result = number;  // 隱式轉換
```
static_cast範例
```c++
int number = 10;
double result = static_cast<double>(number);
```