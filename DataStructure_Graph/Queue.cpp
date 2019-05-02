#include "Queue.h"

void Queue_push(queue *q, char e)
{
	q->num++;
	q->Element[q->back] = e;
	q->back = ++q->back % Queue_max;
}

char Queue_pop(queue *q)
{
	char elem = q->Element[q->front];
	q->num--;
	//For easy debugging
	q->Element[q->front] = -52;//-52 -> '?' 
	
	q->front = ++q->front % Queue_max;
	return elem;
}

bool IsEmpty(queue *q)
{
	if (q->num==0)
	{
		return true;
	}
	return false;
}

void InitQueue(queue *&q)
{
	q = new queue;
	q->back = q->front = q->num = 0;
}
