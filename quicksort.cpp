#include<iostream>
using namespace std;
void partition(int x[],int lb,int ub,int *pj)
{
	int a,down,up,tmp;
	a=x[lb];
	up=ub;
	down=lb;
	while(down<up)
	{
		while(x[down]<=a)
			down++;
		while(x[up]>a)
			up--;
		if(down<up)
		{
			tmp=x[up];
			x[up]=x[down];
			x[down]=tmp;
		}
	}
	x[lb]=x[up];
	x[up]=a;
	*pj=up;
}
void quick(int x[],int lb,int ub)
{
	int j;
	if(lb>=ub)
		return;
	partition(x,lb,ub,&j);
	quick(x,lb,j-1);
	quick(x,j+1,ub);
}
int main()
{
	int n;
	cout<<"Enter the size:";
	cin>>n;
	int a[n];
	cout<<"Enter the values:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	quick(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
