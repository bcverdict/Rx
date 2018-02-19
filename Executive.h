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
		double deg2rad(double deg);
		double rad2deg(double rad);
		double Calc(double Lat, double Long);
		void setName(std::string Name);
		void setAddress(std::string Address);
		std::string getName();
		std::string getAddress();
	private:
		std::vector<std::string> m_Name;
		std::vector<std::string> m_Address;
		std::vector<double> m_Lat;
		std::vector<double> m_Long;
		std::vector<int> m_Order;
		std::string m_FinName;
		std::string m_FinAddress;
};
#endif
