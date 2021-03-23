#include<stdio.h>
#include <stdbool.h>
#define ROW 4
#define COLUMN 4
int walk=0,path=0,a;
int calculate(int x,int y,int sum,bool maze[ROW][COLUMN]);
int main(){
	bool maze[ROW][COLUMN];

	/*input the map*/
	for(int i=0; i<COLUMN; i++){
		for(int j=0; j<ROW; j++){
			maze[i][j]=false;
		}
	}
	maze[0][0]=true;
	/*obstacle location*/
	int x,y,sum=15;
	while(scanf("%d,%d",&x,&y)!=EOF){	
		/*if (x==-1&&y==-1){
		  printf("path:2\n");
		  continue;
		  }
		  else{*/
		if(x==-1)
			break;
		maze[x][y]=true;
		sum-=1;

	}
	//path=0,walk=0;
	/*calculate the paths: caculatePath()*/
	//if(x!=-1&&y!=-1){
	a=calculate(0,0,sum,maze);
	printf("path:%d\n",path);
	//}
	return 0;
	}

	//int x=0,y=0;
	int calculate(int x,int y,int sum,bool maze[ROW][COLUMN]){

		/*Arrive successfully*/
		if(x==3&&y==0){
			if(walk==sum){
				walk--;
				maze[3][0]=false;
				//printf("yes%d ",walk);
				path=path+1;
				return 1;
			}
			else{
				walk--;
				//printf("X%d ",walk);
				maze[3][y]=false;
				return 0;
			}
		}
		if(x<3&&maze[x+1][y]==false){
			walk++;
			maze[x+1][y]=true;
			//printf("(%d,%d)%d ",x+1,y,walk);
			a=calculate(x+1,y,sum,maze);
		}
		if(y<3&&maze[x][y+1]==false){
			walk++;
			maze[x][y+1]=true;
			//printf("(%d,%d)%d ",x,y+1,walk);
			a=calculate(x,y+1,sum,maze);
		}
		if(x>0&&maze[x-1][y]==false){
			walk++;
			maze[x-1][y]=true;
			//printf("(%d,%d)%d ",x-1,y,walk);
			a=calculate(x-1,y,sum,maze);
		}
		if (y>0&&maze[x][y-1]==false){
			walk++;
			maze[x][y-1]=true;
			//printf("(%d,%d)%d ",x,y-1,walk);
			a=calculate(x,y-1,sum,maze);
		}
		walk--;
		//printf("(%d,%d)%d",x,y,walk);
		maze[x][y]=false;
		return 0;

	}
