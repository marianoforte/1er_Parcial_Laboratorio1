#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "breedStructure.h"


void hardcodeBreed(sBreed listing[], int quant)
{
    int idBreed[4] = {1, 2, 3, 4};
    char description[4][20] = {"Siames", "Doberman", "Persa", "Pastor Belga"};
    char size[4][20] = {"Chico", "Grande", "Chico", "Grande"};
    char originCountry[4][20] = {"Tailandia", "Alemania", "Persia", "Belgica"};
    int isEmpty [4] = {0,0,0,0};
    int i;

    for(i = 0; i <= 4; i++)
    {
        listing[i].idBreed =  idBreed[i];
        strcpy(listing[i].description, description[i]);
        strcpy(listing[i].size, size[i]);
        strcpy(listing[i].originCountry, originCountry[i]);
        listing[i].isEmpty = isEmpty[i];
    }
}


