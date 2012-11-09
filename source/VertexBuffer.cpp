#include "VertexBuffer.hpp"

namespace ft
{

VertexBuffer::VertexBuffer()
{
	#ifdef D_VLOG_
		*Flog::getInstance() << "%tCreating VertexBuffer using default constructor\n";
	#endif
}
VertexBuffer::VertexBuffer(bool _useColor, bool _useTextures)
{
	#ifdef D_VLOG_
		*Flog::getInstance() << "%tCreating VertexBuffer using secondary constructor\n";
	#endif
}

bool VertexBuffer::generateBuffer(const ArrayType type)
{
	#ifdef D_VLOG_
		*Flog::getInstance() << "%tGenerating VBO of type: " << type << "\n";
	#endif
	
}

bool VertexBuffer::bufferVertexData(const ArrayType type,const GLsizei size,GLvoid* data,const GLenum usage)
{
	#ifdef D_VLOG_
		*Flog::getInstance() << "%tCreating VertexBuffer using default constructor\n";
	#endif

	glBindBuffer(GL_ARRAY_BUFFER,vertexObject);

}

void VertexBuffer::arrayPointer(const ArrayType type,const GLenum glType, const GLint size)
{
	
	glBindBuffer(GL_ARRAY_BUFFER,vertexObject);
	glVertexPointer(size,glType,0,0);
}

void VertexBuffer::drawArrays(const GLenum mode,const GLint first,const GLsizei count)
{
	glDrawArrays(mode,first,count);
}

bool VertexBuffer::drawElements(const GLenum mode)
{
}

}