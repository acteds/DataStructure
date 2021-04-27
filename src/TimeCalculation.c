#include <stdio.h>
#include <time.h>
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
    Sleep(123);
    //�ڶ��λ�ȡʱ�䣬����ʾ������ʱ
    mingw_gettimeofday(&end, NULL);

    //����ʱ������ӡ
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Ordinary Method:");
    printf("time:%10ld��s\n", diff);

    //todo ����2
    clock_t start2, end2;
    double duration;
    start2 = clock();
    //�����Լ��ĳ���
    Sleep(123);

    end2 = clock();
    duration = ((double)(end2 - start2)) / CLK_TCK;
    printf("%-25s", "Ordinary Method:");
    printf("time:%10lf��s\n", duration);
    return 0;
}