- 一旦引入std(標準函式庫)裡面可能有一堆函式表示他們都一起被引用進來
- 如果某天你剛好寫了個名字跟std裡面樣的函式可能會導致編譯器就會不知道該用哪一個，因而報錯，例如你寫了個count()但std裡面也有個count()會報錯
- 打上std::也比較好閱讀例如std::vector跟myProject::vector你可以以解單知道哪個是std裡的哪個是自己寫的
- `禁止在.h檔直接引入std`不然後續用到該.h檔的都會**被迫**一起引入導致後面有問題很難找
- 為什麼有`#include <vector>`還是要std::vector
	- `#include`就像把一本書給你
	- `std::vector`就像告訴你我要用該書的哪個章節
	- 如果不加std告訴他用誰的假設我今天include兩個庫他都有vector那就不知道該用誰的，就像今天有兩本書都有vector這個章節那我就要告訴編譯器我要用哪本的vector


### 折衷方法
- 只引入特定名稱例如只引入vector `using std::vector;`
- 把影響範圍限制在某個函數內這樣就不會汙染外部
```c++
	void myFunction() 
	{
	    using namespace std; // 只有在這個函數內有效
	    vector<int> v;
	} // 離開大括號後，using namespace 就失效了

```
