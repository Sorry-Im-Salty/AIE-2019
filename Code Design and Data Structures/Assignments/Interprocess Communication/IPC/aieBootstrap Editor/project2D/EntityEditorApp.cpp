#include "EntityEditorApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

#include <imgui.h>


EntityEditorApp::EntityEditorApp() {

}

EntityEditorApp::~EntityEditorApp() {

}

bool EntityEditorApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	setBackgroundColour(1, 1, 1);

	for (int i = 0; i < ENTITY_COUNT; ++i)
	{
		m_entities[i].x = 100 + i * 50;
		m_entities[i].y = 100 + i * 50;
		m_entities[i].size = 20;
	}

	//Create shared memory to store how many objects there are
		fileHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		nullptr,
		PAGE_READWRITE,
		0, sizeof(ENTITY_COUNT),
		L"EntityCount");
	//Create shared memory to store the array of objects.
		sizeHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		nullptr,
		PAGE_READWRITE,
		0, sizeof(m_entities),
		L"ArrayObjects");

	return true;
}

void EntityEditorApp::shutdown() {

	UnmapViewOfFile(fileHandle);
	UnmapViewOfFile(sizeHandle);
	CloseHandle(fileHandle);
	CloseHandle(sizeHandle);
	delete m_font;
	delete m_2dRenderer;
}

void EntityEditorApp::update(float deltaTime) {

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	static int selection = 0;
	ImGui::SliderInt("entry #", &selection, 0, ENTITY_COUNT - 1);
	ImGui::Separator();
	ImGui::BeginGroup();

	ImGui::InputFloat("x", &m_entities[selection].x);
	ImGui::InputFloat("y", &m_entities[selection].y);
	ImGui::SliderAngle("rotation", &m_entities[selection].rotation);
	ImGui::SliderFloat("size", &m_entities[selection].size, 0, 1000);
	ImGui::SliderFloat("speed", &m_entities[selection].speed, 0, 1000);
	ImGui::ColorEdit3("colour", &m_entities[selection].r);
	ImGui::EndGroup();

	for (auto& entity : m_entities) {
		float s = sinf(entity.rotation) * entity.speed;
		float c = cosf(entity.rotation) * entity.speed;
		entity.x -= s * deltaTime;
		entity.y += c * deltaTime;

		entity.x = fmod(entity.x, (float)getWindowWidth());
		if (entity.x < 0)
			entity.x += getWindowWidth();
		entity.y = fmod(entity.y, (float)getWindowHeight());
		if (entity.y < 0)
			entity.y += getWindowHeight();
	}

	//Map pointer to memory to store object count
	int* OBJECT_COUNT  = (int*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(int));

	//Set object count
	*OBJECT_COUNT = ENTITY_COUNT;
	UnmapViewOfFile(OBJECT_COUNT);
	//Map pointer to memory to store array of objects
	Entity* OBJECT_ARRAY = (Entity*)MapViewOfFile(sizeHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity)* ENTITY_COUNT);
	memcpy(OBJECT_ARRAY, m_entities, sizeof(Entity)* ENTITY_COUNT);
	UnmapViewOfFile(OBJECT_ARRAY);
	//Set array of objects
	
}

void EntityEditorApp::draw() {

	clearScreen();

	m_2dRenderer->begin();

	for (auto& entity : m_entities) {
		m_2dRenderer->setRenderColour(entity.r, entity.g, entity.b);
		m_2dRenderer->drawBox(entity.x, entity.y, entity.size, entity.size, entity.rotation);
	}
	
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	m_2dRenderer->end();
}