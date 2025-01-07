#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        // ...
		BSTree<TableEntry<V>>* tree;
    public:
        // ...
        BSTreeDict();
		~BSTreeDict();
		friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
			out << *(bs.tree); 
			out << std::endl;
			return out;
		}
		V operator[](std::string key);
		void insert(std::string key, V value);
		V search(std::string key);
		V remove(std::string key);
		int entries();
};

#endif

template <typename V>

BSTreeDict<V>::BSTreeDict(){
	tree = new BSTree<TableEntry<V>>();
}


template <typename V>

BSTreeDict<V>::~BSTreeDict(){
	if(tree != nullptr){
		delete tree;
	}
}


template <typename V>

V BSTreeDict<V>::operator[](std::string key){
	return search(key);
}


template <typename V>

void BSTreeDict<V>::insert(std::string key, V value){
	TableEntry<V> entrada(key, value);
	tree->insert(entrada);
}


template <typename V>

V BSTreeDict<V>::search(std::string key){
	TableEntry<V> entrada(key);
	TableEntry<V> encontrado = tree->search(entrada);
	return encontrado.value;
}


template <typename V>

V BSTreeDict<V>::remove(std::string key){
	TableEntry<V> entrada(key);
	V eliminado = tree->search(entrada).value;
	tree->remove(entrada);
	return eliminado;
}


template <typename V>

int BSTreeDict<V>::entries(){
	return tree->size();
}
