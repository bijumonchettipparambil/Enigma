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
    
    t_Input_Context in_cntxt =
    {
        1,      // Turn on debug
        1,      // Right rotor_id
        2,      // Middle rotor_id
        3,      // Left rotor_id
        0,      // Right rotor offset
        0,      // Middle rotor offset
        0,      // Left rotor offset
        'A',    // Right rotor window letter
        'A',    // Middle rotor window letter
        'A',    // Left rotor window letter
        "Enigma test input"
    };
   
    debug_print_input_context(in_cntxt);

    t_Processing_Context proc_cntxt = setup_for_processing(in_cntxt);

    debug_print_processing_context(proc_cntxt);

    printf("%s\n", process_input(proc_cntxt));

    printf("[Info] Enigma: Completed...\n");
    return 0;
}
