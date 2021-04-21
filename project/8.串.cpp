#include <stdio.h>
#define MaxSize 100
typedef struct
{
    char data[MaxSize];
    int length;
} SqString;

void Assign(SqString &s,const char *a){//������
    int i;
    for(i=0; a[i]!='\0'; i++)
        s.data[i]=a[i];
     s.data[i]=a[i];//��ֵ\0
    s.length=i;
}

void Copy(SqString &s,SqString t){//���ƴ�
    int i=0;
    while(i<t.length){
        s.data[i]=t.data[i];
        i++;
    }
    s.data[i]=t.data[i];//��\0
    s.length=t.length;
}

int Strcmp(SqString s,SqString t){//�ַ����Ƚ�
    int i=0;
    while(i<s.length&&i<t.length){
        if(s.data[i]!=t.data[i])
            break;
        i++;
    }
    return s.data[i]-t.data[i];
}

SqString InsStr(SqString s,int i,SqString t){//�����Ӵ�
    int j;
	if (i<0||i>s.length+1)return s;
    for(j=s.length;j>=i-1;--j)
        s.data[j+t.length]=s.data[j];
    for(j=0;j<t.length;++j)
        s.data[i+j-1]=t.data[j];
    s.length+=t.length;
	return s;
}

SqString SubStr(SqString s,int i,int j){//�����Ӵ�	
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

int Index(SqString s,SqString t){//�����Ӵ�����λ��
    int i,j,z;
    for(i=0;i<s.length;++i)
        for(j=0,z=i;s.data[z]==t.data[j]||t.data[j]=='\0';++j,++z)
            if(t.data[j]=='\0')
                return i+1;
    return 0;
}

int DelStr(SqString &s,int i,int j){//ɾ��ָ��λ���ַ�	
	int k;
	if (i<=0 || i>s.length || i+j>s.length+1)return 0;
	for(k=i+j-1;k<=s.length;++k)
	    s.data[k-j]=s.data[k];
	s.length=s.length-j;
	return 1;
}

SqString RepStr(SqString s,SqString s1,SqString s2){//��s�в���s1���滻Ϊs2
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
	printf("������:\ns1:%-15s����Ϊ%d\n",s1.data,s1.length);
    printf("���ƴ�s1��s2\n");
    Copy(s2,s1);
	printf("s2:%-15s����Ϊ%d\n",s1.data,s1.length);
    printf("s1��s2�Ĵ�С��ϵ��%d\n",Strcmp(s1,s2));
    Assign(s3,"12345678");
    printf("������:\ns3:%-15s����Ϊ%d\n",s3.data,s3.length);
    printf("s1��s3���ӵõ�:\n");
    s4=InsStr(s1,s1.length+1,s3);
    printf("s4:%-15s����Ϊ%d\n",s4.data,s4.length);
    printf("ȡs3�ġ�2-5���ֽڸ�s5\n");
    s5=SubStr(s3,2,4);
    printf("s5:%-15s����Ϊ%d\n",s5.data,s5.length);
    Assign(s6,"567");
    printf("������:\ns6:%-15s����Ϊ%d\n",s6.data,s6.length);
    printf("s6��s3��λ��Ϊ��%d\n",Index(s3,s6));
    printf("��s3��ɾ����3-6���ַ�\n");
    DelStr(s3,3,4);
    printf("s3:%-15s����Ϊ%d\n",s3.data,s3.length);
    printf("��s4�н�s6�滻Ϊs1����s7\n");
    s7=RepStr(s4,s6,s1);
    printf("s7:%-15s����Ϊ%d\n",s7.data,s7.length);
	getchar();
}