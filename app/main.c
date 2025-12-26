/**
 * File type    : Header
 * File name    : Rotor.h
 * Description  : Implementation of the standard German enigma rotor assembly, 
 *                for rotors I through V.
 */

#include <stdio.h>

#include "Rotor.h"
#include "Reflector.h"
#include "Enigma.h"

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

    t_Rotor rotor = get_rotor(1);

    rotor = initial_rotor_adjustment(rotor, 25);
    printf("Rotor adjusted by offset: %d\n", 25);
    print_rotor(rotor);

    rotor = step_rotor_by_count(rotor, 1);
    printf("Rotor stepped by : %d\n", 1);
    print_rotor(rotor);
 
    rotor = step_rotor_by_count(rotor, 2);
    printf("Rotor stepped by : %d\n", 2);
    print_rotor(rotor);

    rotor = step_rotor_by_count(rotor, 3);
    printf("Rotor stepped by : %d\n", 3);
    print_rotor(rotor);

    printf("Notch: %d", is_rotor_at_notch(rotor, 17));
    
    printf("Index of \"%c\" is \"%d\".\n", 'Z',get_window_letter_index('Z'));
    
    printf("[Info] Enigma: Completed...\n");
    return 0;
}
