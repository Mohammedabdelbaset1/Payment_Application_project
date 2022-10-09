#include "App.h"


int main()
{
	//getCardHolderName(&CardData_Instance);
	//getCardExpiryDate(&CardData_Instance);
	getCardPAN(&CardData_Instance);

	//getTransactionDate(&TerminalDate_Instance);
	//isCardExpired(CardData_Instance, TerminalDate_Instance);
	getTransactionAmount(&TerminalDate_Instance);
	setMaxAmount(&TerminalDate_Instance);
	//isBelowMaxAmount(&TerminalDate_Instance);
	isValidAccount(CardData_Instance);
	isBlockedAccount(&accountRefrence);
	isAmountAvailable(&TerminalDate_Instance);
	


	return 0;
}