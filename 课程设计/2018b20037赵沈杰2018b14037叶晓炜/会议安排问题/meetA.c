#include<stdio.h>
#define MAXSIZE 30
int num,sum=1,last=1;
struct node{
	int begin;
	int end;
	int vis; 
}meet[MAXSIZE];
void sort(int n){
	int i=1,tag;
	do{
		tag=0;
		for(int j=n;j>i;j--)
			if(meet[j].end<meet[j-1].end){
				struct node temp;
				temp=meet[j];
				meet[j]=meet[j-1];
				meet[j-1]=temp;
				tag=1;
			}
			i++;
	}while(tag==1&&i<=n);
}//��end�������� 
void inputdata(){
	FILE *fpRead = fopen("meetA.txt", "r");
    fscanf(fpRead, "%d", &num);
    for(int i=1;i<=num;i++)
    	fscanf(fpRead, "%d %d", &meet[i].begin,&meet[i].end);
    fclose(fpRead);
}
void go(){
	printf("���鰲�����£�\n"); 
    printf("��ʼʱ��\t����ʱ��\n");
    meet[1].vis=1;
    for(int i=2;i<=num;i++){
    	if(meet[i].begin<meet[last].end)
    		continue;
    	else{
    		meet[i].vis=1;
    		last=i;
    		sum++;
		}
	}
	for(int i=1;i<=num;i++){
		if(meet[i].vis)
			printf("%d\t\t%d\n",meet[i].begin,meet[i].end);
	}
    printf("ȡ������%d��",num-sum);
}
int main(){
	inputdata();
    sort(num);
    go();
	return 0;
}
//˼· ̰�� ������ʱ���������� Ȼ��ȥ���غϼ��� 
