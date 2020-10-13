/**
 * \brief Prints a list with all the pets and their respective breed data registered in the system
 * \param petListing It is the array where to gather all pet data
 * \param quantFirstListing It is the length of the pet array itself
 * \param breedListing It is the array where to gather all breed data
 * \param quantSecondListing It is the length of the breed array itself
 * \return The printed data
 *
 */
void printPetAndBreed(sPet petListing[], int quantFirstListing, sBreed breedListing[], int quantSecondListing);

/**
 * \brief Prints a list with all breed data registered in the system
 * \param petListing It is the array where to gather all pet data
 * \param breedListing It is the array where to gather all breed data
 * \param quantPets It is the length of the pet array itself
 * \param quantBreeds It is the length of the breed array itself
 * \param id It is the breed id to choose from
 * \return The printed data
 *
 */
void printBreedList(sPet petListing[], sBreed breedListing[],int quantPets, int quantBreeds, int id);

/**
 * \brief Prints a message telling wich country has the most pets
 * \param breedListing It is the array where to gather all breed data
 * \param petListing It is the array where to gather all pet data
 * \param quantBreed It is the length of the breed array itself
 * \param quantPet It is the length of the pet array itself
 * \return The printed data
 *
 */
void showCountryMorePets(sBreed breedListing[], sPet petListing[], int quantBreed, int quantPet);


