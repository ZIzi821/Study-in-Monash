#include "splashkit.h"
#include <string>

// Struct to hold game state
struct game_data
{
    circle target;    // target circle
    timer game_timer; // timer to measure reaction
    int score;        // number of hits
    int best_time;    // fastest reaction in ms
};

// Initialize the game
void setup_game(game_data &game)
{
    game.target.radius = 50;                    // initial radius
    game.target.center = random_screen_point(); // random position
    game.game_timer = create_timer("reaction_timer");
    start_timer(game.game_timer);
    game.score = 0;
    game.best_time = 999999; // large initial value
}

// Draw the game state
void draw_game(const game_data &game)
{
    clear_screen(COLOR_WHITE);
    fill_circle(COLOR_RED, game.target); // draw target
    draw_text("Score: " + std::to_string(game.score), COLOR_BLACK, 10, 10);
    draw_text("Best: " + std::to_string(game.best_time) + " ms", COLOR_BLACK, 10, 40);
    refresh_screen(60);
}

// Update the game when target is clicked
void handle_input(game_data &game)
{
    if (mouse_clicked(LEFT_BUTTON))
    {
        point_2d mouse_pos = mouse_position();
        if (point_in_circle(mouse_pos, game.target))
        {
            int reaction_time = timer_ticks(game.game_timer);

            // update score
            game.score++;

            // update best time
            if (reaction_time < game.best_time)
            {
                game.best_time = reaction_time;
            }

            // adjust radius based on reaction time
            if (reaction_time > 1000)
            {
                game.target.radius += 5; // slower → bigger
            }
            else
            {
                game.target.radius = (reaction_time / 1000.0) * 200;
                if (game.target.radius < 20)
                    game.target.radius = 20; // minimum size
            }

            // move target to new position
            game.target.center = random_screen_point();

            // reset timer
            reset_timer(game.game_timer);
        }
    }
}

int main()
{
    open_window("Reaction Game", 800, 600);

    game_data game;
    setup_game(game);

    while (not quit_requested())
    {
        process_events();
        handle_input(game);
        draw_game(game);
    }

    return 0;
}
