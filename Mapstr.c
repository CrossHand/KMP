#include<string.h>
#include<iostream>
using namespace std;
void GetNext(char *p,int *next)
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 1;
	while (j < pLen)
	{
		//p[k]表示前缀，p[j]表示后缀
		if (k == -1) 
		{
			
			next[j] = 0;
			k=next[j];
			cout<<"k="<<k<<"  j="<<j<<"   next[j]="<<next[j]<<endl;
			j++;
			
		}
		else if(p[j-1]==p[k])
		{
			cout<<"fuck j="<<j<<endl;
			cout<<next[j-1]<<endl;
			next[j]=k+1;
			k=next[j];
			cout<<"k="<<k<<"  j="<<j<<"   next[j]="<<next[j]<<endl;
			j++;
			
		}
		else
		{
			k = next[k];
		}
	}
}
int main()
{
	char S[]="BBC ABCDAB ABCDABCDABDE";
	char P[]="ABCDABD";
	int Slen=strlen(S);
	int Plen=strlen(P);
	int next[Plen];
	GetNext(P,next);
	int i=0;
	int j=0;
	while((i<Slen)&&(j<Plen))
	{
		if(S[i]==P[j]){
		   i++;
		    j++;
		}
		else{
			i=i+j-next[j];//move the P,delta=j-next[j]
			j=0;
		}
		
	}
	if(j==Plen) cout<<"the map position:"<<i-j<<endl;
	else cout<<"wrong"<<endl;
	return 0;
}
