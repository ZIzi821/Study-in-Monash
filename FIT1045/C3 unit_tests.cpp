#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "header.h"

TEST_CASE("Add cheese increases stock list")
{
    std::vector<Cheese> cheeses;
    add_cheese(cheeses, "Cheddar", 10);
    REQUIRE(cheeses.size() == 1);
    REQUIRE(cheeses[0].stock == 10);
}

TEST_CASE("Add and fulfill customer order decreases stock")
{
    std::vector<Cheese> cheeses;
    add_cheese(cheeses, "Brie", 20);

    std::vector<CustomerOrder> orders;
    add_order(orders, 1);
    add_item_to_order(orders[0], "Brie", 5);

    fulfill_order(orders[0], cheeses);
    REQUIRE(cheeses[0].stock == 15);
    REQUIRE(orders[0].fulfilled == true);
}

TEST_CASE("Edit and remove items in order")
{
    CustomerOrder order{1, {}, false};
    add_item_to_order(order, "Cheddar", 5);
    edit_item_in_order(order, "Cheddar", 10);
    REQUIRE(order.items[0].quantity == 10);

    remove_item_from_order(order, "Cheddar");
    REQUIRE(order.items.empty());
}
