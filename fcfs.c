#include<stdio.h>

int* promedios(int n, int* bt, int* wt);


 
int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    
    printf("Indica el número total de procesos (maximo 20):");
    scanf("%d",&n);
 
    printf("\nIndica el tiempo de rafaga de CPU de cada proceso\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    wt[0]=0;  // Tiempo de espera para el primer proceso es 0

    // Calculando el tiempo de espera 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\nProceso\t\tTiempo rafaga CPU\tTiempo de espera\tTiempo de vuelta");
 
    //Calculando el tiempo de vuelta
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    int* arre = promedios(n, wt, tat);
    avwt = arre[0];
    avtat = arre[1];
 
    printf("\n\nTiempo de espera promedio:%d",avwt);
    printf("\nTiempo de vuelta promedio:%d\n",avtat);
 
    return 0;
}

int* promedios(int n, int* wt, int* tat){
    int i = 0;
    int avwt = 0;
    int avtat = 0;
    for(i = 0; i < n; i+=1){
        avwt+=wt[i];
        avtat+=tat[i];
    }

    avwt/=n;
    avtat/=n;

    int* arre = (int*)malloc(sizeof(int)*2);

    arre[0] = avwt;
    arre[1] = avtat;

    return arre;
}

