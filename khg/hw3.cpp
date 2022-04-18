#ifndef __cplusplus
#error This file works only with C++
#endif

#include <iostream>
using namespace std;

#pragma warning(disable: 4711 4710 4100 4514 4626 4774 4365 4625 4464 4571 4201 5026 5027 5039)

#define GLM_FORCE_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp> // for glm::to_string()
#include <glm/gtc/type_ptr.hpp> // for glm::value_ptr( )

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma warning(disable: 4711 4710 4100)

#include "./common.c" // shader program을 파일로 저장한 것. file로 저장하고, 읽어오는 함수 const char* loadFile(const char* filename)을 개발

const unsigned int WIN_W = 600; // window size in pixels, (Width, Height)
const unsigned int WIN_H = 600;
const unsigned int WIN_X = 200; // window position in pixels, (X, Y)
const unsigned int WIN_Y = 200;

const char* vertFileName = "19-uniform-tri.vert";
const char* fragFileName = "19-uniform-tri.frag";

GLuint vert = 0; // vertex shader ID number
GLuint frag = 0; // fragment shader ID number
GLuint prog = 0; // shader program ID number

void initFunc(void) {
	const char* vertSource = loadFile(vertFileName);
	const char* fragSource = loadFile(fragFileName);// common.c에 정의된 함수
	char buf[1024]; // mesg buffer
	GLint status; // for glGetShaderiv(), 디버깅을 위해 사용

	// vert: vertex shader
	vert = glCreateShader(GL_VERTEX_SHADER);//return shaderID number
	glShaderSource(vert, 1, &vertSource, nullptr);//vertSource의 파일을 쉐이더에 다운받음
	glCompileShader(vert); // compile to get .OBJ
	//OpenGL 프로그램 전체에 여러개의 shader가 존재 가능
	
	glGetShaderiv(vert, GL_COMPILE_STATUS, &status);//성공하면 1, 실패하면 0
	//컴파일 할 때 status 제공, GL_COMPILE_STATUS->상태를 불러옴
	printf("vert compile status = %s\n", (status == GL_TRUE) ? "true" : "false");//성공하면 true, 실패하면 false
	
	glGetShaderInfoLog(vert, sizeof(buf), nullptr, buf); //vert:어느 쉐이더에 대한 info log냐
	//컴파일 할 때 에러를 로그로 출력, (GLuint shader, GLsizei maxLen, GLsizei* length(real output length), GLchar* infoLog)
	printf("vert log = [%s]\n", buf); // buf에 복사되어 출력
	
	// frag: fragment shader
	frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag, 1, &fragSource, nullptr);
	glCompileShader(frag); // compile to get .OBJ
	glGetShaderiv(frag, GL_COMPILE_STATUS, &status);
	printf("frag compile status = %s\n", (status == GL_TRUE) ? "true" : "false");
	glGetShaderInfoLog(frag, sizeof(buf), nullptr, buf);
	printf("frag log = [%s]\n", buf);

	// prog: program
	prog = glCreateProgram();
	glAttachShader(prog, vert);
	glAttachShader(prog, frag);
	glLinkProgram(prog); // link to get .EXE
	
	glGetProgramiv(prog, GL_LINK_STATUS, &status);//링크에 문제가 생겼을 시
	printf("prog link status = %s\n", (status == GL_TRUE) ? "true" : "false");
	
	glGetProgramInfoLog(prog, sizeof(buf), nullptr, buf);//문제가 생기건 말건 버퍼에 로그 받아오기
	printf("link log = [%s]\n", buf);
	
	glValidateProgram(prog);

	//유효성 검증 함수(더 많은 에러 검사)
	glGetProgramiv(prog, GL_VALIDATE_STATUS, &status);
	printf("prog validate status = %s\n", (status == GL_TRUE) ? "true" : "false");
	//info log 출력
	glGetProgramInfoLog(prog, sizeof(buf), nullptr, buf);
	printf("validate log = [%s]\n", buf);
	fflush(stdout);
	// execute it!
	glUseProgram(prog); // install the program to the GPU
	// done
	free((void*)vertSource);
	free((void*)fragSource);
}

glm::vec4 vertOrg_first[3] = { // first triangle: original position
	{ -0.25F, -0.25F, 0.0F, 1.0F, },
	{ +0.25F, -0.25F, 0.0F, 1.0F, },
	{ -0.25F, +0.25F, 0.0F, 1.0F, },
};
/*
GLfloat vertPos[] = {
	-0.25F, -0.25F, 0.0F, 1.0F,
	+0.25F, -0.25F, 0.0F, 1.0F,
	-0.25F, +0.25F, 0.0F, 1.0F,
};
*/


