#include<stdio.h>
#define MAXSIZE 30
int num,must,sum,last,limit1,limit2,slast=1;
struct node{
	int bgin;
	int end;
}meet[MAXSIZE],smeet[MAXSIZE];
void sort(struct node r[MAXSIZE],int n){
	int i=1,tag;
	do{
		tag=0;
		for(int j=n;j>i;j--)
			if(r[j].end<r[j-1].end){
				struct node temp;
				temp=r[j];
				r[j]=r[j-1];
				r[j-1]=temp;
				tag=1;
			}
			i++;
	}while(tag==1&&i<=n);
}//��end��������
void inputdata(){
	FILE *fpRead = fopen("meetB.txt", "r");
    fscanf(fpRead, "%d %d", &num,&must);
    fscanf(fpRead, "\n");
    for(int i=1;i<=must;i++){
    	fscanf(fpRead, "%d %d", &smeet[i].bgin,&smeet[i].end);
    	fscanf(fpRead, "\n");
	}
    for(int i=1;i<=num;i++){
    	fscanf(fpRead, "%d %d", &meet[i].bgin,&meet[i].end);
    	fscanf(fpRead, "\n");
	}
    fclose(fpRead);
} 
void go(){
	printf("���鰲�����£�\n"); 
    printf("��ʼʱ��\t����ʱ��\n");
	limit1=0,limit2=smeet[1].bgin; 
    for(int i=1;i<=num+must;i++){
    	if(meet[i].bgin>=limit1&&meet[i].end<=limit2){//������� 
    		if(meet[i].bgin<meet[last].end)
    			continue;
    		else{
    			printf("%d\t\t%d\n",meet[i].bgin,meet[i].end);
    			last=i;
    			sum++;
			}	
		}else{//�����limit1limit2������ڽ�β��������  
			if(smeet[slast].end==0) 
				continue;
			printf("%d\t\t%d\n",smeet[slast].bgin,smeet[slast].end);
			sum++;
			limit1=smeet[slast].end;
			if(slast==must)//����
			{
				limit2=10e5;
				slast++;// 
				continue;
			}
			limit2=smeet[slast+1].bgin;
			slast++;
		}
	}
    printf("ȡ������%d��",num-sum);
}
int main(){
	inputdata(); 
	sort(smeet,must);
    sort(meet,num);
    go();
	return 0;
}

