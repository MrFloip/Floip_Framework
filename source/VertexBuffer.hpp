#ifndef _VERTEXBUFFER_HPP_
#define _VERTEXBUFFER_HPP_
#include "include_gl.hpp"
#include "flog.hpp"

namespace ft
{

enum ArrayType
{
	COLOR_ARRAY = 1,
	VERTEX_ARRAY = 2,
	INDEX_ARRAY = 3,
	TEXTURE_COORD_ARRAY = 4
};

class VertexBuffer
{
protected:
	GLuint vertexObject;
public:
	VertexBuffer();
	VertexBuffer(const bool _useColor, const bool _useTexture);
	virtual ~VertexBuffer(){}

	virtual bool generateBuffer(const ArrayType type);
	virtual bool bufferVertexData(const ArrayType type,const GLsizei size,GLvoid* data,const GLenum usage);
	virtual void arrayPointer(const ArrayType type,GLenum glType, const GLint size);
	virtual void drawArrays(const GLenum mode,const GLint first,const GLsizei count);
	virtual bool drawElements(const GLenum mode);
};

}
#endif