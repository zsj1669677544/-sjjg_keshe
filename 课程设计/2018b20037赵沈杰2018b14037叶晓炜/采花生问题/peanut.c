#include <stdio.h>
#include <stdlib.h>//abs()
#define MAXSIZE 1000
int n, m, limitTime,ans,k,next=1,nx,ny;//ans�洢��� k��¼ֲ���� next��¼��һ�����ֲ�� nxny��¼��ǰ���� 
struct node{
	int x,y,val;
}peanut[MAXSIZE];//��һ������洢ֲ����Ϣ 
void sort(int n){
	int i=1,tag;
	do{
		tag=0;
		for(int j=n;j>i;j--)
			if(peanut[j].val>peanut[j-1].val){
				struct node temp;
				temp=peanut[j];
				peanut[j]=peanut[j-1];
				peanut[j-1]=temp;
				tag=1;
			}
			i++;
	}while(tag==1&&i<=n);
}//��val�������� 
void inputdata(FILE *fp){
	if(fp==NULL){
		printf("�ļ���ʧ�ܣ�"); 
		return;
	}
	fscanf(fp, "%d %d %d", &n, &m, &limitTime); //��������ʱ�� 
	printf("%d %d %d\n",n,m,limitTime);
    fscanf(fp, "\n");
    int ipt;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++){
			if(fscanf(fp, "%d", &ipt)!=0){//��ά�������Ԫ�洢 ����0 ��ʡ�ռ� 
				peanut[++k].x=i;
				peanut[k].y=j;
				peanut[k].val=ipt;
			}	  
			printf("%2d ",ipt);
		} 
        fscanf(fp, "\n");
        printf("\n");
    }
} //�ļ����ݶ�ȡ 
void go(){
	ny=peanut[1].y;
	nx=1;
	limitTime--;//������һ�� 
	while(limitTime){
		if(limitTime-abs(peanut[next].x-nx)-abs(peanut[next].y-ny)-1-peanut[next].x>=0){
			limitTime -= abs(peanut[next].x-nx)+abs(peanut[next].y-ny) + 1;
            ans+=peanut[next].val;
            if(peanut[next].val==0)
            	break;
			nx=peanut[next].x;
			ny=peanut[next].y;
			next++;
		}else
			break;
	}
} 
int main()
{
    FILE *fpRead = fopen("peanut4.txt", "r");
    inputdata(fpRead);
    fclose(fpRead);
	sort(k);
	go();
	printf("���ɵ���%d������",ans);
    return 0;
}
//С�᣺��ʼ���˸�map[][]���� �������ֲ���Ҫ0��λ�� ֻҪֲ���xy��key��Ϣ�͹��� �����Դ��ϡ�����Ĵ���ʽ 
//����map����һά����洢 ��һ���ô��Ǳ���ÿһ����Ҫ��maxֲ�� Ҫ��������map ���һ��кܶ�0����Чλ�� ���˷�
//ֻ�洢ֲ����Ϣ�Ļ�  ֻҪ��key����һ������ �Ϳ���ֱ��ʹ���� 
