/**
 * File type	: Source
 * File name	: Reflector.c
 * Description	: Implementation of the standard German enigma reflector assembly, 
 * 		          for reflectors UKW-B and UKW-C
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Reflector.h"

//----------------------------------------------------------------
// Function definition
//----------------------------------------------------------------

// Generate and return an instance of a reflector assembly
// for a given reflector name
t_Reflector get_reflector(const char* name)
{
    if (strcmp(name, "UKW-B") == 0) return build_reflector_UKW_B();
    if (strcmp(name, "UKW-C") == 0) return build_reflector_UKW_C();
    fprintf(stderr, "[Error] Reflector.h: Reflector name \"%s\" is invalid, it must be \"UKW-B\" or \"UKW-C\".", name);
    exit(1);
}

// Build reflector assembly for reflector UKW-B
t_Reflector build_reflector_UKW_B(void)
{
    t_Reflector reflector = {"UKW-B", "YRUHQSLDPXNGOKMIEBFZCWVJAT"};
    return reflector;
}

// Build reflector assembly for reflector UKW-C
t_Reflector build_reflector_UKW_C(void)
{
    t_Reflector reflector = {"UKW-C", "FVPJIAOYEDRZXWGCTKUQSBNMHL"};
    return reflector;
}

// Print the reflector assembly settings for a given reflector
// name
void view_reflector(const char* name)
{
    t_Reflector reflector = get_reflector(name);
    fprintf(stdout,"[Info] Reflector.h: {\"name\": \"%s\", \"wiring\": \"%s\"}\n", reflector.name, reflector.wiring);
}
