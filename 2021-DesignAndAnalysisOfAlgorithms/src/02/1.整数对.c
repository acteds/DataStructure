#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, a, b, count = 0, t;
    printf("����������n\n");
    scanf("%d", &n);
    for (a = n / 2; a <= n - 1; a++)
    {
        b = n - a;//todo �ٶ�b
        t = 1;        //todo ����ȡ��
        while (a > t) //todo ��ȡ����λ������aʱ�˳�
        {   //ȥ��һ��������b������ҵ�������
            if (a / (t * 10) * t + a % t==b)
            {
                printf("��%d����:a=%d,b=%d\n",++count, a, b);
                break;
            }
            t *= 10;//����ȥ����λ��.
        }
    }

    return 0;
}
