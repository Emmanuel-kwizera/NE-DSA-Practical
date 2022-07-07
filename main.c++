#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include "./Functions/views.c++"
#include "./Functions/commandProcessor.c++"
#include "./Functions/cases.c++"
using namespace std;

int main(int argc, char const *argv[]){
    print_landing_display();
    string input;

    Disease disease {0,"covid"};
    insert_disease(disease);

    do{
        std::cout << "Console > ";
	int num = len(input);
        int sum = 0;

        getline(std::cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        char seperator = ' '; 
        command_processor(input,seperator);
        string first,second,third,fourth;
        for (int i = 0; i <=max ; i++) { 
            first = strings[0];
            transform(first.begin(), first.end(), first.begin(), ::tolower);
            second = strings[1];
            transform(second.begin(), second.end(), second.begin(), ::tolower);
            third = strings[2];
            transform(third.begin(), third.end(), third.begin(), ::tolower);
            fourth = strings[3];
            transform(fourth.begin(), fourth.end(), fourth.begin(), ::tolower);
        } 

        if(first == "add"){
            Location location;
            location.id = 0;
            location.name = second;
            if(insert_location(location)){
                std::cout << "Location " << location.name << " is successfully added" << std::endl;
            }else{
                std::cout << "An Error occurred " << std::endl;
            }
        }
        
        else if(input == "list locations"){
            cout<<"hello"<<std::endl;
            vector<Location> locations = get_all_locations();
            for(Location location : locations){
                std::cout <<"\t\t" << location.name <<std::endl;
            }
        }

        else if(input == "list diseases"){
            vector<Cases> cases = get_all_cases();
            for(Cases cas : cases){
                std::cout <<"\t\t" << cas.disease_name <<"\t\t" << cas.location_name << std::endl;
            }
        }

        else if(first == "record"){
            Cases cases;
            cases.id = 0;
            int cases_number = stoi(fourth);
            cases.location_name = second;
            cases.disease_name = third;
            cases.cases_no = cases_number;

            insert_case(cases,second,third);
        }
        
        else if(first == "delete"){
            delete_cases_by_location(second);
            delete_location(second);
        }

        else if(first == "where"){
            vector<Cases> cases = get_cases_by_disease(second);
            if(cases.size() > 0){
                for(Cases cas : cases){
                    std::cout << "\t\t" << cas.location_name << std::endl;
                }
            }else{
                std::cout << "\t\t No location with this disease." << std::endl;
            }
        }

        else if(first == "cases"){
            vector<Cases> cases = get_cases_by_disease(second);
            if(cases.size() > 0){
                for(Cases cas : cases){
                    sum += cas.cases_no;                    
                }
                std::cout << "\t\t Total cases of ' " << second <<" ' = " << sum << std::endl;
            }else{
                std::cout << "\t\t No known cases for this disease." << std::endl;
            }
        }
        else if(num > 13 && first == "cases"){
            vector<Cases> cases = get_cases_by_disease_and_location(second,third);
            if(cases.size() > 0){
                for(Cases cas : cases){
                    sum += cas.cases_no;
                }
                std::cout << "\t\t Cases of ' " << third << " at " << second<< " are :" << sum << std::endl;
            }else{
                std::cout << "\t\t No known cases for this disease in given location" << std::endl;
            }
        }
        
        else if(input == "help"){
            print_help_menu();
        }
        
        else if(input == "exit"){
            std::cout << "\t* +-----------------------------------------------------+ *" << std::endl;
            std::cout << "\t*  Thank you for using Disease Cases Reporting System!\t*" << std::endl;
            std::cout << "\t* +-----------------------------------------------------+ *" << std::endl;
            return 0;
            break;
        }else{
            std::cout << "Invalid command. Type 'help' to see the list of commands." << std::endl;
        }
    }while (input != "exit");

    return EXIT_SUCCESS;
}
