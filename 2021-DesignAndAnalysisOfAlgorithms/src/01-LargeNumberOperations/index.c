#include <stdio.h>
#include <string.h>
#define N 256
typedef struct HighInteger
{
    int src[N];
    int length;
} HI;

void user_print(HI *temp);
void add(HI *a, HI *b, HI *c);
void sub(HI *a, HI *b, HI *c);
void mul(HI *a, const int *b , HI *c);
int div(HI *a, const int *b, HI *c);
void factorial(HI *c, const int *n);
int Count0(HI *c);

int main(int argc, char const *argv[])
{
    //�ӵ͵���λ�洢
    //��a=987654321,b=1123456789
    HI a = {{4321, 8765, 9}, 3}, b = {{6789, 2345, 11}, 3}, c = {{0}, 0};

    //todo �ӷ�
    add(&a, &b, &c);

    printf("\n");
    user_print(&a);
    printf("+");
    user_print(&b);
    printf("=");
    user_print(&c); //�ӷ����Ϊ2111111110
    printf("\n");

    //todo ����
    c.length = 0;
    sub(&a, &b, &c);
    user_print(&a);
    printf("-");
    user_print(&b);
    printf("=");
    user_print(&c); //�������Ϊ-135802468
    printf("\n");

    //todo �˷�
    c.length = 0;
    int temp = 13;
    mul(&a,&temp, &c);
    user_print(&a);
    printf("*%d=", temp);
    user_print(&c); //�˷����Ϊ12839506173
    printf("\n");

    //todo ����
    c.length = 0;
    temp = 13;
    int remainder = div(&a, &temp, &c);

    user_print(&a);
    printf("/%d=", temp);
    user_print(&c); //�������Ϊ75973409,����:4
    printf(",����:%d\n",remainder);

    //todo n�Ľ׳�
    int n = 0;
    c.length = 0;

    printf("������n,��n!\n");
    scanf("%d", &n);

    factorial(&c, &n);

    printf("%d�Ľ׳���:", n);
    user_print(&c);
    printf("\n");
    printf("��ĸ�����:%d\n", Count0(&c));

    return 0;
}
/**
 * @brief  �ӷ���
 * @note
 * @param  *a: ����
 * @param  *b: ����
 * @param  *c: ���
 * @retval None
 */
void add(HI *a, HI *b, HI *c)
{
    int i, max, carry = 0;
    max = a->length > b->length ? a->length : b->length;
    //���ӷ���ɲ���û�н�λ��ֹͣ
    for (i = 0; i < max || carry != 0; i++)
    {
        c->src[i] = a->src[i] + b->src[i] + carry;
        carry = c->src[i] / 10000;//��λ
        c->src[i] = c->src[i] % 10000;
    }
    c->length = i;//��ֵλ��
}
/**
 * @brief  ������
 * @note   ���Ϊ����Ҳ����������
 * @param  *a: ����
 * @param  *b: ����
 * @param  *c: ���
 * @retval None
 */
void sub(HI *a, HI *b, HI *c)
{
    //flagΪ�������.
    int i, max, borrow = 0,flag=0;
    max = a->length >= b->length ? a->length : b->length;
    //���b��λ������a�򽻻�,����flag��1
    if (a->length<b->length)
    {
        HI *temp = a;
        a = b;
        b = temp;
        flag = 1;
    }else if(a->length==b->length){
        //�����ͬ�������жϴ�С
        i = 0;
        while (a->src[i]==b->src[i])
        {
            i++;
        }
        //���aС��b�򽻻�,����flag��1
        if (a->src[i] < b->src[i]){
            HI *temp = a;
            a = b;
            b = temp;
            flag = 1;
        }
    }

    //��������ɲ���û�н�λ��ֹͣ
    for (i = 0; i < max || borrow != 0; i++)
    {
        c->src[i] = a->src[i] - b->src[i] - borrow;
        //���a�и���λ,�ҽ��Ϊ�������λ
        if (c->src[i]<0&&(a->length-1)>i)
        {
            borrow = 1;
            c->src[i] += 10000;
        }else{
            borrow = 0;
        }
    }
    c->length = i; //��ֵλ��
    //���������������ӷ���λ
    if (flag)
    {
        c->src[c->length - 1] = -c->src[c->length - 1];
    }
}
/**
 * @brief  ��������ͨ���˷�
 * @note
 * @param  *a: ����
 * @param  *b: ��ͨ��
 * @param  *c: ���
 * @retval None
 */
void mul(HI *a, const int *b, HI *c)
{
    int i,carry=0;
    for (i = 0; i < a->length||carry!=0; i++)
    {
        c->src[i] = a->src[i] * (*b) + carry;
        carry = c->src[i] / 10000;
        c->src[i] %= 10000;
    }
    c->length = i;
}
/**
 * @brief  ������(����)
 * @note
 * @param  *a: ����
 * @param  *b: ��ͨ����
 * @param  *c: ���
 * @retval ��������
 */
int div(HI *a, const int *b, HI *c)
{
    int i, remain = 0;
    for (i = a->length-1; i >=0; i--)
    {
        c->src[i] = (a->src[i] + remain * 10000) / (*b);
        remain = (a->src[i] + remain * 10000) % (*b);
    }
    //������ռ�õ�λ��,���������ɳ���
    c->length = a->length;
    for (i = c->length-1; c->src[i]==0; i--)
    {
        c->length--;
    }

    return remain;
}
/**
 * @brief  �׳�
 * @note
 * @param  *c:
 * @param  *n:
 * @retval None
 */
void factorial(HI *c,const int *n)
{
    int i,j,carry=0;
    //��ʼ������
    for ( i = 0; i < N; i++)
    {
        c->src[i] = 0;
    }
    c->src[0] = 1;
    c->length = 1;
    for ( i = 1; i <= *n; i++)
    {
        for ( j = 0; j < c->length; j++)
        {
            c->src[j] = c->src[j] * i + carry;
            carry = c->src[j] / 10000;
            c->src[j] %= 10000;
            //���Ϊ���һλ,�ҽ����˽�λ,��c�ĳ���+1.
            if (c->length-1==j&&carry!=0)
            {
                c->length++;
            }
        }
    }
}
/**
 * @brief  ��������е���
 * @note
 * @param  *c: ����
 * @retval ��ĸ���
 */
int Count0(HI *c)
{
    int i,j,count=0,length=0;
    for ( i = 0; i < c->length; i++)
    {
        char temp[5];
        //���ÿ�β���4λ����ʾ����,�Լ����λ����ʾ0������
        if (i == c->length - 1)
        {
            length = sprintf(temp,"%d", c->src[i]);
        }else{
            length = sprintf(temp, "%04d", c->src[i]);
        }
        for (j = 0; j < length; j++)
        {
            if (temp[j]=='0')
            {
                count++;
            }
        }
    }
    return count;
}
    /**
 * @brief  ���
 * @note
 * @param  *temp: �ṹ��ָ��
 * @retval None
 */
void user_print(HI *temp)
{
    int i;
    for (i = temp->length - 1; i >= 0; i--)
    {
        //���ÿ�β���4λ����ʾ����,�Լ����λ����ʾ0������
        if (i == temp->length - 1)
        {
            printf("%d", temp->src[i]);
        }else{
            printf("%04d", temp->src[i]);
        }
    }
}