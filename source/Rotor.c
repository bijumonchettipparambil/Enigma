/**
 * File type	: Header
 * File name	: Rotor.c
 * Description	: Implementation of the standard German enigma rotor assembly, 
 * 		          for rotors I through V
 */

#include <stdio.h>
#include <stdlib.h>

#include "Rotor.h"

//----------------------------------------------------------------
// Function definition
//----------------------------------------------------------------

// Generate and return an instance of a rotor assembly
// for a given rotor id
t_Rotor get_rotor(const int id)
{
    switch (id)
    {
        case 1: return build_rotor1();
        case 2: return build_rotor2();
        case 3: return build_rotor3();
        case 4: return build_rotor4();
        case 5: return build_rotor5();
        default: 
                fprintf(stderr, "[Error] Rotor.h: Rotor id must be in the range 1 to 5, received \"%d\".\n", id);
                exit(1);
    }
}

// Build rotor assembly for rotor id#1
t_Rotor build_rotor1(void)
{
    t_Rotor rotor = {1, "EKMFLGDQVZNTOWYHXUSPAIBRCJ", 16};
    return rotor;
}

// Build rotor assembly for rotor id#2
t_Rotor build_rotor2(void)
{
    t_Rotor rotor = {2, "AJDKSIRUXBLHWTMCQGZNPYFVOE", 4};
    return rotor;
}

// Build rotor assembly for rotor id#3
t_Rotor build_rotor3(void)
{
    t_Rotor rotor = {3, "BDFHJLCPRTXVZNYEIWGAKMUSQO", 21};
    return rotor;
}

// Build rotor assembly for rotor id#4
t_Rotor build_rotor4(void)
{
    t_Rotor rotor = {4, "ESOVPZJAYQUIRHXLNFTGKDCMWB", 9};
    return rotor;
}

// Build rotor assembly for rotor id#5
t_Rotor build_rotor5(void)
{
    t_Rotor rotor = {5, "VZBRGITYUPSDNHLXAWMJQOFECK", 25};
    return rotor;
}

// Print the rotor assembly settings for a given rotor
// id.
void view_rotor(const int id)
{
    t_Rotor rotor = get_rotor(id);
    fprintf(stdout,"[Info] Rotor.h: {\"id\": %d, \"wiring\": \"%s\", \"notch\": %d}\n", rotor.id, rotor.wiring, rotor.notch);
}

// Print a given rotor
void print_rotor(const t_Rotor rotor)
{
    fprintf(stdout,"[Info] Rotor.h: {\"id\": %d, \"wiring\": \"%s\", \"notch\": %d}\n", rotor.id, rotor.wiring, rotor.notch);
}

// Convert a given rotor to string representation
void rotor_to_string(const t_Rotor rotor, char* p_buffer, size_t buffer_length)
{
    snprintf(p_buffer, buffer_length, "{\"id\": %d, \"wiring\": \"%s\", \"notch\": %d}", 
    rotor.id, rotor.wiring, rotor.notch);
}
