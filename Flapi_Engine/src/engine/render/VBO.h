#pragma once
#include<iostream>
#include "glad/glad.h"

namespace Engine
{
	class VBO
	{
	public:
		VBO();

		void attachVertices(float* vertices, GLsizeiptr size);
		void bind();
		void unbind();
		void Delete();
	private:
		unsigned int ID;
	};

}