#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <source/shaders.h>
#include <source/models.h>
#include <iostream>
#include <source/Inputs/inputs.h>

// Constant that help us
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const std::string vertexShaderCode = R"(
        #version 130                                                       
                                                                           
        uniform mat4 projection;                                           
        uniform mat4 view;                                                 
        uniform mat4 model;                                                
        in vec3 position;                                                  
        in vec3 color;                                                     
        out vec3 newColor;                                                 
                                                                           
        void main()                                                        
        {                                                                  
            gl_Position = projection * view * model * vec4(position, 1.0f);
            newColor = color;                                              
        }
    )";

const std::string fragmentShaderCode = R"(
        #version 130                        
                                            
        in vec3 newColor;                   
        out vec4 outColor;                  
                                            
        void main()                         
        {                                   
            outColor = vec4(newColor, 1.0f);
        }
    )";

// Function that help us
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Main function
int main()
{
    // init and configure glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create the window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "ventana_main", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Error al crear la ventana" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // load glad for OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    ShaderProgram shaderProgram(vertexShaderCode.c_str(), fragmentShaderCode.c_str());
    
    shaderProgram.useProgram();

    // obejct
    float vertices[] = {
        -0.1f,  0.9f, 0.0f,  // top right
        -0.1f,  0.8f, 0.0f,  // bottom right
        -0.9f,  0.8f, 0.0f,  // bottom left
        -0.9f,  0.9f, 0.0f,   // top left 
         0.9f,  0.9f, 0.0f,  // top right
         0.9f,  0.8f, 0.0f,  // bottom right
         0.1f,  0.8f, 0.0f,  // bottom left
         0.1f,  0.9f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3,  // second Triangle
        4, 5, 7,
        5, 6, 7
    };

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

    GLfloat vertices_sqare[] = {
         0.1f,  0.1f, 0.0f,  // top right
         0.1f, -0.1f, 0.0f,  // bottom right
        -0.1f, -0.1f, 0.0f,  // bottom left
        -0.1f,  0.1f, 0.0f,   // top left 
    };

    GLint indices_sqare[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3,  // second Triangle
    };
    unsigned int nindice_sqare = 6;
    unsigned int VAO1, VBO1, EBO1;
    glGenVertexArrays(1, &VAO1);
    glGenBuffers(1, &VBO1);
    glGenBuffers(1, &EBO1);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    
    glUniform3f(glGetUniformLocation((shaderProgram.getID()), "FragColor"), 0.0f, 0.0f, 1.0f);
    glBindVertexArray(VAO1);

    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_sqare), vertices_sqare, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO1);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_sqare), indices_sqare, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

    Fighters::InputKeyboard keyboard(window);
    Fighters::InputGamepad joystick(window, GLFW_JOYSTICK_1);

    // LOOP RENDERING, PRINCIPAL LOOP
    while(!glfwWindowShouldClose(window))
    {
        // Obtains inputs
        processInput(window);

        // rendering commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw health bar 1
        shaderProgram.useProgram();
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0); // no need to unbind it every time

        glBindVertexArray(VAO1); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawElements(GL_TRIANGLES, nindice_sqare, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0); // no need to unbind it every time

        // check and call events and swap the buffers
        Fighters::_Inputs_Keyboard temp_keyboard = keyboard.returnMapInputs();
        Fighters::_Inputs_Keyboard temp_joystick = joystick.returnMapInputs();

        if(temp_keyboard.upButton) std::cout << "upButton" << std::endl;
        if(temp_keyboard.downButton) std::cout << "downButton" << std::endl;
        if(temp_keyboard.leftButton) std::cout << "leftButton" << std::endl;
        if(temp_keyboard.rightButton) std::cout << "rightButton" << std::endl;
        if(temp_keyboard.oneButton) std::cout << "1" << std::endl;
        if(temp_keyboard.twoButton) std::cout << "2" << std::endl;
        if(temp_keyboard.threeButton) std::cout << "3" << std::endl;
        if(temp_keyboard.fourButton) std::cout << "4" << std::endl;
        if(temp_keyboard.menuButton) std::cout << "menu" << std::endl;

        if(temp_joystick.upButton) std::cout << "JupButton" << std::endl;
        if(temp_joystick.downButton) std::cout << "JdownButton" << std::endl;
        if(temp_joystick.leftButton) std::cout << "JleftButton" << std::endl;
        if(temp_joystick.rightButton) std::cout << "JrightButton" << std::endl;
        if(temp_joystick.oneButton) std::cout << "J1" << std::endl;
        if(temp_joystick.twoButton) std::cout << "J2" << std::endl;
        if(temp_joystick.threeButton) std::cout << "J3" << std::endl;
        if(temp_joystick.fourButton) std::cout << "J4" << std::endl;
        if(temp_joystick.menuButton) std::cout << "Jmenu" << std::endl;

/*
        if(joystick.isConnected())
        {
        joystick.refreshInputs();
        if(joystick.isKeyDown_Press()) std::cout << "sj" << std::endl;
        if(joystick.isKeyUp_Press()) std::cout << "wj" << std::endl;
        if(joystick.isKeyLeft_Press()) std::cout << "aj" << std::endl;
        if(joystick.isKeyRight_Press()) std::cout << "dj" << std::endl;
        if(joystick.isKeyAction1_Press()) std::cout << "1j" << std::endl;
        if(joystick.isKeyAction2_Press()) std::cout << "2j" << std::endl;
        if(joystick.isKeyAction3_Press()) std::cout << "3j" << std::endl;
        if(joystick.isKeyAction4_Press()) std::cout << "4j" << std::endl;
        if(joystick.isKeyPause_Press()) std::cout << "escj" << std::endl; 
        }
*/
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glfwTerminate();
    return 0;
}   