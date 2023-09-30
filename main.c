#include <stdio.h>
#include <stdlib.h>

int dp(int n, int* G, int* V, int R)
{
    int a[R+1];

    for(int i = 0; i<=R; i++) //am initializat a-ul cu 0
        a[i]=0;

    for(int i=0; i<n; i++) //fiecare obiect de la 0 la n-1
        for(int j=R; j>= 0; j--) //pt fiecare greutate
        {
            if(G[i] <= j && V[i]+a[j-G[i]] > a[j])
                a[j]=V[i]+a[j-G[i]];
        }
    return a[R]; //ne folosim de greutatine mai mici ca R pt a afla R, de aia returnam pozitia R
}

int main()
{
    int n = 4; //nr de obiecte
    int G[]={1,4,5,8}; //greutatile obiectelor
    int V[]={10, 8, 15, 20}; //valorile obiectelor

    int R=12; //greutatea ruxacului

    int pmax;
    pmax= dp(n, G, V, R);
    printf("%d", pmax);
    return 0;
}
