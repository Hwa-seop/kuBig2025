#include "date.h"

void printDate(Date *pDate)
{
    /*printf("%d/%d/%d \n",
        (*pDate).year, 
        (*pDate).month,
        (*pDate).day);
*/

    printf("%d/%d/%d \n",
        pDate->year,
        pDate->month,
        pDate->day);
        for(int i;i<6;i++){
            printf("%d,  ",pDate->temp[i]);
        }
        printf("\n");

}

