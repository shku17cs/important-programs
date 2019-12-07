 // to calculate the longest pallindromic substrings in a given string//
 #include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int l=0,m,lp,ci;
	lp=0;
	
	string cp;
	//to calculate the pallindromic substring with odd length//
	for(int ci=1;ci<s.length();ci++)
	{
		l=ci-1;
		m=ci+1;
		while(l>=0 && m<s.length())	
		{
			if(s.at(l)!=s.at(m))
			{
				break;
			}
			cp=s.substr(l,m+1);
			if(cp.length()>lp)
			{
				
				lp=cp.length();
			}
			l--;
			m++;
		}
		//to calculate the substrig   WHICH IS POSSIBLE with even length
			l=ci-1;
		m=ci;
			while(l>=0 && m<s.length())	
		{
			if(s.at(l)!=s.at(m))
			{
				break;
			}
			cp=s.substr(l,m+1);
			if(cp.length()>lp)
			{
				
				lp=cp.length();
			}
			l--;
			m++;
		}
		
	}
	cout<<lp<<endl;
	
	
}
