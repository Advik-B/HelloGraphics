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

    // Set the size of the window
    SetNextWindowSize(ImVec2(400, 400), ImGuiCond_FirstUseEver);
    // Set the position of the window
    SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    // Set GLFW window size
    glfwSetWindowSize(window, 400, 400);
    // Set GLFW window position
    glfwSetWindowPos(window, 0, 0);

    // Set the imgui callback for keyboard input
    glfwSetKeyCallback(window, handleImGuiInput);
}


void renderUI() {
    using namespace ImGui;
    using namespace std;

    // Create a window called "My First Tool", with a menu bar.
    ImGui::Begin("My First Tool", nullptr, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
            if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
            if (ImGui::MenuItem("Close", "Ctrl+W"))  { glfwSetWindowShouldClose(glfwGetCurrentContext(), true); }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    // Edit a color stored as 4 floats
    ImGui::ColorEdit4("Color", (float*)&bgColor);

    // Add a combo box to select between sin and cos
    const char* items[] = { "sin", "cos", "tan", "cot", "sec", "csc", "log", "ln", "arcsin", "arccos", "arctan", "arccot", "arcsec", "arccsc", "sinh", "cosh", "tanh", "coth", "sech", "csch", "arcsinh", "arccosh", "arctanh", "arccoth", "arcsech", "arccsch" };
    static int item_current = 0;

    if (ImGui::BeginCombo("Combo", items[item_current])) // The second parameter is the label previewed before opening the combo.
    {
        for (int n = 0; n < IM_ARRAYSIZE(items); n++)
        {
            bool is_selected = (item_current == n); // You can store your selection however you want, outside or inside your objects
            if (ImGui::Selectable(items[n], is_selected))
                item_current = n;
            if (is_selected)
                ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
        }
        ImGui::EndCombo();
    }

    ImGui::SliderFloat("Values Offset Multiplier", &multiplier, 0.0f, 1.0f);
    ImGui::SliderInt("Sample Size", &sampleSize, 0, 1000);



    // Generate samples and plot them
    vector<float> samples(sampleSize);
    for (int n = 0; n < sampleSize; n++) {
        switch (item_current) {
        case 0:
            samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 1:
            samples[n] = cosf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 2:
            samples[n] = tanf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 3:
            samples[n] = 1 / tanf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 4:
            samples[n] = 1 / cosf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 5:
            samples[n] = 1 / sinf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 6:
            samples[n] = logf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 7:
            samples[n] = logf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 8:
            samples[n] = asinf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 9:
            samples[n] = acosf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 10:
            samples[n] = atanf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 11:
            samples[n] = 1 / atanf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 12:
            samples[n] = 1 / asinf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 13:
            samples[n] = 1 / acosf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 14:
            samples[n] = sinhf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 15:
            samples[n] = coshf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 16:
            samples[n] = tanhf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 17:
            samples[n] = 1 / tanhf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 18:
            samples[n] = 1 / coshf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 19:
            samples[n] = 1 / sinhf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 20:
            samples[n] = asinhf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 21:
            samples[n] = acoshf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 22:
            samples[n] = atanhf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 23:
            samples[n] = 1 / atanhf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 24:
            samples[n] = 1 / acoshf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        case 25:
            samples[n] = 1 / asinhf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;
        default:
            samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 1.5f * multiplier);
            break;

        }
    }

    ImGui::PlotLines("Lines", samples.data(), sampleSize, 0, NULL, FLT_MAX, FLT_MAX, ImVec2(0, 80));

    // Display contents in a scrolling region
    ImGui::TextColored(ImVec4(1,1,0,1), "Important Stuff");
    ImGui::BeginChild("Scrolling");
    for (int n = 0; n < 50; n++)
        ImGui::Text("%04d: Some text", n);
    ImGui::EndChild();
    ImGui::End();

}
