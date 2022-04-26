#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Fighters
{
    class Window
    {
        public:
            Window();
            ~Window();

            Window(const Window& win) = delete;
            Window& operator=(const Window& win) = delete;

            void StartUp();

            bool isFullScreen() const;

            void setFullScreen(bool value);

            bool ShouldClose() const;

            glm::ivec2 GetWindowDimension() const;

            void setWindowDimension(glm::ivec2 &dimension);

        
        private:
            GLFWwindow* m_windowHandle = nullptr;
            WindowData m_data;
            glm::ivec2 m_oldWindowPos = glm::vec2(0,0);
            void Update();

    };
}