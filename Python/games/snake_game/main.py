import pygame
import time
import random

# Initialize Pygame
pygame.init()

# Define colors
white = (255, 255, 255)
yellow = (255, 255, 102)
black = (0, 0, 0)
red = (213, 50, 80)
green = (0, 255, 0)
blue = (50, 153, 213)

# Set display dimensions
window_width = 600
window_height = 400

# Create the game window
game_window = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption('Snake Game')

# Set up the clock for controlling the frame rate
clock = pygame.time.Clock()

# Define snake properties
snake_block = 10  # Size of each snake segment
snake_speed = 15  # Initial speed of the snake

# Set up the fonts for displaying score and messages
font_style = pygame.font.SysFont("bahnschrift", 25)
score_font = pygame.font.SysFont("comicsansms", 35)

def your_score(score):
    """Displays the current score on the screen."""
    value = score_font.render("Your Score: " + str(score), True, yellow)
    game_window.blit(value, [0, 0])

def draw_snake(snake_block, snake_list):
    """Draws the snake on the screen."""
    for x in snake_list:
        pygame.draw.rect(game_window, green, [x[0], x[1], snake_block, snake_block])

def message(msg, color):
    """Displays a message in the center of the screen."""
    mesg = font_style.render(msg, True, color)
    mesg_rect = mesg.get_rect(center=(window_width/2, window_height/2))
    game_window.blit(mesg, mesg_rect)

def game_loop():
    """Main function that contains the game loop."""
    game_over = False
    game_close = False

    # Starting position of the snake
    x1 = window_width / 2
    y1 = window_height / 2

    # Movement variables
    x1_change = 0
    y1_change = 0

    # Snake body list and initial length
    snake_List = []
    Length_of_snake = 1

    # Generate initial food coordinates
    foodx = round(random.randrange(0, window_width - snake_block) / 10.0) * 10.0
    foody = round(random.randrange(0, window_height - snake_block) / 10.0) * 10.0

    while not game_over:

        while game_close:
            # Fill the background and display the game over message
            game_window.fill(black)
            message("You Lost! Press C-Play Again or Q-Quit", red)
            your_score(Length_of_snake - 1)
            pygame.display.update()

            # Event handling for game over state
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    game_over = True
                    game_close = False
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        game_over = True
                        game_close = False
                    if event.key == pygame.K_c:
                        game_loop()

        # Event handling for game play state
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x1_change = -snake_block
                    y1_change = 0
                elif event.key == pygame.K_RIGHT:
                    x1_change = snake_block
                    y1_change = 0
                elif event.key == pygame.K_UP:
                    y1_change = -snake_block
                    x1_change = 0
                elif event.key == pygame.K_DOWN:
                    y1_change = snake_block
                    x1_change = 0

        # Check for boundaries to end the game if snake hits the wall
        if x1 >= window_width or x1 < 0 or y1 >= window_height or y1 < 0:
            game_close = True

        # Update the snake's position
        x1 += x1_change
        y1 += y1_change

        # Fill the background
        game_window.fill(black)

        # Draw the food
        pygame.draw.rect(game_window, red, [foodx, foody, snake_block, snake_block])

        # Update the snake's body
        snake_Head = []
        snake_Head.append(x1)
        snake_Head.append(y1)
        snake_List.append(snake_Head)

        if len(snake_List) > Length_of_snake:
            del snake_List[0]

        # Check for self-collision
        for x in snake_List[:-1]:
            if x == snake_Head:
                game_close = True

        # Draw the snake and display the score
        draw_snake(snake_block, snake_List)
        your_score(Length_of_snake - 1)

        # Update the display
        pygame.display.update()

        # Check if the snake has eaten the food
        if x1 == foodx and y1 == foody:
            # Generate new food coordinates
            foodx = round(random.randrange(0, window_width - snake_block) / 10.0) * 10.0
            foody = round(random.randrange(0, window_height - snake_block) / 10.0) * 10.0
            Length_of_snake += 1  # Increase the length of the snake

        # Control the speed of the snake
        clock.tick(snake_speed)

    # Quit the game properly
    pygame.quit()
    quit()

# Start the game
game_loop()
