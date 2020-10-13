#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "petStructure.h"
#include "breedStructure.h"
#include "structureManagement.h"
#include "abm.h"

sPet addPet(sPet petListing,sBreed breedListing[], int breedQuant)
{
    int ageNumber;
    char sexLetter;
    char typeAux[20];

    fflush(stdin);
    getCharString("\nIngrese el nombre: ", "\nError! Ingrese solamente letras. Vuelva a intentarlo: ", petListing.name);
    removeBackslashN(petListing.name);
    firstLetterInCaps(petListing.name);

    fflush(stdin);
    ageNumber = getInt("\nIngrese la edad: ");
    while(ageNumber < 1)
    {
        fflush(stdin);
        getInt("\nEl sector debe ser un numero mayor a cero. Ingrese nuevamente el sector: ");
    }
    petListing.age = ageNumber;

    fflush(stdin);
    printf("\nIngrese el peso en Kg (ej: 2.7): ");
    getAndValidateIntAndFloatNumber("%f",&petListing.weight);
    while(petListing.weight < 0){
        printf("\nEl peso debe ser un numero mayor a cero. Ingrese el peso en Kg (ej: 2.7): ");
        getAndValidateIntAndFloatNumber("%f",&petListing.weight);
    }

    fflush(stdin);
    getChar(&sexLetter, "\nIngrese el sexo (f o m): ");
    sexLetter = tolower(sexLetter);
    while(sexLetter != 'f' && sexLetter != 'm')
    {
        fflush(stdin);
        sexLetter = getChar(&sexLetter, "\nIngrese el sexo (f o m): ");

    }
    petListing.sex = sexLetter;
    removeBackslashN(&petListing.sex);
    firstLetterInCaps(&petListing.sex);

    fflush(stdin);
    getCharString("\nIngrese la especie del animal (Perro, Gato o Raro): ", "\nError! Ingreso invalido. Vuelva a intentarlo: ", typeAux);
    strlwr(typeAux);
    while(!(strcmp(typeAux, "perro") > 0 || strcmp(typeAux, "gato") > 0 || strcmp(typeAux, "raro") > 0))
    {
        fflush(stdin);
        getCharString("\nIngreso invalido. Vuelva a ingresar la especie del animal (Perro, Gato o Raro): ", "\nError! Ingrese solamente letras. Vuelva a intentarlo: ", typeAux);
        strlwr(typeAux);
    }
    strcpy(petListing.type,typeAux);
    removeBackslashN(petListing.type);
    firstLetterInCaps(petListing.type);

    petListing.idBreed = chooseBreed(breedListing, breedQuant);

    return petListing;
}

sBreed addBreed(sBreed breedListing)
{
    char sizeAux[20];

    fflush(stdin);
    getCharString("\nIngrese el nombre de la raza: ", "\nError! Ingrese solamente letras. Vuelva a intentarlo: ", breedListing.description);
    removeBackslashN(breedListing.description);
    firstLetterInCaps(breedListing.description);

    fflush(stdin);
    getCharString("\nIngrese el tamanio de la raza (Chico, Mediano o Grande): ", "\nError! Ingreso invalido. Vuelva a intentarlo: ", sizeAux);
    strlwr(sizeAux);
    while(!(strcmp(sizeAux, "chico") > 0 || strcmp(sizeAux, "mediano") > 0 || strcmp(sizeAux, "grande") > 0))
    {
        printf("\nPor favor seleccione una de las tres opciones v%clidas\n",160);
        fflush(stdin);
        getCharString("\nIngrese el tamanio de la raza (Chico, Mediano o Grande): ", "\nError! Ingreso invalido. Vuelva a intentarlo: ", sizeAux);
        strlwr(sizeAux);
    }
    strcpy(breedListing.size,sizeAux);
    removeBackslashN(breedListing.size);
    firstLetterInCaps(breedListing.size);

    fflush(stdin);
    getCharString("\nIngrese el pais de origen de la raza: ", "\nError! Ingrese solamente letras. Vuelva a intentarlo: ", breedListing.originCountry);
    removeBackslashN(breedListing.originCountry);
    firstLetterInCaps(breedListing.originCountry);

    return breedListing;
}

