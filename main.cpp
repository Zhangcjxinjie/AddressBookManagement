//
// Created by Xinjie Zhang on 1/23/2023.
//
#include <iostream>
#include <stdlib.h>
using namespace std;

// Print out the menu
void showMenu(){
    cout<<"************************************"<<endl;
    cout<<"***** 1,add contact person     *****"<<endl;
    cout<<"***** 2,show contact person    *****"<<endl;
    cout<<"***** 3,delete contact person  *****"<<endl;
    cout<<"***** 4,find contact person    *****"<<endl;
    cout<<"***** 5,edit contact person    *****"<<endl;
    cout<<"***** 6,delete all person      *****"<<endl;
    cout<<"***** 0,quit address book      *****"<<endl;
    cout<<"************************************"<<endl;
}
// Using struct to make persons with name , sex , age , phone , address
struct Person{
    string m_Name;
    int m_Sex;
    int m_age;
    string m_phone;
    string m_address;
};
// Using struct to make an address book with an array of persons and int size
struct AddressBooks{
    Person personArr[1000];
    int m_Size;
};
// add person
void addPerson(struct AddressBooks * abs){
    // if book is full do not add person
    if(abs->m_Size >= 1000){
        cout<< "the Address book is full"<<endl;
        return;
    }
    else{
        //add name , sex , age , phone number , address
        string name;
        int sex = 0;
        int age = 0;
        string phoneNumber;
        string address;
        cout << "Please enter his/her name: "<<endl;
        cin >> name;
        abs->personArr[abs->m_Size].m_Name = name;
        cout << "Please enter "<<abs->personArr[abs->m_Size].m_Name<<" sex :"<<endl;
        cout<<"1 ----male"<<endl;
        cout<<"2 ----female"<<endl;
        cin >> sex;
        abs->personArr[abs->m_Size].m_Sex = sex;
        cout << "Please enter "<<abs->personArr[abs->m_Size].m_Name<<" age :"<<endl;
        cin >> age;
        abs->personArr[abs->m_Size].m_age = age;
        cout << "Please enter "<<abs->personArr[abs->m_Size].m_Name<<" phone number :"<<endl;
        cin >> phoneNumber;
        abs->personArr[abs->m_Size].m_phone = phoneNumber;
        cout << "Please enter "<<abs->personArr[abs->m_Size].m_Name<<" Address :"<<endl;
        cin >> address;
        abs->personArr[abs->m_Size].m_address = address;
        // refresh size of the address book
        abs->m_Size ++;
        cout << "add person success!"<<endl;
        system("PAUSE");
        system("CLS");
    }
}
void showPerson(struct AddressBooks * abs){
    cout << "name\tsex  \tage\tphone number\taddress"<<endl;
    for(int i = 0 ; i < abs->m_Size;i++){
        cout<<abs->personArr[i].m_Name << "\t";
        if(abs->personArr[i].m_Sex == 1){
            cout<<"male\t";
        } else{
            cout<<"female\t";
        }
        cout<<abs->personArr[i].m_age<< "\t";
        cout<<abs->personArr[i].m_phone << "\t";
        cout<<abs->personArr[i].m_address << endl;
        cout<<endl;

    }

}
// delete all person

void deleteAllPerson(struct AddressBooks * abs){
    abs->m_Size = 0;
    cout<<"delete all person success!"<<endl;
    system("PAUSE");
    system("CLS");
}
// find person
void findPerson(struct AddressBooks * abs) {
    string name;
    cout << "Please enter the name you want to find: " << endl;
    cin >> name;
    for (int i = 0; i < abs->m_Size; i++) {
        if (abs->personArr[i].m_Name == name) {
            cout << "find person success!" << endl;
            cout << "name\tsex  \tage\tphone number\taddress" << endl;
            cout << abs->personArr[i].m_Name << "\t";
            if (abs->personArr[i].m_Sex == 1) {
                cout << "male\t";
            } else {
                cout << "female\t";
            }
            cout << abs->personArr[i].m_age << "\t";
            cout << abs->personArr[i].m_phone << "\t";
            cout << abs->personArr[i].m_address << endl;
            cout << endl;
        }
    }
}
// delete person
void deletePerson(struct AddressBooks * abs){
    string name;
    cout << "Please enter the name you want to delete: " << endl;
    cin >> name;
    for (int i = 0; i < abs->m_Size; i++) {
        if (abs->personArr[i].m_Name == name) {
            for(int j = i ; j < abs->m_Size;j++){
                abs->personArr[j] = abs->personArr[j+1];
            }
            abs->m_Size--;
            cout << "delete person success!" << endl;
            system("PAUSE");
            system("CLS");
        }
    }
}
// edit person
void editPerson(struct AddressBooks * abs){
    string name;
    cout << "Please enter the name you want to edit: " << endl;
    cin >> name;
    for (int i = 0; i < abs->m_Size; i++) {
        if (abs->personArr[i].m_Name == name) {
            cout << "Please enter his/her name: " << endl;
            cin >> name;
            abs->personArr[i].m_Name = name;
        }
    }
}
int main() {
    //declare a struct AddressBook
    AddressBooks abs;
    //no person now so the size is 0;
    abs.m_Size = 0;
    int userSelect = INT_MIN;
    while (true) {
        //print the menu
        showMenu();
        cin >> userSelect;
        switch (userSelect) {
            case 1: //add contact person
                addPerson(&abs);
                break;
            case 2: //show contact person
                showPerson(&abs);
                break;
            case 3: //delete contact person
                deletePerson(&abs);

                break;
            case 4: //find contact person
                findPerson(&abs);
                break;
            case 5: //edit contact person
                editPerson(&abs);
                break;
            case 6: //delete all contact person
                deleteAllPerson(&abs);
                break;
            case 0://quit address book
                cout << "see you next time :)" << endl;
                return 0;
            default:
                break;

        }
    }
}