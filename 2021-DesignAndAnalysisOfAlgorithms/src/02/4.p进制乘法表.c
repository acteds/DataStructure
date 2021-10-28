#include<stdio.h>
int main(int argc, char const *argv[])
{
    char ref[17] = "0123456789abcdef",result[3]="00\0";
    int i, j, z, p, temp, length = 2;
    printf("请输入p:\n");
    scanf("%d", &p);
    for (i = 1; i < p; i++)
    {
        for (j = 1; j <= i; j++)
        {
            //todo 结果集初始化
            length = 2;
            for ( z = 0; z < length; z++)
            {
                result[z] = '0';
            }
            //todo 进制转换
            temp = i * j;
            while (temp)
            {
                length--;
                result[length] = ref[temp % p];
                temp /= p;
            }
            //todo 输出
            printf("%2c*%c=%s", ref[j], ref[i], result);
        }
        printf("\n");
    }
    return 0;
}
