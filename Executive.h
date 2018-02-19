#ifndef Executive_h
#define Executive_h
#define _USE_MATH_DEFINES
#include <cmath>

#include <string>
#include <vector>


class Executive
{
	public:
		Executive();
		~Executive();
		double getRadians(double Deg);
		void Calc(double Lat, double Long);
		void setName(std::string Name);
		void setAddress(std::string Address);
		void setDistance(double Distance);
		std::string getName();
		std::string getAddress();
		double getDistance();
	private:
		std::vector<std::string> m_Name;
		std::vector<std::string> m_Address;
		std::vector<double> m_Lat;
		std::vector<double> m_Long;
		std::vector<double> m_Distance;
		std::string m_FinName;
		std::string m_FinAddress;
		double m_FinDistance;
};
#endif
