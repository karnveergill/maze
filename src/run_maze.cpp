#include "maze.h"
#include <string>
#include "version.h"

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

    return 0;
}