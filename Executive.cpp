#include "Executive.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Executive::Executive()
{
	ifstream InFile("pharmacies.csv");
	string Variable;
	string Temp;
	double DoubleConvert;
	getline(InFile,Temp);
	while(!InFile.eof())
	{
		Variable="";
		getline(InFile,Temp,',');
		if(Temp=="")
		{
			break;
		}
		m_Name.push_back(Temp.substr(1,Temp.length()-2));

		getline(InFile,Temp,',');
		Variable+=Temp.substr(1,Temp.length()-2)+" ";
		getline(InFile,Temp,',');
		Variable+=Temp.substr(1,Temp.length()-2)+" ";
		getline(InFile,Temp,',');
		Variable+=Temp.substr(1,Temp.length()-2)+" ";
		getline(InFile,Temp,',');
		Variable+=Temp.substr(1,Temp.length()-2);
		m_Address.push_back(Variable);

		getline(InFile,Temp,',');
		DoubleConvert = atof(Temp.c_str());
		m_Lat.push_back(DoubleConvert);

		getline(InFile,Temp);
		DoubleConvert = atof(Temp.c_str());
		m_Long.push_back(DoubleConvert);
	}
	for(int i = 0; i<m_Name.size(); i++)
	{
		cout<<"Name: "<<m_Name[i]<<endl;
		cout<<"Address: "<<m_Address[i]<<endl;
		cout<<"Latitude: "<<m_Lat[i]<<endl;
		cout<<"Longitude: "<<m_Long[i]<<endl;
	}
	cout<<"Size: "<<m_Name.size()<<endl;
}
Executive::~Executive()
{
}
double Executive::getRadians(double Deg)
{
	return(Deg*M_PI/180);
}
void Executive::Calc(double Lat, double Long)
{
	double Lat2Con,Long2Con,Comp1,Comp2,Temp,F;
	int index = 0;
	double Lat1Con = getRadians(Lat);
	double Long1Con = getRadians(Long);
	for(int i = 0; i<m_Name.size();i++)
	{
		Lat2Con = getRadians(m_Lat[i]);
		Long2Con = getRadians(m_Long[i]);
		Comp1 = sin((Lat2Con-Lat1Con)/2);
		Comp2 = sin((Long2Con-Long1Con)/2);
		Temp=2.0*6371.0*asin(sqrt(Comp1*Comp1+cos(Lat1Con)*cos(Lat2Con)*Comp2*Comp2));	
		m_Distance.push_back(Temp);
		cout<<"Temp: "<<Temp<<endl<<"Index: "<<i<<endl;
		if(i==0)
		{
			F=Temp;
		}
		else if(Temp<F)
		{
			F=Temp;
			index = i;
		}
	}
	setName(m_Name[index]);
	setAddress(m_Address[index]);
	setDistance(m_Distance[index]);
	cout<<"Name: "<<getName()<<endl<<"Address: "<<getAddress()<<endl<<"Distance: "<<getDistance()<<endl;
}
void Executive::setName(string Name)
{
	m_FinName=Name;
}
void Executive::setAddress(string Address)
{
	m_FinAddress=Address;
}
void Executive::setDistance(double Distance)
{
	m_FinDistance=Distance;
}
string Executive::getName()
{
	return(m_FinName);
}
string Executive::getAddress()
{
	return(m_FinAddress);
}
double Executive::getDistance()
{
	return(m_FinDistance);
}
