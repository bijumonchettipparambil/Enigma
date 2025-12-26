#ifndef ENIGMA_ROTOR_H_
#define ENIGMA_ROTOR_H_

/**
 * File type	: Header
 * File name	: Rotor.h
 * Description	: Definition of the standard German enigma rotor assembly, 
 * 		          for rotors I through V
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Structure representing a German Enigma rotor assembly
typedef struct Rotor
{
	int id; 		// Identification of the Rotor
	char wiring[27];	// Wiring order of alphabets
	int notch;		// Location of the notch
}t_Rotor;

//----------------------------------------------------------------
// Function declaration
//----------------------------------------------------------------

// Generate and return an instance of a rotor assembly
// for a given rotor id.
t_Rotor get_rotor(const int);

// Build rotor assembly for rotor id#1
t_Rotor build_rotor1(void);

// Build rotor assembly for rotor id#2
t_Rotor build_rotor2(void);

// Build rotor assembly for rotor id#3
t_Rotor build_rotor3(void);

// Build rotor assembly for rotor id#4
t_Rotor build_rotor4(void);

// Build rotor assembly for rotor id#5
t_Rotor build_rotor5(void);

// Print the rotor assembly settings for a given rotor
// id.
void view_rotor(const int);

// Print a given rotor
void print_rotor(const t_Rotor);

// Convert a given rotor to string representation
void rotor_to_string(const t_Rotor, char*, size_t);

#endif
