#include<iostream>                                                        
using namespace std;
void merge(int a[],const int l,const int m,const int n)
{
	int i,j,k;
	int b[50];
	for(i=l,k=l,j=m+1;i<=m&&j<=n;k++)
		if(a[i]<=a[j])
			b[k]=a[i++];
		else
			b[k]=a[j++];
	while(i<=m)
		b[k++]=a[i++];
	while(j<=n)
		b[k++]=a[j++];
	for(i=0;i<k;i++)
		a[i]=b[i];
}
void mergesort(int a[],int lb,int ub)
{
	int mid;                                                                                                                                        
	if(ub!=lb)
	{
		mid=(lb+ub)/2;
		mergesort(a,lb,mid);
		mergesort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}
int main()
{
	int n;
	cout<<"Enter the size:";
	cin>>n;
	int a[n];
	cout<<"Enter the elements:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
