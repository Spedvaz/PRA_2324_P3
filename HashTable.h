#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
  // ¡¡¡¡MODIFICAR!!!!
//#include "fish/home/spedvaz/PRA/lab/PRA_2324_P1/ListLinked.h"
#include "fish/home/spedvaz/PRA/lab/PRA_2324_P1/[PRA_2323_P1]/ListLinked.h"
template <typename V>
class HashTable: public Dict<V> {

    private:
        // ...
		int n;
		int max;
		ListLinked<TableEntry<V>>* table;
		int h(std::string key);
		void insert(std::string key, V value) override final;
		V search(std::string key) override final;
		V remove(std::string key) override final;
		int entries() override final;

    public:
        // ...
		HashTable(int size);
		~HashTable();
		int capacity();
		friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
			out << th.key << "->" << th.value << " ";
			return out;
		}
		V operator[](std::string key);
        
};

template <typename V>

HashTable<V>::HashTable(int size){
	this->table = new V[max];
	this->n = n;
	this->max = max;
}

template <typename V>

HashTable<V>::~HashTable(){
	delete[] table;
}

template <typename V>

int HashTable<V>::capacity(){
	return n; // no esto nada seguro
}

template <typename V>

V HashTable<V>::operator[](std::string key){
	
}


template <typename V>

void HashTable<V>::insert(std::string key, V value){
	int pos = 0;
	pos = h(key);
	if(table[pos] == nullptr){
		table[pos].key = key;
		table[pos].value = value;
	}else{
		throw std::runtime_error ("Key ya existe");
	}	
}


template <typename V>

V HashTable<V>::search(std::string key){
	int pos = 0;
	pos = h(key);
	if(table[pos] != nullptr){
		return table[pos].value;
	}else{
		throw std::runtime_error ("Key no encontrada");
	}
	
}


template <typename V>

V HashTable<V>::remove(std::string key){
	int pos = 0;
	pos = h(key);

	if(table[pos] != nullptr){
		delete[] table[pos];
	}else{
		throw std::runtime_error ("Key no encontrada");
	}
}


template <typename V>

int HashTable<V>::entries(){
	for(int i = 0; i < max; i++){
		if(table[i] != nullptr){
			n++;
		}
	}
	return n;
}


template <typename V>

int HashTable<V>::h(std::string key){
	int ascii = 0;
	for(char c : key){
		ascii += int(c);
	}
	return ascii % max;
}

#endif
