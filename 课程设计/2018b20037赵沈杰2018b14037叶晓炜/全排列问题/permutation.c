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
	for(int i=b;i<=e;i++){//����i���ܴ�b+1��ʼ ��ΪҪ��һ���Լ����Լ��Ľ��� ����������� 
		swap(b,i);
		go(b+1,e);
		swap(b,i);
	}
}
int main(){
	printf("������Ҫȫ���е��ַ���\n");
	scanf("%s",a);
	go(0,strlen(a)-1); 
	printf("ȫ���и�����%d",ans); 
	return 0;
}
//˼· ���� �ݹ�
//����A����ÿһ���ַ������ݶ�һ����һλ��Ȼ�������Ϊ�Ӵ�����A��Ȼ���һλ�͵�2345λֱ�����λ�ã��ٽ���A 
 
