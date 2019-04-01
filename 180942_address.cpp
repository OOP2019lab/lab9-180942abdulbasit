#include "180942_Address.h"
#include "180942_Project.h"
#include "180942_Employee.h"
using namespace std;

Address::Address(char* house, char* street, char * City,char* Country)
{
	this->house_Number=new char[strlen(house)];
	strcpy(this->house_Number,house);
	this->street_Name=new char[strlen(street)];
	strcpy(this->street_Name,street);
	this->city=new char[strlen(City)];
	strcpy(this->city,City);
	this->county=new char[strlen(Country)];
	strcpy(this->county,Country);
}
ostream& operator<<(ostream& osObject, const Address& a)
{
	osObject<<a.house_Number<<" "<<a.street_Name<<" "<<a.city<<" "<<a.county<<endl;
	return osObject;

}
Address::Address(const Address &a)
{
	this->house_Number=new char[strlen(a.house_Number)];
	strcpy(this->house_Number,a.house_Number);
	this->street_Name=new char[strlen(a.street_Name)];
	strcpy(this->street_Name,a.street_Name);
	this->city=new char[strlen(a.city)];
	strcpy(this->city,a.city);
	this->county=new char[strlen(a.county)];
	strcpy(this->county,a.county);
}

Address::~Address()
{
	if(house_Number!=nullptr)
	{
		delete[] house_Number;
		delete[] street_Name;
		delete[] city;
		delete[] county;
	}
}
const Address & Address::operator=(const Address& other)
{
	if(house_Number!=nullptr)
		delete house_Number;
	if(street_Name!=nullptr)
		delete street_Name;
	if(city!=nullptr)
		delete city;
	if(county!=nullptr)
		delete county;
	house_Number = new char[strlen(other.house_Number)];
	strcpy(this->house_Number, other.house_Number);
    street_Name = new char[strlen(other.street_Name)];
	strcpy(this->street_Name, other.street_Name);
	city = new char[strlen(other.city)];
	strcpy(this->city, other.city);
	county = new char[strlen(other.county)];
	strcpy(this->county, other.county);
	return *this;
}
//Address::~Address()
//{
//	delete house_Number;
//	delete city;
//	delete county;
//	delete street_Name;
//}
