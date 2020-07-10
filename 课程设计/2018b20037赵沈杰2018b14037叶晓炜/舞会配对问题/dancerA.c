#include<stdio.h>
#define MAXSIZE 30
typedef struct
{  	char name[20];  //�������������ÿλ��Ա���������Ȳ�����20���ַ�
	char sex;      //sex�ַ���������Ա�M��ʾ��ʿ��F��ʾŮʿ
}Person;
typedef struct
{  	int front;          /* ͷָ�룬�ӷǿ�ʱָ���ͷԪ�� */
	int rear;           /* βָ�룬�ӷǿ�ʱָ���βԪ�ص���һλ�� */
	int count;          /* ����������¼����Ԫ������ */
	Person dancer[MAXSIZE];
}CirQueue;
int num;
CirQueue Fdancers,Mdancers;
void inputdata(CirQueue *Q){
	FILE *fpRead = fopen("dancerA4.txt", "r");
	if(fpRead==NULL){
		printf("�ļ���ʧ�ܣ�"); 
		return;
	}
	fscanf(fpRead, "%d", &num);
    fscanf(fpRead, "\n");
    char temp[30];//��ʱ�����洢 �������ٽ��д洢 
    int k=0;
    while (!feof(fpRead)){ 
        fgets(temp,20,fpRead);  //��ȡһ��
        int i;
        k++;
        for(i=0;temp[i+3]!='\0';i++)
			Q->dancer[k].name[i]=temp[i];
		Q->dancer[k].sex=temp[i+1];
		Q->dancer[k].name[i]='\0';
    }
	fclose(fpRead);
}
void queueIn(CirQueue *Q,Person x){
	if((Q->rear+1)%MAXSIZE == Q->front)
		return;
	Q->dancer[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;
	Q->count++;
}
Person queueOut(CirQueue *Q){
    Person x= Q->dancer[Q->front];
    Q->front = (Q->front+1)%Q->count;//ʵ��ѭ������ 
    return x;
}
int minn(int a,int b){
	return a<=b?a:b;
}
void DancePartners(CirQueue *Q){
	for(int i=1;i<=num;i++){//���� 
		if(Q->dancer[i].sex=='M')
			queueIn(&Mdancers,Q->dancer[i]);
		else
			queueIn(&Fdancers,Q->dancer[i]);
	}
	if(Mdancers.count+Fdancers.count==1){
		printf("ֻ��һ�ˣ��޷���ԣ�"); 
		return; 
	}
	if(Mdancers.count==0){
		printf("ȱ�����ԣ��޷���ԣ�"); 
		return; 
	}
	if(Fdancers.count==0){
		printf("ȱ��Ů�ԣ��޷���ԣ�");
		return; 
	} 
	int rounds=minn(Mdancers.count,Fdancers.count);	
	for(int i=1;i<=3;i++){//ƥ�� 
		printf("��%d����飺\n",i);
		for(int j=0;j<rounds;j++){
			printf("%-20s%s\n",queueOut(&Fdancers).name,queueOut(&Mdancers).name);
		}
		printf("\n");
	}
}
int main(){
	CirQueue Q;
	inputdata(&Q);
	DancePartners(&Q);
	return 0;
}
