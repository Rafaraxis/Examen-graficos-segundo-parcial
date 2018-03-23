// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <math.h>
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"


#include <iostream>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "Nave.h"


using namespace std;

GLfloat red, green, blue;

GLuint posicionID;
GLuint colorID;
GLuint transformacionesID;

Nave *nave;
Modelo *cielo;
Modelo *cuadrado;
Modelo *puerta;
Modelo *ventana;
Modelo *pajaro;
Modelo *lineapuerta;
Modelo *lineaventana;



Shader *shader;
//Declaración de ventana
GLFWwindow *window;

/*void actualizar() { 
	int estadoDerecha = 
		glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		nave->rotarNave(1);
	}

	int estadoIzquierda =
		glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		nave->rotarNave(0);
	}

	int estadoArriba =
		glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		nave->moverNave();
	}
	
	
}*/

void actualizar()
{
	pajaro->transformaciones = translate(pajaro->transformaciones, vec3(0.0001f, 0.0f, 0.0f));
	pajaro->transformaciones = rotate(pajaro->transformaciones, 0.000004f, vec3(0.0f, 1.0f, 0.0f));


}

void dibujar() {
	cielo->dibujar(GL_QUADS);
	cuadrado->dibujar(GL_POLYGON);
	nave->dibujar(GL_POLYGON);
	
	puerta->dibujar(GL_QUADS);
	ventana->dibujar(GL_QUADS);
	lineapuerta->dibujar(GL_LINES);
	lineaventana->dibujar(GL_LINES);
	pajaro->dibujar(GL_POLYGON);
}
void inicializarCielo() {
	cielo = new Modelo();
	Vertice v1 =
	{ vec4(-1.0f,1.0f,0.0f,1.0f), vec4(0.0f,0.0f,1.0f,0.0f) };
	Vertice v2 =
	{ vec4(1.0f,1.0f,0.0f,1.0f), vec4(0.0f,0.0f,1.0f,0.0f) };
	Vertice v3 =
	{ vec4(1.0f,-1.0f,0.0f,1.0f), vec4(0.0f,0.0f,1.0f,0.0f) };
	Vertice v4 =
	{ vec4(-1.0f,-1.0f,0.0f,1.0f), vec4(0.0f,0.0f,1.0f,0.0f) };
	cielo->vertices.push_back(v1);
	cielo->vertices.push_back(v2);
	cielo->vertices.push_back(v3);
	cielo->vertices.push_back(v4);
}

void inicializarCuadrado() {
	cuadrado = new Modelo();
	Vertice v1 =
	{ vec4(-0.3f,-0.3f,0.0f,1.0f), vec4(1.0f,0.0f,0.0f,0.0f) };
	Vertice v2 =
	{ vec4(-0.3f,0.3f,0.0f,1.0f), vec4(1.0f,0.0f,0.0f,0.0f) };
	Vertice v3 =
	{ vec4(0.3f,0.3f,0.0f,1.0f), vec4(1.0f,0.0f,0.0f,0.0f) };
	Vertice v4 =
	{ vec4(0.3f,-0.3f,0.0f,1.0f), vec4(1.0f,0.0f,0.0f,0.0f) };
	cuadrado->vertices.push_back(v1);
	cuadrado->vertices.push_back(v2);
	cuadrado->vertices.push_back(v3);
	cuadrado->vertices.push_back(v4);
}

void inicializarFigura() {
	nave = new Nave();
	Vertice v1 =
	{ vec4(-0.5f,0.2f,0.0f,1.0f), vec4(1.0f,0.0f,1.0f,1.0f) };
	Vertice v2 =
	{ vec4(0.0f,0.9f,0.0f,1.0f), vec4(1.0f,0.0f,1.0f,1.0f) };
	Vertice v3 =
	{ vec4(0.5f,0.2f,0.0f,1.0f), vec4(1.0f,0.0f,1.0f,1.0f) };
	nave->vertices.push_back(v1);
	nave->vertices.push_back(v2);
	nave->vertices.push_back(v3);
}



void inicializarPuerta()
{
	puerta = new Modelo();
	Vertice v1 = 
	{ vec4(-0.1f,-0.3f,0.0f,1.0f), vec4(1.0f,0.0f,1.0f,1.0f) };
	Vertice v2 =
	{ vec4(-0.1f,0.0f,0.0f,1.0f), vec4(1.0f,0.0f,1.0f,1.0f) };
	Vertice v3 =
	{ vec4(0.1f,0.0f,0.0f,1.0f), vec4(1.0f,0.0f,1.0f,1.0f) };
	Vertice v4 =
	{ vec4(0.1f,-0.3f,0.0f,1.0f), vec4(1.0f,0.0f,1.0f,1.0f) };
	puerta->vertices.push_back(v1);
	puerta->vertices.push_back(v2);
	puerta->vertices.push_back(v3);
	puerta->vertices.push_back(v4);

}

