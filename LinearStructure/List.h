#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

template<typename Type>
class List{
public:
	virtual void clear()=0;
	virtual int length() const=0;
	virtual void insert(int i,const Type &x)=0;
	virtual void remove(int i)=0;
	virtual int search(const Type &x) const=0;
	virtual Type visit(int i)=0;
	virtual void traverse() const=0;
	virtual ~List()=default;
};

#endif //DATASTRUCTURE_LIST_H
