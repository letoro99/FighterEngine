#pragma once
#include <GLFW/glfw3.h>

namespace Fighters
{
    struct _Inputs_Keyboard {
        bool upButton, downButton, leftButton, rightButton;
        bool oneButton, twoButton, threeButton, fourButton;
        bool menuButton;
        void set(){
            upButton = downButton = leftButton = rightButton = false;
            oneButton = twoButton = threeButton = fourButton = menuButton = false;
        }
    };

    class Input
    {
        public:
            Input(GLFWwindow *window);

            void setWindow(GLFWwindow *window);

            GLFWwindow* getWindow() const;

        private:
            GLFWwindow* m_window;
    };

    class InputKeyboard: public Input
    {
        public:
            InputKeyboard(GLFWwindow *window);

            bool isKeyUp_Press() const;

            bool isKeyDown_Press() const;

            bool isKeyRight_Press() const;

            bool isKeyLeft_Press() const;

            bool isKeyAction1_Press() const;

            bool isKeyAction2_Press() const;

            bool isKeyAction3_Press() const;

            bool isKeyAction4_Press() const;

            bool isKeyPause_Press() const;

            void setKeyUp(int keycode);

            void setKeyDown(int keycode);

            void setKeyRight(int keycode);

            void setKeyLeft(int keycode);

            void setKeyAction1(int keycode);

            void setKeyAction2(int keycode);

            void setKeyAction3(int keycode);

            void setKeyAction4(int keycode);
            
            void setKeyPause(int keycode);

            _Inputs_Keyboard returnMapInputs();

        private:
            int KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ACTION1, KEY_ACTION2, KEY_ACTION3, KEY_ACTION4, KEY_MENU;
    };

    class InputGamepad: public Input
    {
        public:
            InputGamepad(GLFWwindow *window, int joystickId);

            int getId() const;

            void setId(int new_id);
            
            bool isKeyUp_Press() const;

            bool isKeyDown_Press() const;

            bool isKeyRight_Press() const;

            bool isKeyLeft_Press() const;

            bool isKeyAction1_Press() const;

            bool isKeyAction2_Press() const;

            bool isKeyAction3_Press() const;

            bool isKeyAction4_Press() const;

            bool isKeyPause_Press() const;

            bool isConnected();
            
            void refreshInputs();

            _Inputs_Keyboard returnMapInputs();

        private:
            bool msg_disconnect;
            int joystickId;
            int buttonsCount;
            int axesCount;
            const unsigned char* buttons;
            const float* axes;
    };
}