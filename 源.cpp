#include<iostream>
#include<algorithm>
using namespace std;

int f[100][100], sum[100] = { 0 };

int main()
{
	int n, k, tmp;
	cin >> n >> k;//�������ֺͳ˺ŵĸ���
	for (int i = 1;i <= n;i++)//��ʼ��
	{
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp; 
		f[i][0] = sum[i];
	}
	for (int i = 2;i <= n;i++)//�Զ����¼���i��Ԫ�ص���ʽ���ֵ
	{
		tmp = min(i - 1, k);//Լ��ǰi��Ԫ�������n-1���˺ţ����˺Ÿ������ܳ���k
		for (int j = 1;j <= tmp;j++)//�˺ŵĸ���
			for (int l = tmp;l <= i;l++)//���һ���˺ŵ�λ��
				f[i][j] = max(f[i][j], f[l - 1][j - 1] * (sum[i] - sum[l - 1]));
	}
	cout << f[n][k] << endl;
	return 0;
}