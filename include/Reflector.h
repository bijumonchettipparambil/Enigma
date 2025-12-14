#ifndef ENIGMA_REFLECTOR_H_
#define ENIGMA_REFLECTOR_H_

/**
 * File type	: Header
 * File name	: Reflector.h
 * Description	: Implementation of the standard German enigma reflector assembly, 
 * 		          for reflectors UKW-B and UKW-C
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure representing a German Enigma reflector assembly
typedef struct Reflector
{
	char* name; 		// Name of the Reflector
	char wiring[26];	// Wiring order of alphabets
}t_Reflector;

//----------------------------------------------------------------
// Function declaration
//----------------------------------------------------------------

// Generate and return an instance of a reflector assembly
// for a given reflector name
static t_Reflector get_reflector(const char* name);

// Build reflector assembly for UKW-B
static t_Reflector build_reflector_UKW_B(void);

// Build reflector assembly for UKW-C
static t_Reflector build_reflector_UKW_C(void);

// Print the reflector assembly settings for a given reflector
// name
static void view_reflector(const char* name);

//----------------------------------------------------------------
// Function definition
//----------------------------------------------------------------

// Generate and return an instance of a reflector assembly
// for a given reflector name
static t_Reflector get_reflector(const char* name)
{
    if (strcmp(name, "UKW-B") == 0) return build_reflector_UKW_B();
    if (strcmp(name, "UKW-C") == 0) return build_reflector_UKW_C();
    fprintf(stderr, "[Error] Reflector.h: Reflector name \"%s\" is invalid, it must be \"UKW-B\" or \"UKW-C\".", name);
    exit(1);
}

// Build reflector assembly for reflector UKW-B
static t_Reflector build_reflector_UKW_B(void)
{
    t_Reflector reflector = {"UKW-B", "YRUHQSLDPXNGOKMIEBFZCWVJAT"};
    return reflector;
}

// Build reflector assembly for reflector UKW-C
static t_Reflector build_reflector_UKW_C(void)
{
    t_Reflector reflector = {"UKW-C", "FVPJIAOYEDRZXWGCTKUQSBNMHL"};
    return reflector;
}

// Print the reflector assembly settings for a given reflector
// name
static void view_reflector(const char* name)
{
    t_Reflector reflector = get_reflector(name);
    fprintf(stdout,"[Info] Reflector.h: {\"name\": \"%s\", \"wiring\": \"%s\"}\n", reflector.name, reflector.wiring);
}

#endif
