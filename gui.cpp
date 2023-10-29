#ifdef _DEBUG
    #include <iostream>
#endif

// Global variables, used in renderUI()
ImColor bgColor = ImColor(40, 44, 52);

void renderUI() {
    ImGui::Begin("Hello, world!");
    ImGui::Text("This is some useful text.");
    // Add a color edit widget thats linked with bgColor
    ImGui::ColorEdit3("Change background color",(float*)&bgColor,ImGuiColorEditFlags_NoInputs);
    // Add a button that prints a message when clicked
    if (ImGui::Button("Button")) {
#ifdef _DEBUG
        std::cout << "Button pressed\n";
#endif

    }
    ImGui::End();

}
