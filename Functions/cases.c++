#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

#include "./diseases.c++"
#include "./locations.c++"

using namespace std;

struct Cases{
    int id;
    string location_name;
    string disease_name;
    int cases_no;
};

int next_case(){
    int id = 1;
    fstream file;

    file.open("./Files/cases.txt",ios::in);
    string line;

    while(getline(file,line)){
        // stringstream ss(line);
        // string id_as_string;
        // getline(ss, id_as_string, ',');
        // id = stoi(id_as_string) + 1;
        id++;
    }

    file.close();

    return id;
}

void insert_case(Cases cases,string location,string disease){
    cases.id = next_case();
    fstream file;

    file.open("./Files/cases.txt", ios::out | ios::app);

    int x,y;
    vector<Location> locations = get_location_by_name(location);
    if(locations.size() > 0){
        for(Location loc : locations){
            cases.location_name = loc.name;
            x = 1;
        }
    }else{
        std::cout<< "No location found" << std::endl;
        x = 0;
    }
    vector<Disease> diseases = get_disease_by_name(disease);
    if (diseases.size() > 0){
        for (Disease d : diseases){
            cases.disease_name = d.name;
            y=1;
        }        
    }else{
        std::cout << "disease not recorded in the system" << std::endl;
        y = 0;
    }
    if(x == 1 and y == 1){
        file << cases.id << "|" << cases.location_name << "|" <<cases.disease_name << "|" << cases.cases_no << "\n";
    }else{
        std::cout << "The above error occured" << std::endl;
    }

    file.close();
}

vector<Cases> get_all_cases(){
    fstream file;
    file.open("./Files/cases.txt",ios::in);

    vector<Cases> cases;

    string line;

    while(getline(file,line)){
        Cases cs; 
        stringstream ss(line);
        int k = 0;
        while(ss.good()) {
            string substr;

            getline(ss, substr, '|');
            if(k == 0){
                cs.id = stoi(substr);
            } 
            else if(k==1) {
                cs.location_name = substr;
            } 
            else if(k==2) {
                cs.disease_name = substr;
            } 
            else if(k==3) {
                cs.cases_no = stoi(substr);
            } 
            k++;
        }
        cases.push_back(cs);
    }
    file.close();
    return cases;
}

void delete_cases_by_location(string location_to_remove) {
    vector<Cases> cases = get_all_cases();

    fstream file;
    file.open("./Files/temp_cases.txt", ios::out | ios::app);

    for(Cases cas : cases){
        if (cas.location_name != location_to_remove){
            file << cas.id << "|" << cas.location_name << "|" <<cas.disease_name << "|" << cas.cases_no << "\n";
        }
    }

    file.close();

    remove("./Files/cases.txt");
    rename("./Files/temp_cases.txt","./Files/cases.txt");
}

vector<Cases> get_cases_by_disease(string disease) {
    fstream file;
    file.open("./Files/cases.txt",ios::in);

    vector<Cases> cases;

    string line;

    while(getline(file,line)){
        Cases cs; 
        stringstream ss(line);
        int k = 0;
        while(ss.good()) {
            string substr;

            getline(ss, substr, '|');
            if(k == 0){
                cs.id = stoi(substr);
            } 
            else if(k==1) {
                cs.location_name = substr;
            } 
            else if(k==2) {
                cs.disease_name = substr;
            } 
            else if(k==3) {
                cs.cases_no = stoi(substr);
            } 
            k++;
        }
        if (cs.disease_name == disease){
            cases.push_back(cs);
        }
        
    }
    file.close();
    return cases;
}

vector<Cases> get_cases_by_disease_and_location(string location, string disease) {
    fstream file;
    file.open("./Files/cases.txt",ios::in);

    vector<Cases> cases;

    string line;

    while(getline(file,line)){
        Cases cs; 
        stringstream ss(line);
        int k = 0;
        while(ss.good()) {
            string substr;

            getline(ss, substr, '|');
            if(k == 0){
                cs.id = stoi(substr);
            } 
            else if(k==1) {
                cs.location_name = substr;
            } 
            else if(k==2) {
                cs.disease_name = substr;
            } 
            else if(k==3) {
                cs.cases_no = stoi(substr);
            } 
            k++;
        }
        if (cs.location_name == location && cs.disease_name == disease){
            cases.push_back(cs);
        }
        
    }
    file.close();
    return cases;
}

