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
//��A[i]>A[i]+sum[i-1],����Ϊ��������ĵ�һ��Ԫ�أ��������ǰ���Ѿ��ҵ���������
����sum[i-1]��

result[i]=max(sum[i],result[i-1]);
}
return result[n-1];
}