#pragma once
#include <glad/glad.h>
#include <string>

class ShaderProgram
{
    private:
        unsigned int ID;

    public:
        ShaderProgram() = delete;

        ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);

        void useProgram() const;
};