void inicializarlineap()
{
	lineapuerta = new Modelo();
	Vertice v1 =
	{ vec4(0.0f,-0.3f,0.0f,1.0f), vec4(1.0f,1.0f,1.0f,1.0f) };
	Vertice v2 =
	{ vec4(0.0f,0.0f,0.0f,1.0f), vec4(1.0f,1.0f,1.0f,1.0f) };
	lineapuerta->vertices.push_back(v1);
	lineapuerta->vertices.push_back(v2);
}

void inicializarVentana() {
	ventana = new Modelo();
	Vertice v1 =
	{ vec4(-0.1f,0.1f,0.0f,1.0f), vec4(1.0f,1.0f,1.0f,1.0f) };
	Vertice v2 =
	{ vec4(-0.1f,0.2f,0.0f,1.0f), vec4(1.0f,1.0f,1.0f,1.0f) };
	Vertice v3 =
	{ vec4(0.1f,0.2f,0.0f,1.0f), vec4(1.0f,1.0f,1.0f,1.0f) };
	Vertice v4 =
	{ vec4(0.1f,0.1f,0.0f,1.0f), vec4(1.0f,1.0f,1.0f,1.0f) };
	ventana->vertices.push_back(v1);
	ventana->vertices.push_back(v2);
	ventana->vertices.push_back(v3);
	ventana->vertices.push_back(v4);
}

void inicializarlineaventana()
{
	lineaventana = new Modelo();
	Vertice v1 =
	{ vec4(0.0f,0.1f,0.0f,1.0f), vec4(0.0f,0.0f,0.0f,0.0f) };
	Vertice v2 =
	{ vec4(0.0f,0.2f,0.0f,1.0f), vec4(0.0f,0.0f,0.0f,0.0f) };
	lineaventana->vertices.push_back(v1);
	lineaventana->vertices.push_back(v2);
}

void inicializarPajaro() {
	pajaro = new Modelo();
	Vertice v1 =
	{ vec4(-0.1f,0.0f,0.0f,1.0f), vec4(1.0f,1.0f,1.0f,1.0f) };
	Vertice v2 =
	{ vec4(0.0f,0.1f,0.0f,1.0f), vec4(1.0f,1.0f,1.0f,1.0f) };
	Vertice v3 =
	{ vec4(0.1f,0.0f,0.0f,1.0f), vec4(1.0f,1.0f,1.0f,1.0f) };
	pajaro->vertices.push_back(v1);
	pajaro->vertices.push_back(v2);
	pajaro->vertices.push_back(v3);
}


int main()
{
	
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicialización de GLFW
	if (!glfwInit()) {
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se creó bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}



	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;


	red = green = blue = 0.75f;

	inicializarCielo();
	inicializarCuadrado();
	inicializarFigura();
	inicializarPuerta();
	inicializarVentana();
	inicializarlineap();
	inicializarlineaventana();
	inicializarPajaro();
	

	//Crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";
	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID =
		glGetAttribLocation(shader->getID(), "posicion");
	colorID =
		glGetAttribLocation(shader->getID(), "color");
	transformacionesID =
		glGetUniformLocation(shader->getID(), "transformaciones");

	//Desenlazar shader
	shader->desenlazarShader();

	cielo->shader = shader;
	cielo->inicializarVertexArray(posicionID, colorID, transformacionesID);

	nave->shader = shader;
	nave->inicializarVertexArray(posicionID, colorID, transformacionesID);

	cuadrado->shader = shader;
	cuadrado->inicializarVertexArray(posicionID, colorID, transformacionesID);

	puerta->shader = shader;
	puerta->inicializarVertexArray(posicionID, colorID, transformacionesID);

	ventana->shader = shader;
	ventana->inicializarVertexArray(posicionID, colorID, transformacionesID);

	
	lineapuerta->shader = shader;
	lineapuerta->inicializarVertexArray(posicionID, colorID, transformacionesID);

	lineaventana->shader = shader;
	lineaventana->inicializarVertexArray(posicionID, colorID, transformacionesID);
	
	pajaro->shader = shader;
	pajaro->inicializarVertexArray(posicionID, colorID, transformacionesID);


	
	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo

		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

