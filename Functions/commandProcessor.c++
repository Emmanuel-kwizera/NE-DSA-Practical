#include <iostream>  
#include <string>  
#define max 20 // define the max string  
using namespace std;  
  
string strings[max]; // define max string  

int len(string str)  
{  
    int length = 0;  
    for (int i = 0; str[i] != '\0'; i++)  
    {  
        length++;  
          
    }  
    return length;     
}  

void command_processor(string command, char separator){
    int currIndex = 0, i = 0;  
    int startIndex = 0, endIndex = 0;  
    while (i <= len(command))  
    {  
        if (command[i] == separator || i == len(command))  
        {  
            endIndex = i;  
            string subcommand = "";  
            subcommand.append(command, startIndex, endIndex - startIndex);  
            strings[currIndex] = subcommand;  
            currIndex += 1;  
            startIndex = endIndex + 1;  
        }  
        i++;  
    }     
}