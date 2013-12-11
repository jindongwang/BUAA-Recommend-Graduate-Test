// 406-�����ַ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"                                  //�����visual studio��Ѵ���ע�ʹ�
#include<stdio.h>
#include<string.h>

char alphabet[26],afterMap[26];               //ȫ�ֱ�����������ĸ��Ͷ�Ӧ�����ĸ��
int GetIndex(char s[],char c)                     //�õ��ַ�c�ڴ�s�е������ţ���0��ʼ��������Ҳ����򷵻�-1
{
	for(int i = 0;s[i] != 0;i++)
	{
		if(s[i] == c)
			return i;
	}
	return -1;
}
char GetEncryptChar(char c)                    //�õ�ԭ�ַ�c���ܺ���ַ�
{
	int index = GetIndex(alphabet, c);        //�õ�c�ڳ�����ĸ���������
	if(index >= 0)                                      //���������С��0����ʾ��Сд��ĸ��ֱ�Ӽ��ܼ���
	{
		return afterMap[index];
	}
	else                                                             //�������������
	{
		index = GetIndex(alphabet, c + 32);         //����c�Ǵ�д��ĸ���������Сд���ٵ�������ĸ������һ��
		if(index >= 0)                                          //����ҵ���
		{
			return afterMap[index] - 32;                //��c����Сд��ĸ���ܺ�ת���ɴ�д��ĸ������
		}
		else                                                        //�����ʾc���Ǵ�д��ĸ����ֱ�ӷ���c
		{
			return c;
		}
	}
}
int StrContains(char key[],char c)                    //���ַ�c�Ƿ�����ڴ�c�У���������1�����򷵻�0
{
	for(int i = 0;key[i] != 0;i++)
	{
		if(key[i] == c)
			return 1;
	}
	return 0;
}
void GetCharMap(char key[])                         //�õ�������ĸ�������Կkey��ӳ�����Ϊ�������ܵ���Ч��Ӧ��
{
	int k = 97;
	for(int i = 0;i < 26;i++)                               //ѭ��26��
	{
		if(i < strlen(key))                                    //����±��key�ĳ���С��ֱ�Ӹ�ֵ
		{
			afterMap[i] = key[i];
		}
		else                                                       //�����մ���ĸ���в���ĸ�ķ�������
		{
			for(int j = k;j < 97 + 26;j++)              //j�ĳ�ֵΪk=97��Ҳ����a�����Ժ�k��ֵ��仯
			{
				if(StrContains(key,j))                      //���j����key�г��֣���������������
				{ 
					continue;
				}
				else                                               //����˵��key�в�����j��ֱ�Ӹ�ֵ
				{
					afterMap[i] = j;                          
					k = j + 1;                                   //֮��k��ֵ���1����֤�´θ�ֵʱ�����ظ�ǰ�����ĸ
					break;
				}
			}
		}
	}
}

void Reverse(char key[])                                //��key����
{
	int keyLen = strlen(key);
	for(int i = 0;i <= keyLen / 2 - 1;i++)
	{
		char t = key[i];
		key[i] = key[keyLen - 1 - i];
		key[keyLen - 1 - i] = t;
	}
}

void GeneAlphabet()                                //����26��������Сд��ĸ
{
	for(int i = 0;i < 26;i++)
	{
		alphabet[i] = 97 + i;
	}
}
void Encrypt(char s[],char key[],char encrypt[])      //����
{
	int i;
	for(i = 0;s[i] != 0;i++)
	{
		encrypt[i] = GetEncryptChar(s[i]);     //ÿ���ַ������м���
	}
	encrypt[i] = 0;                                     //���Ҫ���˰Ѵ��ضϣ�0�൱��'\0'�������ǵȼ۵�
}
int main()
{
	int i,n;
	char s[80],key[12],encrypt[80];              //���봮����Կ�����ܺ�Ĵ�
	scanf("%s",key);
	getchar();                                            //�Ե�������Կ����Ǹ��س�
	GeneAlphabet();                                  //������ĸ��
	Reverse(key);                                       //����Կkey��ת
	GetCharMap(key);                               //�õ���ĸ��ļ����ַ��Ķ�Ӧ��
	while(1)
	{
		gets(s);                                            //�õ�ÿ��Ҫ���ܵĴ�
		if(strcmp(s,"#") == 0) break;            //�������#������ֹ����
		strcpy(encrypt,"");                            //�����ܺ�Ĵ������
		Encrypt(s,key,encrypt);                     //����
		puts(encrypt);                                  //���
	}
	return 0;
}

