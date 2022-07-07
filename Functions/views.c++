#include <iostream>
#include <chrono>
#include <ctime> 
using namespace std;

void print_landing_display(){
    std::cout << "=========================================================="<<std::endl;
    std::cout << "\n*" << "\t Welcome to Disease Cases Reporting System!" << "\t\t *" << std::endl;
    std::cout << "\n*" << "\t ***************************************" << "\t *"<<std::endl;
    std::cout << "\n*" << "\t\t\t\t *"<<std::endl;
    std::cout << "\n*" << " It is developed by RCA Student Kwizera Emmanuel as practical"<<" *" <<std::endl;
    std::cout << "\n*" << " evaluation for the end of year 3." <<"\t\t\t\t\t *"<<std::endl;
    std::cout << "\n=========================================================="<<std::endl;

    auto start = std::chrono::system_clock::now(); 
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::cout << "\nStarting Time:  " << std::ctime(&start_time)<< std::endl;
    std::cout << "Need a help? Type 'help' then press Enter key.\n" << std::endl;
}

void print_help_menu(){
    std::cout << "\n======================================================================"<<std::endl;
    std::cout << "\n*" << "\t\t\t H E L P   M E N U "<<std::endl;
    std::cout << "\n======================================================================"<<std::endl;
    std::cout << "add <Location>" << "\t\t\t\t : Add a new location" << std::endl;
    std::cout << "delete <Location>" << "\t\t\t : Delete an existing location" << std::endl;
    std::cout << "record <Location> <disease> <cases>" << "\t : Record a disease and its cases" << std::endl;
    std::cout << "list locations" << "\t\t\t\t : List all exisiting locations" << std::endl;
    std::cout << "list diseases" << "\t\t\t\t : List all exisiting Diseases in locations" << std::endl;
    std::cout << "where <disease>" << "\t\t\t\t : Find where disease exisits" << std::endl;
    std::cout << "cases <location><disease>" << "\t\t : Find cases of a disease in location" << std::endl;
    std::cout << "cases <disease>" << "\t\t\t\t : Find total cases of a given disease" << std::endl;
    std::cout << "help" << "\t\t\t\t\t : Prints user manual" << std::endl;
    std::cout << "Exit" << "\t\t\t\t\t : Exit the program \n" << std::endl;
}