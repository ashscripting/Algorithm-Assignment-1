//
// Created by morta on 2024-02-02.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <vector>
#include "file_handler.h"

std::fstream file;


file_handler::file_handler() {
    file.open("product_data.txt");
    if (file.is_open()) {
        std::cout << "File Loaded Successfully." << std::endl;
        sleep(1);
        while (getline(file, line)) {
            std::istringstream iss(line);
            while (std::getline(iss, word, ',')) {
                file_line_data.push_back(word);
            }
        }
        std::cout << "Files' Data Is Processing..." << std::endl;
        sleep(1);
        for (int i{0}; i < file_line_data.size(); i++) {
            temp.push_back(file_line_data[i]);
            if ((i + 1) % 4 == 0 || i == file_line_data.size() - 1) {
                file_data.push_back(temp);
                temp.clear();
            }
        }
    } else {
        std::cout << "Filed To Load The File!!" << std::endl;
    }
    for (const std::vector<std::string> &i: file_data) {
        Item item;
        item.Id = stoi(i[0]);
        item.Name = i[1];
        item.Price = stod(i[2]);
        item.Category = i[3];
        items.push_back(item);
    }
}

void file_handler::display_content(const std::vector<Item>& items) {
    for (const Item& i: items) {
        std::cout << i.Id << "  "<< i.Name<< "  " << i.Price << "  "<< i.Category << "  ";
        std::cout<< std::endl;
    }
}

std::vector <file_handler::Item> file_handler::get_info() const {

    return items;

}

void file_handler::search (const std::string& name) const {
    for (const Item &item : items) {
        if (item.Name == name) {
            std::cout << "Item found: " << item.Name << ", ID: " << item.Id << std::endl;
            return;
        }
    }
    std::cout << "Item with name '" << name << "' not found." << std::endl;
}
void file_handler::new_item (std::string &id, std::string &name, std::string &price, std::string &category){
    try {
        Item item;
        item.Id = stoi(id);
        item.Name = name;
        item.Price = stod(price);
        item.Category = category;
        items.push_back(item);
    }
    catch (std::invalid_argument &) {
        std::cout << "Invalid Input!!!" << std::endl;
    }
}

bool file_handler::is_id_there (int  id){
    for (Item &item : items){
        if (item.Id == id){
            return true;
        }
    }
    return false;

}
void file_handler::remove_item (std::string& id){
    for (auto item = items.begin(); item != items.end(); ) {
        if (item->Id == stoi(id)) {
            item = items.erase(item);
        } else {
            ++item;
        }
    }
}

void file_handler::edit_item(std::string &id, std::string &name, std::string &price, std::string &category) {
   bool loop {true};
    do{
        try{
                for (Item &item: items) {
                    if (item.Id == stoi(id)) {
                        if (!name.empty()) {
                            item.Name = name;
                        }
                        if (!price.empty()) {
                            item.Price = stod(price);
                        }
                        if (!category.empty()) {
                            item.Category = category;
                        }
                    }
                    loop = false;
                }
                std::cout << " Product edited successfully" << std::endl;
        }
        catch (std::invalid_argument&) {
            std::cout << "Invalid input!!!" << std::endl;
            break;
        }
    }while(loop);
}


void file_handler::Sort() {
    bool change {false};
    for (int i {0}; i < items.size() - 1; i++) {
        for (int j {0}; j < items.size() - i - 1; j++) {
            if (items[j].Price > items[j + 1].Price) {
                std::swap(items[j], items[j + 1]);
                change = true;
            }
        }
        if (!change) {
            break;
        }
    }
    std::cout << "Sorting Was Successful." << std::endl;
}