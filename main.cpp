/******************************************************************
 * main.cpp
 *
 *  Created on: Jul 27, 2019
 *      Author: Sven Gotal
 *
 * Description: Test program for custom, Singly-Linked-List
 ******************************************************************/

#include<iostream>
#include<string>
#include "list.h"



/****************************************************************
* preallocate memory byte by byte for the list Element<T> chain
*****************************************************************/
//#define MEMORY_REQ 32 // Memory requirement - max how many Elements<type> will be used

//static uint8_t* preallocated = new uint8_t[MEMORY_REQ * sizeof(Element<double>)]; // memory location

//static Element<double>* lista = new(preallocated) Element<double>[MEMORY_REQ];	   // allocation to preallocated mem_location
/****************************************************************/



int main(){


	/* TEST */


	List<double> lista_lf; //= new List<double>();


	lista_lf.add_element(3.14);	    // Pi
	lista_lf.add_element(2.718);	// Euler's number
	//lista_lf.add_element(1.618);	// Golden cut
	//lista_lf.add_element(0.577);	// Euler-Mascheroni constant
	//lista_lf.add_element(1.414);	// sqrt(2) Pythagora
	//lista_lf.add_element(0.280);	// Bernstein's constant
	//lista_lf.add_element(0.5671);	// Omega constant

	std::cout << lista_lf;

	return 0;
}
