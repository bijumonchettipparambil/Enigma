/**
 * File type    : Header
 * File name    : Rotor.h
 * Description  : Implementation of the standard German enigma rotor assembly, 
 *                for rotors I through V.
 */

#include <stdio.h>

#include "Rotor.h"
#include "Reflector.h"

int main()
{
    printf("[Info] Enigma: Initialising...\n");
    view_rotor(1);
    view_rotor(2);
    view_rotor(3);
    view_rotor(4);
    view_rotor(5);
    view_reflector("UKW-B");
    view_reflector("UKW-C");
    printf("[Info] Enigma: Completed...\n");
    return 0;
}
