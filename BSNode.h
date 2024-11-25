#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
    public:
        // miembros públicos
	T elem;
	BSNode<T>* left;
	BSNode<T>* right;

	BSNode(T elem, BSNode<T>* left = nullptr, BSNode <T>* right = nullptr);
	friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn){
		out <<"Elemento: " <<bsn.elem << std::endl;
		return out;
	}    
};

#endif

template <typename T>

BSNode::BSNode(T elem, BSNode<T>* left = nullptr, BSNode <T>* right = nullptr){
	this -> elem = elem;
	this -> right = right;
	this -> left = left;
}
