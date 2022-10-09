

                      /*****  Header Files *****/

/***********************************************************************/
#include "Server.h"
/***********************************************************************/

ST_accountsDB_t accounts_DB[255] = {
	{1000.00, RUNNING,"61234567891234567"},
	{2000.00, BLOCKED,"71234567891234567"},
	{7000.100,RUNNING,"81234567891234567"},
	{20000.00,RUNNING,"91234567891234567"},
	{3000.00, RUNNING,"51234567891234567"},
	{200.00,  RUNNING,"41234567891234567"}
};


ST_transaction_t transaction[255];


				 /***** Recieve Transation Data Function *****/

/***********************************************************************/
/*
	-

*/
EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	EN_transState_t error;
	
	printf("---------------------------------------\n");
	if (isValidAccount(transData ->cardHolderData) == ACCOUNT_NOT_FOUND)
	{
		error = FRAUD_CARD;
		printf("FRAUD_CARD\n");
	}
	else  if (isAmountAvailable(&transData ->terminalData) == LOW_BALANCE)
	{
		error = DECLINED_INSUFFECIENT_FUND;
		printf("DECLINED_INSUFFECIENT_FUND\n");
	}
	else if (isBlockedAccount(&accountRefrence) == BLOCKED_ACCOUNT)
	{
		error = DECLINED_STOLEN_CARD;
		printf("DECLINED_STOLEN_CARD\n");

	}
	else if (saveTransaction(&transData) == SAVING_FAILED)
	{
		error = SAVING_FAILED;
		printf("SAVING_FAILED\n");
	}
	else
	{
		error = APPROVED;
		printf("APPROVED\n");
	}

	return error;
	
}
/***********************************************************************/

				   /*****  Is valid Account Function *****/

/***********************************************************************/
/*
	-

*/
EN_serverError_t isValidAccount(ST_cardData_t cardData)
{
	EN_serverError_t error;
	uint8_t check=0, Reference=0;
	printf("the Enter PAN is : %s\n", cardData.primaryAccountNumber);
	for (int i = 0; i < 255; i++)
	{
		
		if ((strcmp(cardData.primaryAccountNumber, accounts_DB[i].primaryAccountNumber) == 0))
		{
			check = 0;
			Reference = i;
			break;
		}
		else
		{
			check = 1;

		}

	}

	if (check == 0)
	{
		error = SERVER_OK;
		printf("PAN found\n");
		accountRefrence = accounts_DB[Reference];
	}
	else
	{
		error = ACCOUNT_NOT_FOUND;
		printf("PAN Not Found \n");
		accountRefrence.balance = 0.0;
		accountRefrence.state = NO_STATE;
	}
	return error;
}
/***********************************************************************/

			  /*****  Is Blocked Account Function *****/

/***********************************************************************/
/*
	-

*/
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t error;
	printf("*********%d \n", accountRefrence->state);
	printf("*********%s\n", accountRefrence->primaryAccountNumber);

	if ((accountRefrence->state == BLOCKED))
	{
		error = BLOCKED_ACCOUNT;
		printf(" Blocked Account\n");

	}
	else if (accountRefrence ->state == RUNNING)
	{
		error = SERVER_OK;
		printf(" Running Account\n");
		
	}
	else
	{
		printf("wrong Account\n");
		error = ACCOUNT_NOT_FOUND;
	}

	return error; 
}

/***********************************************************************/


			  /*****  Is Amount Avaliable Function *****/

/***********************************************************************/
/*
	-

*/
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	EN_serverError_t error;
	printf("Your transation Amount is : %f\n", termData->transAmount);
	printf("your Balance is :%f\n", accountRefrence.balance);

	if (termData->transAmount > accountRefrence.balance)
	{
		error = LOW_BALANCE;
		printf("Low Balance \n");

	}
	else
	{
		error = SERVER_OK;
	}


	

	return error;
}
/***********************************************************************/

			   /*****  Save Transation Function *****/

/***********************************************************************/
/*
	-

*/
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	EN_serverError_t error=0;
	

	



	return error;
}
/***********************************************************************/

	         /*****  Get Transation  Function *****/

/***********************************************************************/
/*
	-

*/
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{




	return 0;

}
/***********************************************************************/

	     
