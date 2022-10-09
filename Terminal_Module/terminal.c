                        /*****  Header Files *****/

/***********************************************************************/
#include "Terminal.h"
/***********************************************************************/



				 /*****  Transation Date Function *****/

/***********************************************************************/
/*
	-this function takes the transation date from the user in the format DD/MM/YYYY
	-check if the date string is entered not empty data , less or more the standard length
	-compare the input transation date with the system date to validate the enter value 
	-if all checks are passed return ok otherwise return the error

*/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	EN_terminalError_t error;
	uint8_t length;
	uint32_t day = 0, month = 0, year = 0;

	printf("Kindly Enter transaction Date in the Following Formate DD/MM/YYYY \n");
	gets(termData->transactionDate);

	length = strlen(termData->transactionDate);
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);

	if ((termData->transactionDate == NULL) || (length < 10) || (length > 10))
	{	
		error = WRONG_DATE;
		printf("Wrong Date \n");

	}
	else
	{
		day = termData->transactionDate[0] - '0';
		day = day * 10 + termData->transactionDate[1] - '0';

		month = termData->transactionDate[3] - '0';
		month = month * 10 + termData->transactionDate[4] - '0';

		year = termData->transactionDate[6] - '0';
		year = ((year * 10 ) + ( termData->transactionDate[7] - '0'));
		year =( year * 10) + (termData->transactionDate[8] - '0');
		year = (year * 10) + (termData->transactionDate[9] - '0');


		if ((day != str_t.wDay) || (month != str_t.wMonth) || (year != str_t.wYear))
		{
			error = WRONG_DATE;
			printf("Wrong Date \n");

		}
		else
		{
			error = OKAY;
		}
	}

	
	return error;
}
/***********************************************************************/

                   /*****  Card Expired Function *****/

/***********************************************************************/
/*
	-this function check if the card is Expaird or not 
	-compare the card Expiry date with transation date 
	-if all checks are passed return ok otherwise return the error

*/
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	EN_terminalError_t error;
	uint8_t TE_Year = 0, CA_Year = 0, TE_Month = 0, CA_Month = 0;

	CA_Year = cardData.cardExpirationDate[3] - '0';
	CA_Year = CA_Year * 10 + cardData.cardExpirationDate[4] - '0';

	TE_Year = termData.transactionDate[8] - '0';
	TE_Year = TE_Year * 10 + termData.transactionDate[9] - '0';

	CA_Month = cardData.cardExpirationDate[0] - '0';
	CA_Month = CA_Month * 10 + cardData.cardExpirationDate[1] - '0';

	TE_Month = termData.transactionDate[3] - '0';
	TE_Month = TE_Month * 10 + termData.transactionDate[4] - '0';

	if (TE_Year > CA_Year)
	{
		error = EXPIRED_CARD;
		printf("EXPIRED CARDy\n");

	}
	else if ((TE_Month > CA_Month) && (CA_Year < TE_Year))
	{
		error = EXPIRED_CARD;
		printf("EXPIRED CARDm\n");

	}
	else if ((TE_Year == CA_Year) && (TE_Month == CA_Month))
	{
		error = EXPIRED_CARD;
		printf("EXPIRED CARDe\n");

	}
	else
	{
		error = OKAY;
	}


	return error;



}
/***********************************************************************/

              /*****  Transation Amount Function *****/

/***********************************************************************/
/*
	-this function takes the transition amount from the user 
	-check if the transtion amount is valid value not 0 nor negative value 
	-if all checks are passed return ok otherwise return the error

*/

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t error;

	printf("Kindly Enter transaction Amount  \n");
	scanf_s("%f", &termData->transAmount);


	if (termData->transAmount <= 0 )
	{
		error = INVALID_AMOUNT;
		printf("Invalid Amount \n");

	}
	else
	{
		error = OKAY;
	}


	return error;
}
/***********************************************************************/


			  /*****  Set Maximum Amount Function *****/

/***********************************************************************/
/*
	-

*/
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t error;
	termData->maxTransAmount = 20000.00;
	if (termData->maxTransAmount <= 0)
	{
		error = INVALID_MAX_AMOUNT;
		printf("Invalid Max amount\n");
		
	}
	else
	{
		error = OKAY;
		printf("The Maximum transation amount Is : %0.3f\n", termData->maxTransAmount);
	}


	return error;

}
/***********************************************************************/

               /*****  Below Maximum Amount Function *****/

/***********************************************************************/
/*
	-

*/
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{	
	EN_terminalError_t error;

	if (termData->transAmount > termData->maxTransAmount)
	{
		error = EXCEED_MAX_AMOUNT;
		printf("Exceed the maximum Amount of transation \n");
	}
	else
	{
		error = OKAY;
	}

	return error;


}
/***********************************************************************/


