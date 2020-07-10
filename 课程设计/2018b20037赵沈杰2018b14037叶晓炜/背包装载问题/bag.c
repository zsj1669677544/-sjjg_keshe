#include<stdio.h>
#include<math.h>
#include <string.h>
#define MAXSIZE 30
int c1,c2,n;
int ans1,sum,flag,max;
int w[MAXSIZE],vis[MAXSIZE];//w�洢�����飬visΪ1��ŵ�c1 
void inputdata(){
	scanf("%d %d",&c1,&c2);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		sum+=w[i];
	}
}
void pr(){
	printf("book\t");
	for(int i=1;i<=n;i++)
		printf("%-5d",w[i]);
	printf("\nc1\t");
	for(int i=1;i<=n;i++)
		printf("%-5d",vis[i]);
	printf("\nc2\t");
	for(int i=1;i<=n;i++)
		printf("%-5d",1-vis[i]);
}
int maxn(int a,int b){
	return a>b?a:b;
}
int check(int val,int k){//c1����͵�k������һ�����ϣ���ӽ�c1;��ֵ��������ͬ��0-1�������� 
	int dp[200];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=k;i++)
		for(int j=c1;j>=w[i];j--)  
			dp[j] = maxn(dp[j - w[i]] + w[i], dp[j]);
	if(dp[c1]<=c1&&dp[c1]>max)//dp[c1]��¼��c1�����Ŵ洢���������� 
		max=dp[c1];
	if(max>val)//�������װ�ĸ��� 
		return 1;	
	return 0;
}

void dfs(int k) { 
	if(flag)
		return;
    if(k==n+1){    
		if(ans1<=c1&&sum-ans1<=c2){
			if(ans1<max)
				return;
			pr();
			flag=1;
			return;
		}
 	}else{   
	 	if(ans1+w[k]<=c1){  
 			ans1 += w[k];
 			vis[k]=1;
 			dfs(k+1);
 			ans1 -= w[k];
 			vis[k]=0;
		}else if(check(ans1,k)){
 			return;//������һ�� 
		}
 		dfs(k+1); 
	}
} 
int main(){
	inputdata(); 
	dfs(1);
	if(!flag) 
		printf("Unsolvable");
	return 0;
}
