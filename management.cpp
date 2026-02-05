#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;
    string grade;
    
    void inputData() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
        
        if(marks >= 90) grade = "A+";
        if(marks >= 80 && marks < 90) grade = "A";
        if(marks >= 70 && marks < 80) grade = "B";
        if(marks >= 60 && marks < 70) grade = "C";
        if(marks >= 50 && marks < 60) grade = "D";
        if(marks < 50) grade = "F";
    }
    
    void showData() {
        cout << "\nRoll Number: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << grade << endl;
        cout << "------------------------\n";
    }
};

void addStudent() {
    Student s;
    s.inputData();
    
    ofstream file("students.txt", ios::app);
    file << s.roll << endl;
    file << s.name << endl;
    file << s.marks << endl;
    file << s.grade << endl;
    file.close();
    
    cout << "\nStudent added!\n";
}
//swanandi
void displayAllStudents() {
    ifstream file("students.txt"); // opens file in read mode 
    Student s;
    int count = 0; // creates an integer variable count
    
    cout << "\n--- All Students ---\n";
    while(file >> s.roll) { 
        file.ignore();
        getline(file, s.name);
        file >> s.marks;
        file.ignore();
        getline(file, s.grade);
        s.showData();
        count++; //increases student counter one after displaying one student’s data
    }
    
    cout << "Total: " << count << " students\n";
    file.close();
}

void searchStudent() {
    int searchRoll; //declares an integer variable to store the roll number that the user 
    cout << "Enter Roll Number: ";
    cin >> searchRoll;
    
    ifstream file("students.txt");
    Student s;
    bool found = false;
    
    while(file >> s.roll) {
        file.ignore();
        getline(file, s.name);
        file >> s.marks;
        file.ignore();
        getline(file, s.grade);
        
        if(s.roll == searchRoll) {
            cout << "\nFound!\n";
            s.showData();
            found = true;
            break;
        }
    }
    
    if(!found)
        cout << "\nNot found!\n";
    
    file.close();
} 
//mansi
void updateStudent() {
    int updateRoll;
    cout << "Enter Roll Number: ";
    cin >> updateRoll;
    
    ifstream file("students.txt");
    Student students[100];
    int count = 0;
    bool found = false;
    
    while(file >> students[count].roll) {
        file.ignore();
        getline(file, students[count].name);
        file >> students[count].marks;
        file.ignore();
        getline(file, students[count].grade);
        count++;
    }
    file.close();
    
    for(int i = 0; i < count; i++) {
        if(students[i].roll == updateRoll) {
            found = true;
            students[i].showData();
            
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "Enter new marks: ";
            cin >> students[i].marks;
            
            if(students[i].marks >= 90) students[i].grade = "A+";
            else if(students[i].marks >= 80) students[i].grade = "A";
            else if(students[i].marks >= 70) students[i].grade = "B";
            else if(students[i].marks >= 60) students[i].grade = "C";
            else if(students[i].marks >= 50) students[i].grade = "D";
            else students[i].grade = "F";
            break;
        }
    }
    
    if(!found) {
        cout << "\nNot found!\n";
        return;
    }
    
    ofstream outFile("students.txt");
    for(int j = 0; j < count; j++) {
        outFile << students[j].roll << endl;
        outFile << students[j].name << endl;
        outFile << students[j].marks << endl;
        outFile << students[j].grade << endl;
    }
    outFile.close();
}

void deleteStudent() {
    int deleteRoll;
    cout << "Enter Roll Number: ";
    cin >> deleteRoll;
    
    ifstream file("students.txt");
    Student students[100];
    int count = 0;
    bool found = false;
    
    while(file >> students[count].roll) {
        file.ignore();
        getline(file, students[count].name);
        file >> students[count].marks;
        file.ignore();
        getline(file, students[count].grade);
        count++;
    }
    file.close();
    
    ofstream outFile("students.txt");
    for(int i = 0; i < count; i++) {
        if(students[i].roll == deleteRoll) {
            found = true;
            students[i].showData();
            continue;
        }
        outFile << students[i].roll << endl;
        outFile << students[i].name << endl;
        outFile << students[i].marks << endl;
        outFile << students[i].grade << endl;
    }
    outFile.close();
    
    if(!found)
        cout << "\nNot found!\n";
}
//sarthak
// -------- STORE & RETRIEVE (OPTION 6) --------
void storeAndRetrieve() {
    ofstream fout("data.txt");
    string name;

    cout << "Enter your name: ";
    cin >> name;
    fout << name;
    fout.close();

    cout << "Data stored successfully!\n";

    ifstream fin("data.txt");
    string readName;
    fin >> readName;
    fin.close();

    cout << "Retrieved data: " << readName << endl;
}

void showMenu() {
    cout << "\n----- Student Management -----\n";
    cout << "1. Add Student\n";
    cout << "2. Show All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Store & Retrieve\n";
    cout << "7. Exit\n";
    cout << "Choice: ";
}

int main() {
    int choice;
    cout << "Welcome!\n";
    
    while(true) {
        showMenu();
        cin >> choice;
        
        if(choice == 1) addStudent();
        else if(choice == 2) displayAllStudents();
        else if(choice == 3) searchStudent();
        else if(choice == 4) updateStudent();
        else if(choice == 5) deleteStudent();
        else if(choice == 6) storeAndRetrieve();
        else if(choice == 7) {
            cout << "\nBye!\n";
            break;
        }
        else {
            cout << "\nWrong choice!\n";
        }
    }
    
    return 0;
}