#include <iostream>
#include <limits>
using namespace std;
int menu() {
    int choice = -1;
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1) ADD TWO NUMBERS" << endl;
        cout << "2) SUBSTRACT TWO NUMBERS" << endl;
        cout << "3) MULTIPLY TWO NUMBERS" << endl;
        cout << "4) DIVIDE TWO NUMBERS" << endl;
        cout << "5) EXIT PROGRAM" << endl; 
        cout << "Choose an option (1-5): ";

        if (!(cin >> choice)) {
            // handle non-integer input
            cout << "Invalid input (not a number). Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
            continue;
        }

        if (choice < 1 || choice > 5) {
            cout << "WRONG INPUT, TRY AGAIN!\n";
            choice = -1;
        }
    } while (choice == -1);

    return choice;
}
void add(double a, double b){
    cout << a + b << endl;    
}
void sub(double a, double b){
    cout << a - b << endl;
}
void divide(double a, double b){
    if(a == 0 || b == 0)
    {
        cout << "MATH ERROR" << endl;
    }
    else
    {
        cout << a/b << endl;
    }
}
void multi(double a, double b){
    cout << a * b << endl;
}

void sys(double &a, double &b){
    int tt=0;
    while (true) {
        tt++;
        int choice = menu();
        if (choice == 1) add(a, b);
        else if (choice == 2) sub(a, b);
        else if (choice == 3) multi(a, b);
        else if (choice == 4) divide(a, b);
        else if (choice == 5) {
            cout << "Exiting. Goodbye!\n";
            cout << "Number Of Opertations Have Done: " << tt-1 << endl;
            break;
        }
    }
}
int main()
{
    double a, b;
    cout << "Welcome!, Please Enter The Two numbers:" << endl;
    cin >> a >> b;
    sys(a, b);
}
