#include<iostream>
#include<algorithm>
using namespace std;

int f[100][100], sum[100] = { 0 };

int main()
{
	int n, k, tmp;
	cin >> n >> k;//输入数字和乘号的个数
	for (int i = 1;i <= n;i++)//初始化
	{
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp; 
		f[i][0] = sum[i];
	}
	for (int i = 2;i <= n;i++)//自顶向下计算i个元素的算式最大值
	{
		tmp = min(i - 1, k);//约束前i个元素最多有n-1个乘号，但乘号个数不能超过k
		for (int j = 1;j <= tmp;j++)//乘号的个数
			for (int l = tmp;l <= i;l++)//最后一个乘号的位置
				f[i][j] = max(f[i][j], f[l - 1][j - 1] * (sum[i] - sum[l - 1]));
	}
	cout << f[n][k] << endl;
	return 0;
}