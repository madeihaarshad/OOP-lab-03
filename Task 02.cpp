#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Define a map to store contacts with names as keys and contact details as values
    map<string, string> contacts;

    // Add some initial contacts
    contacts["Madeiha Arshad"] = "madeiha.satti@gmail.com";
    contacts["Mehak Fatima"] = "mehak.fatima02@gmail.com";
    contacts["Meerab Khan"] = "meerab123@gmail.com";

    while (true) {
        // Display all contacts
        cout << "-------------------------" << endl;
        cout << "|       All Contacts     |" << endl;
        cout << "-------------------------" << endl;
        for (const auto& contact : contacts) {
            cout << contact.first << ": " << contact.second << endl;
        }
        cout << "-------------------------" << endl;

        // Take input for search
        string searchName;
        cout << "Enter name to search (or type 'quit' to exit): ";
        getline(cin, searchName);

        if (searchName == "quit") {
            break; // Exit the loop if the user types 'quit'
        }
// Search for a contact by name
        auto it = contacts.find(searchName);
        if (it != contacts.end()) {
            cout << "Contact found for " << searchName << ": " << it->second << endl;
// Ask to add a new contact
            string addNewContact;
            cout << "Do you want to add a new contact? (yes/no): ";
            getline(cin, addNewContact);
if (addNewContact == "yes") {
                string newContactName, newContactEmail;
                cout << "Enter name of the new contact: ";
                getline(cin, newContactName);
                cout << "Enter email of the new contact: ";
                getline(cin, newContactEmail);
                contacts[newContactName] = newContactEmail;
cout << "New contact added: " << newContactName << ": " << newContactEmail << endl;
// Display updated list of contacts after adding a new contact
                cout << "-------------------------" << endl;
                cout << "|  Updated Contacts List |" << endl;
                cout << "-------------------------" << endl;
                for (const auto& contact : contacts) {
                    cout << contact.first << ": " << contact.second << endl;
                }
                cout << "-------------------------" << endl;
            }
        } else {
            cout << "Contact not found for " << searchName << endl;
// Display valid contacts to search
            cout << "Valid contacts to search:" << endl;
            for (const auto& contact : contacts) {
                cout << contact.first << endl;
            }
        }}
return 0;
}

