//
//  main.c
//  listaNatal2018
//
//  Created by Bernardo Russo on 19/11/18.
//  Copyright © 2018 Bernardo Russo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char comp[2];
    char nome[21];
}crianca;

void swapElements(int *inputArray, int index1, int index2){
    int temporary = inputArray[index1];
    inputArray[index1] = inputArray[index2];
    inputArray[index2] = temporary;
}

int particao(int *inputArray, int low, int high)
{
    int eixo = inputArray[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (inputArray[j] <= eixo)
        {
            i++;
            swapElements(inputArray, i, j);
        }
    }
    swapElements(inputArray, i + 1, high);
    return (i + 1);
}

void quickSort(int *inputArray, int low, int high)
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
    char sinalBon[]="+";
   // char entrada[23], ch = '\0';
    for (i=0; i<n; i++)
    {
        scanf("%s%s",c[i].comp,c[i].nome);
        if (c[i].comp[0] == '+')
            good++;
        else
            evil++;
    }
    
    for (i=0; i<n; i++)
    {
        printf("%s%s\n",c[i].comp,c[i].nome);
    }
    printf("\nSe comportaram: %d | Nao se comportaram: %d", good, evil);
    return 0;
}
