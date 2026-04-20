#include "splashkit.h"
#include <string>

// ---------------- DynamicArray Template ----------------
template <typename T>
class DynamicArray
{
private:
    T* data;
    int capacity;
    int length;

    void resize(int new_capacity)
    {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < length; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    DynamicArray(int initial_capacity = 10)
    {
        capacity = initial_capacity;
        length = 0;
        data = new T[capacity];
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    int size() const { return length; }

    void push_back(const T& value)
    {
        if (length >= capacity)
        {
            resize(capacity * 2);
        }
        data[length++] = value;
    }

    void remove_at(int index)
    {
        if (index < 0 || index >= length) return;
        data[index] = data[length - 1]; // overwrite with last element
        length--;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    const T& operator[](int index) const
    {
        return data[index];
    }
};

// ---------------- Game Structures ----------------
const int PLAYER_SIZE = 30;

struct rock_data
{
    double x, y;
    double size;
    double speed;
};

struct game_data
{
    DynamicArray<rock_data> rocks; // dynamic array of rocks
    double player_x, player_y;
    int score;
    int lives;
    unsigned int next_rock_time;

    game_data() : rocks(10) {} // constructor with initial capacity
};

// ---------------- Game Functions ----------------
void setup_game(game_data &game)
{
    game.score = 0;
    game.lives = 3;
    game.player_x = screen_width() / 2;
    game.player_y = screen_height() - 50;
    game.next_rock_time = current_ticks() + rnd(1000, 6000);
}

void add_rock(game_data &game)
{
    rock_data r;
    r.size = rnd(20, 200);
    r.y = -r.size;
    r.x = rnd(0, screen_width());
    r.speed = rnd(1, 5);

    game.rocks.push_back(r);
    game.score++;
    game.next_rock_time = current_ticks() + rnd(1000, 6000);
}

void update_game(game_data &game)
{
    if (current_ticks() > game.next_rock_time)
    {
        add_rock(game);
    }

    for (int i = 0; i < game.rocks.size(); i++)
    {
        game.rocks[i].y += game.rocks[i].speed;

        if (game.rocks[i].y > screen_height())
        {
            game.score += (int)game.rocks[i].size;
            game.rocks.remove_at(i);
            i--;
        }
        else if (circles_intersect(
                     {game.player_x, game.player_y, PLAYER_SIZE},
                     {game.rocks[i].x, game.rocks[i].y, game.rocks[i].size}))
        {
            game.lives--;
            game.rocks.remove_at(i);
            i--;
        }
    }
}

void handle_input(game_data &game)
{
    if (key_down(LEFT_KEY))
        game.player_x -= 3;
    if (key_down(RIGHT_KEY))
        game.player_x += 3;
}

void draw_game(const game_data &game)
{
    clear_screen(COLOR_WHITE);
    draw_text("Score: " + std::to_string(game.score), COLOR_BLACK, 10, 10);
    draw_text("Lives: " + std::to_string(game.lives), COLOR_BLACK, 10, 30);

    draw_circle(COLOR_BLUE, game.player_x, game.player_y, PLAYER_SIZE);

    for (int i = 0; i < game.rocks.size(); i++)
    {
        draw_circle(COLOR_RED, game.rocks[i].x, game.rocks[i].y, game.rocks[i].size);
    }

    refresh_screen();
}

// ---------------- Main ----------------
int main()
{
    open_window("Rock Dodge", 800, 600);

    game_data game;
    setup_game(game);

    while (!quit_requested() && game.lives > 0)
    {
        process_events();
        handle_input(game);
        update_game(game);
        draw_game(game);
    }

    return 0;
}