glm::vec4 vertPos_first[3] = { // first triangle: current position
	// will be calculated !
};
/*
glm::vec4 vertOrg_second[3] = { // second triangle: original position
	{ 0.0F, 0.0F, 0.0F, 1.0F, },
	{ +0.5F, 0.0F, 0.0F, 1.0F, },
	{ 0.0F, +0.5F, 0.0F, 1.0F, },
};

GLfloat vertColor[] = {
	1.0F, 0.0F, 0.0F, 1.0F, //red
	0.0F, 1.0F, 0.0F, 1.0F, //green
	0.0F, 0.0F, 1.0F, 1.0F, //blue
}


glm::vec4 vertPos_second[3] = { // second triangle: current position
	// will be calculated !
};
*/

glm::vec4 vertColor[] = {
	{ 1.0F, 0.0F, 0.0F, 1.0F, }, // red
	{ 0.0F, 1.0F, 0.0F, 1.0F, }, // green
	{ 0.0F, 0.0F, 1.0F, 1.0F, }, // blue
};

glm::vec4 moveCur1 = glm::vec4(0.0F, 0.0F, 0.0F, 0.0F); // movement vector, current time
//uniform variable을 미리 선언한 후 사용
const GLfloat uMoveValue[] = { 0.0F, 0.0F, 0.0F, 0.0F };//GL function으로 작성한 예
glm::vec4 moveCur2 = glm::vec4(0.0F, 0.0F, 0.0F, 0.0F); // movement vector, current time

float theta = 0.0F;
const float theta_step = 0.001F; // radians. must be tuned for your system
float step_x = 0.0000F;
float step_y = 0.0000F;

void updateFunc(void) {
	theta += theta_step; // radian
	
	moveCur1[0] += step_x;
	moveCur1[1] += step_y;

	// update the position
	for (int i = 0; i < 3; i++) { // for each vertex,
		vertPos_first[i].x = vertOrg_first[i].x * cosf(theta) - vertOrg_first[i].y * sinf(theta);
		vertPos_first[i].y = vertOrg_first[i].x * sinf(theta) + vertOrg_first[i].y * cosf(theta);
		vertPos_first[i].z = vertOrg_first[i].z;
		vertPos_first[i].w = vertOrg_first[i].w;
	}
}

//void updateFunc_2(void) {
//	theta += theta_step; // radian
//
//	// update the position
//	for (int i = 0; i < 3; i++) { // for each vertex,
//		vertPos_second[i].x = vertOrg_second[i].x * cosf(theta) - vertOrg_second[i].y * sinf(theta);
//		vertPos_second[i].y = vertOrg_second[i].x * sinf(theta) + vertOrg_second[i].y * cosf(theta);
//		vertPos_second[i].z = vertOrg_second[i].z;
//		vertPos_second[i].w = vertOrg_second[i].w;
//	}
//}

void drawFunc(void) {
	// clear in gray color
	glClear(GL_COLOR_BUFFER_BIT);// 화면 지우기
	// provide the vertex attributes
	GLuint locPos = glGetAttribLocation(prog, "aPos"); // .vert파일에 있는 aPos 사용 -> in vec4 aPos
	glEnableVertexAttribArray(locPos);
	glVertexAttribPointer(locPos, 4, GL_FLOAT, GL_FALSE, 0, glm::value_ptr(vertPos_first[0]));

	// provide the color attributes
	GLuint locColor = glGetAttribLocation(prog, "aColor");// .vert파일에 있는 aColor 사용 -> in vec4 aColor
	glEnableVertexAttribArray(locColor);//turn on the vertex array
	//<-> void glDisableVertexAttribArray(GLuint inidex)
	glVertexAttribPointer(locColor, 4, GL_FLOAT, GL_FALSE, 0, glm::value_ptr(vertColor[0]));
	//(glUint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer)
	//user provides an "array" -> pointer
	//size: 1,2,3,4 -> float, vec2, vec3, vec4 in shader program
	//type: GL_INT, GL_FLOAT, ...
	//normalized: usually GL_FALSE
	//stride: usually 0
	//pointer: start address of the array
	

	// draw the triangle
	GLuint locMove = glGetUniformLocation(prog, "uMove"); // vert파일에 있는 uMove 사용 -> uniform vec4 uMove;
	//uniform register의 이름을 알려주고 그 위치를 가져오는 함수
	//(GLuint prog, const GLchar* name)
	//name: uniform variable name
	//returns the location index of the specified uniform variable
	//return -1 for failure
	glUniform4fv(locMove, 1, glm::value_ptr(moveCur1));
	//Uniform variable value를 설정, 모든 버텍스 쉐이더가 이 값을 공유함
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//glVertexAttribPointer(locPos, 4, GL_FLOAT, GL_FALSE, 0, glm::value_ptr(vertPos_second[0])); 이렇게 하면 안됨
	glUniform4fv(locMove, 1, glm::value_ptr(glm::vec4(0.0F, 0.0F, 0.0F, 0.0F))); //movement만 수정해서 같은 삼각형을 그리는 것
	//두 번째 삼각형 그리기
	glDrawArrays(GL_TRIANGLES, 0, 3);//(GLenum mode, GLint first, GLsizei count)
	//trigger the graphics pipeline to get the result
	//mode = GL_POINTS, GL_LINES, GL_TRIANGLES
	//first: start index in your attribute arrays
	//count: number of vertices in your attribute arrays
	
	// done
	glFinish();//finish all OpenGL calls
}

