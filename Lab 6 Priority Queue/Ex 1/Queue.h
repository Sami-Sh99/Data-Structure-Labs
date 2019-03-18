#include"Type_Queue.h"

queue CreateQueue();
extern int EnQueue(queue*, element, int);
extern int DeQueue(queue*);
extern int Front(queue, element*);
extern int isEmptyQueue(queue);
extern int isFullQueue(queue);
