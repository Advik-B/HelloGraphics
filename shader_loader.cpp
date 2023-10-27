#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <fstream>

#define shaderPath "../shaders/"

unsigned int compileShader(std::string shaderName, GLenum shaderType) {

    unsigned int shader = glCreateShader(shaderType);
    std::string shaderSource = shaderPath + shaderName;
    std::string line;
    std::ifstream shaderFile(shaderSource);
    if (shaderFile.is_open()) {
        while (getline(shaderFile, line)) {
            shaderSource += line + '\n';
        }
        shaderFile.close();
    } else {
        debug("Unable to open shader file " + shaderName);
        return 0;
    }
    const char* shaderSourceCStr = shaderSource.c_str();
    glShaderSource(shader, 1, &shaderSourceCStr, nullptr);
    glCompileShader(shader);
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        debug("Shader compilation failed for " + shaderName + " with error " + infoLog);
        debug("Shader source: " + shaderSource);
        debug("Info-log: " + std::string(infoLog));
        return 0;
    }
    return shader;
}

// Link shaders
// Takes in any number of shaders and links them together
// Returns the shader program
unsigned int linkShaders(int shaderCount, ...) {
    unsigned int shaderProgram = glCreateProgram();
    va_list shaders;
    va_start(shaders, shaderCount);
    for (int i = 0; i < shaderCount; i++) {
        glAttachShader(shaderProgram, va_arg(shaders, unsigned int));
    }
    va_end(shaders);
    glLinkProgram(shaderProgram);
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        debug("Shader linking failed with error " + std::string(infoLog));
        return SHADER_LINKING_FAIL;
    }
    // Delete shaders after linking
    va_start(shaders, shaderCount);
    for (int i = 0; i < shaderCount; i++) {
        glDeleteShader(va_arg(shaders, unsigned int));
    }
    va_end(shaders);

    return shaderProgram;
}