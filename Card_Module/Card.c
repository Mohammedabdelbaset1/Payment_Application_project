                            /*****  Header Files *****/

/***********************************************************************/
#include "Card.h"
/***********************************************************************/

                        /*****  Card Holder Name Function *****/

/***********************************************************************/
/* 
    -function take the name on the card from the user 
	-check if the name string is entered not empty data 
	-check if the name length is within the boundaries 
	-if all checks are passed return ok otherwise return the error

*/
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{

	EN_cardError_t error;
	uint8_t length;

	printf("Kindly Enter The Name printed on your Card \n");
	gets(cardData ->cardHolderName);

	length = strlen(cardData->cardHolderName);

	if ((cardData->cardHolderName == NULL))
	{
		error = WRONG_NAME;
		printf("Wrong name \n");
	}
	
	else if ((length < 20) || (length > 24))
	{
		error = WRONG_NAME;
		printf("Wrong name \n");

	}
	else
	{
		error = OK;
	}


	return error;

}

/***********************************************************************/

              /*****  Card Holder Expiry Date Function *****/

/***********************************************************************/
/*	
	-this function takes the expiry date from the user
	-check if the date string is entered not empty data , less or more the standard length
	-check the format MM/YY
	-check the month & year numbers is valid  
	-if all checks are passed return ok otherwise return the error

*/
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	EN_cardError_t error;
	uint8_t length;
	uint8_t month = 0, year = 0;
	
	printf("kindly Enter the Expiry Date printed on the card on the format MM/YY \n");
	gets(cardData->cardExpirationDate);

	length = strlen(cardData->cardExpirationDate);

	if ((cardData->cardExpirationDate == NULL) || ( length < 5) || (length > 5))
	{	
		error = WRONG_EXP_DATE;
		printf("Wrong Expiry Date 2  \n");


	}
	else if (cardData->cardExpirationDate[2] != '/')
	{
			
		error = WRONG_EXP_DATE;
		printf("Wrong Expiry Date 3 \n");
			
			
	}
	else
	{
		
		month = cardData->cardExpirationDate[0] - '0';
		month = month * 10 + cardData->cardExpirationDate[1]-'0';

		year = cardData->cardExpirationDate[3] - '0';
		year = year * 10 + cardData->cardExpirationDate[4] - '0';
		
		if ((month >= 0) && (month <= 12) && (year >= 20) && (year <= 33))
		{
			error = OK;
		}
		else
		{	
			error = WRONG_EXP_DATE;
			printf("Wrong Expiry Date 4 \n");

		}
	}

	return error;
}

/***********************************************************************/

			  /*****  Card Holder PAN Number Function *****/

/***********************************************************************/
/*
	-this function takes the the card's Primary Account Number from the user
	-check if the date string is entered not empty data , less or more the standard length
	-check that the PAN is alphanumeric only not any special characters 
	-if all checks are passed return ok otherwise return the error

*/
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	EN_cardError_t error = OK;
	uint8_t length;

	printf("kindly Enter the PAN Primary account Number \n");
	gets(cardData->primaryAccountNumber);


	length = strlen(cardData->primaryAccountNumber);
	

	if ((cardData->primaryAccountNumber == NULL) || (length > 19) || (length < 16))
	{
		error = WRONG_PAN;
		printf("Wrong PAN  \n");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (!(((cardData->primaryAccountNumber[i] >= '0') && ((cardData->primaryAccountNumber[i]) <= '9')) ))
			{
				error = WRONG_PAN;
				printf("Wrong PAN  \n");
				break;

			}
			else
			{
				error = OK;

			}

		}
		
		
	}
	

	return error;

}

/***********************************************************************/