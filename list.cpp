/*
 * list.cpp
 *
 *  Created on: Aug 13, 2019
 *      Author: sven
 */

#include "list.h"

template<typename T> Element<T>::Element() : next(nullptr) { }
template<typename T> Element<T>::Element(T elem, Element* to) : element(elem), next(to) { }
template<typename T> Element<T>::Element(const Element<T>& other) : element(other.element), next(other.next) {}
template<typename T> Element<T>::~Element() { next = nullptr; }

template struct Element<double>;
