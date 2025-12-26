#ifndef ENIGMA_ENIGMA_H_
#define ENIGMA_ENIGMA_H_
/**
 * File type	: Header
 * File name	: Enigma.h
 * Description	: Definition of the German Enigma core processing engine.
 */

#include <stdio.h>
#include <stdlib.h>

#include "Rotor.h"

// Structure representing an encyption context
typedef struct 
{

    // Input configuration
	int slot1_rotor_id;
    int slot1_window_letter;
    int slot1_rotor_offset;
    int slot2_rotor_id;
    int slot2_window_letter;
    int slot2_rotor_offset;
	int slot3_rotor_id;
    int slot3_window_letter;
    int slot3_rotor_offset;
    // Input data
    const char* input;
    // Output data
    char* output;

}t_Context;

//----------------------------------------------------------------
// Function declaration
//----------------------------------------------------------------

// Adjust rotor for a given offset
t_Rotor initial_rotor_adjustment(const t_Rotor, const int);

// Step rotor forward by a given index
t_Rotor step_rotor_by_count(const t_Rotor, const int);

// Checks if g given rotor's notch position aligns with 
// the window letter. If true returns 1, else returns 0
int is_rotor_at_notch(const t_Rotor, const int);

// Compute window letter to the corresponding integer offset
int get_window_letter_index(const char);

#endif // ENIGMA_ENIGMA_H_
