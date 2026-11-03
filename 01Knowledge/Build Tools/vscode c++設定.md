- 需裝vscdoe的c++ extension
- 還有安裝MinGW / g++並加入環境變數
- vscode按下f5進行編譯，第一次編譯時他會問你選什麼就選g++
	- 他會產生一個tasks.json
	- 如果不小心按到用gcc或是第一次編譯跳出問題可以去檢查tasks.json看看是不是不小心用成gcc是的話把`"command": "C:\\MinGW\\bin\\gcc.exe",`改為g++.exe，gcc是編譯c語言的
![[Pasted image 20261030204502.png||下面那個才是g++]]
## 直接使用f5處理編譯、執行
- 如果我的專案開在上層資料夾但要編譯的檔案再子資料夾這樣每次要編譯都還要手動cd進去該資料夾很麻煩，或是有很多的cpp時我都要自己用指令去編譯，我們也可以用f5去編譯
	- 例如我目前架構是這樣VS Code 開啟的是 `Project`，但實際專案在裡面的2d game
		- 我們可以透過告訴VS Code 的 `tasks.json` 與 `launch.json`
			- CMake 專案在哪裡
			- 要執行哪個編譯指令
			- 編譯完成後要啟動哪個 `.exe`
			- 就可以達到用f5編譯執行
### Task.json
- task.json一樣用f5可以產生一份此時不管他有沒有報錯我們來修改
	- 改了這些地方
	- type改為process表是執行外部程式
	- label方便方便 launch.json 呼叫改為Build 2D Game要跟 launch.json 裡的一樣
	- comand改為用cmake建制
	- args就是build的參數，command和args加起來就是`cmake --build build --parallel 4`
		- {workspaceFolder}表示vscode開啟的根工作區，在這個範例是project資料夾
	- option的cwd是在設定當前工作資料夾，就是build資料夾會產生在哪個位置，程式要在哪執行，這個例子是在根目錄下的2d game因此是{workspaceFolder}/2d game
	- detail修改說明
	- 此時按下f5他會要你選擇用什麼編譯但g++是針對單一檔案的我們需要自己設定`launch.json`
		- `tasks.json`：負責編譯
		- `launch.json`：用來負責啟動遊戲與除錯
>[!warning] 執行這個f5編譯前要先確定有用cmake -S . -B build -G "MinGW Makefiles"產生build資料夾了
```c++

{
    "tasks": [
        {
            "type": "process",
            "label": "Build 2D Game",
            "command": "cmake",
            "args": [
                "--build",
                "${workspaceFolder}/2d game/build",
                "--parallel",
                "4"
            ],
            "options": {
                "cwd": "${workspaceFolder}/2d game"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Build using CMake"
        }
    ],
    "version": "2.0.0"
}
```

### launch.json
- 這個不用自己打一樣可以讓他自己產生一份再修改
	- 按下f5選擇`(gdb) Launch`就會產生一份launch.json
![[Pasted image 20261103205759.png|600]]
- 再來應該會跳出錯誤說什麼沒有launch.json04開啟後他又會叫你選一次，一樣選gdb
	- 因為環境是 MinGW GCC，使用 GDB 作為除錯器
	- 再來他應該會會建立 `launch.json`，並放入一份 C++ GDB 的基本除錯設定
 ![[Pasted image 20261103210227.png|600]]
 - 打開launch會發現建立的東西很少，此時可以去左邊的run and debug選擇create a launch.json她會跳到 launch.json並且可以選擇把gdb的設定帶入，再選擇launch那個
![[Pasted image 20261103210801.png]]
- 有改的地方
	- name：除錯設定的名稱，方便自己辨識改為`Run 2D Game`
	- program：要執行哪個程式，改為我們編譯出來的exe
	- cwd：一樣程式執行時的工作目錄
	- miDebuggerPath：GDB 的位置
- 新增的地方
	- `"preLaunchTask": "Build 2D Game"`在啟動 GDB 和執行遊戲之前，先執行指定的 Task，這裡的Build 2D Game要跟task.json的label名稱一樣，意思就是再執行前先執行task.json
```c++

{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Run 2D Game",
            "type": "cppdbg",
            "request": "launch",

            "program": "${workspaceFolder}/2d game/build/bin/CppSandbox.exe",

            "args": [],
            "stopAtEntry": false,

            "cwd": "${workspaceFolder}/2d game",

            "environment": [],
            "externalConsole": false,

            "MIMode": "gdb",
            "miDebuggerPath": "C:/MinGW/bin/gdb.exe",

            "preLaunchTask": "Build 2D Game",

            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Set Disassembly Flavor to Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}

```

- 再按下f5就有我們命名的可以選了但我不知道為什麼有兩份，反正都有prelaunch有救是先編譯再執行應該都可以
![[Pasted image 20261103211702.png]]