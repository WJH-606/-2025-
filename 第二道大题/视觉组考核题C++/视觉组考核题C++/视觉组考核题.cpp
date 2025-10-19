#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

struct Rect//Rect结构体
{
	int IDNum = 0;//ID
	int Color = 0;//颜色
	int x = 0; int y = 0;//坐标
	int Width = 0;//宽度
	int Height = 0;//高度
};
class Armor//创建Armor类
{
public:

	int Central_Piont(int num1, int num2)
	{
		int sum1 = num1 + num2;
		return sum1;
	}//加法函数
};

int main()
{
	int Color = 0;
	Rect r;
	std::cin >> r.IDNum;
	if (r.IDNum < 7)
	{
		cout << "ID:" << r.IDNum;
	}
	else
	{

	}//让只有输入1-6的时候可以进行输出，别的数字不行
	std::cin >> r.Color;
	if (r.Color == 0)
	{
		cout << "颜色:蓝色" << endl;
	}
	if (r.Color == 1)
	{
		cout << "颜色:红色" << endl;
	}
	else
	{

	}//让只有输入0和1的时候可以进行输出，别的数字不行
	cin >> r.x; cin >> r.y; cin >> r.Width; cin >> r.Height;
	Armor obj;//对象
	int a = obj.Central_Piont(r.x, r.Width / 2);
	int b = obj.Central_Piont(r.y, r.Height / 2);
	cout << "(" << a << "," << b << ")";
	float length = sqrt(r.Width * r.Width + r.Height * r.Height);
	cout << fixed << setprecision(2) << "长度：" << length << endl;
	cout << "(" << r.x << "," << r.y << ")";
	int c = obj.Central_Piont(r.x, r.Width );
	cout << "(" << c << "," << r.y << ")";
	int d = obj.Central_Piont(r.x, r.Width);
	int e = obj.Central_Piont(r.y, r.Height);
	cout << "(" << d << "," << e << ")";
	int f = obj.Central_Piont(r.y, r.Height);
	cout << "(" << r.x << "," << f << ")";
	return 0;
}