void refreshFunc(GLFWwindow* window) { //define refresh function
	// refresh
	drawFunc();
	// GLFW action
	glfwSwapBuffers(window);
}

void keyFunc(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//target window, key is the keyboard key that is pressed or released
	//scancode는 키의 시스템별 스캔 코드
	//action: GLFW_PRESS, GLFW_RELEASE, GLFW_REPEAT
	//mod: modifier keys, GLFW_MOD_SHIFT, CONTROL, ALT, SUPER
	//ex) CTRL + SHIFT + 'C'를 누르면 key = 'C', mods = GLFW_MOD_SHIFT | GLFW_MOD_CONTROL, action = GLFW_PRESS -> 키를 떼면 release 이벤트도 발생
	switch (key) {
	case GLFW_KEY_ESCAPE:
		if (action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GL_TRUE);
			//해당 윈도우의 close flag를 설정
		}
		break;
	case GLFW_KEY_R:
		if (action == GLFW_PRESS) {
			theta = 0.0F;
		}
		break;
	case GLFW_KEY_A:
		if (action == GLFW_PRESS)
			step_x = -0.001F;
		else
			step_x = 0.0F;
		break;
	case GLFW_KEY_S:
		if (action == GLFW_PRESS)
			step_y = -0.001F;
		else
			step_y = 0.0F;
		break;
	case GLFW_KEY_D:
		if (action == GLFW_PRESS)
			step_x = 0.001F;
		else
			step_x = 0.0F;
		break;
	case GLFW_KEY_W:
		if (action == GLFW_PRESS)
			step_y = 0.001F;
		else
			step_y = 0.0F;
		break;
	}
}

int main(int argc, char* argv[]) {
	const char* basename = getBaseName(argv[0]);
	// start GLFW & GLEW
	glfwInit(); // initialization, return GLFW_TRUE if successful, GLFW_FALSE if any error
	GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, basename, NULL, nullptr); //width, heigth, title, monitor, share / 윈도우 및 OpenGL context 생성
	//context = current OpenGL state + internal variables
	//mointer는 풀 스크린 모드 여부를 결정, NULL이면 창모드, glfwGetPrimaryMonitor()이면 전체화면
	//share는 context를 공유할 이미 존재하는 윈도우 or NULL
	glfwSetWindowPos(window, WIN_X, WIN_Y);
	glfwMakeContextCurrent(window); //앞으로 오는 모든 OpenGL function calls를 window로 보냄
	glewInit();
	
	// prepare
	glfwSetWindowRefreshCallback(window, refreshFunc);
	//refresh callback funtion 등록, func가 NULL이면 현재 callback 함수가 지워짐
	glfwSetKeyCallback(window, keyFunc);//set the key callback function. func가 NULL이면 현재 콜백 함수가 지워짐
	glClearColor(0.5F, 0.5F, 0.5F, 1.0F);//set clear values for the color buffers
	// main loop
	initFunc();
	while (!glfwWindowShouldClose(window)) { // X를 누르면 TRUE반환 -> 종료
		//animation loop
		updateFunc();
		//updateFunc_2();
		
		drawFunc();
		// GLFW actions
		glfwSwapBuffers(window);//updated graphics results to the window
		glfwPollEvents();//check events
	}
	// done
	glfwTerminate(); //termination, destroy all remaining windows and resources
	return 0;
}
