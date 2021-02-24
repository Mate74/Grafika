#include "cuboid.h"

#include <math.h>
double set_size(Cuboid* cuboid, double x, double y, double z){
	if (x> 0.0) {
		cuboid->x = x;
	} else {
		cuboid->x = NAN;
	}
		if (y> 0.0) {
		cuboid->y = y;
	} else {
		cuboid->y = NAN;
	}
		if (z> 0.0) {
		cuboid->z = z;
	} else {
		cuboid->z = NAN;
	}
}
double calc_cuboid_volume(const Cuboid* cuboid){

double volume=cuboid->x*cuboid->y*cuboid->z;
return volume;
}
double calc_cuboid_surface(const Cuboid* cuboid){

double surface=2*((cuboid->x*cuboid->y)+(cuboid->z*cuboid->y)+(cuboid->x*cuboid->z));
return surface;
}
int is_side_square(const Cuboid* cuboid){
	if(cuboid->x==cuboid->y){
		return 1;
	}
	else if(cuboid->x==cuboid->z){
		return 1;
	}
	else if(cuboid->y==cuboid->z){
		return 1;
	}
	else{
		return 0;
	}
}