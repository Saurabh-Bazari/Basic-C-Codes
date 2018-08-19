#include <stdlib.h>
#include <stdio.h>

int d;

int absolute(int a){

	if (a < 0)
		return -a;
	else
		return a;
}

int optimal(int m,int optimalarray[][m+1],int cost[][m+1],int n,int i,int j,int flag[][m+1]){

	if ( i>0 && j > 0 &&  optimalarray[i][j] != -1)
		return optimalarray[i][j];

	if (i==1 && j==1)
	{
		optimalarray[i][j]=cost[1][1];
		return cost[1][1];
	}

	if (i==0)
	{
		optimalarray[i][j]=d*j;
		return d*j;
	}

	if (j==0)
	{
		optimalarray[i][j]=d*i;
		return d*i;
	}

	int a=optimal(m,optimalarray,cost,n,i-1,j-1,flag) + cost[i][j];
	int b=optimal(m,optimalarray,cost,n,i,j-1,flag) + d;
	int c=optimal(m,optimalarray,cost,n,i-1,j,flag) + d;

	if (a <= b && a <= c)
	{
		flag[i][j]=1;
		optimalarray[i][j]=a;
		return a;
	}

	if (b <= a && b <= c)
	{
		flag[i][j]=2;
		optimalarray[i][j]=b;
		return b;
	}

	if (c <= b && c <= a)
	{
		flag[i][j]=3;
		optimalarray[i][j]=c;
		return c;
	}
}

void findmapping(char array1[],char array2[],int n,int m,int i,int j,int flag[][m+1]){

	if (i==0 )
	{
		for (int i1=0; i1 < j; ++i1)
			printf("\tdash <--> %c\n",array2[i1] );

		return;
	}

	if (j==0)
	{
		for (int i1=0 ; i1 < i; ++i1)
			printf("\t%c <--> dash\n",array1[i1] );
		
		return;
	}

	if (i==1 && j==1)
	{
		printf("\t%c <--> %c\n",array1[i-1],array2[j-1] );
		return;
	}

	int a=flag[i][j];

	if (a==1)
	{
		findmapping(array1,array2,n,m,i-1,j-1,flag);
		printf("\t%c <--> %c\n",array1[i-1],array2[j-1] );
	}

	else if (a==2)
	{
		findmapping(array1,array2,n,m,i,j-1,flag);
		printf("\tdash <--> %c\n",array2[j-1] );
	}

	else if (a==3)
	{
		findmapping(array1,array2,n,m,i-1,j,flag);
		printf("\t%c <--> dash\n",array1[i-1] );
	}

	return;
}

int main(){

	int n,m;	
	printf("Enter number of rows , coloum , and gap palenty\n");
	scanf("%d %d %d",&n,&m,&d);

	char array1[n],array2[m];
	printf("Enter first string of %d char\n",n);
	scanf("%s",array1);	
	printf("Enter second string of %d char\n",m);
	scanf("%s",array2);
	printf("Enter table of %d*%d of cost values \n",n,m);

	int cost[n+1][m+1],flag[n+1][m+1],optimalarray[n+1][m+1];

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d",&cost[i][j]);
			flag[i][j]=0;
		}
	}

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			optimalarray[i][j]=-1;
		}
	}

	int ans = optimal(m,optimalarray,cost,n,n,m,flag);

	optimalarray[n][m] = ans;

	printf("\nOptimal Value:  %d\n\n", optimalarray[n][m] );

	printf("Mapping : \n\tArray1 <--> Array2\n");

	findmapping(array1,array2,n,m,n,m,flag);

	return 0;
}