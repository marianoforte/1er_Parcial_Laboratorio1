#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "petStructure.h"
#include "breedStructure.h"

void hardcodePet(sPet listing[], int quant)
{
    int id[5] = {1, 2, 3, 4, 5};
    char name[5][20] = {"Bobby", "Lisa", "Nestor", "Eva", "Luke"};
    char age[5] = {1, 5, 7, 3, 2};
    char sex[5] = {'M', 'F', 'M', 'F', 'M'};
    float weight[5] = {2.6, 25, 1.7, 13, 3.1};
    char type[5][10] = {"Gato", "Perro","Gato", "Perro","Gato"};
    int idBreed[5] = {1, 4, 3, 2, 3};
    int isEmpty[5] = {0,0,0,0,0};
    int i;

    for(i = 0; i <= 4; i++)
    {
        listing[i].idPet =  id[i];
        strcpy(listing[i].name, name[i]);
        listing[i].age = age[i];
        listing[i].sex = sex[i];
        listing[i].weight = weight[i];
        strcpy(listing[i].type, type[i]);
        listing[i].idBreed = idBreed[i];
        listing[i].isEmpty = isEmpty[i];
    }
}
