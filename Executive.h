#ifndef Executive_h
#define Executive_h

#include <string>
#include <vector>

class Executive
{
	public:
		Executive(std::string Filename);
		~Executive();
		void Run();
		double deg2rad(double deg);
		double rad2deg(double rad);
		double Calc(double Lat, double Long);
	private:
		std::vector<std::string> m_Name;
		std::vector<std::string> m_Address;
		std::vector<double> m_Lat;
		std::vector<double> m_Long;
		std::vector<int> m_Order;
};
#endif
