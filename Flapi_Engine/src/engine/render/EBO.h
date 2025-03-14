#pragma once
#include "glad/glad.h"

namespace Engine
{
	class EBO
	{
	public:
		EBO();

		void attachIndices(unsigned int* indices, GLsizeiptr size);
		void bind();
		void unbind();
		void Delete();
	private:
		unsigned int ID;
	};

}