#pragma once
#include <glad/glad.h>
#include <iostream>
#include <vector>

class Figure{
    private:
        unsigned int vao, vbo, ebo, num_indice;

        GLfloat* vertices;
        GLint* indices;

        void initShaders();

        void loadBuffers();

    public:
        Figure() = delete;

        Figure(GLfloat vertices[], GLint indices[], unsigned int num_indice);

        void draw();

        Figure load();

        void clearBuffers();
};