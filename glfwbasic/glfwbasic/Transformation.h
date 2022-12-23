#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Transformation
{

public:
	/// <summary>
	/// Transformation class will store the sprites or gameObjects position 
	/// and will allow users or class that wish to access the store values.
	/// </summary>
	float x = 0;
	float y = 0;
	float z = 0;
	glm::vec3 Position = { x,y,z };

	glm::vec3 rotation = glm::vec3(0.0f);
	glm::vec3 translate = glm::vec3(0.0f);
	glm::vec3 scale = glm::vec3(1.0f);

	glm::mat4 trans = glm::rotate(trans, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));


	Transformation();
	~Transformation();
};
