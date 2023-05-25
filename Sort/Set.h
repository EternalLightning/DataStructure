#ifndef DATASTRUCTURE_SET_H
#define DATASTRUCTURE_SET_H

template<typename KEY,typename VALUE>
struct SET{
	KEY key;
	VALUE val;
    bool operator<(SET<KEY, VALUE> x){
        return key<x.key;
    }
    bool operator<=(SET<KEY, VALUE> x){
        return key<=x.key;
    }
    bool operator>(SET<KEY, VALUE> x){
        return key>x.key;
    }
    bool operator>=(SET<KEY, VALUE> x){
        return key>=x.key;
    }
};

template<typename Type>
void swap(Type &a, Type &b){
    Type tmp=a;
    a=b;
    b=tmp;
}

#endif //DATASTRUCTURE_SET_H