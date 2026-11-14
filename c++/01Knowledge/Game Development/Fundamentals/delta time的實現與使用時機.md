- sfml實現delta time很簡單
- delta time就是上一個frame到這個frame經過的時間消除掉了電腦性能的誤差ex.
	- $$\text{實際位移量} = \text{速度（每秒幾像素）} \times \Delta t\text{（秒）}$$
	- 如果速度是 `300 像素/秒`，而這一幀經過了 `0.016 秒`：
	- 這一幀角色實際移動的距離就是 $300 \times 0.016 = 4.8$ 像素。
實現方法
- 宣告一個clock，clock可以看成被宣告後就開始計時
- 在遊戲迴圈使用restart()，表示
	- 停止計時
	- 回傳一個從上一次計時到停止經過的時間
	- 重新計時
- asSeconds() 轉成秒數
```c++
sf::Clock clock;
while (window.isOpen())
{
	float deltaTime = clock.restart().asSeconds();//計算delta time
}
```

## 使用時機
- 通常和速度相關例如加速度、重力等幾乎都要乘上她因為要計算實際的位移或是實際速度