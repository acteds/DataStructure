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
    //从低到高位存储
    //即a=987654321,b=1123456789
    HI a = {{4321, 8765, 9}, 3}, b = {{6789, 2345, 11}, 3}, c = {{0}, 0};

    //todo 加法
    add(&a, &b, &c);

    printf("\n");
    user_print(&a);
    printf("+");
    user_print(&b);
    printf("=");
    user_print(&c); //加法结果为2111111110
    printf("\n");

    //todo 减法
    c.length = 0;
    sub(&a, &b, &c);
    user_print(&a);
    printf("-");
    user_print(&b);
    printf("=");
    user_print(&c); //减法结果为-135802468
    printf("\n");

    //todo 乘法
    c.length = 0;
    int temp = 13;
    mul(&a,&temp, &c);
    user_print(&a);
    printf("*%d=", temp);
    user_print(&c); //乘法结果为12839506173
    printf("\n");

    //todo 除法
    c.length = 0;
    temp = 13;
    int remainder = div(&a, &temp, &c);

    user_print(&a);
    printf("/%d=", temp);
    user_print(&c); //除法结果为75973409,余数:4
    printf(",余数:%d\n",remainder);

    //todo n的阶乘
    int n = 0;
    c.length = 0;

    printf("请输入n,求n!\n");
    scanf("%d", &n);

    factorial(&c, &n);

    printf("%d的阶乘是:", n);
    user_print(&c);
    printf("\n");
    printf("零的个数是:%d\n", Count0(&c));

    return 0;
}
/**
 * @brief  加法器
 * @note
 * @param  *a: 大数
 * @param  *b: 大数
 * @param  *c: 结果
 * @retval None
 */
void add(HI *a, HI *b, HI *c)
{
    int i, max, carry = 0;
    max = a->length > b->length ? a->length : b->length;
    //当加法完成并且没有进位后停止
    for (i = 0; i < max || carry != 0; i++)
    {
        c->src[i] = a->src[i] + b->src[i] + carry;
        carry = c->src[i] / 10000;//进位
        c->src[i] = c->src[i] % 10000;
    }
    c->length = i;//赋值位数
}
/**
 * @brief  减法器
 * @note   结果为负数也能正常计算
 * @param  *a: 大数
 * @param  *b: 大数
 * @param  *c: 结果
 * @retval None
 */
void sub(HI *a, HI *b, HI *c)
{
    //flag为负数标记.
    int i, max, borrow = 0,flag=0;
    max = a->length >= b->length ? a->length : b->length;
    //如果b的位数大于a则交换,并将flag置1
    if (a->length<b->length)
    {
        HI *temp = a;
        a = b;
        b = temp;
        flag = 1;
    }else if(a->length==b->length){
        //如果相同长度则判断大小
        i = 0;
        while (a->src[i]==b->src[i])
        {
            i++;
        }
        //如果a小于b则交换,并将flag置1
        if (a->src[i] < b->src[i]){
            HI *temp = a;
            a = b;
            b = temp;
            flag = 1;
        }
    }

    //当减法完成并且没有借位后停止
    for (i = 0; i < max || borrow != 0; i++)
    {
        c->src[i] = a->src[i] - b->src[i] - borrow;
        //如果a有更高位,且结果为负数则借位
        if (c->src[i]<0&&(a->length-1)>i)
        {
            borrow = 1;
            c->src[i] += 10000;
        }else{
            borrow = 0;
        }
    }
    c->length = i; //赋值位数
    //如果经过交换则添加符号位
    if (flag)
    {
        c->src[c->length - 1] = -c->src[c->length - 1];
    }
}
/**
 * @brief  大数与普通数乘法
 * @note
 * @param  *a: 大数
 * @param  *b: 普通数
 * @param  *c: 结果
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
 * @brief  除法器(整数)
 * @note
 * @param  *a: 大数
 * @param  *b: 普通除数
 * @param  *c: 结果
 * @retval 返回余数
 */
int div(HI *a, const int *b, HI *c)
{
    int i, remain = 0;
    for (i = a->length-1; i >=0; i--)
    {
        c->src[i] = (a->src[i] + remain * 10000) / (*b);
        remain = (a->src[i] + remain * 10000) % (*b);
    }
    //计算余占用的位置,并重新生成长度
    c->length = a->length;
    for (i = c->length-1; c->src[i]==0; i--)
    {
        c->length--;
    }

    return remain;
}
/**
 * @brief  阶乘
 * @note
 * @param  *c:
 * @param  *n:
 * @retval None
 */
void factorial(HI *c,const int *n)
{
    int i,j,carry=0;
    //初始化清零
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
            //如果为最后一位,且进行了进位,则c的长度+1.
            if (c->length-1==j&&carry!=0)
            {
                c->length++;
            }
        }
    }
}
/**
 * @brief  计算大数中的零
 * @note
 * @param  *c: 大数
 * @retval 零的个数
 */
int Count0(HI *c)
{
    int i,j,count=0,length=0;
    for ( i = 0; i < c->length; i++)
    {
        char temp[5];
        //解决每段不满4位的显示问题,以及最高位多显示0的问题
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
 * @brief  输出
 * @note
 * @param  *temp: 结构体指针
 * @retval None
 */
void user_print(HI *temp)
{
    int i;
    for (i = temp->length - 1; i >= 0; i--)
    {
        //解决每段不满4位的显示问题,以及最高位多显示0的问题
        if (i == temp->length - 1)
        {
            printf("%d", temp->src[i]);
        }else{
            printf("%04d", temp->src[i]);
        }
    }
}