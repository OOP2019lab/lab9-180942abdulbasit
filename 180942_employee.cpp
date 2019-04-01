#include "180942_Address.h"
#include "180942_Project.h"
#include "180942_Employee.h"
using namespace std;

ostream& operator<<(ostream& osObject, const Employee& other)
{
	osObject<<"Name: "<<other.emp_name<<endl;
	osObject<<"Address: "<<other.emp_address<<endl;
	/*if(other.no_of_proj==0)
		osObject<<"No projects"<<endl;
	else*/
	osObject<<"Projects: "<<endl;
	for (int i=0; i<other.no_of_proj;i++)
		osObject<<other.emp_project[i]<<endl;
	return osObject;
}
Employee::Employee(const Employee &e):emp_address(e.emp_address)
{
	emp_name=new char(*e.emp_name);
	emp_project=e.emp_project;
	no_of_proj=e.no_of_proj;

}
Employee::Employee(char* name, const Address &a):emp_address(a)
{

	this->emp_name=new char(strlen(name));
	strcpy(emp_name,name);
	this->emp_project=nullptr;
	this->no_of_proj=0;
}
const Employee & Employee::operator=(const Employee& other)
{
	if(emp_name!=nullptr)
	delete emp_name;
	//delete emp_address;
	if(emp_project!=nullptr)
	delete emp_project;
	//emp_address=new Address(other.emp_address);
	emp_address=other.emp_address;
	emp_name = new char[strlen(other.emp_name)];
    strcpy(emp_name, other.emp_name);
	return *this;
}
void Employee::addProject(Project const *proj)
{
	bool check=false;
	if(emp_project==nullptr)
	{
		emp_project=new Project*[2];
		emp_project[0]=new Project(*proj);
		no_of_proj++;
	}

	else
	{
	for(int i=0;i<no_of_proj;i++)
	{
		check=true;
		if(emp_project[i]==proj){
			check=false;
			break;
		}
	}
	if(check)
	{
	if(no_of_proj<2)
	{
		emp_project[no_of_proj]=new Project(*proj);  
	}
	no_of_proj++;
	}
	}
}
void Employee::removeProject(Project const *proj)
{
	for(int  i=0;i<2;i++)
	if(emp_project[i]==proj)
	{
	emp_project[i]=nullptr;
	if(i==0)
	{
		emp_project[0]=emp_project[1];
		emp_project[1]=nullptr;
	}
	no_of_proj--;
	}
}