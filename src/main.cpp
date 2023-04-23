#include "GLAD/khrplatform.h"
#include "GLAD/glad.h"
#include "GLFW/glfw3.h"


#include <iostream>
#include <ctime>

// settings
unsigned int SCREEN_WIDTH = 1000;
unsigned int SCREEN_HEIGHT = 600;

// window adjustments
void framebuffer_size_callback(GLFWwindow* box, int width, int height);
void process_inputs(GLFWwindow* box);

// shader sources
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource1 = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

const char *fragmentShaderSource2 = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.0f, 1.0f, 1.0f);\n"
    "}\n\0";

int main()
{	
	// boilerplate for glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* box = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "title test", NULL, NULL);

	if(!box){
		std::cout << "Failed to load GLFW\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(box);
	glfwSetFramebufferSizeCallback(box, framebuffer_size_callback);

	// initialize glad	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}    


	/////////////////////
	/////////////////////
	/////////////////////
	/////////////////////
	/////////////////////
	// opengl boilerPlate

	// build and compile our shader program
	// ------------------------------------
	// vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader1
	unsigned int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
	glCompileShader(fragmentShader1);
	// check for shader compile errors
	glGetShaderiv(fragmentShader1, GL_COMPILE_STATUS, &success);
	if (!success)	{
		glGetShaderInfoLog(fragmentShader1, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader2
	unsigned int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
	glCompileShader(fragmentShader2);
	// check for shader compile errors
	glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// link shaders
	unsigned int shaderProgram1 = glCreateProgram();
	unsigned int shaderProgram2 = glCreateProgram();

	// 1st shader
	glAttachShader(shaderProgram1, vertexShader);
	glAttachShader(shaderProgram1, fragmentShader1);
	glLinkProgram(shaderProgram1);


	// 2nd shader
	glAttachShader(shaderProgram2, vertexShader);
	glAttachShader(shaderProgram2, fragmentShader2);
	glLinkProgram(shaderProgram2);
	// check for linking errors
	glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	// check for linking errors
	glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader1);
	glDeleteShader(fragmentShader2);





	/*
	// setup vertex data
	float vertices[] {
		 ORIGINAL 2 TRIANGLES
		// 1st triangle
		-0.5f, -0.5f, 0.0f,	// bot left
		0.5f, -0.5f, 0.0f,	// bot right
		0.0f, 0.5f, 0.0f,	// top
		// 2nd triangle
		-0.5f, -0.5f, 0.0f, 	// bot left
		-0.5f, 0.5f, 0.0f,	// top left
		0.0f, 0.5f, 0.0f	// top
		*/
		/*	example code
		   0.5f,  0.5f, 0.0f,  // top right
		   0.5f, -0.5f, 0.0f,  // bottom right
		   -0.5f, -0.5f, 0.0f,  // bottom left
		   -0.5f,  0.5f, 0.0f	// top left
		*/

		/* working 1
		-0.5f, -0.5f, 0.0f,	// bot left
		0.5f, -0.5f, 0.0f,	// bot right
		0.0f, 0.5f, 0.0f,	// top
		-0.5f, 0.5f, 0.0f,	// top left
	

		// for exercise 1
		// 1sttriangle
		-0.7f, -0.7f, 0.0f,	// bot left
		-0.4f, 0.4f, 0.0f,	// top
		-0.1f, -0.7f, 0.0f,	// bot right
		// 2nd triangle	
		0.7f, -0.7f, 0.0f,	// bot right
		0.4f, 0.4f, 0.0f,	// top
		0.1f, -0.7f, 0.0f	// bot left
	};*/
	// for exercise 2
	float triangle1[] = {	
		// 1sttriangle
		-0.7f, -0.7f, 0.0f,	// bot left
		-0.4f, 0.4f, 0.0f,	// top
		-0.1f, -0.7f, 0.0f,	// bot right
	};
	float triangle2[] = {	
		// 2nd triangle	
		0.7f, -0.7f, 0.0f,	// bot right
		0.4f, 0.4f, 0.0f,	// top
		0.1f, -0.7f, 0.0f	// bot left
	};

	unsigned int indices[] {
		0, 1, 2,	// 1st triangle workign1
		//0, 3, 2	// 2nd triangel wokring1
		3, 4, 5		// separate triangel for exercise1
	};

	// configure vertex attributes
	// generate vertex buffer object and vertex array object
	/*
	unsigned int VBO, VAO;	
	glGenVertexArrays(1, &VAO);

	glGenBuffers(1, &VBO);
	unsigned int EBO;
	glGenBuffers(1, &EBO);


	// bind vertex array object first
	glBindVertexArray(VAO);

	// 2nd "copy" or bind the vertices array in a vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);	

	// 3rd "copy" or bind the index array in an element buffer 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4th set the vertex attribute pointers
	glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	
		// we can now unset the buffers to 0 
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	*/

	// for exercise 2
	unsigned int VBOs[2], VAOs[2];
	glGenVertexArrays(2, VAOs);
	glGenBuffers(2, VBOs);

	// first triangle setup	
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1), triangle1, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// 2nd trinagle setup
	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle2), triangle2, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);



	// uncomment this call to draw in wireframe polygons.
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



	// loop
	while(!glfwWindowShouldClose(box)){
		
		// inputs
		process_inputs(box);
		
		// render loop
		glClearColor(0.2f, 0.4f, 0.1f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT);


		// use it now
		// first triangle
		glUseProgram(shaderProgram1);

		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// 2nd triangle
		glUseProgram(shaderProgram2);

		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		


		glfwSwapBuffers(box);
		glfwPollEvents();
	}


	glfwDestroyWindow(box);
	glfwTerminate();
	return 0;

}



void framebuffer_size_callback(GLFWwindow* box, int width, int height){
	glViewport(0, 0, width, height);
}
void process_inputs(GLFWwindow* box){
	if(glfwGetKey(box, GLFW_KEY_ESCAPE) == GLFW_PRESS) //
		glfwSetWindowShouldClose(box, true);
}
