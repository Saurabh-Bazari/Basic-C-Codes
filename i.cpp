#include <bits/stdc++.h>
using namespace std;

struct node
{
	int num;
	int s;
	int f;
	int p;
};

void merge(node data[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
   	node L[n1+1], R[n2+1];
 
    for (i = 0; i <= n1; i++)
        L[i] = data[l + i];
   

    for (j = 0; j <= n2; j++)
        R[j]= data[m + 1+ j] ;

    i = 0; 
    j = 0; 
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].f <= R[j].f)
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        data[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(node data[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        mergeSort(data, l, m);
        mergeSort(data, m+1, r);
        merge(data, l, m, r);
    }
}

int main(){

	int n,a,b,c;
	scanf("%d",&n);

	node data[n];

	for (int i = 0; i < n; ++i){

		data[i].num=i+1;
		scanf("%d %d %d",&a,&b,&c);

		data[i].s=a;
		data[i].f=b;
		data[i].p=c;
	}

	mergeSort(data,0,n-1);

	for (int i = 0; i < n; ++i)
	{
		
		// cout <<  data[i].s <<  data[i].f << data[i].p << data[i].num << endl;

	}

	int soln[n+1];

	for (int i = 1; i <= n; ++i)
	{
		soln[i]=-100;
	}

	soln[0]=0;

	


	return 0;
}