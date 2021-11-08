#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void putX(int index, int n3){
    int row=index/3;
    int col=index%3;
    int xpos, ypos, i, j, k;
    int size = 90, left = 105, top = 45;
    for(k = 0; k < 3; k++)
	{

		xpos = left;
		for(i = 0; i < 3; i++)
		{
			ypos = top;
			for(j = 0; j < 3; j++)
			{
		    if(i==row && j==col){
						setcolor(n3);
			line(xpos,  ypos, xpos + size, ypos + size);
			line(xpos + size, ypos, xpos, ypos + size);
		    }
				ypos += size;

			}
			xpos += size;
		}
	}
}

void putO(int index, int n){
    int row=index/3;
    int col=index%3;
    int xpos, ypos, i, j, k;
    int size = 90, left = 105, top = 45;
    for(k = 0; k < 3; k++)
	{

		xpos = left;
		for(i = 0; i < 3; i++)
		{
			ypos = top;
			for(j = 0; j < 3; j++)
			{
		    if(i==row && j==col){
						setcolor(n);
			circle(xpos + 45,  ypos + 45, 35);
		    }
				ypos += size;

			}
			xpos += size;
		}
	}
}

int isWin(int arr[3][3], int k){
	int i, j;
    for(i=0;i<3;i++){
	int count=0;
	for(j=0;j<3;j++){
	    if(arr[i][j]==k)count++;
	    if(count==3){
		return 1;
	    }
	}
    }
    for(i=0;i<3;i++){
       int count=0;
	for(j=0;j<3;j++){
	    if(arr[j][i]==k)count++;
	    if(count==3){
		return 1;
	    }
	}
    }
    if(arr[0][0]==k && arr[1][1]==k && arr[2][2]==k)return 1;
    if(arr[0][2]==k && arr[1][1]==k && arr[2][0]==k)return 1;

    return 0;
}

int main ()
{
     int xpos, ypos, i, j, k, ind, x[3][3], o[3][3], row, col, n, n1, n2, n3, ncount = 0, tag = 0;
	 int  num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
     char next[10];
	 int size = 90;
	 int gd = DETECT, gm;
	 initgraph(&gd, &gm, "C:\TDM-GCC-32\lib\bgi.a");
	 xpos = 105;
	 printf("\nEnter the number: ");
	 printf("\nBLUE: 1\nGREEN: 2\nRED: 3\nWHITE: 4\n");
	 printf("For O: ");
	 scanf("%d", &n1);
	 switch(n1) {

		 case 1: {n = 1;
			   break; }
		 case 2: {n = 2;
			      break;}
		 case 3: {n = 4;
		       break; }
		 case 4: {n = 15;
			  break;  }

	 }
	 printf("For X: ");
	 scanf("%d", &n2);
	 switch(n2) {

		 case 1: {n3 = 1;
			   break; }
		 case 2: {n3 = 2;
			      break;}
		 case 3: {n3 = 4;
		       break; }
		 case 4: {n3 = 15;
			  break;  }

	 }
	for(i = 0; i < 3; i++)
	{
		ypos = 45;
		for(j = 0; j < 3; j++)
		{
		rectangle(xpos + size - 30, ypos + size - 15, xpos + size, ypos + size);
			sprintf(next, "%d", num[ncount]);
			outtextxy(xpos + size - 22, ypos + size - 10, next);
			rectangle(xpos, ypos, xpos + size, ypos + size);
			ypos += size;
			ncount++;
		}
		xpos += size;
	}

    for(i=0;i<9;i++){
		if(i%2 == 0) {
	printf("Enter X:");
		}
		else {
			printf("Enter O:");
		}
	scanf("%d",&ind);

	row=ind/3;
	col=ind%3;

	if(i%2==0){
	    if(x[row][col]!=1 && x[row][col]!=2){
	       putX(ind, n3);
	       x[row][col]=1;
	       o[row][col]=2;
	       if(isWin(x,1)){
		tag = 1;
		printf("X-win");
		break;
	       }
	    }
	    else{
		printf("already marked\n");
		i--;
	    }

	}
	else{
	    if(x[row][col]!=1 && x[row][col]!=2){
	       putO(ind, n);
	       x[row][col]=2;
	       o[row][col]=1;
	       if(isWin(o,1)){
			   tag = 1;
		printf("O-win");
		break;
	       }
	    }
	    else{
		printf("already marked\n");
		i--;
	    }
	}
    }
  if(i == 9 && tag == 0) {
  printf("Tie!\n");
  }
  getch();
}
