/**
 * \brief Initialize all indexes of the array as empty
 * \param petListing It is the array in which to set the empty states
 * \param quant It is the length of the array itself
 * \return If the process was successfull or not
 *
 */
int initPetArrayAsEmpty(sPet petListing[], int quant);

/**
 * \brief Initialize all indexes of the array as empty
 * \param breedListing It is the array in which to set the empty states
 * \param quant It is the length of the array itself
 * \return If the process was successfull or not
 *
 */
int initBreedArrayAsEmpty(sBreed breedListing[], int quant);

/**
 * \brief Traverse the array looking for the first available place to store the data
 * \param petData It is the array in which to search for the empty state
 * \param quant It is the length of the array itself
 * \return The index where to put all the data
 *
 */
int searchListingFirstEmptyPlace(sPet petData[], int quant);

/**
 * \brief Traverse the array looking for the first available place to store the data
 * \param breedData It is the array in which to search for the empty state
 * \param quant It is the length of the array itself
 * \return The index where to put all the data
 *
 */
int searchBreedListingFirstEmptyPlace(sBreed breedData[], int quant);

/**
 * \brief Changes the empty state of the index so the data won't be over-written
 * \param petData It is the array where the state is modified
 * \return The change status
 *
 */
int changeIsPetEmptyState(sPet petData);

/**
 * \brief Changes the empty state of the index so the data won't be over-written
 * \param breedData It is the array where the state is modified
 * \return The change status
 *
 */
int changeBreedIsEmptyState(sBreed breedData);

/**
 * \brief Creates an ID for every pet entry
 * \param petData It is the array where to place the ID
 * \param lastId Recieves the last ID at the moment
 * \param quant It is the length of the array itself
 * \return The new Id created
 *
 */
int createPetId(sPet petData[],int lastId, int quant);

/**
 * \brief Creates an ID for every breed entry
 * \param breedData It is the array where to place the ID
 * \param lastId Recieves the last ID at the moment
 * \param quant It is the length of the array itself
 * \return The new Id created
 *
 */
int createBreedId(sBreed breedData[],int lastId, int quant);

/**
 * \brief Traverse the array received looking for the ID index
 * \param breedListing It is the array in which to search for the ID index
 * \param quant It is the length of the array itself
 * \param idBreed Receives the ID to look for
 * \return The ID index
 *
 */
int searchBreed(sBreed breedListing[], int quant, int idBreed);

/**
 * \brief Sorts the pets in ascending order by ID
 * \param petData It is the array to sort
 * \param quant It is the length of the array itself
 * \return The sorting confirmation
 *
 */
int sortPetsByIdAscendent(sPet petData[], int quant);

/**
 * \brief Sorts the pets in ascending order by weight
 * \param petData It is the array to sort
 * \param quant It is the length of the array itself
 * \return The sorting confirmation
 *
 */
int sortPetsWeightAscendent(sPet petData[], int quant);

/**
 * \brief Sorts the pets in descending order by weight
 * \param petData It is the array to sort
 * \param quant It is the length of the array itself
 * \return The sorting confirmation
 *
 */
int sortPetsWeightDescendent(sPet petData[], int quant);

/**
 * \brief Searches into the breed list for the country with more pets
 * \param petListing It is the array where to look for pet data
 * \param breedListing It is the array where to look for breed data
 * \param quantPet It is the length of the pet array itself
 * \param quantBreed It is the length of the pet array itself
 * \return The breed index corresponding to the country with more pets
 *
 */
int selectCountryWithMorePets(sPet petListing[], sBreed breedListing[], int quantPet, int quantBreed);


