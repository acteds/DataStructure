#include<stdio.h>
int main(int argc, char const *argv[])
{
    char ref[17] = "0123456789abcdef",result[3]="00\0";
    int i, j, z, p, temp, length = 2;
    printf("������p:\n");
    scanf("%d", &p);
    for (i = 1; i < p; i++)
    {
        for (j = 1; j <= i; j++)
        {
            //todo �������ʼ��
            length = 2;
            for ( z = 0; z < length; z++)
            {
                result[z] = '0';
            }
            //todo ����ת��
            temp = i * j;
            while (temp)
            {
                length--;
                result[length] = ref[temp % p];
                temp /= p;
            }
            //todo ���
            printf("%2c*%c=%s", ref[j], ref[i], result);
        }
        printf("\n");
    }
    return 0;
}
