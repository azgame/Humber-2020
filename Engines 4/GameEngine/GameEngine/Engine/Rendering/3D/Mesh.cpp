#include "Mesh.h"


Mesh::Mesh(std::vector<Vertex>* vertexList_) : vertexList(std::vector<Vertex>()), VAO(0), VBO(0) {
	vertexList.reserve(100);
	vertexList = *vertexList_;
	GenerateBuffers();
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Mesh::Render() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertexList.size());
	glBindVertexArray(0);
}

void Mesh::GenerateBuffers() {
	//Generate arrays and buffers
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

    //Bind the arrays and buffers
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//Pass in data, make sure to * by size of data type.
	glBufferData(GL_ARRAY_BUFFER, vertexList.size() * sizeof(Vertex), &vertexList[0], GL_STATIC_DRAW);

	//POSITION
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	//NORMAL
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));

	//TEX COORDS
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));

	//COLOUR
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, colour));
	
	//Unbind array and buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
