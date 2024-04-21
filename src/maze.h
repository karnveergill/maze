#ifndef MAZE_H
#define MAZE_H

#include <SDL.h>

class Maze
{
public:
    Maze(SDL_Window* window,
         SDL_Renderer* renderer);

    /**
     * @brief Destructor frees up window and renderer 
    */
    ~Maze() {}

private:
};

#endif // MAZE_H