#include "Type_PQueue.h"
extern pqueue CreateQueue();
extern int EnQueue(pqueue *q, element e, int priority);
extern int DeQueue(pqueue *q);
extern int Front(pqueue q, element *e);
extern int isEmptyQueue(pqueue q);
extern void update_priority(pqueue *q, element data, int priority);