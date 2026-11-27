- 有時候輸出文字時可能需要跟著輸出一堆變數用cout可能要打一堆<<此時就可以用format
- format用法可以再文字中插入{}，並在最後打上變數名稱
- 要`#include <format>`
- 並且是`C++20`後才可用
```c++
#include <format>

 std::cout << std::format(
        "ID: {} | Task: {}\n", id, title
    );
```
- 可以指定精度、寬度、對齊、進位等格式做搭配
	- ` std::cout << std::format("{:.2f}", 3.14159);`
