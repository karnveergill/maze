#include "maze.h"
#include <string>
#include "version.h"
#include <SDL.h>

///////////////////////////////////////////////////////////////////////////////
// Constants //////////////////////////////////////////////////////////////////

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

///////////////////////////////////////////////////////////////////////////////
// Application Entry///////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    // Set application version 
    static const std::string app_version = "v" 
                                           + std::to_string(PROJECT_VERSION_MAJOR) + "." 
                                           + std::to_string(PROJECT_VERSION_MINOR) + "." 
                                           + std::to_string(PROJECT_VERSION_PATCH); 

    // Handle application arguments 
    for(int i = 1; i < argc; i++)
    {
        // Print version and leave application
        if(std::string(argv[i]) == "--version" || std::string(argv[i]) == "-v")
        {
            printf("maze : %s\n", app_version.c_str());
            return 0; 
        }
    }
    printf("maze : %s\n", app_version.c_str());

    // Create SDL window to display maze
    static const std::string window_title = "Maze "  + app_version;
    SDL_Window* window = SDL_CreateWindow(window_title.c_str(), 
                                          SDL_WINDOWPOS_CENTERED, 
                                          SDL_WINDOWPOS_CENTERED, 
                                          WINDOW_WIDTH, 
                                          WINDOW_HEIGHT, 
                                          SDL_WINDOW_SHOWN);

    // Create renderer
    static const int USE_FIRST_AVAILABLE_RENDERING_DRIVER = -1;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 
                                                USE_FIRST_AVAILABLE_RENDERING_DRIVER,
                                                SDL_RENDERER_ACCELERATED);
                                                
    // Destroy SDL assets
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}