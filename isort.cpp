#include<iostream>
using namespace std;
template<class T>
void isort(T *a,const int n)
{
	for(int j=2;j<=n;j++)
	{
		T temp=a[j];
		insert(temp,a,j-1);
	}
}
template<class T>
void insert(const T& e,T *a,int i)
{
	a[0]=e;
	while(e<a[i])
	{
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=e;
}
int main()
{
	int i,n;
	cout<<"Enter the size:";
	cin>>n;
	int a[n];
	cout<<"Enter the elements:";
	for(i=1;i<=n;i++)
		cin>>a[i];
	isort(a,n);
	for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
