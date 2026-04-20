#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

// Cheese item
struct Cheese
{
    std::string name;
    int stock;
};

// Customer order item
struct OrderItem
{
    std::string cheeseName;
    int quantity;
};

// Customer order
struct CustomerOrder
{
    int id;
    std::vector<OrderItem> items;
    bool fulfilled;
};

// Function declarations
void add_cheese(std::vector<Cheese> &cheeses, const std::string &name, int stock);
void list_cheeses(const std::vector<Cheese> &cheeses);

void add_order(std::vector<CustomerOrder> &orders, int id);
void add_item_to_order(CustomerOrder &order, const std::string &cheeseName, int qty);
void edit_item_in_order(CustomerOrder &order, const std::string &cheeseName, int newQty);
void remove_item_from_order(CustomerOrder &order, const std::string &cheeseName);
void fulfill_order(CustomerOrder &order, std::vector<Cheese> &cheeses);

#endif
