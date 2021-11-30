/*
    Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 to use a
    vector<Name_value> instead of two vectors.

    Chapter 4, exercise 19: Write a program where you first enter a set of name-and-value pairs, 
    such as Joe 17 and Barbara 22. For each pair, add the name to a vector called names and the 
    number to a vector called scores (in corresponding positions, so that if names[7]=="Joe" then 
    scores[7]==17). Terminate input with NoName 0. Check that each name is unique and terminate with 
    an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.
*/

#include "std_lib_facilities.h"

class Name_value{   
    public:
	    Name_value(string name, int value): name(name), value(value) { }
	    string name;
	    int value;
};

int main(){
    vector<Name_value> data;

    String name;
    int value;
    int flag = 0;

    cout << "Enter a name and value. Continue entering until you want to quit. Enter 'NoName' and '0' to quit.\n";

    while (cin >> name >> value && name != "NoName" && value != 0){
		for (int i = 0; i < data.size(); i++){
            if(name == data[i].name){
                cout << "Error: The name entered is a duplicate.\n";
                flag = 1;
            }
        }

        if(flag == 1){
            flag = 0;
            break;
        }

        data.push_back(Name_value(name, value));
	}

    cout << "\nThe list is:\n";
    for(int i = 0; i < data.size(); ++i){
        cout << "(" << data[i].name << ", " << data[i].value << ")\n";
    }

    return 0;
}