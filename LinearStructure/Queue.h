#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

template<typename Type>
class Queue{
private:
	virtual void doubleSpace()=0;
public:
	virtual bool empty() const=0;
	virtual void push(const Type &x)=0;
	virtual Type pop()=0;
	virtual Type top() const=0;
	virtual ~Queue()=default;
};

#endif //DATASTRUCTURE_QUEUE_H
