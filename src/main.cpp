#include <iostream>
#include "RGUI.h"
#include <raylib.h>

int main() {
	InitWindow(800, 800, "Testing RGUI.h");

	RGUI::BasicComponent MyComponent = RGUI::BasicComponent(
		{100, 100},
		{150, 60},
		PURPLE
	);

	MyComponent.SetOnHoverProperties(
		{90, 90},
		{170, 80},
		GRAY
	);
	MyComponent.SetOnClickProperties(
		{ 95, 95 },
		{ 160, 70 },
		YELLOW
	);

	MyComponent.SetDefaultLabelTextProperties("Hello world!", 20, { 120, 120 }, BLACK);
	MyComponent.SetOnHoverLabelTextProperties("Hello world!", 20, { 120, 120 }, BLUE);
	MyComponent.SetOnClickLabelTextProperties("Hello world!", 20, { 120, 120 }, GREEN);

	RGUI::Component MyComponent2 = RGUI::Component(
		{ 100, 200 },
		{ 200, 60 },
		GREEN
	);

	MyComponent2.SetBorderProperties({4, YELLOW});
	MyComponent2.SetOnHoverBorderProperties({ 8, BLUE });
	MyComponent2.SetOnClickBorderProperties({ 12, RED });

	MyComponent2.SetDefaultLabelTextProperties("Component Idol....", 20, { 120, 220 }, BLACK);
	MyComponent2.SetOnHoverLabelTextProperties("Component Hovered!", 20, { 120, 220 }, WHITE);
	MyComponent2.SetOnClickLabelTextProperties("Component Clicked!", 20, { 120, 220 }, YELLOW);

	RGUI::ComponentPro MyComponent3 = RGUI::ComponentPro(
		{ 100, 300 },
		{ 200, 60 },
		BLUE
	);

	MyComponent3.SetBorderTProperties({ 6.0f, GREEN });
	MyComponent3.SetBorderLProperties({ 6.0f, ORANGE });
	MyComponent3.SetBorderRProperties({ 6.0f, RED });
	MyComponent3.SetBorderBProperties({ 6.0f, PURPLE });

	MyComponent3.SetOnHoverBorderProperties(
		{
			3.0f,		3.0f,	3.0f,		3.0f,
			PURPLE,		RED,	ORANGE,		GREEN
		}
	);
	MyComponent3.SetOnClickBorderProperties(
		{
			5.0f,		5.0f,	5.0f,	5.0f,
			RED,		PURPLE,	GREEN,	ORANGE
		}
	);

	MyComponent3.SetDefaultLabelTextProperties("Component Pro", 20, { 120, 320 }, WHITE);
	MyComponent3.SetOnHoverLabelTextProperties("Component Pro", 20, { 120, 320 }, WHITE);
	MyComponent3.SetOnClickLabelTextProperties("Component Pro", 20, { 120, 320 }, WHITE);

	SetTargetFPS(60);
	while (!WindowShouldClose()) { 
		BeginDrawing();

		MyComponent.Draw();
		MyComponent2.Draw();
		MyComponent3.Draw();

		ClearBackground(DARKGRAY);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}