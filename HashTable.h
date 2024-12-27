#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
  // ¡¡¡¡MODIFICAR!!!!
#include "/home/spedvaz/PRA/lab/PRA_2324_P1/[PRA_2323_P1]/ListLinked.h"

using namespace std;

template <typename V>
class HashTable: public Dict<V> {

    private:
        // ...
		int n;
		int max;
		ListLinked<TableEntry<V>>* table;
		int h(std::string key);

    public:
        // ...
		HashTable(int size);
		~HashTable();
		int capacity();
		friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
			out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]\n";
			out << "==============\n\n";
			for(int i = 0; i < th.max; i++){
			out<< "== Cubeta " << i << " ==\n\n";
			out <<"List => [" << "("<<th.table[i] <<")\n" << "]\n\n";
			}

			out << "==============\n";
			return out;
		
		}
		V operator[](std::string key);		
		void insert(std::string key, V value) override final;
		V search(std::string key) override final;
		V remove(std::string key) override final;
		int entries() override final;
        
};

template <typename V>

HashTable<V>::HashTable(int size){ //hecho
	table = new ListLinked<TableEntry<V>>[size];
	this->n = 0;
	this->max = size;
}

template <typename V>

HashTable<V>::~HashTable(){
	delete[]table; //hecho
}

template <typename V>

int HashTable<V>::capacity(){
	return max; //hecho
}

template <typename V>

V HashTable<V>::operator[](std::string key){
	int pos = h(key);
	Node<TableEntry<V>>* current = table[pos].first;
	while(current != nullptr){
		if(current -> data.key == key){
			return current -> data.value;
		}		
		current = current -> next;
	}
	
	throw runtime_error ("Key no encontrada");
}


template <typename V>

void HashTable<V>::insert(std::string key, V value){
	int pos = h(key);
	Node<TableEntry<V>>* current = table[pos].first;	
	while(current != nullptr){
		if( current -> data.key == key){
			throw runtime_error ("Key ya introducida");
		}
		current = current -> next;
	}
	
	TableEntry<V> NuevaEntrada(key, value);
	table[pos].prepend(NuevaEntrada);
	n++;
}



template <typename V>

V HashTable<V>::search(std::string key){
	int pos = h(key);
	Node<TableEntry<V>>* current = table[pos].first;
	
	do{
		if(current -> data.key == key){
			return current -> data.value;
		}
		current = current -> next;
	}while(current != nullptr);

	throw runtime_error ("Key no encontrada");
}


template <typename V>

V HashTable<V>::remove(std::string key){
	int pos = h(key);
	Node<TableEntry<V>>* current = table[pos].first;
	Node<TableEntry<V>>* prev = nullptr;
	V valor;
	
	while(current != nullptr){
		if(current -> data.key == key){
			if( prev != nullptr){
				valor = current -> data.value;
				prev->next = current ->next;
				
			}else{
				valor = current -> data.value;
				table[pos].first = current -> next;
			}
			
			delete current;
			n--;
			return valor;
		}else{
			prev = current;
			current = current -> next;
		}
	}	

	throw runtime_error ("Key no encontrada");
}


template <typename V>

int HashTable<V>::entries(){ //hecho
	return n;
}


template <typename V>
//hecha
int HashTable<V>::h(std::string key){
	int ascii = 0;
	for(char c : key){
		ascii += int(c);
	}
	return ascii % max;
}

#endif
