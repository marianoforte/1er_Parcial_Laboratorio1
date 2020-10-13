typedef struct{
    int idBreed; //Primary Key
    char description[20];
    char size[20];
    char originCountry[20];
    int isEmpty;
}sBreed;

/**
 * \brief Writes an initial data inside the respective indexes
 * \param listing It is the array in which to set the breed data
 * \param quant It is the length of the array itself
 * \return The written data
 *
 */
void hardcodeBreed(sBreed listing[], int quant);
