/**
 * \brief Requests the data of the pet to be registered
 * \param petListing It is the array where to place the new pet
 * \param breedListing It is the array where to search for the breed
 * \return The pet data to put into corresponding index
 *
 */
sPet addPet(sPet petListing,sBreed breedListing[], int breedQuant);

/**
 * \brief Requests the data of the breed to be registered
 * \param breedListing It is the array where to place the new breed
 * \return The breed data to put into corresponding index
 *
 */
sBreed addBreed(sBreed breedListing);

/**
 * \brief Shows a list of pets registered in the system
 * \param petListing It is the array where to search for the pet
 * \param breedListing It is the array where to search for the breed
 * \param quant It is the pet list index quantity
 * \param quantBreedListing It is the breed list index quantity
 * \return The list of options to choose from
 *
 */
int choosePet(sPet petListing[], sBreed breedListing[], int quant, int quantBreedListing);

/**
 * \brief Shows a list of breeds registered in the system
 * \param breedListing It is the array where to search for the breed
 * \param quant It is the breed list index quantity
 * \return The list of options to choose from
 *
 */
int chooseBreed(sBreed breedListing[], int quant);

/**
 * \brief Modifies a choosen pet
 * \param petListing It is the array where to search for the pet
 * \param breedListing It is the array where to search for the breed
 * \param quant It is the pet list index quantity
 * \param quantQuant It is the breed list index quantity
 * \return The modified pet data
 *
 */
int modifyPet(sPet petListing[], sBreed breedListing[], int quant, int breedQuant);

/**
 * \brief Modifies a choosen breed
 * \param breedListing It is the array where to search for the breed
 * \param quant It is the breed list index quantity
 * \return The modified pet data
 *
 */
int modifyBreed(sBreed breedListing[], int quant);

/**
 * \brief Deletes a pet by using the ID received
 * \param petListing It is the array where to delete the pet
 * \param quant It is the length of the array itself
 * \return The success or not of the deletion
 *
 */
int deletePet(sPet petListing[], int quant);

/**
 * \brief Deletes a breed by using the ID received
 * \param petListing It is the array where to delete the breed
 * \param quant It is the length of the array itself
 * \return The success or not of the deletion
 *
 */
int deleteBreed(sBreed breedListing[], int quant);

/**
 * \brief Searches for the ID index of a certain breed
 * \param breedListing It is the array where to search for the breed
 * \param quantBreedListing It is the breed list index quantity
 * \param petListing It is the array where to search for the pet
 * \param quantPetListing It is the pet list index quantity
 * \return The ID index
 *
 */
int breedIdIndex(sBreed breedListing[], int quantBreedListing, sPet petListing[], int quantPetListing);

/**
 * \brief Allows the entry of a text string
 * \param message It is the entry request message
 * \param errorMessage It is the error message in case of an invalid entry
 * \param input It is the array where text to be loaded up
 * \return 1 if the text only contains letters and spaces
 *
 */
int getCharString(char message[], char errorMessage[], char input[]);

/**
 * \brief Verifies if the received value contains only letters and spaces
 * \param string It is the array with the string to be analized
 * \return 1 if the text only contains letters and spaces; 0 if there is more than letters and spaces
 *
 */
int charactersOnly(char string[]);

/** \brief Solicita al usuario un caracter, por ejemplo: A.
 *
 * \param  pResult Dirección de memoria donde se guarda el caracter (validado) ingresado por el usuario
 * \param  message Mensaje que deseamos mostrar al usuario al pedir el caracter
 * \return Devuelve 0: OK / -1: Error de parametros
 *
 */
int getChar(char* pResult, char* message);

/**
 * \brief Asks for an integer number and calls isInt function to validate it,
            shows error message if it isn't an integer number
 * \param message It is the entry request message
 * \return The integer value
 *
 */
int getInt(char message[]);

/**
 * \brief Takes the integer given by getInt function and verifies if it is a valid input
 * \param string It is the array with the number to be analized
 * \return 1 if it is a valid integer; 0 if it is not an integer
 *
 */
int isInt(char string[]);

/**
 * \brief Asks for an integer and float number and verifies it
 * \param floatMask It is the mask to put into the scanf function
 * \param variable It is the variable where to place the validated number
 * \return 1 if it is a valid number; 0 if it isn't
 *
 */
int getAndValidateIntAndFloatNumber(const char* floatMask, void* variable);

/**
 * \brief Looks for a newline character inside the array and replaces it with a '\0'
 * \param string It is the array in which to search
 * \return The modified string
 *
 */
char removeBackslashN(char string[]);

/**
 * \brief Converts the first character of one or more words to uppercase
 * \param string It is the array in which to search
 * \return A confirmation value of the modify
 *
 */
int firstLetterInCaps(char string[]);

/**
 * \brief Function to use strlwr function in Linux based systems
 * \param str It is the array wich to modify
 * \return The lower-case string
 *
 */
char* strlwr(char *str);

