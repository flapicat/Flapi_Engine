#include "Camera.h"
#include <iostream>

namespace Engine
{
    glm::mat4 Camera::GetViewMatrix()
    {
        return glm::lookAt(Position, Position + Front, Up);
    }

    void Camera::update()
    {
        if (zoom == true)
            Zoom = 1.0f;
        if (zoom == false)
            Zoom = ZOOM;
    }

    void Camera::ProcessKeyboard(Camera_Action action, float deltaTime)
    {
        float velocity = MovementSpeed * deltaTime;
        if (action == FORWARD)
            Position += Front * velocity;
        if (action == BACKWARD)
            Position -= Front * velocity;
        if (action == LEFT)
            Position -= Right * velocity;
        if (action == RIGHT)
            Position += Right * velocity;
        if (action == UP)
            Position += Up * velocity;
        if (action == DOWN)
            Position -= Up * velocity;
        if (action == FAST)
            MovementSpeed = 10.0f;
        else
            MovementSpeed = SPEED;
    }

    void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw += xoffset;
        Pitch += yoffset;

        if (constrainPitch)
        {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        updateCameraVectors();
    }

    void Camera::ProcessMouseScroll(float yoffset)
    {
        Zoom -= (float)yoffset;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f;
    }

    void Camera::updateCameraVectors()
    {
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        Right = glm::normalize(glm::cross(Front, WorldUp));
        Up = glm::normalize(glm::cross(Right, Front));
    }
}