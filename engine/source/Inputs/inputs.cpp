#include "inputs.h"
#include <GLFW/glfw3.h>
#include <iostream>

namespace Fighters
{
    Input::Input(GLFWwindow *window)
    {
        this->m_window = window;
    };

    void Input::setWindow(GLFWwindow *window)
    {
        this->m_window = window;
    };

    GLFWwindow* Input::getWindow() const
    {
        return this->m_window;
    };

    void InputKeyboard::setKeyUp(int keycode)
    {
        this->KEY_UP = keycode;
    };

    void InputKeyboard::setKeyDown(int keycode)
    {
        this->KEY_DOWN = keycode;
    };

    void InputKeyboard::setKeyLeft(int keycode)
    {
        this->KEY_LEFT = keycode;
    };

    void InputKeyboard::setKeyRight(int keycode)
    {
        this->KEY_RIGHT = keycode;
    };

    void InputKeyboard::setKeyAction1(int keycode)
    {
        this->KEY_ACTION1 = keycode;
    };

    void InputKeyboard::setKeyAction2(int keycode)
    {
        this->KEY_ACTION2 = keycode;
    };

    void InputKeyboard::setKeyAction3(int keycode)
    {
        this->KEY_ACTION3 = keycode;
    };

    void InputKeyboard::setKeyAction4(int keycode)
    {
        this->KEY_ACTION4 = keycode;
    };

    void InputKeyboard::setKeyPause(int keycode)
    {
        this->KEY_MENU = keycode;
    };

    bool InputKeyboard::isKeyUp_Press() const
    {
        int state = glfwGetKey(Input::getWindow(), this->KEY_UP);
        if (state == GLFW_PRESS) return true;
        return false;
    };

    bool InputKeyboard::isKeyDown_Press() const
    {
        int state = glfwGetKey(Input::getWindow(), this->KEY_DOWN);
        if (state == GLFW_PRESS) return true;
        return false;
    };

    bool InputKeyboard::isKeyLeft_Press() const
    {
        int state = glfwGetKey(Input::getWindow(), this->KEY_LEFT);
        if (state == GLFW_PRESS) return true;
        return false;
    };

    bool InputKeyboard::isKeyRight_Press() const
    {
        int state = glfwGetKey(Input::getWindow(), this->KEY_RIGHT);
        if (state == GLFW_PRESS) return true;
        return false;
    };

    bool InputKeyboard::isKeyAction1_Press() const
    {
        int state = glfwGetKey(Input::getWindow(), this->KEY_ACTION1);
        if (state == GLFW_PRESS) return true;
        return false;
    };

    bool InputKeyboard::isKeyAction2_Press() const
    {
        int state = glfwGetKey(Input::getWindow(), this->KEY_ACTION2);
        if (state == GLFW_PRESS) return true;
        return false;
    };

    bool InputKeyboard::isKeyAction3_Press() const
    {
        int state = glfwGetKey(Input::getWindow(), this->KEY_ACTION3);
        if (state == GLFW_PRESS) return true;
        return false;
    };

    bool InputKeyboard::isKeyAction4_Press() const
    {
        int state = glfwGetKey(Input::getWindow(), this->KEY_ACTION4);
        if (state == GLFW_PRESS) return true;
        return false;
    };

    bool InputKeyboard::isKeyPause_Press() const
    {
        int state = glfwGetKey(Input::getWindow(), this->KEY_MENU);
        if (state == GLFW_PRESS) return true;
        return false;
    };

    _Inputs_Keyboard InputKeyboard::returnMapInputs()
    {
        _Inputs_Keyboard inputsMap;
        inputsMap.set();
        
        inputsMap.upButton = isKeyUp_Press();
        inputsMap.downButton = isKeyDown_Press();
        inputsMap.leftButton = isKeyLeft_Press();
        inputsMap.rightButton = isKeyRight_Press();
        inputsMap.oneButton = isKeyAction1_Press();
        inputsMap.twoButton = isKeyAction2_Press();
        inputsMap.threeButton = isKeyAction3_Press();
        inputsMap.fourButton = isKeyAction4_Press();
        inputsMap.menuButton = isKeyPause_Press();

        return inputsMap;
    };

