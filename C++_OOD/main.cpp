#include <bits/stdc++.h>

using namespace std;


// read, add, update, delete, exit.
// our basic local database haha <:
const int MAX = 1000;

string names[MAX];
int ages[MAX];
int salaries[MAX];
int added_emp = 0;

int menu(){

    int choice = -1;
    while(choice = -1)
    {
        cout << "1) ADD NEW EMPLOYEE:" << endl;
        cout << "2) SEE ALL EMPLOYEES:" << endl;
        cout << "3) REMOVE EMPLOYEE BY AGE:" << endl;
        cout << "4) UPDATE SALARY BY NAME:" << endl;
        cin >> choice;
        if(choice >= 5 || choice < 1)
        {
            cout << "WRONG INPUT, TRY AGAIN!" << endl;
            choice = -1;
        } 
    }
    return choice;
}

void read_employee() // add
{
    cout << "ENTER HIS NAME:" << endl;
    cin >> names[added_emp];
    cout << "ENTER HIS AGE:" << endl;
    cin >> ages[added_emp];
    cout << "ENTER HIS SALARY:" << endl;
    cin >> salaries[added_emp];
}


void show_data() // show employees and thier data
{

    for(int i = 0; i < added_emp; i++)
    {
        while (ages[i] != -1)
        {
            cout << names[i] << "" << salaries[i] << "" << ages[i] << endl;
        }
        
    }
}

int deletion_array(int arr[], int &size, int index) {
    
    for (int j = index; j < size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    size--; 
    return 1;
}

int deletion_array(string arr[], int &size, int index) {
    
    for (int j = index; j < size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    size--; 
    return 1;
}

void delete_data() // by age idk why Xd
{
    int start, end;
    cout << "ENTER START AND END:" << endl;
    cin >> start >> end;
    for (int i = 0; i < added_emp; i++)
    {
        if(start <= ages[i] && end >= ages[i])
        {
            deletion_array(names, added_emp, i);
            deletion_array(ages, added_emp, i);
            deletion_array(salaries, added_emp, i);
        }
    }
    
}


void Update(){

    string name;
    int new_Salary;
    cout << "ENTER EMPLOYEE NAME:" << endl;
    cin >> name;
    cout << "ENTER THE NEW SALARY" << endl;
    cin >> new_Salary;
    
    for(int i = 0; i < added_emp; i++)
    {
        if(name == names[i]){
            salaries[i] = new_Salary;
        }
    }
}

void employee_sys()
{
    while(true){
        int choice = menu();
        if(choice == 1){
            read_employee();
        }
        else if(choice == 2){
            show_data();
        }
        else if(choice == 3)
        {
            delete_data();
        }
        else if(choice == 4){
            Update();
        }
    }
}



int main(){

    cout << "HELLO, MY NAME IS OMAR AND I'M 16 YEARS OLD AND THIS IS MY FIRST C++ PROJECT (: " << endl;
    employee_sys();

}