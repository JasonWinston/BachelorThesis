// author: dybisz

#include "glfw_io.h"

bool    CGLFWInputOutput::_rightButtonPressed = false;
double  CGLFWInputOutput::_mouseX = 0;
double  CGLFWInputOutput::_mouseY = 0;
vec2    CGLFWInputOutput::_intersectionCoordinates(-1.0, -1.0);
bool    CGLFWInputOutput::_intersectionRequested = false;

CGLFWInputOutput::CGLFWInputOutput(GLFWwindow *window)
        : _window(window){

}

void CGLFWInputOutput::setCamera(CCustomCamera *camera) {
    _camera = camera;
}

void CGLFWInputOutput::key_callback(GLFWwindow *window,
                                    int key,
                                    int scancode,
                                    int action,
                                    int mods) {

}

void CGLFWInputOutput::cursor_position_callback(GLFWwindow *window, double xpos,
                                                double ypos) {

}

void CGLFWInputOutput::updateCamera(float deltaTime) {
    _handleMouse(deltaTime);
    _handleKeyboard(deltaTime);
}

void CGLFWInputOutput::mouse_button_callback(GLFWwindow *window, int button,
                                             int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS) {
        glfwGetCursorPos(window, &_mouseX, &_mouseY);
        _rightButtonPressed = true;
    } else if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE) {
        _rightButtonPressed = false;
    }

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double x;
        double y;
        glfwGetCursorPos(window, &x, &y);
        _intersectionCoordinates.x = x;
        _intersectionCoordinates.y = y;
        _intersectionRequested = true;
    }

    TwEventMouseButtonGLFW(window, button, action, mods);
}

void CGLFWInputOutput::setIntersectionRequested(bool intersectionRequested) {
    _intersectionRequested = intersectionRequested;
}

bool CGLFWInputOutput::isIntersectionRequested() {
    return _intersectionRequested;
}

vec2 CGLFWInputOutput::getIntersectionCoordinates() {
    return _intersectionCoordinates;
}

void CGLFWInputOutput::_handleMouse(double deltaTime) {
    if (_rightButtonPressed) {
        double mouseX, mouseY;
        glfwGetCursorPos(_window, &mouseX, &mouseY);
        _camera->updateViewingAngles(_mouseX - mouseX, _mouseY - mouseY,
                                     deltaTime);
        _mouseX = mouseX;
        _mouseY = mouseY;
    }
}

void CGLFWInputOutput::_handleKeyboard(double deltaTime) {
    if (glfwGetKey(_window, 'W')) {
        _camera->moveForward(deltaTime);
    } else if (glfwGetKey(_window, 'S')) {
        _camera->moveBackward(deltaTime);
    }

    if (glfwGetKey(_window, 'A')) {
        _camera->moveLeft(deltaTime);
    } else if (glfwGetKey(_window, 'D')) {
        _camera->moveRight(deltaTime);
    }

    if (glfwGetKey(_window, 'Z')) {
        _camera->moveUp(deltaTime);
    } else if (glfwGetKey(_window, 'X')) {
        _camera->moveDown(deltaTime);
    }
}