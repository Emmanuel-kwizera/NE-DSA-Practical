#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

struct Location{
    int id;
    string name;
};

int next_id(){
    int id = 1;
    fstream file;

    file.open("./Files/locations.txt",ios::in);
    string line;

    while(getline(file,line)){
        stringstream ss(line);
        string id_as_string;
        getline(ss, id_as_string, ',');
        id = stoi(id_as_string) + 1;
        // id++;
    }

    file.close();

    return id;
}

bool insert_location(Location location){
    location.id = next_id();

    fstream file;

    file.open("./Files/locations.txt", ios::out | ios::app);

    if(file << location.id<< "|"<< location.name << endl){
        return true;
    }

    file.close();
    return false;

}

vector<Location> get_all_locations(){

    fstream file;
    file.open("./Files/locations.txt",ios::in);

    vector<Location> locations;

    string line;

    while(getline(file,line)){
        Location location; 
        stringstream ss(line);
        int k = 0;
        while(ss.good()) {
            string substr;

            getline(ss, substr, '|');
            if(k == 0){
                location.id = stoi(substr);
            } 
            else if(k==1) {
                location.name = substr;
            } 
            k++;
        }
        locations.push_back(location);
    }
    file.close();
    return locations;
}

vector<Location> get_location_by_name(string location_name){

    fstream file;
    file.open("./Files/locations.txt",ios::in);

    vector<Location> locations;

    string line;

    while(getline(file,line)){
        Location location; 
        stringstream ss(line);
        int k = 0;
        while(ss.good()) {
            string substr;

            getline(ss, substr, '|');
            if(k == 0){
                location.id = stoi(substr);
            } 
            else if(k==1) {
                location.name = substr;
            } 
            k++;
        }
        if(location.name == location_name){
            locations.push_back(location);
        }
    }
    file.close();
    return locations;
}


void delete_location(string location_to_remove) {
    vector<Location> locations = get_all_locations();

    fstream file;
    file.open("./Files/temp_locations.txt", ios::out | ios::app);

    for(Location location : locations){
        if (location.name != location_to_remove){
            file << location.id << "|" << location.name << std::endl;
        }
    }

    file.close();

    remove("./Files/locations.txt");
    rename("./Files/temp_locations.txt","./Files/locations.txt");
}
