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

// Structure representing input context
typedef struct 
{

    // Debug switch
    const int debug;
    // Input configuration
	const int right_rotor_id;
    const int middle_rotor_id;
    const int left_rotor_id;
	const int right_rotor_offset;
    const int middle_rotor_offset;
    const int left_rotor_offset;
    const int right_window_letter;
    const int middle_window_letter;
    const int left_window_letter;
   // Input data
    const char* input;

}t_Input_Context;

// Structure representing processing context
typedef struct
{
    // Debug switch
    const int debug;
    // Input data
    const char* input;
    // Rotors
    t_Rotor right_rotor;
    t_Rotor middle_rotor;
    t_Rotor left_rotor;
    // Window letters
    char right_window_letter;
    char middle_window_letter;
    char left_window_letter;

}t_Processing_Context;

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

// Setup for processing
t_Processing_Context setup_for_processing(const t_Input_Context);

// Process input
const char* process_input(const t_Processing_Context);

// Debug print input context
void debug_print_input_context(const t_Input_Context);

// Debug print processing context
void debug_print_processing_context(const t_Processing_Context);

#endif // ENIGMA_ENIGMA_H_
