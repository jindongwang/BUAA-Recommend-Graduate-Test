// 405-����ϲ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"                          //�����visual studio��Ѵ���ע�ʹ�
#include<stdio.h>
void QuickSort(int a[],int l,int h)          //��������������ֿ������κ����򷽷�
{
	if (l >= h)return ;
	int j ,i,key;
	i = l;
	j = h;
	key = a[i];
	while(i < j)
	{
		while(i < j && a[j] > key) j--;
		if (i < j) a[i++] = a[j];
		while (i<j&&a[i]<key)i++;
		if (i < j) a[j--] = a[i];
	}
    a[i] = key;
    if (l < i-1)
        QuickSort(a,l,i-1);
    if (i+1 < h)
        QuickSort(a,i+1,h);
}
void Print(int a[],int n)                   //��ӡ
{
	printf("%d ",a[0]);
	for(int i = 1;i < n;i++)
	{
		if(a[i] == a[i - 1])                  //ȥ�ػ���
		{
			continue;
		}
		printf("%d ",a[i]);
	}
}
int main()
{
	int m,n,a[20],b[20],c[40];
	int i,j,k,t;
	scanf("%d",&m);
	for(i = 0;i < m;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&b[i]);
	}
	t = 0;
	for(i = 0;i < m;i++)
	{
		k = 0;
		for(j = 0;j < n;j++)
		{
			if(a[i] != b[j])
			{
				k++;                     //�Ӹ����������Ԫ���ж��Ƿ����ظ�
			}
		}
		if(k == n)
		{
			c[t++] = a[i];
		}
	}
	for(i = 0;i < n;i++)
	{
		k = 0;
		for(j = 0;j < m;j++)
		{
			if(b[i] != a[j])
			{
				k++;
			}
		}
		if(k == m)
		{
			c[t++] = b[i];
		}
	}
	QuickSort(c,0,t - 1);
	Print(c,t);
	return 0;
}