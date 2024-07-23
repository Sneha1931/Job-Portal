//JOB PORTAL

#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<string>
#include<Windows.h>
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
    // Get the user input from lpCmdLine
    std::string userInput = lpCmdLine;
    
    // Display the user input in a pop-up window
    MessageBox(NULL, userInput.c_str(), "JOB VACANCIES", MB_OK | MB_ICONINFORMATION);
    
    return 0;
}

//GLOBAL VARIABLRES
int x=1;  //for terminating title repetition

string applicant_path="D:\\JOB_PORTAL\\Applicant\\";
string company_path="D:\\JOB_PORTAL\\Company\\";
string filter_path="D:\\JOB_PORTAL\\Filters\\";

string current_aun="",current_cun="";
 
string getPassword() 
{
    string password = "";
    char ch;
    while((ch = _getch()) != 13)                                   // 13 is the ASCII value for Enter key
	{ 
       if(ch == '\b') 
		{                                                          // Check if Backspace key is pressed
            if(password.length() > 0)
			{
                cout << "\b \b";                                   // Move cursor back, erase character, move cursor back again
                password.erase(password.length() - 1);             // Remove last character from password string
            }
        } else 
		{
            password.push_back(ch);
            cout <<"*";                                          
        }
    }
    cout << endl;                                                  
    return password;
}
  
//*****************APPLICANT_CLASS**************


class Applicant
{
	string name;
	string phoneNum;
	string resume;
	string Aun,Apw;
	public:
		bool login();
		void registration();
		void editprofile();
		void viewprofile();
};

//****************COMPANY_CLASS****************
class Company
{
	string name;
	string about,email;
	string Cun,Cpw;
	public:
		bool login();
		void reg();
		void updateinfo();
		void viewinfo();
};

//***************VACANCY_CLASS********************

//Multiple_Inheritance
class Vacancy: public Company, public Applicant   
{
	string vacancyDetails;
	int vacancyCount=0;
	public:
		void Vacancy_Count();
		void postVacancy();
		void viewVacancy();
};


//**************APPLICANT_CLASS_FUNCTIONS**********

//function_for_login
bool Applicant::login() 
{
    string username, password;
    cout << "Enter Username: ";
    cin >> Aun;
    cout << "Enter Password: ";
    Apw = getPassword();                                                     // Call getPassword() function to mask password input
	current_aun = Aun;
    ifstream read(applicant_path + "Registration_Login\\" + Aun + ".txt");
    getline(read, username);
    getline(read, password);                                                  // Read password from file
    if (username == "Username:" + Aun && password == "Password:" + Apw) 
	{
        cout << "\nApplicant Login Successful:)";
        return true;
    } else 
	{
        cout << "\nApplicant Login Failed:(";
        return false;
    }
}

//function_for_register
void Applicant::registration()
{
	cout<<"Enter Full Name: ";	
	getline(cin>>ws,name);
	cout<<"Enter Phone Number: ";  
	cin>>phoneNum;
	cout<<"Enter Resume Link: ";
	cin>>resume;
	cout<<"Create Username: "; 
	cin>>Aun;
	cout<<"Create Password: "; 
	cin>>Apw;
	
	ofstream file;
	file.open(applicant_path+"Registration_Login\\"+Aun+".txt");
	file<<"Username:"<<Aun<<"\nPassword:"<<Apw<<"\nName:"<<name<<"\nPhone Number:"<<phoneNum<<"\nResume Link:"<<resume;
	file.close();
	cout<<"\nApplicant Registration successful:)"<<endl;
}

//function_for_editprofile
void Applicant::editprofile()
{
	cout<<"\nwhat do you want to edit?\n1.Phone Number\n2.Resume Link\n3.Password\n4.exit\n";
	int ch,m=1;
	//string Aun1,Apw1,name1,resume1 ,phoneNum1;
	ifstream file(applicant_path+"Registration_Login\\"+current_aun+".txt");
	getline(file,Aun);
	getline(file,Apw);
	getline(file,name);
	getline(file,phoneNum);
	getline(file,resume);
	do
	{
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
		   	case 1:
				cin.ignore();                 //for clearing buffer
	   			cin>>phoneNum;
				phoneNum="Phone Number:"+phoneNum;
	   			break;
		   	case 2:
	   			cin.ignore();
	   			getline(cin,resume);
				resume="Resume Link:"+resume;
	   			break;
		   	case 3:
		   		cin.ignore();
	   			getline(cin,Apw);
				Apw="Password:"+Apw;
	   			break;
		   	case 4:	
				m=0;
				break;
		   	default:
				cout<<"wrong choice.";	
		}
	}while(m==1); 
	
	
	
	file.close();
	ofstream file1;
	file1.open(applicant_path+"Registration_Login\\"+current_aun+".txt");
	
	file1<<Aun<<"\n"<<Apw<<"\n"<<name<<"\n"<<phoneNum<<"\n"<<resume;
	file1.close();
}

