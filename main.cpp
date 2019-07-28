/******************************************************************
 * main.cpp
 *
 *  Created on: Jul 27, 2019
 *      Author: Sven
 *
 * Description: Test program for custom, Singly-Linked-List
 ******************************************************************/

#include<iostream>
#include<string>
#include "list.h"



/****************************************************************
* preallocate memory byte by byte for the list Element<T> chain
*****************************************************************/
#define MEMORY_REQ 32 // Memory requirement - max how many Elements<type> will be used

static uint8_t* preallocated = new uint8_t[MEMORY_REQ * sizeof(Element<double>)]; // memory location

static Element<double>* lista = new(preallocated) Element<double>[32];	   // allocation to preallocated mem_location
/****************************************************************/



int main(){


	/* TEST */
/*
	List<double> Lista(lista);
	Lista.add_element(3.14);
	Lista.add_element(2.718);
	Lista.add_element(1.618);
	Lista.add_element(0.577);
	Lista.add_element(1.414);
	Lista.add_element(0.280);
	Lista.add_element(0.5671);

	Lista.delete_element(1.414);

	std::cout << Lista;
	delete lista;
*/

	List<double> lista_lf;

	lista_lf.add_element(3.14);		// Pi
	lista_lf.add_element(2.718);	// Euler's number
	lista_lf.add_element(1.618);	// Golde cut
	lista_lf.add_element(0.577);	// Euler-Mascheroni constant
	lista_lf.add_element(1.414);	// sqrt(2) Pythagora
	lista_lf.add_element(0.280);	// Bernstein's constant
	lista_lf.add_element(0.5671);	// Omega constant

	lista_lf.delete_element(1.414);

	std::cout << lista_lf;
/*
	List<char> lista2;
	lista2.add_element('a');
	lista2.add_element('b');
	lista2.add_element('c');
	lista2.add_element('d');
	lista2.add_element('e');
	lista2.add_element('f');

	lista2.delete_element('a');

	std::cout << "//////////////////////////" << std::endl;
	std::cout << lista2;
*/
	return 0;
}
