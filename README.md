<h1 align="center">
	<img src="./textures/player.png" alt="Player Image">
	SO_LONG
</h1>

<p align="center">
	<b><i>Build a very small 2D game</i></b><br>
</p>

<p align="center">
    <img alt="score" src="https://img.shields.io/badge/score-0%2F100-brightgreen" />
<p align="center">
    <img alt="solo" src="https://img.shields.io/badge/solo-yellow" />
    <img alt="estimated time" src="https://img.shields.io/badge/estimation-60%20hours-blue" />
    <img alt="XP earned" src="https://img.shields.io/badge/XP-1000-orange" />
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/lkilpela/so_long?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/lkilpela/so_long?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/lkilpela/so_long?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/lkilpela/so_long?color=green" />
</p>

## 🎮 About The Project

`so_long` is a 2D game project developed as part of the Hive Helsinki curriculum. The goal of this project is to create a simple game using the MLX42 library, a simple window management and graphics library.

In the game, the player must collect all collectibles in a map and reach the exit. The map is a grid, and the player can only move one square at a time. The game counts the number of moves the player makes, encouraging the player to complete the game in as few moves as possible.

This project was completed as a **solo project**. It provided an opportunity to learn about graphics programming, game logic, and working with external libraries in C.

![Game Screenshot](https://github.com/lkilpela/so_long/blob/main/docs/game_screenshot.png)

### ⭐ Bonuses

- No bonuses were implemented in this project.

### 🎨 Assets

The assets used in this project were taken from:

- **Simplified Platformer Pack**: [Link to Asset](https://www.kenney.nl/assets/simplified-platformer-pack)

## 🏁 Getting Started

### Prerequisites

- The `Makefile` in this project uses the `-framework Cocoa -framework OpenGL -framework IOKit` flags, which are specific to macOS. If you're using a different operating system, you might need to modify the `Makefile` to use the appropriate flags for your system.
- `gcc` or `clang`
- `make`
- MLX42 library. You can find it [here](https://github.com/codam-coding-college/MLX42)
- libft library. 

### 🕹️ How to Play

- Use `W` or `↑` to move up, `A` or `←` to move left, `S` or `↓` to move down, and `D` or `→` to move right.
- Collect all the collectibles in the map.
- Reach the exit once all collectibles have been collected.

### 🛠️ Installation & Setup

1. Clone the repository: 
```
git clone https://github.com/lkilpela/so_long.git
```
2. Navigate into the project directory: `cd so_long`
3. Compile the project: `make`
4. Run the game: `./so_long map_file/map1.ber`

### 🗺️ Map Format

#### Valid Map

The game map is a `.ber` file with the following format:

- `1` represents a wall.
- `0` represents an empty space.
- `C` represents a collectible.
- `E` represents the exit.
- `P` represents the player.

#### Invalid Map

Here are some conditions that can make a map format invalid:
1. The map is not surrounded by walls (represented by '1').
2. The map contains characters other than the predefined ones (for example, 'P', 'E', 'C', '0', '1').
3. The map does not contain a player ('P') or exit point ('E').
4. The map contains more than one player or exit point.
5. The map contains empty line.
6. The map does not have valid path.
7. The map does not have .ber extension

## 📝 Evaluation Requirements

The `so_long` project was evaluated based on the following criteria:

1. **Game Logic**: The game must correctly implement the required logic, including player movement, collectible gathering, and exiting the game.

2. **Graphics**: The game must use the MiniLibX library or MLX42 to create a graphical interface.

3. **Performance**: The game must run smoothly without any performance issues or memory leaks.

4. **Code Quality**: The code must be clear, concise, and efficient. It should be well-organized and easy to read.

5. **Compiling**: The project must compile without any errors or warnings.

### 🧑‍💻 Peer Evaluations (3/3)

Here are some of the comments received during the peer evaluation of the `so_long` project:

> **Peer 1**: "..."

> **Peer 2**: "..."

> **Peer 3**: "..."

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/lkilpela/so_long/blob/main/docs/LICENSE) file for details.

