#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "petStructure.h"
#include "breedStructure.h"
#include "structureManagement.h"


int initPetArrayAsEmpty(sPet petListing[], int quant)
{
    int i;
    int result = 0;

    for(i = 0 ; i < quant; i++)
    {
        petListing[i].isEmpty = 1;
        result = 1;
    }
    return result;
}

int initBreedArrayAsEmpty(sBreed breedListing[], int quant)
{
    int i;
    int result = 0;

    for(i = 0 ; i < quant; i++)
    {
        breedListing[i].isEmpty = 1;
        result = 1;
    }
    return result;
}

int searchListingFirstEmptyPlace(sPet petData[], int quant)
{
    int i;
    int index = -1;

    for(i = 0; i< quant; i++)
    {
        if(petData[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int searchBreedListingFirstEmptyPlace(sBreed breedData[], int quant)
{
    int i;
    int index = -1;

    for(i = 0; i< quant; i++)
    {
        if(breedData[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int changeIsPetEmptyState(sPet petData)
{
    int isEmptyStatus;

    if(petData.isEmpty == 0)
    {
        isEmptyStatus = 1;
    }
    else
    {
        isEmptyStatus = 0;
    }
    return isEmptyStatus;
}

int changeBreedIsEmptyState(sBreed breedData)
{
    int isEmptyStatus;

    if(breedData.isEmpty == 0)
    {
        isEmptyStatus = 1;
    }
    else
    {
        isEmptyStatus = 0;
    }
    return isEmptyStatus;
}

int createPetId(sPet petData[],int lastId, int quant)
{
    int i;
    int actualId;

    actualId = lastId + 1;
    for(i=0;i==quant;i++)
    {
        petData[i].idPet = actualId;
        break;
    }
    return actualId;
}

int createBreedId(sBreed breedData[],int lastId, int quant)
{
    int i;
    int actualId;

    actualId = lastId + 1;
    for(i=0;i==quant;i++)
    {
        breedData[i].idBreed = actualId;
        break;
    }
    return actualId;
}

int searchBreed(sBreed breedListing[], int quant, int idBreed)
{
    int returnValue = -1;
    int i;

    if(breedListing != NULL && quant > 0)
    {
        for(i = 0; i < quant; i++)
        {
            if(breedListing[i].idBreed == idBreed)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int sortPetsByIdAscendent(sPet petData[], int quant)
{
    int i;
    int j;
    int result = 0;
    sPet idAux;

    for(i = 0; i < quant; i++)
    {
        for(j = i+1; j < quant; j++)
        {
            if(petData[i].idPet > petData[j].idPet)//ordenamiento ascendente por peso
            {
                idAux = petData[i];
                petData[i] = petData[j];
                petData[j] = idAux;
                result = 1;
            }
        }
    }
    return result;
}

int sortPetsWeightAscendent(sPet petData[], int quant)
{
    int i;
    int j;
    int result = 0;
    sPet weightAux;

    for(i = 0; i < quant; i++)
    {
        for(j = i+1; j < quant; j++)
        {
            if(petData[i].weight > petData[j].weight)//ordenamiento ascendente por peso
            {
                weightAux = petData[i];
                petData[i] = petData[j];
                petData[j] = weightAux;
                result = 1;
            }
        }
    }
    return result;
}

int sortPetsWeightDescendent(sPet petData[], int quant)
{
    int i;
    int j;
    int result = 0;
    sPet weightAux;

    for(i = 0; i < quant; i++)
    {
        for(j = i+1; j < quant; j++)
        {
            if(petData[i].weight < petData[j].weight)//ordenamiento ascendente por peso
            {
                weightAux = petData[i];
                petData[i] = petData[j];
                petData[j] = weightAux;
                result = 1;
            }
        }
    }
    return result;
}

int selectCountryWithMorePets(sPet petListing[], sBreed breedListing[], int quantPet, int quantBreed)
{
    int i;
    int j;
    int returnValue = -1;
    int max;
    int counter;
    sBreed aux;

    for(i=0; i<quantBreed; i++)
    {
        if(breedListing[i].isEmpty == 0)
        {
            aux = breedListing[i];
            counter = 0;
            for(j=0;j<quantPet;j++)
            {
                if(petListing[j].isEmpty == 0 && breedListing[i].idBreed == petListing[j].idBreed)
                {
                    if(strcmp(breedListing[i].originCountry, aux.originCountry) == 0)
                    {
                        counter++;
                    }
                }
            }
            if(counter>max || i == 0)
            {
                max = counter;
                returnValue = i;
            }
            else if(counter == max)
            {
                returnValue = -1;
            }
        }
    }
    return returnValue;
}
