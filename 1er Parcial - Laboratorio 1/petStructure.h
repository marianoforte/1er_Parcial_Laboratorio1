typedef struct{
    int idPet; //Primary Key
    char name[20];
    int age;
    char sex;
    char type[20];
    float weight;
    int idBreed; //Foreign Key
    int isEmpty;
}sPet;

/**
 * \brief Writes an initial data inside the respective indexes
 * \param listing It is the array in which to set the pet data
 * \param quant It is the length of the array itself
 * \return The written data
 *
 */
void hardcodePet(sPet listing[], int quant);
