#include "180942_Address.h"
#include "180942_Project.h"
#include "180942_Employee.h"
using namespace std;

Project::Project(char* n, int b, int d)
{
	name=new char (strlen(n));
	strcpy(name,n);
	budget=b;
	duration=d;


}
ostream& operator<<(ostream& osObject, const Project& p)
{
	osObject<<"Name: "<<p.name<<endl;
	osObject<<"Budget: "<<p.budget<<endl;
	osObject<<"Duration: "<<p.duration<<" weeks"<<endl;
	return osObject;

}
//void Employee::addProject(Project const *a )
//{
//	if(no_of_proj<=2)
//	{
//		emp_project[no_of_proj]=*a;
//		no_of_proj++;
//	}
//	else
//		cout<<"No more projects can be added"<<endl;
//}
//void Employee::removeProject(Project const *a )
//{
//	if(no_of_proj>0)
//	{
//		for(int i=0;i<no_of_proj;i++)
//			if(emp_project[i]==*a)
//			{
//				if(i==0)
//					emp_project[i]==emp_project[i+1];
//				Project *temp[no_of_proj-1]=new Project
//
//			
//			}
//	}
//}
//bool Project::operator==(const Project& other)
//{
//	if(name==other.name && budget==other.budget && duration==other.duration)
//		return true;
//	return false;
//}
const Project &  Project:: operator=(const Project& other)
{
	if(name!=nullptr)
		delete name;
	name=other.name;
	budget=other.budget;
	duration=other.duration;
	return *this;
}
void Project::setBudget(int a)
{
	budget=a;
}
Project::Project(const Project &other)
{
	/*if(name!=nullptr)
		delete name;
	name=new char(strlen(other.name));
	strcpy(name,other.name);
	budget=other.budget;
	duration=other.duration;*/
	int a=strlen(other.name);
	name=new char[strlen(other.name)+1];
	for(int i=0;i<strlen(other.name);i++)
	{
		name[i]=other.name[i];
	}
	name[a]='\0';
	budget=other.budget;
    duration=other.duration;
}
Project::~Project()
{
	if(name!=nullptr)
		delete name;
}
