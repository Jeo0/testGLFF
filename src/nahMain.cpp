
/* steps in compiling
 *
 * 1. g++ -c main.cpp -IDepend
 * 2. g++ main.o .\Depend\libglfw3.a -lopengl32 -lgdi32
 * 3. run the executable
 *
 */

// if using the dynamic library
// #define GLFW_DLL


// can also be like this IF -IDepend flag is included in the compiler options
// #include "Depend/glfw3.h"
// OR
// if -IDepend flag is omitted, u must use this at compilation
// #include "Depend/glfw3.h" 



// edit the comment above is depreciated, as I transformed the whole project (file structure + main.cpp) into something more managable
// this is depreciated
#include "GLFW/glfw3.h"



int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", glfwGetPrimaryMonitor(), NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here 
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers 
        glfwSwapBuffers(window);

        // Poll for and process events 
        glfwPollEvents();
    }

    glfwTerminate();
    //glfwDestroyWindow(window);
    return 0;
}


