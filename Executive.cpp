#include "Executive.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

Executive::Executive(string Filename)
{
	ifstream InFile(Filename);
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
double Executive::deg2rad(double deg)
{
	return(deg*M_PI / 180);
}
double Executive::rad2deg(double rad)
{
	return(rad*180/M_PI);
}
double Executive::Calc(double Lat, double Long)
{
	double lat1r, lon1r,lat2r,lon2r,u,v;
	lat1r = deg2rad(Lat);
	lon1r = deg2rad(Long);
	lat2r = deg2rad(m_Lat[0]);
	lon2r = deg2rad(m_Long[0]);
	u = sin((lat2r-lat1r)/2);
	v = sin((lon2r-lon1r)/2);
	return(2.0*6371.0*asin(sqrt(u*u+cos(lat1r)*cos(lat2r)*v*v)));	
}
