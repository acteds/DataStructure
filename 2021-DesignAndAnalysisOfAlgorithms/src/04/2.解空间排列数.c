#include<stdio.h>
int a[3] = {1, 2, 3}, n = 3;
void swap(int *a, int *b);
void dfs(int i);
void result();
int main(int argc, char const *argv[])
{
    dfs(0);
    return 0;
}
/**
 * @brief  交换
 * @note
 * @param  *a: 地址1
 * @param  *b: 地址2
 * @retval None
 */
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * @brief  输出结果
 * @note
 * @retval None
 */
void result(){
    printf("(");
    int j;
    for( j = 0; j < n; j++)
    {
        // 如果为最后一个输出,则不输出逗号
        if (j + 1 == n)
        {
            printf("%d) ", a[j]);
        }
        else
        {
            printf("%d,", a[j]);
        }
    }
}
/**
 * @brief  遍历
 * @note
 * @param  i: 层次
 * @retval None
 */
void dfs(int i){
    if (i>=n)
    {
        result();
        return;
    }
    int j;
    for ( j = i; j < n; j++)
    {
        // 交换后递归,完毕后返回原样
        // 使用指针交换,即回溯
        swap(&a[i], &a[j]);
        dfs(i + 1);
        swap(&a[i], &a[j]);
    }
}