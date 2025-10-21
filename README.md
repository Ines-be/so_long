# 2D Princess Adventure Game

<p align="center">
  <img src="img/so_long.gif" alt="Game animation">
</p>


## 👑 Overview
This is a **2D game** written in **C** where the player controls a princess who must **collect all the rubies** while avoiding a monster and reach the exit to win. The game features:
- **Window management** using the MLX library
- **Smooth event handling** with arrow keys
- **Customizable textures** for player, enemy, walls, collectibles, and background
- **Memory-safe code** (no leaks or still reachable allocations)
- **Explicit error handling** with clear messages  

The player wins by collecting all collectibles and reaching the exit. The enemy moves **in the opposite direction of the player**, making the game challenging.


## 🕹️ Game rules
1. The player is a princess (P)
2. The enemy is a monster (M)
3. Collectibles are rubies (C)
4. The exit appears only after all collectibles are collected (E)
5. The player loses if the enemy touches her
6. The player can exit anytime by pressing ESC or clicking the window close button


## 🗺️ Map requirements
Maps are `.ber` files with the following rules:
- Rectangular shape
- Surrounded by walls (`1`)
- Open spaces represented by `0`
- Exactly one player (P), one monster (`M`), and one exit (`E`)
- Collectibles represented by `C`
- Invalid maps will be rejected at parse time


## 🚀 Features
**1. Map Parsing**
- Validates map structure and content
- Checks for rectangle shape, enclosed walls and correct .ber file extension
- Ensures correct number of players, monsters, exits, and collectibles
- Shows an error message if the map is invalid

**2. Gameplay**
- Use **arrow keys** to move the player
- The enemy moves **opposite to the player’s moves**
- The exit becomes active **after** collecting all rubies
- Smooth graphics with proper draw order:
  - Background
  - Walls
  - Collectibles
  - Player and enemy

**3. Animations**
**- End-game animations:**
  - `Game Over` if the player loses
  - `Player Won` if all collectibles are gathered and the exit is reached
- Animations show the text and player/enemy movement dynamically

**4. Exit Handling**
- Press `ESC` to quit the game
- Click the window `close` button to quit
- Memory is freed correctly


## 🎮 Controls
| Key         | Action        |
| ----------- | ------------- |
| Arrow Up    | Move up       |
| Arrow Down  | Move down     |
| Arrow Left  | Move left     |
| Arrow Right | Move right    |
| ESC         | Quit the game |
| Window X    | Quit the game |



## ⚙️ Requirements
- Linux operating system  
- `cc` compiler  
- `make`
- `MLX` library


## 🛠️ Setup and Usage
```bash

# Clone the repository
git clone git@github.com:Ines-be/so_long.git
cd so_long

# Compile the project
make

# Launch the game
./so_long maps/map.ber

# Clean build files
make fclean