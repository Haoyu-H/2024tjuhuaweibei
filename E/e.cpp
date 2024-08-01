#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int part(int* r, int low, int hight)  //���ֺ���
{
	int i = low, j = hight, pivot = r[low]; //��׼Ԫ��
	while (i < j)
	{
		while (i<j && r[j]>pivot) //��������ʼ��һ�� С�ڵ��� pivot����ֵ
		{
			j--;
		}
		if (i < j)
		{
			swap(r[i++], r[j]);  //r[i]��r[j]������ i �����ƶ�һλ
		}
		while (i < j && r[i] <= pivot) //�������ҿ�ʼ��һ�� ���� pivot����ֵ
		{
			i++;
		}
		if (i < j)
		{
			swap(r[i], r[j--]);  //r[i]��r[j]������ i �����ƶ�һλ
		}
	}
	return i;  //�������ջ�����ɺ��׼Ԫ�����ڵ�λ��
}
void Quicksort(int* r, int low, int hight)
{
	int mid;
	if (low < hight)
	{
		mid = part(r, low, hight);  // ���ػ�׼Ԫ��λ��
		Quicksort(r, low, mid - 1); // ������ݹ��������
		Quicksort(r, mid + 1, hight); // ������ݹ��������
	}
}
int max1(int a, int b) {
	if (a >= b) {
		return a;
	}
	else
		return b;
}
int main()
{
	int a[10001];
	int  N;
	//cout << "������Ҫ��������ݵĸ����� " << endl;
	cin >> N;
	//cout << "������Ҫ��������ݣ� " << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	Quicksort(a, 0, N - 1);
	int max = 1; 
	int cur = 1;
	for (int i = 0; i < N; i++) {
		if (a[i] + 1 == a[i + 1]) {
			cur++;
		}
		else {
			max = max1(max, cur);
			cur = 1;
		}
	}
	max = max1(max, cur);
	cout << max << endl;
	return 0;
}