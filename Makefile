
output: objects
	g++ .\obj\main.o .\obj\glad.o .\lib\GLFW\libglfw3.a 	\
		-lopengl32 -lgdi32 				\
		-o .\output.exe
	.\output.exe

objects:
	g++ -c .\src\main.cpp 			\
		-Iinclude 			\
		-o .\obj\main.o 		
	g++ -c .\src\glad.c			\
		-Iinclude			\
		-o .\obj\glad.o
	




clean:
	del /Q /S .\obj\\*.o
	del /Q /S .\output.exe
	
