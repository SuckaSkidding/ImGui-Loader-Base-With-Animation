#include "Loader.h"
#include "icons.h"
#include "menu.h"
#include "fontss.hpp"

char UserName[50];
char PassWord[50];
ImFont* Gay;
ImFont* NotGay;
ImFont* BigGay;
ImFont* BigBigGay;
ImFont* BigBigbGay;

ImFont* Font;
static int tabs = 1;

int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandleA(0), 0,0,0, 0, L"omg j'suis detect sur fn", 0 };
    RegisterClassEx(&wc);
    Window = CreateWindow(wc.lpszClassName, L"Detected source", WS_POPUP, 0, 0, 5, 5, 0, 0, wc.hInstance, 0);

    if (!CreateDeviceD3D(Window)) 
    {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    ShowWindow(Window, SW_HIDE);
    UpdateWindow(Window);

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.LogFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; 
   
    static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
    ImFontConfig icons_config;

    io.IniFilename = nullptr;
    io.LogFilename = nullptr;

    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.OversampleH = 3;
    icons_config.OversampleV = 3;

    ImFontConfig CustomFont;
    CustomFont.FontDataOwnedByAtlas = false;
    Gay = io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 14.5, &CustomFont);;
    NotGay =  io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 15.5, &CustomFont);
    BigGay = io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 17.5, &CustomFont);
    BigBigGay = io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Rubik), sizeof(Rubik), 80.5, &CustomFont);
    BigBigbGay = io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Rubik), sizeof(Rubik), 32.5, &CustomFont);

    Font = io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 22.5f, &icons_config, icons_ranges);
    io.Fonts->AddFontDefault();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    ImGui_ImplWin32_Init(Window);
    ImGui_ImplDX9_Init(g_pd3dDevice);
    MSG msg;

    memset(&msg, 0, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }

        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        if (Menu::tab == 1)
        {
            Menu::Theme();
            {
                ImGui::Begin("yes bebe alors bien ?", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
                {
                    ImVec2 CursorPos = ImGui::GetWindowPos();
                    ImGui::GetWindowDrawList()->AddTriangleFilled(ImVec2(CursorPos.x, CursorPos.y + 200), ImVec2(CursorPos.x + 450, CursorPos.y + 800), ImVec2(CursorPos.x + 0, CursorPos.y + 800), ImColor(8, 8, 8, 255));

                    

                    ImGui::SetCursorPos(ImVec2(120, 30));
                    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
                    ImGui::PushFont(BigBigGay);
                    ImGui::TextColored(ImColor(120, 0, 0, 255), "PASTE");
                    ImGui::SetCursorPos(ImVec2(320, 30));
                    ImGui::TextColored(ImColor(255, 255, 255, 255), ".CC");

                    ImGui::PopFont();
                    ImGui::PopStyleColor();


                    ImGui::SetCursorPos(ImVec2(155, 120));
                    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 120));
                    ImGui::PushFont(Gay);
                    ImGui::Text("Thanks for for choosing our products !");
                    ImGui::PopFont();
                    ImGui::PopStyleColor();

                    ImGui::SetCursorPos(ImVec2(120, 140));
                    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
                    ImGui::PushFont(BigGay);
                    ImGui::Text("My loader is fully pasted like hx software!");
                    ImGui::PopStyleColor();
                    ImGui::PopFont();





                    ImGui::SetCursorPos(ImVec2(100, 220));
                    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(240, 240, 240, 255));
                    ImGui::PushFont(NotGay);
                    ImGui::Text("Username :");
                    ImGui::PopStyleColor();
                    ImGui::PopFont();

                    ImGui::SetCursorPos(ImVec2(100, 300));
                    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(240, 240, 240, 255));
                    ImGui::PushFont(NotGay);
                    ImGui::Text("Password :");
                    ImGui::PopStyleColor();

                    ImGui::PopFont();
                    ImGui::PushFont(NotGay);
                    ImGui::SetCursorPos(ImVec2(100, 240));
                    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(240, 240, 240, 255));
                    ImGui::InputTextNew("##RenderUsername", UserName, sizeof(UserName), ImVec2(350, 35));
                    ImGui::SetCursorPos(ImVec2(100, 320));

                    ImGui::InputTextNew("##RenderPassword", PassWord, sizeof(PassWord), ImVec2(350, 35), ImGuiInputTextFlags_Password);

                    ImGui::SetCursorPos(ImVec2(100, 380));
                    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));

                    if (ImGui::Button("Login Now", ImVec2(350, 42)))
                    {
                        Menu::tab = 2;
                    }
                    ImGui::PopStyleColor();

                    ImGui::PopFont();

                    ImGui::PopStyleColor();
                    // ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(CursorPos.x , CursorPos.y + 450), ImVec2(CursorPos.x + 120, CursorPos.y + 800), ImColor(0, 0, 0, 255));

                }
                ImGui::End();
            }
        }
        else
        {
            Menu::Theme2();
            {
                ImGui::Begin("j'ai tchoupé marwane ?", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
                {
                    ImVec2 CursorPos = ImGui::GetWindowPos();

                    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(5,5,5, 255));
                    ImGui::PushStyleColor(ImGuiCol_WindowBg, IM_COL32(9, 9, 9, 255));

        

                   // ImGui::GetWindowDrawList()->AddTriangleFilled(ImVec2(CursorPos.x, CursorPos.y + 200), ImVec2(CursorPos.x + 450, CursorPos.y + 800), ImVec2(CursorPos.x + 0, CursorPos.y + 800), ImColor(8, 8, 8, 255));
  

                    ImGui::PopStyleColor(2);
                    ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(CursorPos.x , CursorPos.y ), ImVec2(CursorPos.x + 70, CursorPos.y + 800), ImColor(8, 8, 8, 255));
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(CursorPos.x +70 , CursorPos.y), ImVec2(CursorPos.x + 70, CursorPos.y + 800), ImColor(255,255, 255, 10));
                    ImGui::SetCursorPos(ImVec2(21, 40));
                    ImGui::PushFont(Font);
                    if (ImGui::ButtonNew(ICON_FA_DATABASE, ImVec2(30, 30)))
                    {
                        tabs = 1;

                    }
                    ImGui::PopFont();

                    ImGui::SetCursorPos(ImVec2(21, 80));
                    ImGui::PushFont(Font);
                    if (ImGui::ButtonNew(ICON_FA_COGS, ImVec2(30, 30)))
                    {
                        tabs = 2;
                    }
                    ImGui::PopFont();

                    ImGui::SetCursorPos(ImVec2(21, 120));
                    ImGui::PushFont(Font);
                    if (ImGui::ButtonNew(ICON_FA_BARS, ImVec2(30, 30)))
                    {
                        tabs = 3;
                    }
                    ImGui::PopFont();


                    ImGui::SetCursorPos(ImVec2(21, 480));
                    ImGui::PushFont(Font);
                    if (ImGui::ButtonNew("x", ImVec2(30, 30)))
                        exit(-1);
                    ImGui::PopFont();







                }
                ImGui::End();
            }
        }
       
        ImGui::EndFrame();

        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
        if (!Enabled) {
            msg.message = WM_QUIT;
        }
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(Window);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {

            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}