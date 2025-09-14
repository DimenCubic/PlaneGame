# Plane Game

**Plane Game** is a simple airplane shooting game developed in C++ using the EasyX graphics library.

## Project Structure

- `material/`  
  - `Background.jpg`: Background image  
  - `Bullet.jpg`: Bullet image  
  - `Enemy.jpg`: Enemy plane image  
  - `Plane.jpg`: Player plane image  
- `PLaneGame.cpp`: Main source file containing game logic  
- `README.md`: Project documentation

## Features

- Player controls a plane using keyboard input
- Bullets can be fired with the space key
- Bullets move upward and detect collision with enemies
- Enemies randomly spawn and move downward
- Collision detection between bullets and enemies is implemented

## Controls

- `W` / `↑` : Move up  
- `S` / `↓` : Move down  
- `A` / `←` : Move left  
- `D` / `→` : Move right  
- `Spacebar` : Shoot bullet

## How to Run

1. Open `PLaneGame.sln` using Visual Studio  
2. Ensure the `material` folder and image files are in the same directory as the executable  
3. Build and run the project  
4. Use the controls to play and shoot enemies

## Development Environment

- **Language**: C++  
- **Graphics Library**: EasyX (`graphics.h` required)  
- **Platform**: Windows  
- **IDE**: Visual Studio

## Possible Improvements

- Add scoring system  
- Introduce multiple types of enemies and difficulty levels  
- Implement bullet firing cooldown or rate limit  
- Add game-over condition  
- Add sound effects and background music

