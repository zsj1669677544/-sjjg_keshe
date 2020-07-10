#include<stdio.h>
#include<string.h>
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
Person sf,sm;
void inputdata(CirQueue *Q){
	FILE *fpRead = fopen("dancerB.txt", "r");
	if(fpRead==NULL){
		printf("�ļ���ʧ�ܣ�"); 
		return;
	}
	fscanf(fpRead, "%d", &num);
    fscanf(fpRead, "\n");
	char temp[30];//��ʱ�����洢 �������ٽ��д洢
//	
	int j;
    fgets(temp,20,fpRead);
    for(j=0;temp[j]!='\n';j++){
    	sf.name[j]=temp[j];    		
	}
	sf.name[j+1]='\0';
	fgets(temp,20,fpRead);
    for(j=0;temp[j]!='\n';j++){
    	sm.name[j]=temp[j];    		
	}
	sm.name[j+1]='\0';
//	
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
//    for(int i=1;i<=num;i++)
//    	printf("%c",Q->dancer[i].sex);
	fclose(fpRead);
}
void queueIn(CirQueue *Q,Person x){
	if((Q->rear+1)%MAXSIZE == Q->front)
		return;
	Q->dancer[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;
	Q->count++;
}
void queueOut(CirQueue *Q){//�����Ӳ������ 
	Q->front = (Q->front+1)%Q->count;
}
Person queueFront(CirQueue *Q){
	return Q->dancer[Q->front];
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
	int rounds=minn(Mdancers.count,Fdancers.count);	
	printf("%sŮʿ �� %s��������\n",sf,sm);
	
	for(int i=1;i<=10;i++){//10�� 
		for(int j=0;j<rounds;j++){
//			if (strcmp(sm.name, queueFront(&Mdancers).name) == 0)  
//        		printf("ƥ��ɹ�");  
//        	else
//        		printf("%d %d",Mdancers.front,Mdancers.rear);
			if(!strcmp(sm.name, queueFront(&Mdancers).name)&&!strcmp(sf.name, queueFront(&Fdancers).name)){
				printf("��%d����飺\n",i);
				printf("%-20s%s\n",queueFront(&Fdancers).name,queueFront(&Mdancers).name);
				printf("\n");
			}
			queueOut(&Fdancers),queueOut(&Mdancers);
		}
	}
}
int main(){
	CirQueue Q;
	inputdata(&Q);
	DancePartners(&Q);
	return 0;
}
