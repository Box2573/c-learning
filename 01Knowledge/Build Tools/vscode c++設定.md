- 需裝vscdoe的c++ extension
- 還有安裝MinGW / g++並加入環境變數
- vscode按下f5進行編譯，第一次編譯時他會問你選什麼就選g++
	- 他會產生一個tasks.json
	- 如果不小心按到用gcc或是第一次編譯跳出問題可以去檢查tasks.json看看是不是不小心用成gcc是的話把`"command": "C:\\MinGW\\bin\\gcc.exe",`改為g++.exe，gcc是編譯c語言的
![[Pasted image 20261030204502.png||下面那個才是g++]]
