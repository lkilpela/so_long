<h1 align="center">
	<img src="https://github.com/lkilpela/42-project-badges/blob/main/badges/so_longe.png">
</h1>

<p align="center">
	<b><i>Build a very small 2D game</i></b><br>
</p>

<p align="center">
    <img alt="score" src="https://img.shields.io/badge/score-100%2F100-brightgreen" />
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


## <img src="./textures/player.png" alt="Player Image"> About The Project

`so_long` is a 2D game project developed as part of the Hive Helsinki curriculum. The goal of this project is to create a simple game using the MLX42 library, a simple window management and graphics library.

In the game, the player collects collectibles in a map and reach the exit. The map is a grid, and the player can only move one square at a time. The game counts the number of moves the player makes.

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
- `MLX42` library. You can find it [here](https://github.com/codam-coding-college/MLX42)
- `libft` library. 

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

> **Peer 1**: "The project looks good and I like the choice of graphics. Lumi was able to explain how the code works, and I tested the functionality and edge cases according to the eval form. There are some discrepancies between the subject document and the eval form, for example subject wants Error being followed by a newline before the error message, but the eval form does not require it. Also according to the eval form the exit should only work after all collectibles have been collected, but it doesn't state that in the subject. Therefore I judged that it's up to interpretation and either choice can be defended. Good luck in the next evaluations!"

> **Peer 2**: "Lumi's so long was a great learning experience! She was able to explain her code and it was structured in a very easy to follow way. It's great for me to see a fully functional version since I'm working on this project myself and she even helped clarify some misconceptions that I had about the mlx library. I tried to break it but it passed every one of my tests. Overall a great job! There was a small point regarding being able to exit without obtaining all the collectibles but it was not specified clearly in the subject. She was able to defend her logic successfully and even though you can exit without all the collectibles it is a pass in my book after scanning through the subject looking for something that said otherwise. Really visually appealing project and the game runs smoothly. Thanks for taking the time to explain it to me and good luck with the next evals!"

> **Peer 3**: "Lumi's project was very cleanly written and she did a great job explaining it. She had very diverse test maps and test cases prepared for the evaluation. The program also passed any test I could come up with to test it and even in those cases had no leaks. Great job!"

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/lkilpela/so_long/blob/main/docs/LICENSE) file for details.

