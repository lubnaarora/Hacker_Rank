#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
 
int main()
{
    int t; 
	cin>>t;
	for(int i=0;i<t;i++)
    {
        ll n,ans=0; 
		cin>>n;
        ll hashTable[1001]={0}; 
        ll a[n]; for(int i=0;i<n;i++) 
		{
			 cin>>a[i]; 
			 hashTable[a[i]]++;
		}
        for(int i=1;i<1001;i++)
         {
             for(int j=i; j<1001; j++)
              {
                  int s,c;
                  s=sqrt(i+j);
                  c=cbrt(i+j);
                  if((i+j) == s*s || (i+j)==c*c*c){
                      if(i==j){
                          ans = ans + hashTable[i]*(hashTable[i]-1)/2;
                      }
                      else ans=ans+hashTable[i]*hashTable[j];
                  }
              }
         }
         cout<<ans<<endl;
    }
}
