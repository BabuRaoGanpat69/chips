#include "mesh.hpp"

void MESH::Bind_data() {
  // create and bind VAO you need it as this is what that stores your layout
  // when you call glattribpointer

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  // create VBO and EBO
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &VBO);
  // BIND them to buffer
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  // move the data
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0],
               GL_STATIC_DRAW);
  // telling the opengl how to read data
  // offsetof is inside cstddef gives offset
  // enable all the attributes
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void *)(offsetof(Vertex, normals)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void *)(offsetof(Vertex, colors)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void *)(offsetof(Vertex, texcoords)));
  // moving data
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size(), &indices[0],
               GL_STATIC_DRAW);
  glBindVertexArray(0);
  // draw will be in draw function
};
MESH::MESH(std::vector<Vertex> vertices, Materials materials,
           std::vector<unsigned int> indices, std::vector<Texture> textures) {
  this->vertices = vertices;
  this->materials = materials;
  this->indices = indices;
  this->textures = textures;
  Bind_data();
}
MESH::~MESH() {
  // deleting the buffers
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}
