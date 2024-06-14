# 42 so_long

Welcome to my so_long project! This project is part of the 42 curriculum, aimed at creating a simple 2D game application using the MiniLibX library. The goal is to develop a small game that demonstrates basic graphics programming concepts.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Controls](#game-controls)
- [Examples](#examples)
- [Contributing](#contributing)


## Introduction

The project is a simple 2D game developed using the MiniLibX library. The player controls a character that can move around a map, collect items, and reach an exit to complete the level. This project helps students understand graphics programming and event handling.

## Features

- 2D graphics rendering using MiniLibX
- Player movement and collision detection
- Collectible items
- Game map with walls and an exit
- Basic event handling (keyboard input)

## Installation

To install and compile the So Long project, follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/BorisMichaelRandebrock/so_long_bonus.git
   cd so_long
   ```

2. Compile the project:
   ```sh
   make
   ```

3. Run the game:
   ```sh
   ./so_long maps/map.ber
   ```

## Usage

Once you have compiled and run the game, you can start playing by using the keyboard to control the character. The objective is to collect all items and reach the exit.

## Game Controls

- `W` or `Up Arrow`: Move up
- `A` or `Left Arrow`: Move left
- `S` or `Down Arrow`: Move down
- `D` or `Right Arrow`: Move right
- `ESC`: Exit the game

## Examples

Here are a few examples of how to use the So Long project:

```sh
# Run the game with a specific map
./solong maps/map1.ber

# Run the game with another map
./solong maps/map2.ber
```

## Contributing

Contributions are welcome! If you would like to contribute to this project, please fork the repository and create a pull request with your changes. Make sure to follow the coding standards and include relevant tests with your contributions.

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes.
4. Push to your branch.
5. Create a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
