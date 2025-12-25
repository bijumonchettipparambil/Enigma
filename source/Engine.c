#include <stdio.h>
#include <stdlib.h>

#include "Engine.h"
#include "Rotor.h"

t_Rotor initial_rotor_adjustment(const t_Rotor input_rotor, const int offset)
{
	// Ensure the offset is less than or equal to 25
	if (offset < min_value || offset > max_value)
	{
		fprintf(stderr, "[INFO] Engine.h: Offset must be in the range 0 to 25.\n");
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
		fprintf(stderr, "[INFO] Engine.h: Count must be in the range 0 to 25.\n");
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
