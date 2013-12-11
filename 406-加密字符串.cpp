// 406-加密字符串.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"                                  //如果用visual studio则把此行注释打开
#include<stdio.h>
#include<string.h>

char alphabet[26],afterMap[26];               //全局变量，定义字母表和对应后的字母表
int GetIndex(char s[],char c)                     //得到字符c在串s中的索引号（从0开始），如果找不到则返回-1
{
	for(int i = 0;s[i] != 0;i++)
	{
		if(s[i] == c)
			return i;
	}
	return -1;
}
char GetEncryptChar(char c)                    //得到原字符c加密后的字符
{
	int index = GetIndex(alphabet, c);        //得到c在常规字母表里的索引
	if(index >= 0)                                      //如果索引不小于0，表示是小写字母，直接加密即可
	{
		return afterMap[index];
	}
	else                                                             //否则有两种情况
	{
		index = GetIndex(alphabet, c + 32);         //假设c是大写字母，则将它变成小写后再到常规字母表里找一次
		if(index >= 0)                                          //如果找到了
		{
			return afterMap[index] - 32;                //将c按照小写字母加密后转化成大写字母并返回
		}
		else                                                        //否则表示c不是大写字母，则直接返回c
		{
			return c;
		}
	}
}
int StrContains(char key[],char c)                    //看字符c是否包含在串c中，包含返回1，否则返回0
{
	for(int i = 0;key[i] != 0;i++)
	{
		if(key[i] == c)
			return 1;
	}
	return 0;
}
void GetCharMap(char key[])                         //得到常规字母表关于密钥key的映射表，即为用来加密的有效对应表
{
	int k = 97;
	for(int i = 0;i < 26;i++)                               //循环26次
	{
		if(i < strlen(key))                                    //如果下标比key的长度小，直接赋值
		{
			afterMap[i] = key[i];
		}
		else                                                       //否则按照从字母表中补字母的方法来做
		{
			for(int j = k;j < 97 + 26;j++)              //j的初值为k=97（也就是a），以后k的值会变化
			{
				if(StrContains(key,j))                      //如果j已在key中出现，则不算数，继续做
				{ 
					continue;
				}
				else                                               //否则，说明key中不包含j，直接赋值
				{
					afterMap[i] = j;                          
					k = j + 1;                                   //之后k的值会加1，保证下次赋值时不会重复前面的字母
					break;
				}
			}
		}
	}
}

void Reverse(char key[])                                //将key倒置
{
	int keyLen = strlen(key);
	for(int i = 0;i <= keyLen / 2 - 1;i++)
	{
		char t = key[i];
		key[i] = key[keyLen - 1 - i];
		key[keyLen - 1 - i] = t;
	}
}

void GeneAlphabet()                                //产生26个正常的小写字母
{
	for(int i = 0;i < 26;i++)
	{
		alphabet[i] = 97 + i;
	}
}
void Encrypt(char s[],char key[],char encrypt[])      //加密
{
	int i;
	for(i = 0;s[i] != 0;i++)
	{
		encrypt[i] = GetEncryptChar(s[i]);     //每个字符都进行加密
	}
	encrypt[i] = 0;                                     //最后不要忘了把串截断，0相当于'\0'，两个是等价的
}
int main()
{
	int i,n;
	char s[80],key[12],encrypt[80];              //输入串，密钥，加密后的串
	scanf("%s",key);
	getchar();                                            //吃掉输入密钥后的那个回车
	GeneAlphabet();                                  //产生字母表
	Reverse(key);                                       //将密钥key反转
	GetCharMap(key);                               //得到字母表的加密字符的对应表
	while(1)
	{
		gets(s);                                            //得到每行要加密的串
		if(strcmp(s,"#") == 0) break;            //如果输入#号则终止程序
		strcpy(encrypt,"");                            //将加密后的串先清空
		Encrypt(s,key,encrypt);                     //加密
		puts(encrypt);                                  //输出
	}
	return 0;
}