//function_for_viewprofile
void Applicant::viewprofile()
{
	string temp;
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	ifstream file(applicant_path+"Registration_Login\\"+current_aun+".txt");
	while(getline(file,temp))
	{
		cout<<temp<<"\n";
	}
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	file.close();
}



//**************COMPANY_CLASS_FUNCTIONS**********

//function_for_login
bool Company::login()
{
	string username,password;
	cout<<"\nEnter Username: "; 
	cin>>Cun;
	cout<<"Enter Password: "; 
	Cpw=getPassword();
	current_cun = Cun;
	ifstream read(company_path + "Registration_Login\\" + Cun + ".txt");
	getline(read,username);
	getline(read,password);
	if (username == "Username:" + Cun && password == "Password:" + Cpw) {
        cout << "\nCompany Login Successful:)";
        return true;
    } else {
        cout << "\nCompany Login Failed:(";
        return false;
    }
}

//function_for_register
void Company::reg()
{
	cout<<"Enter Company Name: "; 
	getline(cin>>ws,name);
	cout<<"Enter About Company: ";
	getline(cin>>ws,about);
	cout<<"Enter Company Email: ";  
	getline(cin,email);
	cout<<"Create Username: "; 
	getline(cin,Cun);
	cout<<"Create Password: "; 
	getline(cin,Cpw);
	
	ofstream file ;
	file.open(company_path+"Registration_Login\\"+Cun+".txt");
	file<<Cun<<"\n"<<Cpw<<"\n"<<name<<"\n"<<about<<"\n"<<email;
	file.close();
	
	cout<<"\nCompany Registration successful:)"<<endl;
}

//function_for_editprofile
void Company::updateinfo()
{
	ifstream file(company_path+"Registration_Login\\"+Cun+".txt");
	getline(file,Cun); 
	getline(file,Cpw);
	getline(file,name);
	getline(file,about);  
	getline(file,email); 
	cout<<"what do you want to update?\n1.Email\n2.Password\n3.exit\n";
	int ch,m=1;
	do
	{
		cin>>ch;
		switch(ch)
		{
		   	case 1:
				cin.ignore();//for clearing buffer
	   			cin>>email;
	   			break;
		   	case 2:
	   			cin.ignore();
	   			getline(cin,Cpw);
	   			break;
		   	case 3:
				m=0;
				break;
		   	default:
				cout<<"wrong choice.";	
		}
	}while(m==1); 
	
	file.close();
	ofstream file1;
	file1.open(company_path+"Registration_login\\"+current_cun+".txt");
	file1<<"Username:"<<Cun<<"\nPassword:"<<Cpw<<"\nName:"<<name<<"\nAbout Company:"<<about<<"\nEmail:"<<email;
	file1.close();
}

//function_for_viewinfo
void Company::viewinfo()
{
	string temp;
	ifstream file(company_path+"Registration_login\\"+current_cun+".txt");
	while(getline(file,temp))
	{
		cout<<temp<<"\n";
	}
	file.close();
}
//**************VACANCY_CLASS_FUNCTIONS**********

//function_for_vacancy_count
void Vacancy::Vacancy_Count()
{
	vacancyCount++;
}

//function_for_post_vacancy
void Vacancy::postVacancy()
{
//	cout<<"Enter job vacancy details:\n\t";
//	getline(cin>>ws,vacancyDetails);
//	vacancyDetails+="\n";
//	
//	ifstream File("Cname\\"+Cun+".txt");
//		string Cname;
//		getline(File,Cname);
//		File.close();
//		
//		ofstream file; //stream object
//		file.open("Vacancy.txt",ios::app);
//		file<<vacancyCount<<"."<<Cname<<" >> "<<vacancyDetails;
//		file.close();
//	
}

//function_for_view_vacancy
void Vacancy::viewVacancy()
{
	char temp;
	cout<<"\n";
}

//****************USER_DEFINED_FUNCTIONS*************

