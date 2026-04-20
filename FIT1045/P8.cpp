#include "splashkit.h"
#include <string> // for std::to_string

const int MAX_ROCKS = 100;
const int PLAYER_SIZE = 30;

struct rock_data
{
    double x, y;
    double size;
    double speed;
};

struct game_data
{
    rock_data rocks[MAX_ROCKS];
    int rock_count;
    double player_x, player_y;
    int score;
    int lives;
    unsigned int next_rock_time;
};

// Initialize the game
void setup_game(game_data &game)
{
    game.rock_count = 0;
    game.score = 0;
    game.lives = 3;
    game.player_x = screen_width() / 2;
    game.player_y = screen_height() - 50;
    game.next_rock_time = current_ticks() + rnd(1000, 6000);
}

// Add a new rock
void add_rock(game_data &game)
{
    if (game.rock_count >= MAX_ROCKS)
        return;

    rock_data &r = game.rocks[game.rock_count];
    r.size = rnd(20, 200);
    r.y = -r.size;
    r.x = rnd(0, screen_width());
    r.speed = rnd(1, 5);

    game.rock_count++;
    game.score++;
    game.next_rock_time = current_ticks() + rnd(1000, 6000);
}

// Update the game state
void update_game(game_data &game)
{
    // Spawn new rock at intervals
    if (current_ticks() > game.next_rock_time)
    {
        add_rock(game);
    }

    // Update rock positions
    for (int i = 0; i < game.rock_count; i++)
    {
        game.rocks[i].y += game.rocks[i].speed;

        // Rock falls off the screen
        if (game.rocks[i].y > screen_height())
        {
            game.score += (int)game.rocks[i].size;
            game.rocks[i] = game.rocks[game.rock_count - 1];
            game.rock_count--;
            i--;
        }
        // Check collision
        else if (circle_to_circle(
                     {game.player_x, game.player_y, PLAYER_SIZE},
                     {game.rocks[i].x, game.rocks[i].y, game.rocks[i].size}))
        {
            game.lives--;
            game.rocks[i] = game.rocks[game.rock_count - 1];
            game.rock_count--;
            i--;
        }
    }
}

// Handle player input
void handle_input(game_data &game)
{
    if (key_down(LEFT_KEY))
        game.player_x -= 3;
    if (key_down(RIGHT_KEY))
        game.player_x += 3;
}

// Draw the game
void draw_game(const game_data &game)
{
    clear_screen(COLOR_WHITE);
    draw_text("Score: " + std::to_string(game.score), COLOR_BLACK, 10, 10);
    draw_text("Lives: " + std::to_string(game.lives), COLOR_BLACK, 10, 30);

    draw_circle(COLOR_BLUE, game.player_x, game.player_y, PLAYER_SIZE);

    for (int i = 0; i < game.rock_count; i++)
    {
        draw_circle(COLOR_RED, game.rocks[i].x, game.rocks[i].y, game.rocks[i].size);
    }

    refresh_screen();
}

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