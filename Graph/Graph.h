#ifndef DATASTRUCTURE_GRAPH_H
#define DATASTRUCTURE_GRAPH_H

template<typename VerType, typename EdgeType>
class Graph{
protected:
	int vers,edges;
public:
	virtual void insert(VerType x, VerType y, EdgeType w)=0;
	virtual void remove(VerType x, VerType y)=0;
	virtual bool exist(VerType x, VerType y) const=0;
	int verNum() const{
		return vers;
	}
	int edgeNum() const{
		return edges;
	}
};

#endif //DATASTRUCTURE_GRAPH_H
