#include "Executive.h"
#include <iostream>
int main(int argc, char * argv[])
{
	double Lat; 
	double Long;
	std::cout<<"Current latitude?"<<std::endl;
	std::cin>>Lat;
	std::cout<<"Current longitude?"<<std::endl;
	std::cin>>Long;
	Executive E("pharmacies.csv");
	std::cout<<E.Calc(Lat,Long)<<std::endl;
	return 0;
}
