- 有時候可能需要用到新的c++內容
	- 例如我想用println但他是c++23之後才有
- 所以我們要來改變編譯時的c++版本
	- 可以分成有用Cmake和沒有
### 有用Cmake
- cmake應該會有這兩行
	- 把`17`改成`23`就表示我要用c++23
```c++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```
### 沒有用Cmake
- 如果是自己手動打g++編譯可以加入`-std=c++23`告訴他我要用的版本
	- `g++ -std=c++23 -g main.cpp -o main.exe`
- 或試按f5的話可以改`tasks.json`
	- "args":新增`"-std=c++23"`
	- 這串參數等於我直接手動g++
	- "-g"為產生除錯資訊
```c++
"args": [
    "-g",
    "-std=c++23",
    "-fdiagnostics-color=always",
    "${file}",
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}.exe"
]
```
- 改好後vscdoe可能還是會 把新版函式庫內容標示成錯誤或是無法正常完整補全
- 因為也要告訴vscode我們要用的版本
- 修改`c_cpp_properties.json`在`"configurations"`加入`"cppStandard": "c++23"`
```c++
"configurations": [
        {
            "name": "Win32",
            "compilerPath": "你的 g++.exe 路徑",
            "cppStandard": "c++23",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
```
- 之後要用f5 debug我們要確定她是用我們改過的`tasks.json`因此要去新增並指定`launch.json`指定`tasks.json`[[vscode c++設定]]並且`tasks.json`的label要對應`launch.json`的preLaunchTask，二下f5兩者才會連起來

### 錯誤
- 如果改完`tasks.json`和`launch.json`但一樣編譯時會報錯那可以加入``libstdc++exp``
	- 因為部分 Windows 終端輸出實作放在 `libstdc++exp` 這個實驗性函式庫中所以可能還是要連結才有辦法用
	- 他要加在目標檔案之後也就是`g++ -std=c++23 -g main.cpp -o main.exe -lstdc++exp`
	- 在`tasks.json`一樣加在`args`最後
```c++
"args": [
    "-g",
    "-std=c++23",
    "-fdiagnostics-color=always",
    "${file}",
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}.exe"
    "-lstdc++exp" //這裡
]
```
```
