#ifndef DATASTRUCTURE_DYNAMICSEARCHTABLE_H
#define DATASTRUCTURE_DYNAMICSEARCHTABLE_H

template<typename KEY,typename VALUE>
struct SET{
	KEY key;
	VALUE val;
};

template<typename KEY,typename VALUE>
class DynamicSearchTable{
public:
	virtual SET<KEY,VALUE>* find(const KEY &x) const=0;
	virtual void insert(const SET<KEY,VALUE> &x)=0;
	virtual void remove(const KEY &x)=0;
	virtual ~DynamicSearchTable()=default;
};

#endif //DATASTRUCTURE_DYNAMICSEARCHTABLE_H
