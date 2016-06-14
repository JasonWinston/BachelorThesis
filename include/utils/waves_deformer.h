//==============================================================================
// TODO underline that this is kind of double frame buffer, which renders
// TODO stuff offscreen hence it has to have some association with renderable
// TODO object
//==============================================================================
// author: dybisz
//------------------------------------------------------------------------------

#ifndef WAVES_DEFORMER_H
#define WAVES_DEFORMER_H

#include <GL/glew.h>
#include <iostream>
#include "buffers/frame_buffer.h"
#include "textures/texture_2D.h"
#include "glsl_shader.h"
#include "vertex_array.h"
#include "vertex.h"
#include "quad.h"
#include "error_handling.h"
#include <math.h>

using namespace rendering;
using namespace geometry;
using namespace glm;
using namespace utils;
using namespace std;

class CWavesDeformer{

public:
    // input # vertices in row & column !!!
    CWavesDeformer(int width, int height);

    ~CWavesDeformer();
    /**
     * Appropriate Texture unit must be binded befor calling this procedure.
     *
     * After effects:
     * > texture with next sep of te animation binded to GL_TEXTURE_2D
     * > glVieport changed to size o the texture, hence one must regain its
     * original values. It saves sending data about screen resolution and
     * makes this function somehow independent.
     *
     */
    void animationStep();
    void bindTexture();
    void unbindTexture();
    void pointDisturbance(vec2& quad, float amount);
    void areaDisturbance(vec2& quad, float amount, int kernel, float flatness);
    void updateTime(float deltaT);
private:
    GLsizei _width;
    GLsizei _height;
    GLuint _verticesPerSide;
    CFrameBuffer *_fbo0;
    CFrameBuffer *_fbo1;
    CTexture2D *_tex0;
    CTexture2D *_tex1;
    GLSLShader _shader;
    CVertexArray _vao;
    CQuad _quad;
    GLfloat _h;
    GLfloat _c;
    GLfloat _dt;
    void _initShaders();
    void _initVao();
    void _initMembraneCoefficients();
};


#endif
