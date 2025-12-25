#ifndef ENIGMA_ENGINE_H_
#define ENIGMA_ENGINE_H_
/**
 * File type	: Header
 * File name	: Engine.h
 * Description	: Definition of the Enigma core engine.
 */

#include <stdio.h>
#include <stdlib.h>

#include "Rotor.h"

// Structure representing an encyption context
typedef struct 
{
	t_Rotor rotor1;
	int rotor1_offset;
	int rotor1_window_letter;
	t_Rotor rotor2;
	int rotor2_offset;
	int rotor2_window_letter;
	t_Rotor rotor3;
	int rotor3_offset;
	int rotor3_window_letter;

}t_Context;

// Alphabet count
static const int alphabet_count = 26;
static const int min_value = 0;
static const int max_value = 25;

//----------------------------------------------------------------
// Function declaration
//----------------------------------------------------------------

// Adjust rotor for a given offset
t_Rotor initial_rotor_adjustment(const t_Rotor, const int);

// Step rotor forward by a given index
t_Rotor step_rotor_by_count(const t_Rotor, const int);


#endif // ENIGMA_ENGINE_H_
