#include <cstdlib>

// Global variables, used in renderUI()
ImColor bgColor = ImColor(40, 44, 52);


void handleImGuiInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
    using namespace ImGui;
    // If escape is pressed, close the window
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
}

void preStartup(GLFWwindow* window) {
    using namespace ImGui;

    // Never use imgui.ini file
    GetIO().IniFilename = nullptr;
    // Set the style
    ImGuiStyle& style = GetStyle();
    style.WindowRounding = 1.0f;
    style.Colors[ImGuiCol_WindowBg] = bgColor;

    // Set the size of the window
    SetNextWindowSize(ImVec2(400, 400), ImGuiCond_Always);
    // Set the position of the window
    SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);
    // Set GLFW window size
    glfwSetWindowSize(window, 400, 400);
    // Set GLFW window position
    glfwSetWindowPos(window, 100, 100);

    // Set the imgui callback for keyboard input
    glfwSetKeyCallback(window, handleImGuiInput);
}


void renderUI() {
    using namespace ImGui;
    SetNextWindowSize(ImVec2(400, 400), ImGuiCond_Always);
//    SetNextWindowPos(GetMousePos(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    Begin("Hello, world!");
    if (Button("Close Me"))
        glfwSetWindowShouldClose(glfwGetCurrentContext(), true);

    End();

}
