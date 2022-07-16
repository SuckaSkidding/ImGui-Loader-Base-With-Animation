#include "menu.h"


void Menu::Theme()
{
	ImGuiStyle& Style = ImGui::GetStyle();
	auto Color = Style.Colors;
	
	Style.WindowMinSize     = ImVec2(540, 520);
	Style.WindowBorderSize  = 5;

	Style.ChildRounding     = 0;
	Style.FrameRounding     = 5;
	Style.ScrollbarRounding = 0;
	Style.GrabRounding		= 0;
	Style.PopupRounding		= 0;
	Style.WindowRounding	= 0;


	Color[ImGuiCol_WindowBg]            = ImColor(9, 9, 9, 255);
	
	Color[ImGuiCol_FrameBg]		        = ImColor(11,11,11, 255);
	Color[ImGuiCol_FrameBgActive]       = ImColor(18, 17, 17, 255);
	Color[ImGuiCol_FrameBgHovered]      = ImColor(18, 17, 17, 255);

	Color[ImGuiCol_Button]	            = ImColor(29, 29, 29, 255);
	Color[ImGuiCol_ButtonActive]        = ImColor(32, 32, 32, 255);
	Color[ImGuiCol_ButtonHovered]       = ImColor(36, 36, 36, 255);

	Color[ImGuiCol_Border]              = ImColor(0, 0, 0, 0);
	Color[ImGuiCol_Separator]           = ImColor(36, 36, 36, 255);

	Color[ImGuiCol_ResizeGrip]		    = ImColor(30, 30, 30, 255);
	Color[ImGuiCol_ResizeGripActive]    = ImColor(30, 30, 30, 255);
	Color[ImGuiCol_ResizeGripHovered]   = ImColor(30, 30, 30, 255);

	Color[ImGuiCol_ChildBg]			    = ImColor(0, 0, 0, 255);

	Color[ImGuiCol_ScrollbarBg]         = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrab]       = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);

	Color[ImGuiCol_Header]			    = ImColor(18, 17, 17, 255);
	Color[ImGuiCol_HeaderActive]	    = ImColor(18, 17, 17, 255);
	Color[ImGuiCol_HeaderHovered]       = ImColor(18, 17, 17, 255);
	Color[ImGuiCol_CheckMark]		    = ImColor(255, 255, 255, 255);
}

void Menu::Theme2()
{
	ImGuiStyle& Style = ImGui::GetStyle();
	auto Color = Style.Colors;

	Style.WindowMinSize = ImVec2(580, 520);
	Style.WindowBorderSize = 0;

	Style.ChildRounding = 0;
	Style.FrameRounding = 0;
	Style.ScrollbarRounding = 0;
	Style.GrabRounding = 0;
	Style.PopupRounding = 0;
	Style.WindowRounding = 20;
	Style.ChildBorderSize = 0;
	Style.FrameBorderSize = 0;
	Style.WindowBorderSize = 0;


	Color[ImGuiCol_WindowBg] = ImColor(9, 9, 9, 255);

	Color[ImGuiCol_FrameBg] = ImColor(11, 11, 11, 255);
	Color[ImGuiCol_FrameBgActive] = ImColor(18, 17, 17, 255);
	Color[ImGuiCol_FrameBgHovered] = ImColor(18, 17, 17, 255);

	Color[ImGuiCol_Button] = ImColor(29, 29, 29, 255);
	Color[ImGuiCol_ButtonActive] = ImColor(32, 32, 32, 255);
	Color[ImGuiCol_ButtonHovered] = ImColor(36, 36, 36, 255);

	Color[ImGuiCol_Border] = ImColor(0, 0, 0, 0);
	Color[ImGuiCol_Separator] = ImColor(36, 36, 36, 255);

	Color[ImGuiCol_ResizeGrip] = ImColor(30, 30, 30, 255);
	Color[ImGuiCol_ResizeGripActive] = ImColor(30, 30, 30, 255);
	Color[ImGuiCol_ResizeGripHovered] = ImColor(30, 30, 30, 255);

	Color[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 255);

	Color[ImGuiCol_ScrollbarBg] = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrab] = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);

	Color[ImGuiCol_Header] = ImColor(18, 17, 17, 255);
	Color[ImGuiCol_HeaderActive] = ImColor(18, 17, 17, 255);
	Color[ImGuiCol_HeaderHovered] = ImColor(18, 17, 17, 255);
	Color[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);
}