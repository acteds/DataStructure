#include<stdio.h>
#include<time.h>
#include<math.h>
void PrintfN(int N);
int main(int argc, char const *argv[])
{
    //定义两个结构体，来记录开始和结束时间
    struct timeval start;
    struct timeval end;
    //记录两个时间差
    unsigned long diff;
    //todo 方法1
    //第一次获取时间，即表示开始记时
    mingw_gettimeofday(&start, NULL);
    //运行自己的程序
    PrintfN(10);
    
    //第二次获取时间，即表示结束记时
    mingw_gettimeofday(&end, NULL);

    //计算时间差，并打印
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Ordinary Method:");
    printf("time:%10ldμs", diff);
    return 0;
}
void PrintfN(int N){
    int i;
    for (i = 1; i < N; i++)
    {
        printf("%d ", i);
    }
}