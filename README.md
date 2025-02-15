# So Long

A 2D game where the player navigates through a map, collecting items and reaching the exit. The game is built using the MiniLibX library for graphics rendering.

## Features

- Navigate through a grid-based map.
- Collect all items to unlock the exit.
- Simple controls for movement.
- Bonus version with additional features.

## Prerequisites

- **GCC**: Ensure you have GCC installed for compiling the project.
- **MiniLibX**: Required for graphics rendering.
- **Libft**: Custom library for additional functions.
- **ft_printf**: Custom printf implementation.

## Setup

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/jguigli/so_long.git
   cd so_long
   ```

2. **Compile the Project:**

   - For the standard version:

     ```bash
     make
     ```

   - For the bonus version:

     ```bash
     make bonus
     ```

3. **Clean Up:**

   - To remove object files:

     ```bash
     make clean
     ```

   - To remove all compiled files:

     ```bash
     make fclean
     ```

   - To recompile the project:

     ```bash
     make re
     ```

## Usage

1. **Run the Game:**

   - Standard version:

     ```bash
     ./so_long maps/map.ber
     ```

   - Bonus version:

     ```bash
     ./so_long_bonus maps/map.ber
     ```

2. **Controls:**

   - `W`: Move up
   - `A`: Move left
   - `S`: Move down
   - `D`: Move right
   - `ESC`: Exit the game

3. **Objective:**

   - Collect all the chests (`C`) and reach the exit (`E`) to win the game.

## Map Requirements

- The map file should have a `.ber` extension.
- The map must be surrounded by walls (`1`).
- Must contain at least one player (`P`), one exit (`E`), and one collectible (`C`).


## Acknowledgments

- [42 School](https://www.42.fr/) for the project inspiration.
- [MiniLibX](https://github.com/42Paris/minilibx-linux) for the graphics library.