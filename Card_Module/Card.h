
#ifndef CARD_H
#define CARD_H

                        /*****  Header Files *****/

/***********************************************************************/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include"../Header_Files/Std_Types.h"
/***********************************************************************/

                         /*****  Data types *****/

/***********************************************************************/

typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];

}ST_cardData_t;




typedef enum EN_cardError_t
{
	OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN

}EN_cardError_t;

/***********************************************************************/


                       /*****  Variables *****/

/***********************************************************************/

ST_cardData_t CardData_Instance;

/***********************************************************************/



                   /*****  Functions prototypes *****/

/***********************************************************************/

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);

/***********************************************************************/











#endif // !CARD_H

