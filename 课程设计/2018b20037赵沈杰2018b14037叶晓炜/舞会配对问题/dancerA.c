#include<stdio.h>
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
void inputdata(CirQueue *Q){
	FILE *fpRead = fopen("dancerA4.txt", "r");
	if(fpRead==NULL){
		printf("文件打开失败！"); 
		return;
	}
	fscanf(fpRead, "%d", &num);
    fscanf(fpRead, "\n");
    char temp[30];//临时变量存储 解析后再进行存储 
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
    Q->front = (Q->front+1)%Q->count;//实现循环队列 
    return x;
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
	if(Mdancers.count+Fdancers.count==1){
		printf("只有一人，无法配对！"); 
		return; 
	}
	if(Mdancers.count==0){
		printf("缺少男性，无法配对！"); 
		return; 
	}
	if(Fdancers.count==0){
		printf("缺少女性，无法配对！");
		return; 
	} 
	int rounds=minn(Mdancers.count,Fdancers.count);	
	for(int i=1;i<=3;i++){//匹配 
		printf("第%d轮舞伴：\n",i);
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
