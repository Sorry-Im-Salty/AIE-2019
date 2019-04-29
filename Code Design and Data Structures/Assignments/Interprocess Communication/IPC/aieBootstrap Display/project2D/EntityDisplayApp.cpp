#include "EntityDisplayApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

EntityDisplayApp::EntityDisplayApp() {

}

EntityDisplayApp::~EntityDisplayApp() {

}

bool EntityDisplayApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	setBackgroundColour(1, 1, 1);

	//Open shared memory to read object count
	HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"EntityCount");
	//Open shared memory to read array of objects
	HANDLE sizeHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"ArrayObjects");
	
	return true;
}

void EntityDisplayApp::shutdown() {
	
	CloseHandle(fileHandle);
	CloseHandle(sizeHandle);
	delete m_font;
	delete m_2dRenderer;
}

void EntityDisplayApp::update(float deltaTime) {

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	//Map memory for object count
	Entity* ENTITY_COUNT = (Entity*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(ENTITY_COUNT));
	//Read object count

	//Unmap memory for object count
	UnmapViewOfFile(fileHandle);

	//Map memory for object array
	Entity* m_entities = (Entity*)MapViewOfFile(sizeHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(m_entities));
	//Read object array

	//Unmap memory for object array
	UnmapViewOfFile(sizeHandle);
}

void EntityDisplayApp::draw() {

	clearScreen();

	m_2dRenderer->begin();

	for (auto& entity : m_entities) {
		m_2dRenderer->setRenderColour(entity.r, entity.g, entity.b);
		m_2dRenderer->drawBox(entity.x, entity.y, entity.size, entity.size, entity.rotation);
	}
	
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	m_2dRenderer->end();
}