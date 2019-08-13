/******************************************************************
 * list.h
 *
 *  Created on: Jul 27, 2019
 *      Author: Sven
 *
 * Description: Header file for custom, Singly-Linked-List
 * 				- fur die CETiTec interview
 *
 * Known Bugs: unknown for now.
 *
 * Note to self: * Implementations should be moved to .cpp
 *
 * 				 * Instead of methods, operator overloads should
 * 				   be used
 ******************************************************************/

#ifndef LIST_H_
#define LIST_H_
#include<ostream>

/****************************************************************
* Template Element class, these make up the chain for the list
*****************************************************************/
template<typename T>
struct Element{

	T element;
	Element* next;

	Element(); //: next(nullptr) { }
	Element(T elem, Element* to); // : element(elem), next(to) { }
	Element(const Element<T>& other); //: element(other.element), next(other.next) {};
	~Element(); // {  next = nullptr; }
};

/****************************************************************
* Template List class
*****************************************************************/
template<class N>
class List{
	Element<N>* first;
	uint8_t size;

public:

	/****************************************************************
	* Constructors and Destructors
	*****************************************************************/
	List() : first(nullptr), size(0) {}

	/* Constructor with input - for memory preallocation */
	List(Element<N>* mem_destination) : size(0), first(mem_destination)	{}

	List(const List<N>& other) : first(nullptr), size(other.size)
	{
		Element<N>* iter = other.first;


		while(iter != nullptr)
		{

			Element<N>* newNode = new Element<N>();
			newNode->element = iter->element;
			newNode->next = first;

			first = newNode;
			iter = iter->next;
		}

	}

	~List(){ delete_list(); }


	/****************************************************************
	* deletes the list
	*****************************************************************/
	void delete_list()
	{

		Element<N>* iter;
		size = 0;

		while(first != nullptr)
		{

			iter = first->next;
			delete first;
			first = iter;

		}

	}

	/****************************************************************
	* Adds a new element onto the list
	*****************************************************************/
	void add_element(const N value){
		/* create new node */
		Element<N> *newNode = new Element<N>();

		/* Initialize newNode */
		newNode->element = value;
		newNode->next = this->first;

		/* Put the newNode on the first place on the list */
		this->first = newNode;

		/* Increase the size count for each new element */
		size++;
		newNode = nullptr;
	}

	/****************************************************************
	* Delete element method - Deletes only one and first found corresponding value
	*****************************************************************/
	void delete_element(const N value){
		/* 2 x Iterator | previous is required in order
		 * to set a link over the gap in the list */
		Element<N>* iter, *previous;

		/* Previous - first | iter - second iterator */
		previous = this->first;
		iter = previous->next;

		while(iter != NULL && previous != NULL){

			/* In case the first element in a row is the value we are
			 * looking for */
			if(previous->element == value){
				if(iter != NULL)
					this->first = iter;
				delete previous;
				break;
			}

			/* every other case down the link chain
			 * break the loop in case the target is found */
			if(iter->element == value){
				if(iter->next != NULL)
					previous->next = iter->next;
				else
					previous->next = NULL;
				delete iter;
				break;
			}

			/* moving iterators further down the chain */
			previous = previous->next;
			iter = previous->next;
		}
		/* get rid of dangling pointers */
		previous = nullptr;
		iter = nullptr;

		/* decrease the size counter */
		this->size--;
	}

	/****************************************************************
	* Method that will return pointer to the found element or NULL in other case
	*****************************************************************/
	Element<N>* find_element(const N value){
		/* Iterator */
		Element<N>* iter = first;

		/* Search through the list O(n) */
		while(iter != NULL){
			if(iter->element == value)
				return iter;
			iter = iter->next;
		}
		/* In case none are found */
		iter = nullptr;
		return NULL;
	}

	/****************************************************************
	* Helper method for printing all of the list elements
	*****************************************************************/
	friend std::ostream& operator<< (std::ostream& os, const List lista){
		Element<N>* iter = lista.first;
		os << "size: " << lista.size << std::endl;
		while(iter != NULL){
			os << iter->element << std::endl;
			iter = iter->next;
		}
		if(iter != nullptr)
			iter = nullptr;
		return os;
	}


};

#endif /* LIST_H_ */
