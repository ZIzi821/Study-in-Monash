import tkinter as tk
import random

# Window settings
WIDTH, HEIGHT = 400, 500
window = tk.Tk()
window.title("Catch the Ball")

# Create canvas for drawing
canvas = tk.Canvas(window, width=WIDTH, height=HEIGHT, bg="white")
canvas.pack()

# Basket setup
basket_width, basket_height = 80, 20
basket_x = WIDTH // 2 - basket_width // 2
basket_y = HEIGHT - 40
basket = canvas.create_rectangle(basket_x, basket_y,
                                 basket_x + basket_width, basket_y + basket_height,
                                 fill="black")

# Ball setup
ball_radius = 15
ball_x = random.randint(ball_radius, WIDTH - ball_radius)
ball_y = 0
ball = canvas.create_oval(ball_x - ball_radius, ball_y - ball_radius,
                          ball_x + ball_radius, ball_y + ball_radius,
                          fill="red")

# Score setup
score = 0
score_text = canvas.create_text(50, 20, text=f"Score: {score}", font=("Arial", 16))

# Control variables
basket_speed = 20
ball_speed = 3   # Slower ball speed for easier gameplay

# Move basket left
def move_left(event):
    global basket
    canvas.move(basket, -basket_speed, 0)

# Move basket right
def move_right(event):
    global basket
    canvas.move(basket, basket_speed, 0)

# Update game state
def update_game():
    global ball, ball_x, ball_y, score
    # Move the ball down
    canvas.move(ball, 0, ball_speed)
    ball_coords = canvas.coords(ball)
    basket_coords = canvas.coords(basket)

    # Collision detection
    if ball_coords[3] >= basket_coords[1]:  # Ball reaches basket height
        if basket_coords[0] <= ball_coords[0] <= basket_coords[2]:
            score += 1
        else:
            score -= 1
        # Reset ball to top
        new_x = random.randint(ball_radius, WIDTH - ball_radius)
        canvas.coords(ball,
                      new_x - ball_radius, 0,
                      new_x + ball_radius, 2 * ball_radius)

    # Update score display
    canvas.itemconfig(score_text, text=f"Score: {score}")

    # Check for Game Over
    if score < 0:
        canvas.create_text(WIDTH//2, HEIGHT//2, text="Game Over", font=("Arial", 24), fill="red")
        return

    # Check for Player WIN
    if score >= 15:
        canvas.create_text(WIDTH//2, HEIGHT//2, text="Player WIN!", font=("Arial", 24), fill="green")
        return

    # Repeat update after 30 ms
    window.after(30, update_game)

# Bind keyboard controls
window.bind("<Left>", move_left)
window.bind("<Right>", move_right)

# Start the game loop
update_game()
window.mainloop()
