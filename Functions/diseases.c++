#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include<string.h>
using namespace std;

struct Disease{
    int id;
    string name;
};

int next_disease(){
    int id = 1;
    fstream file;

    file.open("./Files/diseases.txt",ios::in);
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

bool insert_disease(Disease disease){
    disease.id = next_disease();

    fstream file;

    file.open("./Files/diseases.txt", ios::out | ios::app);

    if(file << disease.id<< "|"<< disease.name << endl){
        return true;
    }

    file.close();
    return false;
}

vector<Disease> get_disease_by_name(string disease_name){

    fstream file;
    file.open("./Files/diseases.txt",ios::in);

    vector<Disease> diseases;

    string line;

    while(getline(file,line)){
        Disease disease; 
        stringstream ss(line);
        int k = 0;
        while(ss.good()) {
            string substr;

            getline(ss, substr, '|');
            if(k == 0){
                disease.id = stoi(substr);
            } 
            else if(k==1) {
                disease.name = substr;
            } 
            k++;
        }
        if(disease.name == disease_name){
            diseases.push_back(disease);
        }
    }
    file.close();
    return diseases;
}
