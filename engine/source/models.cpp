#include "shaders.h"
#include <glad/glad.h>
#include <iostream>
#include "models.h"

Figure::Figure(GLfloat vertices[], GLint indices[], unsigned int num_indice):
    vertices(vertices), indices(indices), num_indice(num_indice)
{}

void Figure::initShaders()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
}

void Figure::loadBuffers()
{
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
}

void Figure::clearBuffers()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}

void Figure::draw()
{
        glBindVertexArray(vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        std::cout << "draw";
        glDrawElements(GL_TRIANGLES, num_indice, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0); // no need to unbind it every time 
}

Figure Figure::load()
{
    initShaders();
    loadBuffers();
    return *this;
}