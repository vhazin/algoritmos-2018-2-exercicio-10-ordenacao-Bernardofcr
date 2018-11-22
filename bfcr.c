//
//  main.c
//  listaNatal2018
//
//  Created by Bernardo Russo on 19/11/18.
// Com agradecimentos a Otacilio Maia
//  Copyright © 2018 Bernardo Russo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char comp[2];
    char nome[21];
}crianca;

void swapElements(crianca *inputArray, int index1, int index2){
    crianca temporary = inputArray[index1];
    inputArray[index1] = inputArray[index2];
    inputArray[index2] = temporary;
}

int particao(crianca *criancaM, int low, int high)
{
    char *eixo = criancaM[high].nome;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (strcmp(criancaM[j].nome, eixo)<=0)
        {
            i++;
            swapElements(criancaM, i, j);
        }
    }
    swapElements(criancaM, i + 1, high);
    return (i + 1);
}

void quickSort(crianca *inputArray, int low, int high)
{
    if (low < high)
    {
        int indexP = particao(inputArray, low, high);
        quickSort(inputArray, low, indexP - 1);
        quickSort(inputArray, indexP + 1, high);
    }
}


int main() {
    int n,i=0,good=0,evil=0;
    scanf("%d",&n);
    crianca c[n];
    for (i=0; i<n; i++)
    {
        scanf("%s%s",c[i].comp,c[i].nome);
        if (c[i].comp[0] == '+')
            good++;
        else
            evil++;
    }
    quickSort(c,0,n-1);
    for (i=0; i<n; i++)
    {
        printf("%s\n",c[i].nome);
    }
    printf("Se comportaram: %d | Nao se comportaram: %d\n", good, evil);
    return 0;
}
