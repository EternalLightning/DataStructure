#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

template<typename Type>
class Stack{
public:
	virtual bool isEmpty() const=0;
	virtual void push(const Type &x)=0;
	virtual Type pop()=0;
	virtual Type top() const=0;
	virtual ~Stack()=default;
};

#endif //DATASTRUCTURE_STACK_H
