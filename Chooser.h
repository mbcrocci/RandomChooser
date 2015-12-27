//
// Created by Maurizio Crocci on 27/12/15.
//

#ifndef RANDOMCHOOSER_CHOOSER_H
#define RANDOMCHOOSER_CHOOSER_H

#include <vector>
#include <sstream>

class Chooser {
    std::vector<std::string> item_list;

public:

    Chooser() { }

    void addItem(std::string i) {
        this->item_list.push_back(i);
    }

    std::string listAsString() const {
        std::ostringstream oss;

        for (auto &i : item_list)
            oss << "- " << i << "\n";

        return oss.str();
    }

    std::vector<std::string> getItem_list() const {
        return item_list;
    }

    std::string randomItem() const {
        unsigned long r;
        r = rand() % this->item_list.size();
        return this->item_list.at(r);
    }
};


#endif //RANDOMCHOOSER_CHOOSER_H
