#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
#define MAX 1024                    //全局固定变量 MAX 1024
typedef struct{                      //定义结构体
char word[32];
int num;
} wordlist;

wordlist wl[MAX];
int wordnum=0;

void tongji() 
{ 
	char st[32];                          //定义自变量
	int found;
	char c;
	int i;
	int m=0,n=0,j=0,k=0; 
	FILE *fp;                             // 定义文件指针
	if((fp=fopen("14220105.txt","r"))==NULL)
	exit(1);
	while(fscanf(fp,"%s",st)!=EOF)
	{
		found=0;
		for(i=0;i<wordnum;i++)
		{
			if(strcmp(wl[i].word,st)==0)    //字符串的读取
			{
				wl[i].num++;
				found=1;
				break;
			}
		}
		if(!found)
		{
			strcpy(wl[i].word,st);
			wl[i].num=1;
			wordnum++;
		}
	}
	fclose(fp);

	if((fp=fopen("14220105.txt","r"))==NULL)
	exit(1);
	while((c=fgetc(fp))!=EOF) 
	{
		if(c==' ')                          // 数字及空格的读取
			++n;
		else if(c>='0'&&c<='9')
			++j;
		else if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
			++k;
		else ++m;
}
	fclose(fp);
	printf("读取完毕，结果如下：\n");
	printf(" 数字 %d\n 字母 %d\n 空格 %d\n 其他 %d\n",j,k,n,m );// 输出结果

}

void shuru()
{

char str[100];
char letter[52];
int count[52]={0};//初始化计数器
int i;
int lc=0;//记录字母总数
cout<<"输入字符串:"<<endl;
scanf("%s",str);

//初始化字母表
for(i=0;i<26;i++)
letter[i]='A'+i;
for(i=26;i<52;i++)
letter[i]='a'+i-26;

i=0;

while(str[i]!='\0')//字符串未结束 
{
if(str[i]>='A' && str[i]<='Z')//    写字母
{
count[str[i]-65]++;//假设str[i]=='A', 'A'-65等于0 count[0]自增1
lc++;
}
if(str[i]>='a' && str[i]<='z')//    写字母
{
count[str[i]-97+26]++;//'a'==97,前面26   写 所 加26
lc++;
}
i++;
}
for(i=0;i<52;i++)//显示统计情况
{
if(count[i]!=0)
printf("%c-%d-%3.2f％\n",letter[i],count[i],(float)count[i]/lc*100);
}
}
void xuanzhe()
{
 printf("1.读档统计\n");
 printf("2.输入统计\n");
 printf("0.退出\n");//输出退出
	printf("选择您所需要的操作：");
}
int main()          //主函数
{     
	int choice;
	do 
      { xuanzhe();	
	scanf("%d",&choice);
	switch(choice)   // switch函数进行循环执行
	{
	case 0:
		return 0;
	case 1:
		tongji();
		break;
	case 2:
		shuru();
		break;
	}
}while(1);
}
