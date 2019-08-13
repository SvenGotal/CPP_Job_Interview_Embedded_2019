/******************************************************************
 * list.h
 *
 *  Created on: Jul 27, 2019
 *      Author: Sven Gotal
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
template<typename N>
class List{
	Element<N>* first;
	uint8_t size;

public:

	/****************************************************************
	* Constructors and Destructors
	*****************************************************************/
	List();
	/* Constructor with input - for memory preallocation */
	List(Element<N>* mem_destination);
	List(const List<N>& other);
	~List();


	/****************************************************************
	* deletes the list
	*****************************************************************/
	void delete_list();

	/****************************************************************
	* Adds a new element onto the list
	*****************************************************************/
	void add_element(const N value);

	/****************************************************************
	* Delete element method - Deletes only one and first found corresponding value
	*****************************************************************/
	void delete_element(const N value);

	/****************************************************************
	* Method that will return pointer to the found element or NULL in other case
	*****************************************************************/
	Element<N>* find_element(const N value);

	/****************************************************************
	* Helper method for printing all of the list elements
	*****************************************************************/
	friend std::ostream& operator<< (std::ostream& os, const List lista)
	{
		Element<N>* iter = lista.first;
			os << "size: " << (unsigned)lista.size << std::endl;
			while(iter != NULL)
			{
				os << iter->element << std::endl;
				iter = iter->next;
			}
			if(iter != nullptr)
				iter = nullptr;

			return os;
	}


};

#endif /* LIST_H_ */