int choosePet(sPet petListing[], sBreed breedListing[], int quant, int quantBreedListing)
{
    int i;
    int counter = 1;
    int id;
    int breedIndex;

    printf("\nSeleccione una Mascota de la lista\n\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("\n|ID |NOMBRE        |EDAD  |SEXO  |PESO (gr.) |TIPO     |RAZA           |TAMA%cO     |PAIS DE ORIGEN\n",165);
    printf("-----------------------------------------------------------------------------------------------------\n");
    for(i=0;i<quant;i++)
    {
        breedIndex = searchBreed(breedListing, quantBreedListing, petListing[i].idBreed);
        if(petListing[i].isEmpty == 0)
        {
            printf("[%d] |%-13s |%-5d |%-5c |%-10.3f |%-8s |%-14s |%-10s |%-10s\n", counter, petListing[i].name, petListing[i].age, petListing[i].sex, petListing[i].weight, petListing[i].type, breedListing[breedIndex].description, breedListing[breedIndex].size, breedListing[breedIndex].originCountry);
            counter ++;
        }
    }
    id = getInt("\n\nIngrese el ID de la Mascota a modificar: ");
    while(id>counter)
    {
        id = getInt("\n\nOpcion incorrecta. Ingrese una opcion valida: ");
    }

    return id;
}

int chooseBreed(sBreed breedListing[], int quant)
{
    int i;
    int counter = 1;
    int id;

    printf("\nSeleccione una Raza de la lista\n\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("|ID |RAZA           |TAMA%cO     |PAIS DE ORIGEN\n",165);
    printf("-----------------------------------------------------------------------------------------------------\n");
    for(i=0;i<quant;i++)
    {
        if(breedListing[i].isEmpty == 0)
        {
            printf("[%d] |%-14s |%-10s |%-14s\n",counter,breedListing[i].description, breedListing[i].size, breedListing[i].originCountry);
            counter ++;
        }
    }
    id = getInt("\n\nIngrese el ID de la Raza a modificar: ");
    while(id>counter)
    {
        id = getInt("\n\nOpcion incorrecta. Ingrese una opcion valida: ");
    }

    return id;
}

int modifyPet(sPet petListing[], sBreed breedListing[], int quant, int breedQuant)
{
    char stringAux[20];
    int auxAge;
    float auxWeight;
    char auxSex;
    int IdToModify;
    int option;
    int breedOption;
    int flagId = 0;
    int successReturn;
    int i;

    if(petListing != NULL && quant > 0)
    {
        IdToModify = choosePet(petListing, breedListing, quant, breedQuant);
        for(i=0;i<quant;i++)
        {
            if(petListing[i].idPet == IdToModify)
            {
                flagId = 1;
                do{
                    option = getInt("\nSeleccione una opcion\n\n[1] Modificar Nombre\n[2] Modificar Edad\n[3] Modificar Peso\n[4] Modificar Sexo\n[5] Modificar Especie\n[6] Modificar Raza\n[0] Salir\n\nSeleccione una opcion: ");
                    switch(option)
                    {
                        case 1:
                            fflush(stdin);
                            getCharString("\nIngrese el nombre: ", "\nError! Ingrese solamente letras. Vuelva a intentarlo: ", stringAux);
                            if(getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ") != 1)
                            {
                                printf("\nNo se realizar%c la modificaci%cn\n",159,162);
                                successReturn = 0;
                                break;
                            }
                            else
                            {
                                removeBackslashN(stringAux);
                                firstLetterInCaps(stringAux);
                                strcpy(petListing[i].name, stringAux);
                                printf("\n\nModificaciones realizadas con %cxito\n",130);
                                successReturn = 1;
                                break;
                            }
                        case 2:
                            fflush(stdin);
                            auxAge = getInt("\nIngrese la edad: ");
                            if(getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ") != 1)
                            {
                                printf("\nNo se realizar%cn modificaciones\n",160);
                                successReturn = 0;
                                break;
                            }
                            else
                            {
                                while(auxAge < 0)
                                {
                                    fflush(stdin);
                                    getInt("\nLa edad debe ser un numero mayor a cero. Ingrese nuevamente el sector: ");
                                }
                                petListing[i].age = auxAge;
                                printf("\n\nModificaciones realizadas con %cxito\n",130);
                                successReturn = 1;
                                break;
                            }
                        case 3:
                            fflush(stdin);
                            printf("\nIngrese el peso en Kg (ej: 2.7): ");
                            getAndValidateIntAndFloatNumber("%f", &auxWeight);
                            if(getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ") != 1)
                            {
                                printf("\nNo se realizar%cn modificaciones\n",160);
                                successReturn = 0;
                                break;
                            }
                            else
                            {
                                while(auxWeight < 0){
                                printf("\nEl peso debe ser un numero mayor a cero. Ingrese el peso en Kg (ej: 2.7): ");
                                getAndValidateIntAndFloatNumber("%f",&auxWeight);
                                }
                                petListing[i].weight = auxWeight;
                                printf("\n\nModificaciones realizadas con %cxito\n",130);
                                successReturn = 1;
                                break;
                            }
                        case 4:
                            fflush(stdin);
                            getChar(&auxSex, "\nIngrese el sexo (F o M): ");
                            auxSex = tolower(auxSex);
                            if(getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ") != 1)
                            {
                                printf("\nNo se realizar%cn modificaciones\n",160);
                                successReturn = 0;
                                break;
                            }
                            else
                            {
                                while(auxSex != 'f' && auxSex != 'f')
                                {
                                    fflush(stdin);
                                    getChar(&auxSex, "\nIngrese el sexo (F o M): ");
                                    auxSex = tolower(auxSex);

                                }
                                removeBackslashN(&auxSex);
                                firstLetterInCaps(&auxSex);
                                petListing[i].sex = auxSex;
                                printf("\n\nModificaciones realizadas con %cxito\n",130);
                                successReturn = 1;
                                break;
                            }
                        case 5:
                            fflush(stdin);
                            getCharString("\nIngrese la especie del animal (Perro, Gato o Raro): ", "\nError! Ingreso invalido. Vuelva a intentarlo: ", stringAux);
                            strlwr(stringAux);
                            if(getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ") != 1)
                            {
                                printf("\nNo se realizar%cn modificaciones\n",160);
                                successReturn = 0;
                                break;
                            }
                            else
                            {
                                while(!(strcmp(stringAux, "perro") > 0 || strcmp(stringAux, "gato") > 0 || strcmp(stringAux, "raro") > 0))
                                {
                                    fflush(stdin);
                                    getCharString("\nIngreso invalido. Vuelva a ingresar la especie del animal (Perro, Gato o Raro): ", "\nError! Ingrese solamente letras. Vuelva a intentarlo: ", stringAux);
                                    strlwr(stringAux);
                                }
                                removeBackslashN(stringAux);
                                firstLetterInCaps(stringAux);
                                strcpy(petListing[i].type,stringAux);
                                printf("\n\nModificaciones realizadas con %cxito\n",130);
                                successReturn = 1;
                                break;
                            }
                        case 6:
                            breedOption = chooseBreed(breedListing, breedQuant);
                            if(getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ") != 1)
                            {
                                printf("\nNo se realizar%cn modificaciones\n",160);
                                successReturn = 0;
                                break;
                            }
                            else
                            {
                                while(breedOption > 4)
                                {
                                    getInt("\nOpci%cn incorrecta.\nSeleccione una raza:\n\n1. Siames (Gato)\n2. Doberman (Perro)\n3. Persa (Gato)\n4. Pastor Belga (Perro)\n\nOpcion elegida: ");
                                }
                                petListing[i].idBreed = breedOption;
                                printf("\n\nModificaciones realizadas con %cxito\n",130);
                                successReturn = 1;
                                break;
                            }
                        case 0:
                            break;
                    }
                }while(option!=0);
            }
        }
        if(flagId == 0)
        {
            printf("\nNo existe una mascota con la id %04d.\n ",IdToModify);
            successReturn = 0;
        }
    }
    printf("\n");

    return successReturn;
}

int modifyBreed(sBreed breedListing[], int quant)
{

    char stringAux[20];
    int IdToModify;
    int option;
    int flagId = 0;
    int successReturn;
    int i;

    if(breedListing != NULL && quant > 0)
    {
        IdToModify = chooseBreed(breedListing, quant);
        for(i=0;i<quant;i++)
        {
            if(breedListing[i].idBreed == IdToModify)
            {
                flagId = 1;
                do{
                    option = getInt("\nSeleccione una opcion\n\n[1] Modificar Nombre\n[2] Modificar Tamanio\n[3] Modificar Pais de Origen\n[0] Salir\n\nSeleccione una opcion: ");
                    switch(option)
                    {
                        case 1:
                            fflush(stdin);
                            getCharString("\nIngrese el nuevo Nombre de la Raza: ", "\nError! Ingrese solamente letras. Vuelva a intentarlo: ", stringAux);
                            if(getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ") != 1)
                            {
                                printf("\nNo se realizar%cn modificaciones\n",160);
                                successReturn = 0;
                                break;
                            }
                            else
                            {
                                removeBackslashN(stringAux);
                                firstLetterInCaps(stringAux);
                                strcpy(breedListing[i].description, stringAux);
                                printf("\n\nModificaciones realizadas con %cxito\n",130);
                                successReturn = 1;
                                break;
                            }
                        case 2:
                            fflush(stdin);
                            getCharString("\nIngrese el nuevo Tamanio de la Raza: ", "\nError! Ingrese solamente letras. Vuelva a intentarlo: ", stringAux);
                            if(getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ") != 1)
                            {
                                printf("\nNo se realizar%cn modificaciones\n",160);
                                successReturn = 0;
                                break;
                            }
                            else
                            {
                                removeBackslashN(stringAux);
                                firstLetterInCaps(stringAux);
                                strcpy(breedListing[i].size, stringAux);
                                printf("\n\nModificaciones realizadas con %cxito\n",130);
                                successReturn = 1;
                                break;
                            }
                        case 3:
                            fflush(stdin);
                            getCharString("\nIngrese el nuevo Pais de Origen de la Raza: ", "\nError! Ingrese solamente letras. Vuelva a intentarlo: ", stringAux);
                            if(getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ") != 1)
                            {
                                printf("\nNo se realizar%cn modificaciones\n",160);
                                successReturn = 0;
                                break;
                            }
                            else
                            {
                                removeBackslashN(stringAux);
                                firstLetterInCaps(stringAux);
                                strcpy(breedListing[i].originCountry, stringAux);
                                printf("\n\nModificaciones realizadas con %cxito\n",130);
                                successReturn = 1;
                                break;
                            }
                        case 0:
                            break;
                    }
                }while(option!=0);
            }
        }
        if(flagId == 0)
        {
            printf("\nNo existe una raza con la id %04d.\n ",IdToModify);
            successReturn = 0;
        }
    }
    printf("\n");

    return successReturn;
}

int deletePet(sPet petListing[], int quant)
{
    int i;
    int petIdToDelete;
    int confirmation;
    int deletionResult;
    int flagId = 0;

    petIdToDelete = getInt("\nIngresa el ID del animal a eliminar: ");

    if(petListing != NULL && quant > 0)
    {
        for(i = 0; i < quant; i++)
        {
            if(petIdToDelete == petListing[i].idPet && petListing[i].isEmpty == 0)
            {
                flagId = 1;
                confirmation = getInt("\nEsta seguro que quiere eliminar la mascota?\n\nIngrese 1 para si, cualquier tecla para no: ");
                if(confirmation == 1)
                {
                    petListing[i].isEmpty = changeIsPetEmptyState(petListing[i]);
                    printf("\nLa mascota %s, (ID: %04d) ha sido eliminado del sistema.\n",petListing[i].name,petIdToDelete);
                    deletionResult = 1;
                    break;
                }
                else
                {
                    printf("No se eliminar%c la mascota.",160);
                    deletionResult = 0;
                    break;
                }
            }
            else
            {
                printf("No existe una mascota con la id %04d\n\n", petIdToDelete);
                deletionResult = 0;
                break;
            }
        }
        if(flagId == 0)
        {
            printf("\nNo existe una mascota con la id %04d.\n ",petIdToDelete);
            deletionResult = 0;
        }
    }
    return deletionResult;
}

int deleteBreed(sBreed breedListing[], int quant)
{
    int i;
    int breedIdToDelete;
    int confirmation;
    int deletionResult;
    int flagId = 0;

    breedIdToDelete = getInt("\nIngresa el ID del animal a eliminar: ");

    if(breedListing != NULL && quant > 0)
    {
        for(i = 0; i < quant; i++)
        {
            if(breedIdToDelete == breedListing[i].idBreed && breedListing[i].isEmpty == 0)
            {
                flagId = 1;
                confirmation = getInt("\nEsta seguro que quiere eliminar la mascota?\n\nIngrese 1 para si, cualquier tecla para no: ");
                if(confirmation == 1)
                {
                    breedListing[i].isEmpty = changeBreedIsEmptyState(breedListing[i]);
                    printf("\nLa raza %s, (ID: %04d) ha sido eliminado del sistema.\n",breedListing[i].description,breedIdToDelete);
                    deletionResult = 1;
                    break;
                }
                else
                {
                    printf("No se eliminar%c la raza.",160);
                    deletionResult = 0;
                    break;
                }
            }
            else
            {
                printf("No existe una raza con la id %04d\n\n", breedIdToDelete);
                deletionResult = 0;
                break;
            }
        }
        if(flagId == 0)
        {
            printf("\nNo existe una raza con la id %04d.\n ",breedIdToDelete);
            deletionResult = 0;
        }
    }
    return deletionResult;
}

int breedIdIndex(sBreed breedListing[],int quantBreedListing, sPet petListing[], int quantPetListing)
{
    int i, j;
    int returnValue;

    for(i = 0; i < quantPetListing; i++)
    {
        for(j = 0; j < quantBreedListing; i++)
        {
            if(petListing[j].idBreed == breedListing[i].idBreed)
            {
                returnValue = j;
                break;
            }
        }
    }
    return returnValue;
}

int getCharString(char message[], char errorMessage[], char input[])
{
    char aux[51];
    int returnValue = 0;
    printf("%s", message);
    fflush(stdin);
    fgets(aux,sizeof(aux),stdin);
    while(charactersOnly(aux) == 0)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        fgets(aux,sizeof(aux),stdin);
    }
    if(charactersOnly(aux) == 1)
    {
        returnValue = 1;
        strcpy(input,aux);
        return returnValue;
    }
    return returnValue;
}

int charactersOnly(char string[])
{
    int i;
    int ifIsAlpha;
    int sz;

    sz = strlen(string)-1;

    for(i=0; i< sz; i++)
    {
        if((!(isalpha(string[i]) == 0)) || string[i] == ' ')
        {
            ifIsAlpha = 1;
        }
        else
        {
            ifIsAlpha = 0;
            break;
        }
    }
    return ifIsAlpha;
}

int getChar(char* pResult, char* message)
{
    int returns = -1; // Se inicializa con el valor de error
    int exitFlag = 0; // Termina el loop cuando es == 1
    char buffer; // Almacenamiento de inputs del usuario

    if(pResult != NULL && message != NULL)
    {
        do
        {
            printf("%s", message);
            fflush(stdin);
            scanf("%c", &buffer);

            if(!(isalpha(buffer)))
            {
                printf("El valor ingresado no es un caracter alfabetico. \n");
            }
            else
            {
                *pResult = buffer;
                returns = 0; // OK
                exitFlag = 1; // Termina el loop
            }

        } while(exitFlag == 0);
    }

    return returns;
}

int getInt(char message[])
{
    char aux[256];
    int integer;
    int integerValidation;

    printf("%s", message);
    scanf("%s",aux);
    fflush(stdin);
    integerValidation = isInt(aux);

    while(integerValidation == 0)
    {
        printf("\nError! Eso no es un n%cmero. Ingrese un n%cmero: ",163,163);
        scanf("%s",aux);
        fflush(stdin);
        integerValidation = isInt(aux);
        printf("\n");
    }
    if(integerValidation == 1)
    {
        integer = atoi(aux);
    }
    fflush(stdin);
    return integer;
 }

int isInt(char string[])
{
    int i=0;
    int returnValue = 1;

    for(i=0; string[i] != '\0'; i++)
    {
        if(string[i] < '0' || string[i] > '9')
        {
            returnValue = 0;
            return returnValue;
        }
    }
    return returnValue;
}

int getAndValidateIntAndFloatNumber(const char* floatMask, void* variable)
{
    int input;
    int flagConfirmation = 0;
    int returnValue = 0;

    fflush(stdin);
    if(!scanf(floatMask, variable))
    {
        while(flagConfirmation == 0)
        {
            while((input = getchar()) != '\n' && input != EOF);
            printf("\nIngreso Inv%clido.\n\nVuelva a intentarlo: ",160);
            fflush(stdin);
            if(scanf(floatMask, variable))
            {
                fflush(stdin);
                flagConfirmation = 1;
                returnValue = 1;
            }
        }
        fflush(stdin);
        return returnValue;
    }
    if(getchar() != '\n')
    {
        while(flagConfirmation == 0)
        {
            while((input = getchar()) != '\n' && input != EOF);
            printf("\nIngreso Inv%clido.\n\nVuelva a intentarlo: ",160);
            if(scanf(floatMask, variable))
            {
                flagConfirmation = 1;
                returnValue = 1;
            }
        }
        return returnValue;
    }
    return returnValue;
}

char removeBackslashN(char string[])
{
    int i;
    for(i=0;string[i] != '\0';i++)
    {
        if(string[i] == '\n')
        {
            string[i] = '\0';
        }
    }
    return string[i];
}

int firstLetterInCaps(char string[])
{
    int i;
    strlwr(string);
    for(i = 0; i < strlen(string); i++)
    {
        if(i == 0 || (string[i-1] == ' ' && string[i] >= 'a' && string[i] <= 'z'))
        {
            string[i] = toupper(string[i]);
        }
    }
    return 1;
}

char* strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;
  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }
  return str;
}
