#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX = 1000;

string names[MAX];
int ages[MAX];
int salaries[MAX];
int added_emp = 0;

int menu() {
    int choice = -1;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1) ADD NEW EMPLOYEE\n";
        cout << "2) SEE ALL EMPLOYEES\n";
        cout << "3) REMOVE EMPLOYEES BY AGE RANGE\n";
        cout << "4) UPDATE SALARY BY NAME\n";
        cout << "5) EXIT\n";
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

void read_employee() {
    if (added_emp >= MAX) {
        cout << "Database full. Cannot add more employees.\n";
        return;
    }

    cout << "ENTER NAME: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline
    getline(cin, names[added_emp]);                        // allow spaces in name

    cout << "ENTER AGE: ";
    while (!(cin >> ages[added_emp])) {
        cout << "Invalid age. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "ENTER SALARY: ";
    while (!(cin >> salaries[added_emp])) {
        cout << "Invalid salary. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    added_emp++; // IMPORTANT: increment count after successful read
    cout << "Employee added successfully.\n";
}

void show_data() {
    if (added_emp == 0) {
        cout << "No employees to show.\n";
        return;
    }

    cout << "\n--- EMPLOYEES LIST ---\n";
    for (int i = 0; i < added_emp; ++i) {
        cout << i + 1 << ") " << names[i]
             << " | Age: " << ages[i]
             << " | Salary: " << salaries[i] << '\n';
    }
}

// single helper that removes one employee at index (shifts arrays and decrements added_emp)
void remove_employee_at(int index) {
    if (index < 0 || index >= added_emp) return;
    for (int j = index; j < added_emp - 1; ++j) {
        names[j] = names[j + 1];
        ages[j] = ages[j + 1];
        salaries[j] = salaries[j + 1];
    }
    --added_emp;
}

void delete_data() {
    int start, end;
    cout << "ENTER START AND END AGE (e.g. 25 40): ";
    if (!(cin >> start >> end)) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // iterate backward so shifting won't skip elements
    bool removed = false;
    for (int i = added_emp - 1; i >= 0; --i) {
        if (start <= ages[i] && ages[i] <= end) {
            remove_employee_at(i);
            removed = true;
        }
    }

    if (removed) cout << "Employees in the age range removed.\n";
    else cout << "No employees found in that age range.\n";
}

void update_salary() {
    cout << "ENTER EMPLOYEE NAME: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string name;
    getline(cin, name);

    cout << "ENTER THE NEW SALARY: ";
    int newSalary;
    while (!(cin >> newSalary)) {
        cout << "Invalid salary. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool found = false;
    for (int i = 0; i < added_emp; ++i) {
        if (names[i] == name) {
            salaries[i] = newSalary;
            found = true;
        }
    }

    if (found) cout << "Salary updated for employee(s) named \"" << name << "\".\n";
    else cout << "No employee found with that name.\n";
}

void employee_sys() {
    while (true) {
        int choice = menu();
        if (choice == 1) read_employee();
        else if (choice == 2) show_data();
        else if (choice == 3) delete_data();
        else if (choice == 4) update_salary();
        else if (choice == 5) {
            cout << "Exiting. Goodbye!\n";
            break;
        }
    }
}

int main() {
    cout << "HELLO, MY NAME IS OMAR AND THIS IS MY FIRST C++ PROJECT (: \n";
    employee_sys();
    return 0;
}