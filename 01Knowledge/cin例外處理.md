- 如果我今天有個cin給一個變數型態是int的變數a，但傳入是字串那這時候我們就要處理
	```c++
	if (!(std::cin >> petId))//偵測是否錯誤，如果今天錯誤會回傳failbit可以看成式false
	{
	    std::cout << "輸入格式錯誤，請輸入數字。\n";
	}
	```
- 再來確認錯誤後還是要讓使用者重新輸入對吧因此要清空當成輸入的東西
```c++
	#include <limits>//要使用該標頭檔

	std::cin.clear();//清除錯誤狀態
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
	//清空當前輸入輸入長度是numeric_limits<std::streamsize>::max()也就是這個能輸入的最大值或
	//碰到\n為止(直到換行為止)
	
```
- 上面方法是在判斷型態錯誤->就是如果我要整數但輸入字串的錯誤
- 那如果是型態正確但範圍錯呢這樣就更簡單用一個if去判斷cin的值即可
	- 假設a要介於0~100
```c++
if (a => 0 || a <= 100)
 { 
	 std::cout << "輸入錯誤！a必須在 0 到 100 之間。\n"; 
	 std::cout << "請重新輸入: ";
	 std::cin >> a; 
 }
```
- 型態正確但範圍錯和型態錯誤是可以結合的只要再加入一個條件即可
```c++
if (!(std::cin >> a) || a => 0 || a <= 100)
 { 
	 std::cout << "輸入無效！請重新輸入一個 1~10 的數字: \n"; 
	 std::cout << "請重新輸入: ";
	 std::cin.clear(); //重設 cin 的狀態，讓它恢復正常運作
	 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//吃掉緩衝區裡所有錯誤的垃圾字元，直到換行為止
	 std::cin >> a; 
 }
```

- 但如果你用if去寫她只能判斷一次是否輸入錯誤如果今天有人就故意一直輸入錯誤的就不行
	- 因此改用迴圈while並把判斷型態正確但範圍錯和型態錯誤結合
		- 由於`cin`已經被寫在while裡面了因此在while的大括號不用再自己寫`cin`不然會變成輸入兩次才檢查一次
		- 邏輯就是當今天輸入的不是我想要的東西才會去執行while裡的東西，b徂果輸入是正確的那他會跳出while
```c++
#include <limits>

while (!(std::cin >> a) || a < 0 || a > 100)//這邊用<0 > 100才是判斷a是否介於0~100
 { 
	 std::cout << "輸入無效！請重新輸入一個 1~10 的數字: \n"; 
	 std::cout << "請重新輸入: ";
	 std::cin.clear(); //重設 cin 的狀態，讓它恢復正常運作
	 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//吃掉緩衝區裡所有錯誤的垃圾字元，直到換行為止
 }

```
- 或可以不要把條件都放在while改用if比較易懂
	- 在 `if` 條件裡的 `cin` 如果單獨存在（例如 `if (cin)`），它代表檢查目前的輸入流是不是正常的
	- if判斷就不是檢查反例而是直接判斷>=0 <= 100，而且是所有條件成立才break
```c++
 //也可以改成判斷條件對就跳出迴圈
 while (true)
 { 
	 cin >> a;
	 
	 if(std::cin && num >= 0 && num <= 100)//// 用 if 判斷：如果輸入成功，而且數字在 0~100 之間
	 {
		 break;//跳出迴圈
	 }
 
	 //如果能走到這一步，代表上面的 if 沒過（輸入錯誤或超出範圍）
	 std::cout << "輸入無效！請重新輸入一個 1~10 的數字: \n"; 
	 std::cout << "請重新輸入: ";
	 std::cin.clear(); //重設 cin 的狀態，讓它恢復正常運作
	 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//吃掉緩衝區裡所有錯誤的垃圾字元，直到換行為止
 }
```