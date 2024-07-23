# ONLINE JOB PORTAL SYSTEM

## Introduction
This code implements an Online Job Portal System where applicants can search for job vacancies, apply filters to find suitable jobs, view company information, update applicant profiles, and more. Similarly, companies can post job vacancies, view and update company information.

## Features
### Applicant Functions:
   - Login
   - Registration
   - Edit Profile
   - View Profile
   - Search for job vacancies
   - Apply filters for job searches

### Company Functions:
   - Login
   - Registration
   - Update Company Information
   - View Company Information
   - Post Job Vacancies

## Code Organization
The code is organized into classes for **Applicant**, **Company**, and **Vacancy**. Each class contains member functions for specific functionalities.

##### Applicant Class:
  - Contains functions for login, registration, editing, and viewing applicant profiles.

##### Company Class:
  - Contains functions for login, registration, updating, and viewing company information.

##### Vacancy Class:
  - Includes functions for managing job vacancies such as posting and viewing vacancies.


##### User-defined Functions:
continueA(): Function to manage the flow of actions for applicants after login.
continueC(): Function to manage the flow of actions for companies after login.

#### Main Function:
The main function presents a menu for users to choose between applicant or company actions like login, registration, or exiting the system. It calls appropriate functions based on user choices.

## Techniques to be used for the project implementation
> Object Oriented Programming
- Class
- Inheritance
  - Multiple inheritance
> File Handling

## Dependencies
The code uses various C++ libraries such as `iostream`, `fstream`, `string`, `Windows.h` for handling input/output operations, file operations, and Windows API for displaying pop-up windows.

## Instructions
To run the project:
1.Compile the source code files using a C++ compiler (e.g., g++, Visual Studio).
2.Execute the compiled binary file.
3.Follow the on-screen instructions to navigate through the system.
- Users can select their role as an applicant or company and perform actions accordingly.
- Applicants can search for job vacancies, edit their profiles, view job vacancies, etc.
- Companies can post job vacancies, update company information, view job applications, etc.

## Future Improvements
- Enhance the vacancy operations ,working on it.
- Enhance user interface with graphical elements.
- Implement email notifications for job applicants and companies.
- Add functionality for job application submissions and management.