    InputKeyboard::InputKeyboard(GLFWwindow* window):
    Input::Input(window)
    {
        this->setKeyUp(GLFW_KEY_W);
        this->setKeyDown(GLFW_KEY_S);
        this->setKeyLeft(GLFW_KEY_A);
        this->setKeyRight(GLFW_KEY_D);
        this->setKeyAction1(GLFW_KEY_H);
        this->setKeyAction2(GLFW_KEY_U);
        this->setKeyAction3(GLFW_KEY_I);
        this->setKeyAction4(GLFW_KEY_O);
        this->setKeyPause(GLFW_KEY_ESCAPE);     
    };

    InputGamepad::InputGamepad(GLFWwindow *window, int joystickId):
    Input::Input(window)
    {
        int const joystickConnected = glfwJoystickPresent(joystickId);
        int tempInt1 = 0, tempInt2 = 0;
        this->msg_disconnect = false;
        this->buttonsCount = tempInt1;
        this->axesCount = tempInt2;
        this->joystickId = joystickId;
        if(joystickConnected == GLFW_TRUE)
        {
            this->buttons = glfwGetJoystickButtons(this->joystickId, &(this->buttonsCount));
            this->axes = glfwGetJoystickAxes(this->joystickId, &(this->axesCount));
            std::cout << "Se creo un joystick" << std::endl;
        }
        else
        {
            std::cout << "No se pudo crear un gamepad" << std::endl;
        }
    };

    bool InputGamepad::isKeyUp_Press() const
    {
        bool cond_axes = this->axes[1] <= -0.75f;
        return this->buttons[14] == GLFW_PRESS || cond_axes;
    };

    bool InputGamepad::isKeyDown_Press() const
    {
        bool cond_axes = 0.75f <= this->axes[1];
        return this->buttons[16] == GLFW_PRESS || cond_axes;
    };

    bool InputGamepad::isKeyLeft_Press() const
    {
        bool cond_axes = this->axes[0] <= -0.75f;
        return this->buttons[17] == GLFW_PRESS || cond_axes;
    };

    bool InputGamepad::isKeyRight_Press() const
    {
        bool cond_axes = 0.75f <= this->axes[0];
        return this->buttons[15] == GLFW_PRESS || cond_axes;
    };

    bool InputGamepad::isKeyAction1_Press() const
    {
        return this->buttons[0] == GLFW_PRESS;
    };

    bool InputGamepad::isKeyAction2_Press() const
    {
        return this->buttons[3] == GLFW_PRESS;
    };

    bool InputGamepad::isKeyAction3_Press() const
    {
        return this->buttons[1] == GLFW_PRESS;
    };

    bool InputGamepad::isKeyAction4_Press() const
    {
        return this->buttons[2] == GLFW_PRESS;
    };

    bool InputGamepad::isKeyPause_Press() const
    {
        return this->buttons[9] == GLFW_PRESS;
    };

    bool InputGamepad::isConnected()
    {
        int const joystickConnected = glfwJoystickPresent(this->getId());
        if(joystickConnected == GLFW_FALSE) 
        {
            if(!this->msg_disconnect)
            {
                std::cout << "Se desconecto el joystick" << std::endl;
                this->msg_disconnect = true;
            }
            return false;
        }
        this->msg_disconnect = false;
        return true;
    };

    void InputGamepad::refreshInputs()
    {
        this->buttons = glfwGetJoystickButtons(this->joystickId, &(this->buttonsCount));
        this->axes = glfwGetJoystickAxes(this->joystickId, &(this->axesCount));
    };

    _Inputs_Keyboard InputGamepad::returnMapInputs()
    {      
        _Inputs_Keyboard inputsMap;
        inputsMap.set();
        if(this->isConnected())
        {
            this->refreshInputs();
            inputsMap.upButton = isKeyUp_Press();
            inputsMap.downButton = isKeyDown_Press();
            inputsMap.leftButton = isKeyLeft_Press();
            inputsMap.rightButton = isKeyRight_Press();
            inputsMap.oneButton = isKeyAction1_Press();
            inputsMap.twoButton = isKeyAction2_Press();
            inputsMap.threeButton = isKeyAction3_Press();
            inputsMap.fourButton = isKeyAction4_Press();
            inputsMap.menuButton = isKeyPause_Press();
        }
        return inputsMap;
    };

    int InputGamepad::getId() const
    {
        return this->joystickId;
    }

    void InputGamepad::setId(int new_id)
    {
        this->joystickId = new_id;
    };

}
