#include <iostream>
#include "header.h"

void add_cheese(std::vector<Cheese> &cheeses, const std::string &name, int stock)
{
    cheeses.push_back({name, stock});
}

void list_cheeses(const std::vector<Cheese> &cheeses)
{
    std::cout << "Available Cheeses:\n";
    for (const auto &c : cheeses)
    {
        std::cout << "- " << c.name << " (Stock: " << c.stock << ")\n";
    }
}

void add_order(std::vector<CustomerOrder> &orders, int id)
{
    orders.push_back({id, {}, false});
}

void add_item_to_order(CustomerOrder &order, const std::string &cheeseName, int qty)
{
    order.items.push_back({cheeseName, qty});
}

void edit_item_in_order(CustomerOrder &order, const std::string &cheeseName, int newQty)
{
    for (auto &item : order.items)
    {
        if (item.cheeseName == cheeseName)
        {
            item.quantity = newQty;
            return;
        }
    }
}

void remove_item_from_order(CustomerOrder &order, const std::string &cheeseName)
{
    order.items.erase(
        std::remove_if(order.items.begin(), order.items.end(),
                       [&](const OrderItem &i)
                       { return i.cheeseName == cheeseName; }),
        order.items.end());
}

void fulfill_order(CustomerOrder &order, std::vector<Cheese> &cheeses)
{
    if (order.fulfilled)
    {
        std::cout << "Order already fulfilled.\n";
        return;
    }
    for (auto &item : order.items)
    {
        for (auto &cheese : cheeses)
        {
            if (cheese.name == item.cheeseName)
            {
                cheese.stock -= item.quantity;
            }
        }
    }
    order.fulfilled = true;
    std::cout << "Order fulfilled and stock updated.\n";
}

int main()
{
    std::vector<Cheese> cheeses;
    std::vector<CustomerOrder> orders;

    // Initial stock
    add_cheese(cheeses, "Cheddar", 50);
    add_cheese(cheeses, "Brie", 30);

    list_cheeses(cheeses);

    // Create order
    add_order(orders, 1);
    add_item_to_order(orders[0], "Cheddar", 5);
    add_item_to_order(orders[0], "Brie", 2);

    std::cout << "\nFulfilling order #1...\n";
    fulfill_order(orders[0], cheeses);

    list_cheeses(cheeses);

    return 0;
}
