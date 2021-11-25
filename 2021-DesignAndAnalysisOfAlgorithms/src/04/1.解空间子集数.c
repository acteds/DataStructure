#include<stdio.h>
int a[3] = {1, 2, 3}, x[3], n = 3;
void result();
void dfs(int i);
int main(int argc, char const *argv[])
{
    dfs(0);
    return 0;
}
void dfs(int i){
    //到底了,输出内容
    if (i>=n)
    {
        result();
        return;
    }
    //不选择
    x[i] = 0;
    dfs(i + 1);
    //选择
    x[i] = 1;
    dfs(i + 1);
}
void result(){
    printf("{");
    int i;
    for (i = 0; i < n; i++)
    {
        //为选择则输出
        if (x[i])
        {
            // 如果为最后一个输出
            if (i+1==n)
            {
                printf("%d", a[i]);
            }else{
                printf("%d,", a[i]);
            }
        }
    }
    printf("}");
}