//function_for_continueA
bool continueA()
{
	Vacancy V;
	Applicant A;
	do
	{
		cout<<"\n\nJOB SEEKER MENU\n================\n1.Search for your dream job\n2.View Job Vacancies\n3.View Applicant Info\n4.Update Applicant Info\n5.Logout\n";
		int c2;
		cout<<"\nEnter your choice:";
		cin>>c2;
		switch(c2)
		{
			case 1:
				int c5;
				cout<<"\nWhich Filter you want to apply?";
				cout<<"\n1.Apply filters for Jobs\n2.Apply filters for Companies";
				cout<<"\nEnter your choice:";
				cin>>c5;
				if(c5==1)
				{
					cout<<"\n1.Popular categories\n2.Jobs in demand\n3.Jobs by location\n";
					int ch;
					cout<<"\nEnter your choice:";
					cin>>ch;
					if(ch==1)
					{
						cout<<"\n1.IT Jobs\n2.Sales Job\n3.Marketing Job\n4.Data Science Job\n5.HR Jobs\n6.Engineering Jobs\n";
						cout<<"\nEnter your choice:";
						int c1;
						cin>>c1;
						string temp,temp1;
						
						if (c1==1)
						{
							ifstream read(filter_path+"IT Jobs.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(read,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c1==2)
						{
							ifstream r2(filter_path+"Sales Job.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r2,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
							
						}
						else if(c1==3)
						{
							ifstream r3(filter_path+"Marketing Job.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r3,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
							
						else if(c1==4)
						{
								ifstream r4(filter_path+"Data Science Job.txt");
								cout<<endl;
								for(int i=0;i<5;i++)
								{	
									
									getline(r4,temp);
									temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c1==5)
						{
							ifstream r5(filter_path+"HR Jobs.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r5,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
								
							
						}
						else if(c1==6)
						{
							ifstream r6(filter_path+"Engineering Jobs.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r6,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
							break;		
						}
						else
							cout<<"\ninvalid choice";
					}
					else if(ch==2)
					{
						cout<<"\n\n1.Fresher Jobs\n2.MNC Jobs\n3.Work from home Jobs\n4.Part-time Jobs\n5.Remote Jobs\n6.Walk-in Jobs\n";
						int c3;
						cout<<"\nEnter your choice:";
						cin>>c3;
						string temp,temp1;
						
						if (c3==1)
						{
							ifstream read(filter_path+"Fresher Jobs.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(read,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c3==2)
						{
							ifstream r2(filter_path+"MNC Jobs.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r2,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
								
							
						}
						else if(c3==3)
						{
							ifstream r3(filter_path+"Work from home Jobs.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r3,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
							
						else if(c3==4)
						{
								ifstream r4(filter_path+"Part-time Jobs.txt");
								cout<<endl;
								for(int i=0;i<5;i++)
								{	
									
									getline(r4,temp);
									temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c3==5)
						{
							ifstream r5(filter_path+"Remote Jobs.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r5,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c3==6)
						{
							ifstream r6(filter_path+"Walk-in Jobs.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r6,temp);
							temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
							break;		
						}
						else
							cout<<"\ninvalid choice";
					}
					else if(ch==3)
					{
						cout<<"\n\n1.Jobs in Delhi\n2.Jobs in Mumbai\n3.Jobs in Bangalore\n4.Jobs in Hyderabad\n5.Jobs in Chennai\n6.Jobs in Pune\n";
						int c4;
						cout<<"\nEnter your choice:";
						cin>>c4;
						string temp,temp1;
						
						if (c4==1)
						{
							ifstream read(filter_path+"Jobs in Delhi.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(read,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c4==2)
						{
							ifstream r2(filter_path+"Jobs in Mumbai.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r2,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
								
						}
						else if(c4==3)
						{
							ifstream r3(filter_path+"Jobs in Bangalore.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r3,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
							
						else if(c4==4)
						{
								ifstream r4(filter_path+"Jobs in Hyderabad.txt");
								cout<<endl;
								for(int i=0;i<5;i++)
								{	
									
									getline(r4,temp);
									temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c4==5)
						{
							ifstream r5(filter_path+"Jobs in Chennai.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r5,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c4==6)
						{
							ifstream r6(filter_path+"Jobs in Pune.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r6,temp);
							temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
							break;
								
						}
					}
					else
						cout<<endl<<"\ninvalid choice:(";
			    }
			    else if(c5==2)
			    {
			    	int c6;
			    	cout<<"\n\n1.Explore Categories\n2.Explore Collections\n";
			    	cout<<"\nEnter your choice:";
					cin>>c6;
			    	if(c6==1)
			    	{
			    		int c7;
			    		cout<<"\n1.Unicorn\n2.MNC\n3.Startup\n4.Product based\n5.Internet\n";
			    		cout<<"\nEnter your choice:";
						cin>>c7;
						string temp,temp1;
						
						if (c7==1)
						{
							ifstream read(filter_path+"Unicorn.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(read,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c7==2)
						{
							ifstream r2(filter_path+"MNC.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r2,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
							
						}
						else if(c7==3)
						{
							ifstream r3(filter_path+"Startup.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r3,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						
						else if(c7==4)
						{
								ifstream r4(filter_path+"Product based.txt");
								cout<<endl;
								for(int i=0;i<5;i++)
								{	
									
									getline(r4,temp);
									temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c7==5)
						{
							ifstream r5(filter_path+"Internet.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r5,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else
							cout<<"\ninvalid choice";	
					}
					else if(c6==2)
					{
						int c8;
						cout<<"\n\n1.Top companies\n2.IT companies\n3.Fintech companies\n4.Sponsored companies\n5.Featured companies\n";
						cout<<"\nEnter your choice:";
						cin>>c8;
						string temp,temp1;
						
						if (c8==1)
						{
							ifstream read(filter_path+"Top companies.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(read,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c8==2)
						{
							ifstream r2(filter_path+"IT companies.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r2,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
							
						}
						else if(c8==3)
						{
							ifstream r3(filter_path+"Fintech companies.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r3,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
							
						else if(c8==4)
						{
								ifstream r4(filter_path+"Sponsored companies.txt");
								cout<<endl;
								for(int i=0;i<5;i++)
								{	
									
									getline(r4,temp);
									temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else if(c8==5)
						{
							ifstream r5(filter_path+"Featured companies.txt");
							cout<<endl;
							for(int i=0;i<5;i++)
							{	
								
								getline(r5,temp);
								temp1+=to_string(i+1)+". "+temp+"\n\n";
							}
							
							LPSTR lpCmdLine = const_cast<LPSTR>(temp1.c_str());
   								WinMain(GetModuleHandle(NULL), NULL, lpCmdLine, SW_SHOWNORMAL);
						}
						else
							cout<<"\ninvalid choice";
					}
					else
						cout<<endl<<"\ninvalid choice:(";
				}
				else
					cout<<"\ninvalid choice";
				break;
			case 2:
				V.viewVacancy();
				break;
			case 3:
				A.viewprofile();
				break;
			case 4:
				A.editprofile();
				break;
			case 5:
	        	return true;
	        	break;
			default:
			    cout<<"wrong choice:(\n";
		}
    }while(1);
    return false;
}

//function_for_continueC
int continueC()
{
	Vacancy V;
	Company C;
	do
	{
		cout<<"\n\nRECRUITER MENU\n==============\n1.Post Job Vacancies\n2.View Company Info\n3.Update Company Info\n4.Logout\n";
		int c3; 
		cout<<"\nEnter your choice:";
		cin>>c3;
		switch(c3)
		{
			case 1:
				V.Vacancy_Count();
				V.postVacancy();
				break;
			case 2:
				C.viewinfo();
				break;
				
			case 3:
				C.updateinfo();
				break;
			case 4:
				return 1;
				break;
			default:
				cout<<"wrong choice:(\n";
		}
	}while(1);
	return 0;
}

//****************MAIN_FUNCTION****************
int test=0;
int main()
{
	Applicant A;
	Company C;
	Vacancy V;
	
	bool tmp1,tmp2;
	if(x==1)
	{
		cout<<setw(90)<<"------------------------\n";
		cout<<setw(90)<<" ONLINE JOB PORTAL SYSTEM\n";
		cout<<setw(90)<<"------------------------\n";
	}
	x=0; 
	
	cout<<"\nMAIN MENU\n==========\n\n1.Applicant Login\n2.Applicant Register\n3.Company Login\n4.Company Register\n5.Exit\n";
	int c1;
	cout<<"\nEnter your choice:"; 
	cin>>c1;
	cout<<endl;
	switch(c1)
	{
		case 1:
			tmp1=A.login();
			if(tmp1==false)
			{
				cout<<"\n";
				main();
			}
			else if(tmp1==true)
			{
				while(true)
				{
					if(continueA()==true)
					{
						main();
					}
				}
			}
			break;
		case 2:
			A.registration();
			cout<<"\n";
			main();
			break;
		case 3:
			tmp2=C.login();
			if(tmp2==false)
			{
				cout<<"\n";
				main();
			}
			else if(tmp2==true)
			{
				while(true)
				{
					if(continueC()==1)
					{
						main();
					}
				}
			}
			break;
		case 4:
			C.reg();
			cout<<"\n";
			main();
			break;
		case 5:
			cout<<endl<<setw(90)<<"Thank You!!!"<<endl;
			exit(0);
			break;
		default:
			cout<<"\nInvalid Choice:(\n";
			main();
			break;
	}
	return 0;
}
	
     
                            

                            
     
	
	


	



