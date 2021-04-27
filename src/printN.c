#include<stdio.h>
#include<time.h>
#include<math.h>
void PrintfN(int N);
int main(int argc, char const *argv[])
{
    //���������ṹ�壬����¼��ʼ�ͽ���ʱ��
    struct timeval start;
    struct timeval end;
    //��¼����ʱ���
    unsigned long diff;
    //todo ����1
    //��һ�λ�ȡʱ�䣬����ʾ��ʼ��ʱ
    mingw_gettimeofday(&start, NULL);
    //�����Լ��ĳ���
    PrintfN(10);
    
    //�ڶ��λ�ȡʱ�䣬����ʾ������ʱ
    mingw_gettimeofday(&end, NULL);

    //����ʱ������ӡ
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Ordinary Method:");
    printf("time:%10ld��s", diff);
    return 0;
}
void PrintfN(int N){
    int i;
    for (i = 1; i < N; i++)
    {
        printf("%d ", i);
    }
}