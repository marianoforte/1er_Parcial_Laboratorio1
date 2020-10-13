#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "breedStructure.h"
#include "petStructure.h"
#include "structuresRelations.h"
#include "structureManagement.h"
#include "abm.h"
#include "mainMenu.h"
#define PETSIZE 10
#define BREEDSIZE 10

void mainMenu(void)
{
    sPet petListing[PETSIZE];
    sBreed breedListing[BREEDSIZE];
    int option;
    int uploadOption;
    int modifyOption;
    int deleteOption;
    int printOption;
    int weightOrderOption;
    int freeRowPetsList;
    int freeRowBreedList;
    int lastPetId;
    int lastBreedId;
    lastPetId = 5;
    lastBreedId = 4;

    initPetArrayAsEmpty(petListing, PETSIZE);
    initBreedArrayAsEmpty(breedListing, BREEDSIZE);
    hardcodePet(petListing, PETSIZE);
    hardcodeBreed(breedListing, BREEDSIZE);

    do
    {
        printf("\n                    _____________________________________________");
        printf("\n                   |                                             |");
        printf("\n                   |********ADMINISTRACION DE VETERINARIA********|");
        printf("\n                   |_____________________________________________|\n\n");

        option = getInt("\nSeleccione una opcion\n\n[1] Alta\n[2] Modificacion\n[3] Baja\n[4] Informar\n[0] Salir\n\nIngrese una opcion: ");
        switch(option)
        {
            case 1:
                uploadOption = getInt("\n[1] Alta de Mascota\n[2] Alta de Raza\n[0] Salir\n\nIngrese una opcion: ");
                switch(uploadOption)
                {
                    case 1:
                        freeRowPetsList = searchListingFirstEmptyPlace(petListing, PETSIZE);
                        if(freeRowPetsList == -1 || freeRowPetsList == PETSIZE)
                        {
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                            printf("\n\nEl listado esta lleno. Elimine alguna mascota para ingresar una nueva\n\n");
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                        }
                        else
                        {
                            lastPetId = createPetId(petListing, lastPetId, freeRowPetsList);
                            petListing[freeRowPetsList] = addPet(petListing[freeRowPetsList],breedListing,BREEDSIZE);
                            petListing[freeRowPetsList].isEmpty = changeIsPetEmptyState(petListing[freeRowPetsList]);
                            petListing[freeRowPetsList].idPet = lastPetId;
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                            printf("Se le ha asignado la ID %d.", lastPetId);
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        freeRowBreedList = searchBreedListingFirstEmptyPlace(breedListing, BREEDSIZE);
                        if(freeRowBreedList == -1 || freeRowBreedList == BREEDSIZE)
                        {
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                            printf("\n\nEl listado esta lleno. Elimine alguna mascota para ingresar una nueva\n\n");
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                        }
                        else
                        {
                            lastBreedId = createBreedId(breedListing, lastBreedId, freeRowBreedList);
                            breedListing[freeRowBreedList] = addBreed(breedListing[freeRowBreedList]);
                            breedListing[freeRowBreedList].isEmpty = changeBreedIsEmptyState(breedListing[freeRowBreedList]);
                            breedListing[freeRowBreedList].idBreed = lastBreedId;
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                            printf("Se le ha asignado la ID %d.", lastBreedId);
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opci%cn inv%clida. Elija nuevamente.\n\n",162,160);
                        system("pause");
                        system("cls");
                        break;
                }

                break;
            case 2:
                modifyOption = getInt("\n[1] Modificar Mascota\n[2] Modificar Raza\n[0] Salir\n\nIngrese una opcion: ");
                switch(modifyOption)
                {
                    case 1:
                        if(lastPetId == 0)
                        {
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                            printf("\nNo se han ingresado animales hasta el momento.\n");
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                        }
                        else
                        {
                            modifyPet(petListing, breedListing, PETSIZE, BREEDSIZE);
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        if(lastBreedId == 0)
                        {
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                            printf("\nNo se han ingresado razas hasta el momento.\n");
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                        }
                        else
                        {
                            modifyBreed(breedListing, BREEDSIZE);
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 0:
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf("Opci%cn inv%clida. Elija nuevamente.\n\n",162,160);
                        system("pause");
                        system("cls");
                        break;
                }
                break;
            case 3:
                deleteOption = getInt("\n[1] Eliminar Mascota\n[2] Eliminar Raza\n[0] Salir\n\nIngrese una opcion: ");
                switch(deleteOption)
                {
                    case 1:
                        if(lastPetId == 0)
                        {
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                            printf("\nNo se han ingresado animales hasta el momento.\n");
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                        }
                        else
                        {
                            deletePet(petListing, PETSIZE);
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        if(lastBreedId == 0)
                        {
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                            printf("\nNo se han ingresado razas hasta el momento.\n");
                            printf("\n\n------------------------------------------------------------------------------------\n\n");
                        }
                        else
                        {
                            deleteBreed(breedListing, BREEDSIZE);
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 0:
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf("Opci%cn inv%clida. Elija nuevamente.\n\n",162,160);
                        system("pause");
                        system("cls");
                        break;
                }
                break;
            case 4:
                printOption = getInt("\n[1] Mostrar listado completo de Mascotas\n[2] Mostrar Razas con sus respectivas Mascotas\n[3] Mostrar Mascotas ordenadas por Peso\n[0] Salir\n\nIngrese una opcion: ");
                switch(printOption)
                {
                    case 1:
                        sortPetsByIdAscendent(petListing, BREEDSIZE);
                        printPetAndBreed(petListing, PETSIZE, breedListing, BREEDSIZE);
                        printf("-----------------------------------------------------------------------------------------------------\n");
                        showCountryMorePets(breedListing, petListing, BREEDSIZE, PETSIZE);
                        printf("\n");
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        sortPetsByIdAscendent(petListing, BREEDSIZE);
                        printBreedList(petListing, breedListing, PETSIZE, BREEDSIZE, chooseBreed(breedListing, BREEDSIZE));
                        printf("-----------------------------------------------------------------------------------------------------\n");
                        showCountryMorePets(breedListing, petListing, BREEDSIZE, PETSIZE);
                        printf("\n");
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        weightOrderOption = getInt("\n[1] Mostrar en orden Ascendente\n[2] Mostrar en orden Descendente\n[0] Salir\n\nIngrese una opcion: ");
                        switch(weightOrderOption)
                        {
                            case 1:
                                sortPetsWeightAscendent(petListing, PETSIZE);
                                printPetAndBreed(petListing, PETSIZE, breedListing, BREEDSIZE);
                                printf("-----------------------------------------------------------------------------------------------------\n");
                                showCountryMorePets(breedListing, petListing, BREEDSIZE, PETSIZE);
                                printf("\n");
                                system("pause");
                                system("cls");
                                break;
                            case 2:
                                sortPetsWeightDescendent(petListing, PETSIZE);
                                printPetAndBreed(petListing, PETSIZE, breedListing, BREEDSIZE);
                                printf("-----------------------------------------------------------------------------------------------------\n");
                                showCountryMorePets(breedListing, petListing, BREEDSIZE, PETSIZE);
                                printf("\n");
                                system("pause");
                                system("cls");
                                break;
                            case 0:
                                break;
                            default:
                                printf("Opci%cn inv%clida. Elija nuevamente.\n\n",162,160);
                                system("pause");
                                system("cls");
                                break;
                        }
                        break;
                    case 0:
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf("Opci%cn inv%clida. Elija nuevamente.\n\n",162,160);
                        system("pause");
                        system("cls");
                        break;
                }
                break;
            case 0:
                printf("\n\n");
                printf("------------------------------------------------------------------------------------\n");
                printf("\n                         Gracias por utilizar la aplicaci%cn.\n\n                       Dise%co y desarrollo por Mariano Forte.\n\n                                    Version 1.4\n",162,164);
                printf("\n------------------------------------------------------------------------------------\n");
                system("pause");
                system("cls");
                break;
            default:
                printf("Opci%cn inv%clida. Elija nuevamente.\n\n",162,160);
                system("pause");
                system("cls");
                break;
        }
    }while(option != 0);
}

