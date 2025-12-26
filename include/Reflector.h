#ifndef ENIGMA_REFLECTOR_H_
#define ENIGMA_REFLECTOR_H_

/**
 * File type	: Header
 * File name	: Reflector.h
 * Description	: Definition of the standard German enigma reflector assembly, 
 * 		          for reflectors UKW-B and UKW-C
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure representing a German Enigma reflector assembly
typedef struct Reflector
{
	const char* name; 	// Name of the Reflector
	const char* wiring;	// Wiring order of alphabets
}t_Reflector;

//----------------------------------------------------------------
// Function declaration
//----------------------------------------------------------------

// Generate and return an instance of a reflector assembly
// for a given reflector name
t_Reflector get_reflector(const char*);

// Build reflector assembly for UKW-B
t_Reflector build_reflector_UKW_B(void);

// Build reflector assembly for UKW-C
t_Reflector build_reflector_UKW_C(void);

// Print the reflector assembly settings for a given reflector
// name
void view_reflector(const char*);

#endif
