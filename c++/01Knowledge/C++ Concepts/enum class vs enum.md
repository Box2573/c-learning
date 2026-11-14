- 新的c++可以用enum class本質上和enum用法一樣只是可以避免
	- 命名衝突例如
		- 我有兩個enum一個food裡面有apple
		- 另一個breakfast也有apple那你用apple她怎麼知道你要用誰的
		- 因此enum class規定要打上這個誰的例如`fruit::apple`
	- 避免隱式轉型
		- 傳統enum換把內容轉成int，例如`1 + apple`，這樣可能會不小去做加減或是比較造成不必要的問題
		- enum class則不能這樣用
		- enum class要轉成整數要用`static_cast<int>`[[使用static_cast轉變型態]]轉型
```c++
enum class fruit
{
    apple,
    banana
};

int main()
{
    fruit breakfast = fruit::apple;//使用時要加這是誰的也就是用::
    return 0;
}
```
- enum class預設型態是int可以改成你要的例如改成`char(字元)`
```c++
enum class fruit : char
{
    apple = 'a',
    banana = 'b'
};

int main()
{
    fruit breakfast = fruit::apple;//使用時要加這是誰的也就是用::
    std::cout << static_cast<char>(breakfast);//轉成字元輸出
    return 0;
}
```