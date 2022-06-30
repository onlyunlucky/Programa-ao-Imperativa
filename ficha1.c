#include <stdio.h>

void quadrado (int n){
    int i=0,j;
    while(i<n){
    for(j=0; j<n;j++)
        putchar('#');
    putchar('\n');    
    i++;    
    }
}

void xadrez (int n){
    int i, j=0;
    while(j<n){
        for(i=0;i<n;i++)
            if(i%2==0) putchar('#');
            else putchar('_');
        putchar('\n');
       j++;
    }
}

void trianguloH (int n){
    int i=1,j,k=0,z;
    while(i<=n){
        for(j=i;j>0;j--)
            putchar('#');
        putchar('\n');
    i++;    
    }
    while(k<n){
        for(z=k-n;z<0;z++)
            putchar('#');
        putchar('\n');
    k++;
    }
}

void trianguloV (int n){
    int i=0,j,c;
    while(i<n){
        int s = n-i;
        int d = i;
        for(j=0;j<s;j++)
            putchar(' ');
        for(c=0;c<=2*d;c++)
            putchar ('#');
        putchar('\n');
    i++;    
    }
}

oid circulo (int n){
    int x,y, cardinal = 0;
    for(y=n; y>=(-n);y--){
        for(x=(-n); x<=n;x++){
            if(x*x + y*y<=n*n){
                putchar('#');
                cardinal++;
            }
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}


