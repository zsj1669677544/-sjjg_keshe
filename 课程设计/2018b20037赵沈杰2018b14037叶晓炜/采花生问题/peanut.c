#include <stdio.h>
#include <stdlib.h>//abs()
#define MAXSIZE 1000
int n, m, limitTime,ans,k,next=1,nx,ny;//ans存储结果 k记录植株数 next记录下一个最佳植株 nxny记录当前坐标 
struct node{
	int x,y,val;
}peanut[MAXSIZE];//用一个数组存储植株信息 
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
}//按val降序排序 
void inputdata(FILE *fp){
	if(fp==NULL){
		printf("文件打开失败！"); 
		return;
	}
	fscanf(fp, "%d %d %d", &n, &m, &limitTime); //输入行列时间 
	printf("%d %d %d\n",n,m,limitTime);
    fscanf(fp, "\n");
    int ipt;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++){
			if(fscanf(fp, "%d", &ipt)!=0){//二维数组改三元存储 舍弃0 节省空间 
				peanut[++k].x=i;
				peanut[k].y=j;
				peanut[k].val=ipt;
			}	  
			printf("%2d ",ipt);
		} 
        fscanf(fp, "\n");
        printf("\n");
    }
} //文件数据读取 
void go(){
	ny=peanut[1].y;
	nx=1;
	limitTime--;//跳到第一行 
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
	printf("最多采到了%d个花生",ans);
    return 0;
}
//小结：开始搞了个map[][]数组 后来发现不需要0的位置 只要植株的xy和key信息就够了 灵感来源于稀疏矩阵的处理方式 
//放弃map改用一维数组存储 另一个好处是本来每一步都要找max植株 要遍历整个map 而且还有很多0的无效位置 很浪费
//只存储植株信息的话  只要按key进行一次排序 就可以直接使用了 
