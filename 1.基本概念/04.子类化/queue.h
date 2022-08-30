#ifndef QUEUE_H_
#define QUEUE_H_

#define QUEUE_SIZE 10

/* class Queue */
typedef struct Queue Queue;
struct Queue{
    int buffer[QUEUE_SIZE];
    int head;
    int size;
    int tail;
    int (*isFull)(Queue* const me);
    int (*isEmpty)(Queue* const me);
    int (*getSize)(Queue* const me);
    void (*insert)(Queue* const me, int k);
    int (*remove)(Queue* const me);
};

/* Constructors and destructors */
void Queue_Init(Queue* const me);



#endif /* QUEUE_H_ */