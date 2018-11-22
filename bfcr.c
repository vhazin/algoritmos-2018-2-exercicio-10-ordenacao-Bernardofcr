//
//  main.c
//  listaNatal2018
//
//  Created by Bernardo Russo on 19/11/18.
//  Copyright © 2018 Bernardo Russo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char comp;
    char nome[21];
}crianca;

int main() {
    int n,i=0,j=0;
    scanf("%d",&n);
    crianca c[n];
    char entrada[23], ch = '\0';
    while (i<n){
        do{
            scanf("%c",&ch);
            if (ch=='\0')
                break;
            entrada[j]=ch;
            j++;
        }while(1);
        if (j<23){
            while (j<23){
                entrada[j]='\0';
                j++;
            }
        }
        j=0;
        c[i].comp=entrada[0];
        while(j<21){
            c[i].nome[j]=entrada[2+j];
            j++;
        }
        j=0;
        i++;
    }
    i=0;
    while (i<n){
        printf("%c %s",c[i].comp,c[i].nome);
        i++;
    }
    
    return 0;
}
