#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
    int j, k, h, t;

    /* test normal queue */
    Queue *myQ;
    myQ = Queue_Create();
    k = 1000;

    for(j = 0; j < QUEUE_SIZE; j++)
    {
        h = myQ->head;
        myQ->insert(myQ, k);
        printf("inserting %d at posotion %d,size = %d\n",k--,h,myQ->getSize(myQ));

    }

}