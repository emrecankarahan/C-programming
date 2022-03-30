#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

void printboard(int**);
void finish(int,int**);
void  returntonest(int,int**);
void leavefromnest(int ,int**);
void piecelocation(int ,int*[],int*[]);

int main(){
	system("COLOR 2");
	
	int **gameboard,i,j,dice,complete=1,turn=0,temp1[4],choice,tmp;
	
	int *temp[4];
	temp[0]=&temp1[0];temp[1]=&temp1[1];temp[2]=&temp1[2];temp[3]=&temp1[3];
	int *arr[32];
	gameboard=(int**)calloc(9,sizeof(int*));
	for(i=0;i<9;i++)
	gameboard[i]=(int*)calloc(9,sizeof(int));
	for(i=0;i<4;i++)
	arr[i]=&gameboard[3][i];
	for(i=2 ,j=4; i>=0 ;i--,j++)
	arr[j]=&gameboard[i][3];
	arr[7]=&gameboard[0][4];
	for(i=0;i<4;i++)
	arr[i+8]=&gameboard[i][5];
	for(i=6;i<9;i++)
	arr[6+i]=&gameboard[3][i];
	arr[15]=&gameboard[4][8];
	for(i=8 ,j=16 ; i>4 ; i-- ,j++)
	arr[j]=&gameboard[5][i];
	for(i=0;i<3;i++)
	arr[i+20]=&gameboard[i+6][5];
	arr[23]=&gameboard[8][4];
	for(i=8, j=24;i>4 ; i--, j++)
	arr[j]=&gameboard[i][3];
	for(i=2 ,j=28 ;i>=0; i-- , j++)
	arr[j]=&gameboard[5][i];
	arr[31]=&gameboard[4][0];
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			gameboard[i][j]=1;
		}
	}
	for(i=0;i<2;i++){
		for(j=7;j<9;j++){
			gameboard[i][j]=2;
		}
	}
	for(i=7;i<9;i++){
		for(j=0;j<2;j++){
			gameboard[i][j]=3;
		}
	}
	for(i=7;i<9;i++){
		for(j=7;j<9;j++){
			gameboard[i][j]=4;
		}
	}
	srand(time(NULL));
	printboard(gameboard);
	while(complete==1){
		printf("Player %d's turn.",(turn%4)+1);
		dice=(rand()%6)+1;
		printf("Number of dice:  %d.",dice);
		printboard(gameboard);
		if(((turn%4)+1)==1){
			if(gameboard[0][0]==1 && gameboard[0][1]==1 && gameboard[1][0]==1 &&gameboard[1][1]==1 ){
			if(dice!=6){
				printf("Skip\n");	
			}
			else{
				if(*arr[0]!=0){
					returntonest(*arr[0],gameboard);
				}
				*arr[0]=1;gameboard[0][0]=0;
			}
			}
			else if(gameboard[1][1]+gameboard[1][0]+gameboard[0][1]+gameboard[4][3]+gameboard[4][2]+gameboard[4][1]==4){
				printf("Skip\n");
			}
			else if(dice==6 && gameboard[3][0]!=1 && gameboard[1][0]==1){
					printf("Press 1 to release a new piece   Press 2 to move selected piece in the gameboard");
					scanf("%d",&choice);
					if(choice==1){	
						if(gameboard[3][0]!=0){
							returntonest(*arr[0],gameboard);
						}
						leavefromnest(1,gameboard);
					}
					else{
						piecelocation(1,temp,arr);
						printf("Choose the piece: "); 
						scanf("%d",&choice);	
					if((*temp[choice-1]+dice) < 31){
					if(*arr[*temp[choice-1]+dice]!=1){
					if(*arr[*temp[choice-1]+dice]!=0){ 
					returntonest(*arr[*temp[choice-1]+dice],gameboard);
					}
					*arr[*temp[choice-1]+dice]=1;
					*arr[*temp[choice-1]]=0;
					}
				else{
					printf("YOU CANT MOVE THAT PIECE");
					}
			}
			else{
				finish(1,gameboard);
				*arr[*temp[choice-1]]=0;
			}
					}
			
			}

			else{
				piecelocation(1,temp,arr);
				printf("Choose the piece: "); 
				scanf("%d",&choice);	
				if((*temp[choice-1]+dice) < 31){
				if(*arr[*temp[choice-1]+dice]!=1){
				if(*arr[*temp[choice-1]+dice]!=0){ 
				returntonest(*arr[*temp[choice-1]+dice],gameboard);
				}
				*arr[*temp[choice-1]+dice]=1;
				*arr[*temp[choice-1]]=0;
				}
			else{
				printf("YOU CANT MOVE THAT PIECE");
				}
			}
			else{
				finish(1,gameboard);
				*arr[*temp[choice-1]]=0;
			}
			
		}
	}
		else if(((turn%4)+1)==2){
			if(gameboard[0][7]==2 && gameboard[0][8]==2 && gameboard[1][7]==2 &&gameboard[1][8]==2 ){
			if(dice!=6){
				printf("Skip\n");	
			}
			else{
				if(*arr[8]!=0){
					returntonest(*arr[8],gameboard);
				}
				*arr[8]=2;gameboard[0][7]=0;
				
			}
			}
			else if(gameboard[0][8]+gameboard[1][7]+gameboard[1][8]+gameboard[3][4]+gameboard[1][4]+gameboard[2][4]==8){
				printf("Skip\n");
			}
			else if(dice==6 && gameboard[0][5]!=2 && gameboard[1][7]==2){
					printf("Press 1 to release a new piece   Press 2 to move selected piece in the gameboard");
					scanf("%d",&choice);
					if(choice==1){
						if(gameboard[0][5]!=0){
							returntonest(*arr[8],gameboard);
						}
						leavefromnest(2,gameboard);
					}
					else{
					piecelocation(2,temp,arr);
					printf("Choose the piece: "); 
					scanf("%d",&choice);
					tmp=*temp[choice-1]+dice;
					tmp=tmp%32;
					if((tmp-dice) > 7 || tmp < 7){
					if(*arr[tmp]!=2){
					if(*arr[tmp]!=0){ 
					returntonest(*arr[tmp],gameboard);
					}
					*arr[tmp]=2;
					*arr[*temp[choice-1]]=0;
					}
					else{
					printf("YOU CANT MOVE THAT PIECE");
					}
					}
				else{
				finish(2,gameboard);
				*arr[*temp[choice-1]]=0;
				}
				}
			}
	
			else{
					piecelocation(2,temp,arr);
					printf("Choose the piece: "); 
					scanf("%d",&choice);
					tmp=*temp[choice-1]+dice;
					tmp=tmp%32;
					if((tmp-dice) > 7 || tmp < 7){
					if(*arr[tmp]!=2){
					if(*arr[tmp]!=0){ 
					returntonest(*arr[tmp],gameboard);
					}
					*arr[tmp]=2;
					*arr[*temp[choice-1]]=0;
					}
					else{
					printf("YOU CANT MOVE THAT PIECE");
					}
					}
				else{
				finish(2,gameboard);
				*arr[*temp[choice-1]]=0;
				}	
					
				}
			}
			
			
		else if(((turn%4)+1)==3){
			if(gameboard[7][0]==3 && gameboard[8][0]==3 && gameboard[7][1]==3 &&gameboard[8][1]==3 ){
				if(dice!=6){
					printf("Skip\n");	
				}
				else{
					if(*arr[24]!=0){
					returntonest(*arr[24],gameboard);
				}
				*arr[24]=3;gameboard[7][0]=0;
				}
			}
			else if(gameboard[7][1]+gameboard[8][1]+gameboard[8][0]+gameboard[5][4]+gameboard[6][4]+gameboard[7][4]==12){
				printf("Skip\n");
			}	
			else if(dice==6 && gameboard[8][3]!=3 && gameboard[8][0]==3){
					printf("Press 1 to release a new piece   Press 2 to move selected piece in the gameboard");
					scanf("%d",&choice);
					if(choice==1){
				if(gameboard[8][3]!=0){
						returntonest(*arr[24],gameboard);
					}
		if(gameboard[7][0]==3){
			gameboard[8][3]=3;
			gameboard[7][0]=0;
		
		}
		else if(gameboard[7][1]==3){
			gameboard[8][3]=3;
			gameboard[7][1]=0;
			
		}
		else if(gameboard[8][1]==3){
			gameboard[8][1]=0;
			gameboard[8][3]=3;
				
		}
		else{
			gameboard[8][0]=0;
			gameboard[8][3]=3;	
				
		}							
			
					}
				else{
					piecelocation(3,temp,arr);
					printf("Choose the piece: "); 
					scanf("%d",&choice);
					tmp=*temp[choice-1]+dice;
					tmp=tmp%32;
					if((tmp-dice) > 23 || tmp < 23){
					if(*arr[tmp]!=3){
					if(*arr[tmp]!=0){ 
					returntonest(*arr[tmp],gameboard);
					}
					*arr[tmp]=3;
					*arr[*temp[choice-1]]=0;
					}
					else{
					printf("YOU CANT MOVE THAT PIECE");
					}
					}
				else{
				finish(3,gameboard);
				*arr[*temp[choice-1]]=0;
				}	
					
				}
					printf("Degismis eleman= %d",gameboard[7][1]);
			}	
	
			else{
					piecelocation(3,temp,arr);
					printf("Choose the piece:"); 
					scanf("%d",&choice);
					tmp=*temp[choice-1]+dice;
					tmp=tmp%32;
					if((tmp-dice) > 23 || tmp < 23){
					if(*arr[tmp]!=3){
					if(*arr[tmp]!=0){ 
					returntonest(*arr[tmp],gameboard);
					}
					*arr[tmp]=3;
					*arr[*temp[choice-1]]=0;
					}
					else{
					printf("YOU CANT MOVE THAT PIECE");
					}
					}
				else{
				finish(3,gameboard);
				*arr[*temp[choice-1]]=0;
				}					
				
				
			}
			}
			
		
		else{
			if(gameboard[7][7]==4 && gameboard[7][8]==4 && gameboard[8][7]==4 &&gameboard[8][8]==4 ){
			if(dice!=6){
				printf("Skip\n");	
			}
			else{
				if(*arr[16]!=0){
					returntonest(*arr[16],gameboard);
				}
				*arr[16]=4;gameboard[7][7]=0;
			}
			}
			else if(gameboard[7][8]+gameboard[8][8]+gameboard[8][7]+gameboard[4][5]+gameboard[4][6]+gameboard[4][7]==16){
				printf("Skip\n");
			}
			else if(dice==6 && gameboard[5][8]!=4 && gameboard[8][7]==4){
					printf("Press 1 to release a new piece   Press 2 to move selected piece in the gameboard");
					scanf("%d",&choice);
					if(choice==1){
						if(gameboard[5][8]!=0){
							returntonest(*arr[16],gameboard);
						}
		if(gameboard[7][7]==4){
			gameboard[5][8]=4;
			gameboard[7][7]=0;
			
		}
		else if(gameboard[7][8]==4){
			gameboard[7][8]=0;
			gameboard[5][8]=4;
			
		}
		else if(gameboard[8][8]==4){
			gameboard[8][8]=0;
			gameboard[5][8]=4;
				
		}
		else{
			gameboard[8][7]=0;
			gameboard[5][8]=4;
			
		}	

					}
					else{
					piecelocation(4,temp,arr);
					printf("Choose the piece:  "); 
					scanf("%d",&choice);
					tmp=*temp[choice-1]+dice;
					tmp=tmp%32;
					if((tmp-dice) > 15 || tmp < 15){
					if(*arr[tmp]!=4){
					if(*arr[tmp]!=0){ 
					returntonest(*arr[tmp],gameboard);
					}
					*arr[tmp]=4;
					*arr[*temp[choice-1]]=0;
					}
					else{
					printf("YOU CANT MOVE THAT PIECE");
					}
					}
				else{
				finish(4,gameboard);
				*arr[*temp[choice-1]]=0;
				}							
					}
					printf("Degismis eleman= %d",gameboard[7][8]);
				}
				else{
					piecelocation(4,temp,arr);
					printf("Choose the piece:"); 
					scanf("%d",&choice);
					tmp=*temp[choice-1]+dice;
					tmp=tmp%32;
					if((tmp-dice) > 15 || tmp < 15){
					if(*arr[tmp]!=4){
					if(*arr[tmp]!=0){ 
					returntonest(*arr[tmp],gameboard);
					}
					*arr[tmp]=4;
					*arr[*temp[choice-1]]=0;
					}
					else{
					printf("YOU CANT MOVE THAT PIECE");
					}
					}
				else{
				finish(4,gameboard);
				*arr[*temp[choice-1]]=0;
				}					
					
				}

			}
		
	
		
		if(gameboard[0][4]==2 && gameboard[1][4]==2 && gameboard[2][4]==2 && gameboard[3][4]==2){
			complete=0;
			printf("Player 2 won.");
		}
		else if(gameboard[4][0]==1 &&gameboard[4][1]==1 &&gameboard[4][2]==1 &&gameboard[4][3]==1 ){
			complete=0;
			printf("Player 1 won.");
		}
		else if(gameboard[4][5]==4 &&gameboard[4][6]==4 &&gameboard[4][7]==4 &&gameboard[4][8]==4 ){
			complete=0;
			printf("Player 4 won.");
		}
		else if(gameboard[5][4]==3 && gameboard[6][4]==3 && gameboard[7][4]==3 && gameboard[8][4]==3 ){
			complete=0;
			printf("Player 3 won.");
		}
		else{
			printf("Turn %d : \n ",turn+1);
			turn++;
		}
	
	
}
}
void printboard(int **matrix){
	int i,j; 
	printf("GAMEBOARD : \n");
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

void finish(int n,int **matrix){
	if(n==1){
		if(matrix[4][3]!=1){
			matrix[4][3]=1;
		}
		else if(matrix[4][2]!=1){
			matrix[4][2]=1;
		}
		else if(matrix[4][1]!=1){
			matrix[4][1]=1;
		}
		else{
			matrix[4][0]=1;
		}
	}
	else if(n==2){
		if(matrix[3][4]!=2){
			matrix[3][4]=2;
		}
		else if(matrix[2][4]!=2){
			matrix[2][4]=2;
		}
		else if(matrix[1][4]!=2){
			matrix[1][4]=2;
		}
		else{
			matrix[0][4]=2;
		}		
		
	}
	else if(n==3){
		if(matrix[5][4]!=3){
			matrix[5][4]=3;
		}
		else if(matrix[6][4]!=3){
		    matrix[6][4]=3;
		}
		else if(matrix[7][4]!=3){
			matrix[7][4]=3;
		}
		else{
			matrix[8][4]=3;
		}	
		
	}
	else{
		if(matrix[4][5]!=4){
			matrix[4][5]=4;
		}
		else if(matrix[4][6]!=4){
			matrix[4][6]=4;
		}
		else if(matrix[4][7]!=4){
			matrix[4][7]=4;
		}
		else{
			matrix[4][8]=4;
		}	
		
	}
	
}
void  returntonest(int n,int **matrix){
	if(n==1){
		if(matrix[1][0]==0){
			matrix[1][0]=1;
		}
		else if(matrix[1][1]==0){
			matrix[1][1]=1;
		}
		else if(matrix[0][1]==0){
			matrix[0][1]=1;
		}
		else {
			matrix[0][0]=1;
		}
		
	}
	else if(n==2){
		if(matrix[1][7]==0){
			matrix[1][7]=2;
		}
		else if(matrix[1][8]==0){
		matrix[1][8]=2;
		}
		else if(matrix[0][8]==0){
			matrix[0][8]=2;
		}
		else {
			matrix[0][7]=2;
		}
		
	}
	else if(n==3){
		if(matrix[8][0]==0){
			matrix[8][0]=3;
		}
		else if(matrix[8][1]==0){
			matrix[8][1]=3;
		}
		else if(matrix[7][1]==0){
			matrix[7][1]=3;
		}
		else {
			matrix[7][0]=3;
		}
		
	}
	else{
		if(matrix[8][7]==0){
			matrix[8][7]=4;
		}
		else if(matrix[8][8]==0){
			matrix[8][8]=4;
		}
		else if(matrix[7][8]==0){
			matrix[7][8]=4;
		}
		else {
			matrix[7][7]=4;
		}
		
	}
}
void leavefromnest(int piece,int **matrix){
	if(piece==1){
		if(matrix[0][0]==1){
			matrix[3][0]=1;
			matrix[0][0]=0;
		}
		else if(matrix[0][1]==1){
		    matrix[0][1]=0;
			matrix[3][0]=1;
		}
		else if(matrix[1][1]==1){
			matrix[1][1]=0;
			matrix[3][0]=1;
		}
		else{
			matrix[1][0]=0;
		matrix[3][0]=1;	
		}	
	}
	else if(piece==2){
		if(matrix[0][7]==2){
			matrix[0][5]=2;
			matrix[0][7]=0;
		}
		else if(matrix[0][8]==2){
			matrix[0][8]=0;
			matrix[0][5]=2;
		}
		else if(matrix[1][8]==2){
			matrix[1][8]=0;
			matrix[0][5]=2;
		}
		else{
		matrix[1][7]=0;
			matrix[0][5]=2;	
		}	
		
		
	}

}
void piecelocation(int piece,int *temp[],int *ptr[]){
	int i=0,j=0;
	for(i=0;i<32;i++){
		if(*ptr[i]==piece){ 
			*temp[j]=i;
			printf("%d. piece :   %d\n",j+1,i); 
			j++;
		}
	}
}


