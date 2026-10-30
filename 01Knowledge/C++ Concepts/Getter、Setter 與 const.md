- 父類別通常可以把變數用private利用getter和setter讓外部去存取、變動
- setter通常要處理一些無效參數，例如下面例子decreaseHungry會先判斷hungry更動後是否會為0再去判斷hungry數值
```c++
class Cat : public Pet
{
	private:
		int hungry = 50;
		
	public:
		int getHungry() // getter
		{
		    return hungry;
		}
		
		
		void decreaseHungry(int value) //setter，
		 {
		    if (hungry - value <= 0)
		    {
		        hungry = 0;
		    } 
		    else 
		    {
		        hungry -= value;
		    }
		}
};
```

## const
- 可以想成我不會修改目前物件狀態
- getter很適合用畢竟getter不應該修改數值
```cpp
int getHungry() const 
{
    return hungry;
}
```
- 傳參數也可以用const表示我只是把東西傳進去但我不會去更動
```cpp
test(const Pet &pet);
```