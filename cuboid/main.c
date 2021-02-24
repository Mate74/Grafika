#include "cuboid.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	Cuboid cuboid;
	double volume;
	double surface;
	
	set_size(&cuboid, 5, 10, 8);
	volume= calc_cuboid_volume(&cuboid);
	surface= calc_cuboid_surface(&cuboid);
	
	printf("Cuboid volume: %lf\n", volume);
	printf("Cuboid surface: %lf\n", surface);
	if(is_side_square(&cuboid)==1){
		printf("There is a square side.");
	}else{
	printf("There is no square side.");
	}
	
	return 0;
}