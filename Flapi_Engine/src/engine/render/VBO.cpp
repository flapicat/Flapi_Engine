#include "VBO.h"

namespace Engine
{
	VBO::VBO()
	{
	}
	void VBO::attachVertices(float* vertices, GLsizeiptr size)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	void VBO::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}

	void VBO::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VBO::Delete()
	{
		glDeleteBuffers(1, &ID);
	}
}