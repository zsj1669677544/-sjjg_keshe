#include<stdio.h>
#include<string.h>
#define MAXSIZE 30
typedef struct
{  	char name[20];  //存放姓名，假设每位人员的姓名长度不超过20个字符
	char sex;      //sex字符变量存放性别，M表示男士，F表示女士
}Person;
typedef struct
{  	int front;          /* 头指针，队非空时指向队头元素 */
	int rear;           /* 尾指针，队非空时指向队尾元素的下一位置 */
	int count;          /* 计数器，记录队中元素总数 */
	Person dancer[MAXSIZE];
}CirQueue;
int num;
CirQueue Fdancers,Mdancers;
Person sf,sm;
void inputdata(CirQueue *Q){
	FILE *fpRead = fopen("dancerB.txt", "r");
	if(fpRead==NULL){
		printf("文件打开失败！"); 
		return;
	}
	fscanf(fpRead, "%d", &num);
    fscanf(fpRead, "\n");
	char temp[30];//临时变量存储 解析后再进行存储
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
        fgets(temp,20,fpRead);  //读取一行
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
void queueOut(CirQueue *Q){//将出队操作拆分 
	Q->front = (Q->front+1)%Q->count;
}
Person queueFront(CirQueue *Q){
	return Q->dancer[Q->front];
}
int minn(int a,int b){
	return a<=b?a:b;
}
void DancePartners(CirQueue *Q){
	for(int i=1;i<=num;i++){//分组 
		if(Q->dancer[i].sex=='M')
			queueIn(&Mdancers,Q->dancer[i]);
		else
			queueIn(&Fdancers,Q->dancer[i]);
	}
	int rounds=minn(Mdancers.count,Fdancers.count);	
	printf("%s女士 和 %s先生共舞\n",sf,sm);
	
	for(int i=1;i<=10;i++){//10首 
		for(int j=0;j<rounds;j++){
//			if (strcmp(sm.name, queueFront(&Mdancers).name) == 0)  
//        		printf("匹配成功");  
//        	else
//        		printf("%d %d",Mdancers.front,Mdancers.rear);
			if(!strcmp(sm.name, queueFront(&Mdancers).name)&&!strcmp(sf.name, queueFront(&Fdancers).name)){
				printf("第%d轮舞伴：\n",i);
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
