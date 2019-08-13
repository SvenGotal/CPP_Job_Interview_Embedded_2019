/******************************************************************
 * list.cpp
 *
 *  Created on: Aug 13, 2019
 *      Author: Sven Gotal
 *
 * Description: Source file for custom, Singly-Linked-List
 *
 * Known Bugs: when implementations are outside of header file
 *             user-defined data types cannot be used. Only
 *             types defined in template type Class<type>;
 *             in this file can be used
 *
 * Note to self: * Implementations should be moved to .h
 *
 *
 ******************************************************************/

#include "list.h"

template<typename T> Element<T>::Element() : next(nullptr) { }
template<typename T> Element<T>::Element(T elem, Element* to) : element(elem), next(to) { }
template<typename T> Element<T>::Element(const Element<T>& other) : element(other.element), next(other.next) {}
template<typename T> Element<T>::~Element() { next = nullptr; }

template struct Element<double>;
template struct Element<float>;
template struct Element<std::string>;
template struct Element<int>;
template struct Element<char>;

template<typename N> List<N>::List() : first(nullptr), size(0) {}
template<typename N> List<N>::List(const List<N>& other) : first(nullptr), size(other.size)
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
template<typename N> List<N>::List(Element<N>* mem_destination) : first(mem_destination), size(0) {}
template<typename N> List<N>::~List() { delete_list(); }
template<typename N> void List<N>::add_element(N value)
{

	/* create new node */
			Element<N> *newNode = new Element<N>();

			/* Initialize newNode */
			newNode->element = value;
			newNode->next = this->first;

			/* Put the newNode on the first place on the list */
			this->first = newNode;

			/* Increase the size count for each new element */
			size++;

}
template<typename N> void List<N>::delete_element(const N value)
{
	/* 2 x Iterator | previous is required in order
	 * to set a link over the gap in the list */
	Element<N>* iter, *previous;

	/* Previous - first | iter - second iterator */
	previous = this->first;
	iter = previous->next;

	while(iter != NULL && previous != NULL)
	{

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
template<typename N> Element<N>* List<N>::find_element(const N value)
{

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
template<typename N> void List<N>::delete_list()
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

template class List<double>;
template class List<float>;
template class List<std::string>;
template class List<int>;
template class List<char>;






