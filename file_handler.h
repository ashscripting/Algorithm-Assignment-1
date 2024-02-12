//
// Created by morta on 2024-02-02.
//

#ifndef ALGORITHM_ASSIGNMENT_1_FILE_HANDLER_H
#define ALGORITHM_ASSIGNMENT_1_FILE_HANDLER_H


class file_handler {

public:
    file_handler();
    struct Item{
        int Id;
        std::string Name;
        double Price;
        std::string Category;
    };
    void remove_item (std::string&);
    void Sort ();
    [[nodiscard]] std::vector <Item> get_info() const;
    void search(const std::string& ) const;
    bool is_id_there (int );
    static void display_content(const std::vector<Item>&);
    void new_item (std::string&, std::string&, std::string&, std::string&);
    void edit_item (std::string&, std::string&, std::string&, std::string&);
private:
    std::vector <Item> items;
    std::string line{}, word{};
    std::vector <std::string> temp;
    std::vector <std::string> file_line_data;
    std::vector <std::vector<std::string>> file_data;
};


#endif //ALGORITHM_ASSIGNMENT_1_FILE_HANDLER_H
