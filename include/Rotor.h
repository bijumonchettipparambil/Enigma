#ifndef ENIGMA_ROTOR_H_
#define ENIGMA_ROTOR_H_

/**
 * File type	: Header
 * File name	: Rotor.h
 * Description	: Implementation of the standard German enigma rotor assembly, 
 * 		          for rotors I through V
 */

#include <stdio.h>
#include <stdlib.h>

// Structure representing a German Enigma rotor assembly
typedef struct Rotor
{
	int id; 		    // Identification of the Rotor
	char wiring[26];	// Wiring order of alphabets
	int notch;		    // Location of the notch
}t_Rotor;

//----------------------------------------------------------------
// Function declaration
//----------------------------------------------------------------

// Generate and return an instance of a rotor assembly
// for a given rotor id.
static t_Rotor get_rotor(const int id);

// Build rotor assembly for rotor id#1
static t_Rotor build_rotor1(void);

// Build rotor assembly for rotor id#2
static t_Rotor build_rotor2(void);

// Build rotor assembly for rotor id#3
static t_Rotor build_rotor3(void);

// Build rotor assembly for rotor id#4
static t_Rotor build_rotor4(void);

// Build rotor assembly for rotor id#5
static t_Rotor build_rotor5(void);

// Print the rotor assembly settings for a given rotor
// id.
static void view_rotor(const int id);

//----------------------------------------------------------------
// Function definition
//----------------------------------------------------------------

// Generate and return an instance of a rotor assembly
// for a given rotor id
static t_Rotor get_rotor(const int id)
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
static t_Rotor build_rotor1(void)
{
    t_Rotor rotor = {1, "EKMFLGDQVZNTOWYHXUSPAIBRCJ", 16};
    return rotor;
}

// Build rotor assembly for rotor id#2
static t_Rotor build_rotor2(void)
{
    t_Rotor rotor = {2, "AJDKSIRUXBLHWTMCQGZNPYFVOE", 4};
    return rotor;
}

// Build rotor assembly for rotor id#3
static t_Rotor build_rotor3(void)
{
    t_Rotor rotor = {3, "BDFHJLCPRTXVZNYEIWGAKMUSQO", 21};
    return rotor;
}

// Build rotor assembly for rotor id#4
static t_Rotor build_rotor4(void)
{
    t_Rotor rotor = {4, "ESOVPZJAYQUIRHXLNFTGKDCMWB", 9};
    return rotor;
}

// Build rotor assembly for rotor id#5
static t_Rotor build_rotor5(void)
{
    t_Rotor rotor = {5, "VZBRGITYUPSDNHLXAWMJQOFECK", 25};
    return rotor;
}

// Print the rotor assembly settings for a given rotor
// id.
static void view_rotor(const int id)
{
    t_Rotor rotor = get_rotor(id);
    fprintf(stdout,"[Info] Rotor.h: {\"id\": %d, \"wiring\": \"%s\", \"notch\": %d}\n", rotor.id, rotor.wiring, rotor.notch);
}

#endif
