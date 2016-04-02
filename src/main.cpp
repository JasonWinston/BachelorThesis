#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include "glm/ext.hpp"
#include <stdio.h>
#include <glsl_shader.h>
#include <fps_camera.h>
#include "custom_camera.h"
#include <vector>
#include <skybox.h>
#include "water_grid.h"

#define OPENGL_MAJOR        2
#define OPENGL_MINOR        1
#define WINDOW_WIDTH        800
#define WINDOW_HEIGHT       600
#define WINDOW_TITLE        "Ocean"
#define SUCCESS             1
#define ERROR               -1

bool gModernShaders = false;

int initGLFW(int openGLMajor, int openGLMinor);

int openWindow(int windowWidth, int windowHeight, const char *windowTitle);

int initGLEW();

int setupScene();

int runSimulationLoop();

void updateScene(float timeElapsed);

void centerTheWindow();

GLFWwindow *window;
FPSCamera fpsCamera;
CCustomCamera camera;

using namespace glm;
using namespace entities;
using namespace std;

int main(void) {
    cout << "1\n";
    assert (initGLFW(OPENGL_MAJOR, OPENGL_MINOR) == SUCCESS);
    cout << "2\n";
    assert (openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE) == SUCCESS);
    cout << "3\n";
    assert (initGLEW() == SUCCESS);
    cout << "4\n";
    assert (setupScene() == SUCCESS);
    cout << "5\n";
    runSimulationLoop();
	cout << "runSimulationLoopEnded\n";
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

int initGLFW(int openGLMajor, int openGLMinor) {

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return ERROR;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, openGLMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, openGLMinor);

    return SUCCESS;
}

// Open a window and create its OpenGL context
int openWindow(int windowWidth, int windowHeight, const char *windowTitle) {

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL,
                              NULL);

    if (window == NULL) {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        return ERROR;
    }

    glfwMakeContextCurrent(window);

    return SUCCESS;
}

int initGLEW() {
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        return ERROR;
    }

    if(GLEW_VERSION_3_3) {
        gModernShaders = true;
        cout << "Loading modern shaders: version 330 core.\n";
    }
    else {
        cout << "Loading old shaders: version 120.\n";
    }

    if(!GL_ARB_depth_texture)
    {
        cout << "GL_ARB_depth_texture not supported!\n";
    }

    if(!GL_FRAMEBUFFER_EXT)
    {
        cout <<"GL_EXT_framebuffer_object not supported!\r\n";
    }

    return SUCCESS;
}

int setupScene() {
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(window, 0, 0);
    centerTheWindow();
    return SUCCESS;
}

int runSimulationLoop() {
    int sceneSize = 32;
	cout << "6\n";
    std::vector<const GLchar *> facesNames({
                                                   "./res/textures"
                                                           "/skybox/sor_sea/front.jpg",
                                                   "./res/textures"
                                                           "/skybox/sor_sea/back.jpg",
                                                   "./res/textures"
                                                           "/skybox/sor_sea/top.jpg",
                                                   "./res/textures"
                                                           "/skybox/sor_sea/bottom.jpg",
                                                   "./res/textures"
                                                           "/skybox/sor_sea/right.jpg",
                                                   "./res/textures"
                                                           "/skybox/sor_sea/left.jpg"});
cout << "7\n";
    CSkybox skybox(sceneSize, &facesNames, gModernShaders);
cout << "8\n";
    CWaterGrid water(sceneSize, sceneSize, sceneSize, glm::vec2
            (-sceneSize / 2, -sceneSize / 2), gModernShaders);
cout << "9\n";
    water.setSkyboxCubemapId(skybox.getCubemapId());
cout << "10\n";
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    double lastTime = glfwGetTime();

    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update scene
        double thisTime = glfwGetTime();
        double timeLapsed = (float) (thisTime - lastTime);

        updateScene(timeLapsed);
        water.updateTime(thisTime);
        lastTime = thisTime;

        // Draw scene
        mat4 projection = camera.getProjectionMatrix();
        mat4 view = camera.getViewMatrix();
        mat4 vp = projection * view;

//        std::cout << glm::to_string(camera.getPosition()) << std::endl;

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        skybox.setCameraPosition(camera.getPosition());
        skybox.render(&vp[0][0]);

//        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        water.setCameraPosition(camera.getPosition());;
        water.render(&vp[0][0]);

        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0);

    return SUCCESS;
}

void updateScene(float timeElapsed) {

    // Mouse
    const float mouseSensitivity = 0.1f;
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);
//    fpsCamera.changeAzimuth(mouseSensitivity * (float) mouseY,
//                            mouseSensitivity * (float) mouseX);
    camera.updateViewingAngles(mouseX, mouseY, timeElapsed);
    glfwSetCursorPos(window, 0, 0);

    const float moveSpeed = 10.0;

    if (glfwGetKey(window, 'W')) {
//        fpsCamera.moveForward(timeElapsed * moveSpeed);
        camera.moveForward(timeElapsed);
    } else if (glfwGetKey(window, 'S')) {
//        fpsCamera.moveBackward(timeElapsed * moveSpeed);
        camera.moveBackward(timeElapsed);
    }

    if (glfwGetKey(window, 'A')) {
//        fpsCamera.moveLeft(timeElapsed * moveSpeed);
        camera.moveLeft(timeElapsed);
    } else if (glfwGetKey(window, 'D')) {
//        fpsCamera.moveRight(timeElapsed * moveSpeed);
        camera.moveRight(timeElapsed);
    }

    if (glfwGetKey(window, 'Z')) {
//        fpsCamera.moveUp(timeElapsed * moveSpeed);
        camera.moveUp(timeElapsed);
    } else if (glfwGetKey(window, 'X')) {
//        fpsCamera.moveDown(timeElapsed * moveSpeed);
        camera.moveDown(timeElapsed);
    }
}

void centerTheWindow() {
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    glfwSetWindowPos(window, (mode->width - WINDOW_WIDTH) / 2, (mode->height -
                                                                WINDOW_HEIGHT) /
                                                               2);
}
