#ifndef Executive_h
#define Executive_h
#define _USE_MATH_DEFINES
#include <cmath>

#include <string>
#include <vector>


class Executive
{
	public:
		/**
		*Constructor, initializes data and stores values in "pharmacies.csv" in data structures
		*/
		Executive();
		/**
		*Destructor, no objects used on the heap, nothing to delete
		*/
		~Executive();
		/**
		*A simple convertion function that returns radians given degrees by multiplying a given value by PI/180
		*@param of type double, passed in to be converted from degrees to radians
		*@return Returns a double due to its 64 bit precision
		*/
		double getRadians(double Deg);
		/**
		*Acts as the main calculator that determines the distance from the given latitude and longitude and each latitude and longitude for each pharmacy and sets the lowest value to a private member variable of type double
		*@pre parameters must properly conert into doubles by passing the try catch block in the file MyForm.h
		*@post Size of the vector m_Distance equals the size of the m_Name vector and all values within the vector are initiated to distances
		*@param two parameters, both of type double, variables used to calculate distance to closest pharmacy
		*@return None
		*/
		void Calc(double Lat, double Long);
		/**
		*A setter function, used to store the name of the pharmacy that has the lowest distance to the users entered latitude and longitude
		*@pre Passed values must be taken from the first value in a line in a .csv format to to allow corresponding get function to return correct output
		*@post m_FinName is equal to passed value
		*@param of type string, passed in to be stored by a private member variable
		*@return None
		*/
		void setName(std::string Name);
		/**
		*A setter function, used to store the address of pharmacy that has the lowest distance to the users entered latitude and longitude
		*@pre Passed values must be taken from the second through the fifth value in a line in a .csv format to to allow corresponding get function to return correct output
		*@post m_FinAddress is equal to passed value
		*@param of type string, passed in to be stored by a private member variable
		*@return None
		*/
		void setAddress(std::string Address);
		/**
		*A setter function, used to store the lowest distance from the pharmacies latitude and longitue to the users entered latitude and longitude
		*@pre Because of how the function is used, passed value must be from the distance vector
		*@post m_FinDistances is equal to passed value
		*@param of type double, passed in to be stored by a private member variable
		*@return None
		*/
		void setDistance(double Distance);
		/**
		*A getter function, used so the user interface can easily access the name of the closest pharmacy to the user
		*@pre Passed values must be taken from the first value in a line in a .csv format to allow corresponding get function to return correct output
		*@return Returns a private member variable of type string that stored the name of the closest pharmacy to the user
		*/
		std::string getName();
		/**
		*A getter function, used so the user interface can easily access the address of the closest pharmacy to the user
		*@return Returns a private member variable of type string that stored the address of the closest pharmacy to the user
		*/
		std::string getAddress();
		/**
		*A getter function, used so the user interface can easily access the distance of the closest pharmacy to the user
		*@return Returns a private member variable of type double that stored the distance of the closest pharmacy to the user
		*/
		double getDistance();
	private:
		/**
		*A vector of strings that stores all the names of the pharmacies given
		*@pre Indexed values must be taken from the first value in a line in a .csv format to give correct output
		*@return Indexing returns type string to be tested or used as the name of the closest pharmacy to the user
		*/
		std::vector<std::string> m_Name;
		/**
		*A vector of strings that stores all the addresses of the pharmacies given
		*@pre Indexed values must be taken from the second through the fifth value in a line in a .csv format to give correct output
		*@return Indexing returns type string to be tested or used as the address of the closest pharmacy to the user
		*/
		std::vector<std::string> m_Address;
		/**
		*A vector of strings that stores all the latitudes of the pharmacies given
		*@pre Indexed values must be taken from the sixth value in a line in a .csv format to give correct output
		*@return Indexing returns type double to be tested or used as the latitude of the closest pharmacy to the user
		*/
		std::vector<double> m_Lat;
		/**
		*A vector of strings that stores all the longitudes of the pharmacies given
		*@pre Indexed values must be the seventh value in a line in a .csv format
		*@return Indexing returns a private member variable of type double that stored the longitude of all pharmacies given
		*/
		std::vector<double> m_Long;
		/**
		*A vector of doubles that stores all the distances of the users location to the location of the pharmacies given
		*@return Indexing returns a private member variable of type double that stored the longitude of all pharmacies given
		*/
		std::vector<double> m_Distance;
		/**
		*A string used to store the name of the closest pharmacy to the user
		*/
		std::string m_FinName;
		/**
		*A string used to store the address of the closest pharmacy to the user
		*/
		std::string m_FinAddress;
		/**
		*A double used to store the distance of the closest pharmacy to the user
		*/
		double m_FinDistance;
};
#endif
 
