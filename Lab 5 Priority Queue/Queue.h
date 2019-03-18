#include "Type_Queue.h"
extern queue CreateQueue();
extern int EnQueue(queue *q, element e);
extern int DeQueue(queue *q);
extern int Front(queue q, element *e);
extern int isEmptyQueue(queue q);
extern int isFullQueue(queue q);