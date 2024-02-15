#include <iostream>
#include <vector>
#include <string>
#include "file_handler.h"

using namespace std;

int main(){

    file_handler input;

    string name;
    string price;
    string category;
    string id;
    int choice{};
    bool loop{true};
    do {
        cout << "1. Display Products\n2. Find a Product\n3. Add a New Product\n"
                "4. Remove a Product\n5. Edit Existing Product\n6. Sort Data\n7. Exit\n>";
        cin >> choice;
        switch(choice) {
            case 1:
                file_handler::display_content(input.get_info());
                break;
            case 2:
                cin.ignore();
                cout << "Enter the name of the product your looking for: ";
                getline(cin, name);
                input.search(name);
                break;
            case 3:
                cin.ignore();
                cout << "Enter the product id: " << endl;
                getline(cin, id);
                try {
                    if (input.is_id_there(stoi((id)))) {
                        cout << "Invalid ID! ID already exists." << endl;
                        break;
                    }
                }
                catch (std::invalid_argument&) {
                    std::cout << "Invalid Input!!!" << std::endl;
                    break;
                }
                cout << "Enter the product name: " << endl;
                getline(cin, name);
                cout << "Enter the product price: " << endl;
                getline(cin, price);
                cout << "Enter the product category: " << endl;
                getline(cin, category);
                input.new_item(id, name, price, category);
                break;
            case 4:
                cout << "Enter the id opf the product you wish to remove: " << endl;
                cin >> id;
                try{
                if (input.is_id_there(stoi(id))) {
                    input.remove_item(id);
                    cout << "Product Removed Successfully." << endl;
                    break;
                }
                cout << "Invalid ID! Product with this id doesn't exist" << endl;
                break;
                }
                catch (std::invalid_argument&) {
                    std::cout << "Invalid input!!!" << std::endl;
                    break;
                }
            case 5:
                cout << "Enter the id of the product you wish to edit: " << endl;
                cin >> id;
                try {
                    if (input.is_id_there(stoi(id))) {
                        cin.ignore();
                        cout << "Enter the product name: " << endl;
                        getline(cin, name);
                        cout << "Enter the product price: " << endl;
                        getline(cin, price);
                        cout << "Enter the product category: " << endl;
                        getline(cin, category);
                        input.edit_item(id, name, price, category);
                        break;
                    }
                    cout << "Invalid ID! Product with this id doesn't exist" << endl;
                    break;
                }
                catch (std::invalid_argument &) {
                    std::cout << "Invalid Input!!!" << std::endl;
                    break;
                }
            case 6:
                input.Sort();
                break;
            case 7:
                loop = false;
                cout<<"Exiting The Program...";
                break;
            default:
                break;
        }
    }while(loop);

    return 0;

}