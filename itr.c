#include <stdlib.h>
#include <stdio.h>

int d;

void findmapping(char array1[],char array2[],int n,int m,int i,int j,int flag[][m+1]){

	if (i==0 )
	{
		for (int i1=j ; i1 > 0; --i1)
			printf("\tdash <--> %c\n",array2[j-1] );

		return;
	}

	if (j==0)
	{
		for (int i1=i ; i1 > 0; --i1)
			printf("\t%c <--> dash\n",array1[i-1] );
		
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

	optimalarray[0][0]=0;

	for (int i = 1; i <= n; ++i)
	{
		optimalarray[i][0]=optimalarray[i-1][0]+d;
	}

	for (int i = 1; i <= m; ++i)
	{
		optimalarray[0][i]=optimalarray[0][i-1]+d;
	}

	int a,b,c;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			a=optimalarray[i-1][j-1] + cost[i][j];
			b=optimalarray[i][j-1] + d;
			c=optimalarray[i-1][j] + d;

			if (a <= b && a <= c)
			{
				flag[i][j]=1;
				optimalarray[i][j]=a;
			}

			else if (b <= a && b <= c)
			{
				flag[i][j]=2;
				optimalarray[i][j]=b;
			}

			else if (c <= b && c <= a)
			{
				flag[i][j]=3;
				optimalarray[i][j]=c;
			}
		}
	}

	printf("\nOptimal Value:  %d\n\n", optimalarray[n][m] );

	printf("Mapping : \n\tArray1 <--> Array2\n");

	findmapping(array1,array2,n,m,n,m,flag);

	return 0;
}