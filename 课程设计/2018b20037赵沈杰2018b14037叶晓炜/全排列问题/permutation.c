#include<stdio.h>
#include<string.h>
char a[10];
int ans;
void swap(int x,int y){
	char temp;
	temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}
void pr(){
	for(int i=0;i<strlen(a);i++)
		printf("%c",a[i]);
	printf("\t");
}
void go(int b,int e){
	if(b==e){
		pr();
		ans++;
		if(ans%6==0)
			printf("\n");
		return;
	}
	for(int i=b;i<=e;i++){//这里i不能从b+1开始 因为要留一次自己和自己的交换 否则输出会少 
		swap(b,i);
		go(b+1,e);
		swap(b,i);
	}
}
int main(){
	printf("请输入要全排列的字符：\n");
	scanf("%s",a);
	go(0,strlen(a)-1); 
	printf("全排列个数：%d",ans); 
	return 0;
}
//思路 交换 递归
//操作A：对每一个字符串，暂定一个第一位，然后后面作为子串进行A，然后第一位和第2345位直到最后换位置，再进行A 
 
