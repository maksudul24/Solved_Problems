#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("out.txt","w",stdout)
#define FI freopen("in.txt","r",stdin)
#define TFO freopen("Test_Output.txt","w",stdout)
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define SIZE 50
#define uu first
#define vv second
#define pii pair<int,int>

using namespace std;

ll int prime[1000000],nprime;
char mark[5001010];

void sieve(int n)
{
    int i,j,limit=sqrt(n*1.0)+2;
    prime[nprime++]=2;
    for(i=3;i<=n;i+=2){
        if(mark[i]!='1'){
            prime[nprime++]=i;
            if(i<=limit){
                for(j=i*i;j<=n;j+=i*2){
                    mark[j]='1';
                }
            }
        }
    }
    return;
}


int main()
{
    ll int i,j,cas=0,ts,ans,dis,n,m,total,temp,chk,mod=100000007,num;
    FI,FO;
   sieve(5000102);
    while(1){
        scanf("%lld",&n);
        if(n==0) break;
        total=1;
        for(i=0;prime[i]<=n;i++){
            num=prime[i];
            ans=0;
            while(n/num){
                if(n%num!=0){
                    temp=n/num;
                    temp=temp*num;
                }
                else temp=n;
                temp=temp-num;
                temp=temp/num;
                temp=(temp*(temp+1))/2;
                temp=temp*num;
                ans+=temp;
                temp=n%num;
                temp++;
                temp=temp*(n/num);
                ans+=temp;
               // printf("Temp:%d\n",temp);
                num=num*prime[i];
            }
            ans=ans%mod;
            total=(total*(ans+1))%mod;
       //     printf("Prime:%lld counts:%lld total:%lld\n",prime[i],ans,total);
        }
        printf("%lld\n",total);
    }
    return 0;
}

