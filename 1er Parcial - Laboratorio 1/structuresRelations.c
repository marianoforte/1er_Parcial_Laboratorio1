#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "petStructure.h"
#include "breedStructure.h"
#include "structuresRelations.h"
#include "structureManagement.h"
#include "abm.h"

void printPetAndBreed(sPet petListing[], int quantPetListing, sBreed breedListing[], int quantBreedListing)
{
    int i;
    int breedIndex;

    if(petListing != NULL && quantPetListing > 0)
    {
        printf("\n\t\t\t\t\tListado de Mascotas\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("\n|ID   |NOMBRE        |EDAD  |SEXO  |PESO (gr.) |TIPO     |RAZA           |TAMA%cO     |PAIS DE ORIGEN\n",165);
        printf("-----------------------------------------------------------------------------------------------------\n");
        for(i = 0; i < quantPetListing; i++)
        {
            breedIndex = searchBreed(breedListing, quantBreedListing, petListing[i].idBreed);
            if(petListing[i].isEmpty == 0)
            {
                printf("|%-4d |%-13s |%-5d |%-5c |%-10.3f |%-8s |%-14s |%-10s |%-10s\n", petListing[i].idPet, petListing[i].name, petListing[i].age, petListing[i].sex, petListing[i].weight, petListing[i].type, breedListing[breedIndex].description, breedListing[breedIndex].size, breedListing[breedIndex].originCountry);
            }
        }
    }
    else
    {
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tNo se han ingresado mascotas por el momento\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
    }
}

void printBreedList(sPet petListing[], sBreed breedListing[],int quantPets, int quantBreeds, int id)
{
    int i;
    int breedIndex;

    if(petListing != NULL && quantPets > 0)
    {
        printf("\n\t\t\t\t\tListado de Razas\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("|RAZA           |TAMA%cO     |PAIS DE ORIGEN |NOMBRE     |EDAD  |SEXO  |PESO (gr.)  |TIPO\n",165);
        printf("-----------------------------------------------------------------------------------------------------\n");
        for (i = 0; i < quantPets; i++)
        {
            breedIndex = searchBreed(breedListing, quantBreeds, petListing[i].idBreed);
            if (breedListing[breedIndex].idBreed == petListing[i].idBreed && breedListing[breedIndex].idBreed == id && petListing[i].isEmpty == 0)
            {
                printf("|%-14s |%-10s |%-14s |%-10s |%-5d |%-5c |%-10.3f |%-8s\n", breedListing[breedIndex].description, breedListing[breedIndex].size, breedListing[breedIndex].originCountry, petListing[i].name, petListing[i].age, petListing[i].sex, petListing[i].weight, petListing[i].type);
            }
        }
    }
    else
    {
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\tNo se han ingresado mascotas por el momento\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
    }
}

void showCountryMorePets(sBreed breedListing[], sPet petListing[], int quantBreed, int quantPet)
{
    int i;
    int countryMorePets;

    countryMorePets = selectCountryWithMorePets(petListing, breedListing, quantPet, quantBreed);

    for(i=0;i<quantBreed;i++)
    {
        if(countryMorePets == i )
        {
            printf("El pa%cs con m%cs mascotas es %s\n",161,160, breedListing[countryMorePets].originCountry);
        }
    }
}
