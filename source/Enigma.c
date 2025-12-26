/**
 * File type	: Source
 * File name	: Engine.c
 * Description	: Implementation of the German Enigma core processing engine.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "Enigma.h"
#include "Rotor.h"

// Static constants
static const size_t max_input_length = 65535;
static const char* alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const int alphabet_count = 26;
static const int min_value = 0;
static const int max_value = 25;

t_Rotor initial_rotor_adjustment(const t_Rotor input_rotor, const int offset)
{
	// Ensure the offset is less than or equal to 25
	if (offset < min_value || offset > max_value)
	{
		fprintf(stderr, "[ERROR] Enigma.c: Offset must be in the range 0 to 25.\n");
		exit(1);
	}
	// Perform rotor adjustment
	t_Rotor adjusted_rotor;
	adjusted_rotor.id = input_rotor.id;
	adjusted_rotor.notch = (((input_rotor.notch - offset) % alphabet_count) + alphabet_count) % alphabet_count;
	int i = 0;
	while(i < alphabet_count)
	{
		int index = (offset + i) % alphabet_count;
		adjusted_rotor.wiring[i] = input_rotor.wiring[index];
		++i;
	}
	adjusted_rotor.wiring[i] = '\0';

	return adjusted_rotor;
}

t_Rotor step_rotor_by_count(const t_Rotor input_rotor, const int count)
{
	// Ensure the offset is less than or equal to 25
	if (count < min_value || count > max_value)
	{
		fprintf(stderr, "[ERROR] Enigma.c: Count must be in the range 0 to 25.\n");
		exit(1);
	}
	// Perform rotor stepping
	t_Rotor adjusted_rotor;
	adjusted_rotor.id = input_rotor.id;
	adjusted_rotor.notch = input_rotor.notch;
	int i = 0;
	while(i < alphabet_count)	
	{
		int index = (count + i) % alphabet_count;
		adjusted_rotor.wiring[i] = input_rotor.wiring[index];
		++i;
	}
	adjusted_rotor.wiring[i] = '\0';
	return adjusted_rotor;
}

// Check if current rotor position aligns with the notch position,
// when true returns 1, else returns 0
int is_rotor_at_notch(const t_Rotor rotor, const int window_letter_offset)
{
	return rotor.notch == window_letter_offset;
}

// Compute window letter to the corresponding integer offset
int get_window_letter_index(const char window_letter)
{
    int i = 0;
    while(i < 26)
    {
        if (alphabets[i] == window_letter)
            return i;
        ++i;
    }
    fprintf(stderr, "[ERROR] Enigma.c: Invalid window_letter \"%c\"  character supplied", window_letter);
    exit(1);
}

t_Processing_Context setup_for_processing(const t_Input_Context in_cntxt)
{
    // Ensure input is not null and within maximum length allowed
    if (strlen(in_cntxt.input) > max_input_length && in_cntxt.input != NULL)
    {
        fprintf(stderr, "[ERROR] Enigma.c: Input is NULL or length \"%zu\", exceeds maximum acceptable value \"%zu\".", 
        strlen(in_cntxt.input), max_input_length);
        exit(1);
    }
    // Define processing context
    t_Processing_Context proc_cntxt = 
    {
        // Set debug flag
        in_cntxt.debug,
        // Set input
        in_cntxt.input,
        // Get requested rotors and perform initial offset adjustment
        initial_rotor_adjustment(get_rotor(in_cntxt.right_rotor_id), in_cntxt.right_rotor_offset),
        initial_rotor_adjustment(get_rotor(in_cntxt.middle_rotor_id), in_cntxt.middle_rotor_offset),
        initial_rotor_adjustment(get_rotor(in_cntxt.left_rotor_id), in_cntxt.left_rotor_offset),
        // Set window letters
        in_cntxt.right_window_letter,
        in_cntxt.middle_window_letter,
        in_cntxt.left_window_letter
    };

    return proc_cntxt;
}

const char* process_input(const t_Processing_Context proc_cntxt)
{
    int i = 0;
    while(proc_cntxt.input[i] != '\0')
    {
        printf("Processing Char#%d is '%c'.\n", i, proc_cntxt.input[i]);
        ++i;
    }

    return "<--- Placeholder: Change return value in Enigma.c::process_input --->";
}

void debug_print_input_context(const t_Input_Context in_cntxt)
{
    fprintf(stdout, "[DEBUG] Enigma.c: debug_print_input_context {\"debug\": %d, \"right_rotor_id\": %d, "
    "\"middle_rotor_id\": %d, \"left_rotor_id\": %d, \"right_rotor_offset\": %d, \"middle_rotor_offset\" : %d, "
    "\"left_rotor_offset\": %d, \"right_window_letter\": \"%c\", \"middle_window_letter\": \"%c\", "
    "\"left_window_letter\": \"%c\", \"input\": \"%s\"}.\n", in_cntxt.debug, in_cntxt.right_rotor_id, in_cntxt.middle_rotor_id, 
    in_cntxt.left_rotor_id, in_cntxt.right_rotor_offset, in_cntxt.middle_rotor_offset, in_cntxt.left_rotor_offset, 
    in_cntxt.right_window_letter, in_cntxt.middle_window_letter, in_cntxt.left_window_letter, in_cntxt.input);
}

void debug_print_processing_context(const t_Processing_Context proc_cntxt)
{    
    char right_rotor_buffer[256]; 
    char middle_rotor_buffer[256];
    char left_rotor_buffer[256];
    rotor_to_string(proc_cntxt.right_rotor, right_rotor_buffer, sizeof right_rotor_buffer);
    rotor_to_string(proc_cntxt.middle_rotor, middle_rotor_buffer, sizeof middle_rotor_buffer);
    rotor_to_string(proc_cntxt.left_rotor, left_rotor_buffer, sizeof left_rotor_buffer);
    fprintf(stdout, "[DEBUG] Enigma.c: debug_print_processing_context {\"debug\": %d, \"input\": \"%s\", " 
    "\"right_rotor\": %s, \"middle_rotor\": %s, \"left_rotor\": %s, \"right_window_letter\": \"%c\", "
    "\"middle_window_letter\": \"%c\", \"left_window_letter\": \"%c\"}.\n", proc_cntxt.debug, proc_cntxt.input,
    right_rotor_buffer, middle_rotor_buffer, left_rotor_buffer, proc_cntxt.right_window_letter, 
    proc_cntxt.middle_window_letter, proc_cntxt.left_window_letter);
}

