#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,count,max;
	cin>>n;
	int ar[n];
	int ar1[n];
	for(i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	ar1[0]=1;
	
	for(i=1;i<n;i++)
	{
		
		ar1[i]=1;
		max=1;
		for(j=i-1;j>=0;j--)
		{
			
			if(ar[j]<ar[i])
			{
				ar1[i]=ar1[j]+1;
				if(ar1[i]>max)
				{
					max=ar1[i];
				}
			}
		}
		ar1[i]=max;
	}
	max=ar1[0];
	for(i=0;i<n;i++)
	{
		if(ar1[i]>max)
		{
			max=ar1[i];
		}
	}
	cout<<max<<endl;
	return 0;
}
