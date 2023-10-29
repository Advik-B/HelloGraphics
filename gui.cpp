#include <cstdlib>
#include <vector>

#ifdef _DEBUG
    #include <iostream>
#endif

// Global variables, used in renderUI()
ImColor bgColor = ImColor(40, 44, 52);
float multiplier = 0.5f;
int sampleSize = 100;


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


    // Set the size of the window
    SetNextWindowSize(ImVec2(400, 400), ImGuiCond_Always);
    // Set the position of the window
    SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    // Set GLFW window size
    glfwSetWindowSize(window, 400, 400);
    // Set GLFW window position
    glfwSetWindowPos(window, 0, 0);

    // Set the imgui callback for keyboard input
    glfwSetKeyCallback(window, handleImGuiInput);
}


void renderUI() {
    ImGui::SetNextWindowSize(ImVec2(697,324));
    if (ImGui::Begin("window_name"))
    {

        ImGui::SetCursorPos(ImVec2(34,50.5));
        ImGui::PushItemWidth(200);
        static int i11 = 50;
        ImGui::DragInt("##", &i11, 1);
        ImGui::PopItemWidth();

        ImGui::SetCursorPos(ImVec2(37,88.5));
        ImGui::PushItemWidth(200);
        static float f22 = 0.0f;
        ImGui::SliderFloat("##", &f22, -10.0f, 10.0f, "%.4f", ImGuiSliderFlags_Logarithmic);
        ImGui::PopItemWidth();

        ImGui::SetCursorPos(ImVec2(38,137.875));
        ImGui::PushItemWidth(200);
        static float col33[4] = {0.4f, 0.7f, 0.0f, 0.5f};
        ImGui::ColorEdit4("##", col33);

        ImGui::PopItemWidth();

    }
    ImGui::End();

}
