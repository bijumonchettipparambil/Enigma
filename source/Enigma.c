/**
 * File type	: Source
 * File name	: Engine.c
 * Description	: Implementation of the German Enigma core processing engine.
 */

#include <stdio.h>
#include <stdlib.h>

#include "Enigma.h"
#include "Rotor.h"

// Static constants
static const char* alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const int alphabet_count = 26;
static const int min_value = 0;
static const int max_value = 25;

t_Rotor initial_rotor_adjustment(const t_Rotor input_rotor, const int offset)
{
	// Ensure the offset is less than or equal to 25
	if (offset < min_value || offset > max_value)
	{
		fprintf(stderr, "[INFO] Enigma.c: Offset must be in the range 0 to 25.\n");
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
		fprintf(stderr, "[INFO] Enigma.c: Count must be in the range 0 to 25.\n");
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
    fprintf(stderr, "[Error] Enigma.c: Invalid window_letter \"%c\"  character supplied", window_letter);
    exit(1);
}
