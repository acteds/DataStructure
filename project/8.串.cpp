#include <stdio.h>
#define MaxSize 100
typedef struct
{
    char data[MaxSize];
    int length;
} SqString;

void Assign(SqString &s,const char *a){//建立串
    int i;
    for(i=0; a[i]!='\0'; i++)
        s.data[i]=a[i];
     s.data[i]=a[i];//赋值\0
    s.length=i;
}

void Copy(SqString &s,SqString t){//复制串
    int i=0;
    while(i<t.length){
        s.data[i]=t.data[i];
        i++;
    }
    s.data[i]=t.data[i];//加\0
    s.length=t.length;
}

int Strcmp(SqString s,SqString t){//字符串比较
    int i=0;
    while(i<s.length&&i<t.length){
        if(s.data[i]!=t.data[i])
            break;
        i++;
    }
    return s.data[i]-t.data[i];
}

SqString InsStr(SqString s,int i,SqString t){//插入子串
    int j;
	if (i<0||i>s.length+1)return s;
    for(j=s.length;j>=i-1;--j)
        s.data[j+t.length]=s.data[j];
    for(j=0;j<t.length;++j)
        s.data[i+j-1]=t.data[j];
    s.length+=t.length;
	return s;
}

SqString SubStr(SqString s,int i,int j){//返回子串	
    SqString str;
	int k;
	str.length=0;
	if (i<=0 || i>s.length || j<0 || i+j-1>s.length)return str;					
	for (k=i-1;k<i+j-1;k++)  		
		str.data[k-i+1]=s.data[k];
	str.data[k-i+1]='\0';
	str.length=j;
	return str;
}

int Index(SqString s,SqString t){//查找子串所在位置
    int i,j,z;
    for(i=0;i<s.length;++i)
        for(j=0,z=i;s.data[z]==t.data[j]||t.data[j]=='\0';++j,++z)
            if(t.data[j]=='\0')
                return i+1;
    return 0;
}

int DelStr(SqString &s,int i,int j){//删除指定位置字符	
	int k;
	if (i<=0 || i>s.length || i+j>s.length+1)return 0;
	for(k=i+j-1;k<=s.length;++k)
	    s.data[k-j]=s.data[k];
	s.length=s.length-j;
	return 1;
}

SqString RepStr(SqString s,SqString s1,SqString s2){//在s中查找s1并替换为s2
    int i;
	i=Index(s,s1);
	while(i>0){
	    DelStr(s,i,s1.length);
	    s=InsStr(s,i,s2);
	    i=Index(s,s1);
	}
	return s;
}

int main()
{
	SqString s1,s2,s3,s4,s5,s6,s7;
	Assign(s1,"abcd");
	printf("建立串:\ns1:%-15s长度为%d\n",s1.data,s1.length);
    printf("复制串s1到s2\n");
    Copy(s2,s1);
	printf("s2:%-15s长度为%d\n",s1.data,s1.length);
    printf("s1与s2的大小关系是%d\n",Strcmp(s1,s2));
    Assign(s3,"12345678");
    printf("建立串:\ns3:%-15s长度为%d\n",s3.data,s3.length);
    printf("s1与s3连接得到:\n");
    s4=InsStr(s1,s1.length+1,s3);
    printf("s4:%-15s长度为%d\n",s4.data,s4.length);
    printf("取s3的【2-5】字节给s5\n");
    s5=SubStr(s3,2,4);
    printf("s5:%-15s长度为%d\n",s5.data,s5.length);
    Assign(s6,"567");
    printf("建立串:\ns6:%-15s长度为%d\n",s6.data,s6.length);
    printf("s6在s3的位置为：%d\n",Index(s3,s6));
    printf("从s3中删除【3-6】字符\n");
    DelStr(s3,3,4);
    printf("s3:%-15s长度为%d\n",s3.data,s3.length);
    printf("从s4中将s6替换为s1生成s7\n");
    s7=RepStr(s4,s6,s1);
    printf("s7:%-15s长度为%d\n",s7.data,s7.length);
	getchar();
}