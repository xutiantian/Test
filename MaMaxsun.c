int max(int x,int y)
{
return (x>y)?x:y;
}
int MaxSum(int * A,int n)
{
int *sum=(int *)malloc(n*sizeof(int));
int *result=(int *)malloc(n*sizeof(int));
sum[0]=A[0];
result[0]=A[0];
for(int i=1;i<n;i++)
{
sum[i]=max(A[i],A[i]+sum[i-1]);
//若A[i]>A[i]+sum[i-1],则作为新子数组的第一个元素，否则放入前面已经找到的最大的子
数组sum[i-1]中

result[i]=max(sum[i],result[i-1]);
}
return result[n-1];
}