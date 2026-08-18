#ifndef MESH_HPP
#define MESH_HPP
#include <cstddef>
#include <glad/glad.h> // holds all OpenGL type declarations
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <istream>
#include <string>
#include <vector>
struct Materials {
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;
  float shininess;
};
struct Vertex {
  glm::vec3 position;
  glm::vec3 normals;
  glm::vec3 colors;
  glm::vec2 texcoords;
};
struct Texture {
  std::string path;
  std::string id;
};

class MESH {
public:
  Materials materials;
  std::vector<unsigned int> indices;
  std::vector<Texture> textures;
  std::vector<Vertex> vertices;
  MESH(std::vector<Vertex> vertices, Materials materials,
       std::vector<unsigned int> indices, std::vector<Texture> textures);
  void Bind_data();
  ~MESH();

public:
  unsigned int VAO, VBO, EBO;
};
#endif
