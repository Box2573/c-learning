- Cmake定義建置規則，產生建置系統需要的檔案`(規劃)`
- 建置工具依照 CMake 產生的規則，**發號施令**並掌控整個編譯與連結的先後順序ex.MinGW 的 Make 建置工具`（指揮官）`
- g++編譯 C++ 程式`（實作者）`
- MinGW讓你在 Windows 環境中使用 **GCC / G++** 來編譯 C 與 C++ 程式，提供編譯器、連結器那些`(工具箱)`
- SFML也是個工具箱裝著一堆處理視窗、玩家輸出入的工具


- 查看是否有安裝CMake，沒有的話要去官網安裝
```c++
cmake --version
```
- VS Code 寫程式 → CMake 管理建置規則 → MinGW 的 `g++` 編譯與連結 → 產生 `pet.exe`。

## 建立建制規則
- 建立一個`CMakeLists.txt`大小寫盡量一樣，這是CMake預期辨識的設定檔名稱
	- 先用基礎三個指令
		- `cmake_minimum_required(VERSION 3.20)`指定專案要求的最低 CMake 版本
		- `project(DesktopPet LANGUAGES CXX)`設定專案名稱，並宣告使用 C++
		- `add_executable()`指定要產生的執行檔，以及它需要的 `.cpp` 檔案
			- 專案名稱和執行檔可以一樣，除非你可能是一個專案有一堆執行檔才要區分
```CMake
cmake_minimum_required(VERSION 3.20)

project(DesktopPet LANGUAGES CXX)

add_executable(pet
    main.cpp
    Pet.cpp
    Cat.cpp
    Dog.cpp
    PetManager.cpp
)//產生一個叫做 pet.exe的程式，而這個程式是由後面這 5 個 `.cpp` 檔案組合

```
- 如果標頭檔放在不同地方，編譯時顯示include找不到可以再include加上路徑名或是加上標頭檔位置資料夾
	- 例如我的標頭檔放在src的player資料夾下
	- 或自己手動打上路徑`#include "player/Player.hpp"`
```c++
target_include_directories(CppSandbox PRIVATE
    src/Player
)
```
- build方法
	- `-S .`：**Source（原始碼位置）**。告訴 CMake，我的 `CMakeLists.txt` 就在當前這個資料夾（`.` 代表目前路徑）
	- -  `-B build`：**Build（輸出的產物位置）**。告訴 CMake，把所有產生的暫存檔、Makefile 通通丟進一個叫做 `build` 的資料夾。**如果這個資料夾不存在，CMake 會自動幫你建立！**
	- 用`MinGW Makefiles`規則產出MinGW 版本的 Makefile
```
cmake -S . -B build -G "MinGW Makefiles"
```
- 如果想指定指定編譯器可在後面加`-DCMAKE_CXX_COMPILER=C:/MinGW/bin/g++.exe`
	- 如果是用visual studio她預設可能會用MSVC忽略MinGW此時想用mingw就要自己指定
```
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=C:/MinGW/bin/g++.exe
```
- 執行編譯
	- 請 CMake 幫我叫 `build` 資料夾裡設定好的呼叫`mingw32-make`出來編譯
```
cmake --build build
```
- 如果電腦有多核加上`--parallel`可以指定用幾核做並行處理(平常可能是1.cpp編譯完換2.cpp，現在多核可以同時進行)
	- 例如`--parallel 4`就是用4核
	- 也可以直接打-`-parallel`不加數字就是直接用所有可用的核心數
	- 也可以使用`-j`簡寫
```
cmake --build build --parallel 4
cmake --build build -j 4   //用j簡寫
```
- 執行
```
.\build\bin\pet.exe
```

### 如果build後有修改cpp怎麼辦
- 執行了`cmake -S . -B build -G "MinGW Makefiles"`後可以看成他已經寫好了一套規則，因此修改了cpp只需再跑一次bulid`cmake --build build`，mingw32-make 會去檢查所有檔案的修改時間，判斷哪些工作需要重新執行
- 如果修改`CMakeLists.txt`也不用跑`cmake -S . -B build -G "MinGW Makefiles"`一樣跑`cmake --build build`即可他如果自己發現`CMakeLists`改過他會自己先跑cmake -S那個一次












