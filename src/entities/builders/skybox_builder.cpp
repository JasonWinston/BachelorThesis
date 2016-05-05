// author: dybisz

#include "skybox_builder.h"

using namespace entities;

const float CSkyboxBuilder::defaultSideSize = 32.0f;
vector<const GLchar *> *CSkyboxBuilder::defaultFaces = new vector<const
GLchar *>(
                {
                        "./res/textures/skybox/alt2/front.tga",
                        "./res/textures/skybox/alt2/back.tga",
                        "./res/textures/skybox/alt2/up.tga",
                        "./res/textures/skybox/alt2/down.tga",
                        "./res/textures/skybox/alt2/right.tga",
                        "./res/textures/skybox/alt2/left.tga"});

//vector<const GLchar *> *CSkyboxBuilder::defaultFaces = new vector<const
//GLchar *>(
//        {
//                "./res/textures/skybox/alternative/front.jpg",
//                "./res/textures/skybox/alternative/back.jpg",
//                "./res/textures/skybox/alternative/top.jpg",
//                "./res/textures/skybox/alternative/bottom.jpg",
//                "./res/textures/skybox/alternative/right.jpg",
//                "./res/textures/skybox/alternative/left.jpg"});

//vector<const GLchar *> *CSkyboxBuilder::defaultFaces = new vector<const
//GLchar *>(
//        {
//                "./res/textures/skybox/sor_sea/front.jpg",
//                "./res/textures/skybox/sor_sea/back.jpg",
//                "./res/textures/skybox/sor_sea/top.jpg",
//                "./res/textures/skybox/sor_sea/bottom.jpg",
//                "./res/textures/skybox/sor_sea/right.jpg",
//                "./res/textures/skybox/sor_sea/left.jpg"});

const bool CSkyboxBuilder::defaultModernShaders = false;


CSkyboxBuilder::CSkyboxBuilder() {
    _sideSize = defaultSideSize;
    _faces = defaultFaces;
//    _faces->push_back("./res/textures/skybox/alt2/front.tga");
//    _faces->push_back("./res/textures/skybox/alt2/back.tga");
//    _faces->push_back("./res/textures/skybox/alt2/up.tga");
//    _faces->push_back("./res/textures/skybox/alt2/down.tga");
//    _faces->push_back("./res/textures/skybox/alt2/right.tga");
//    _faces->push_back("./res/textures/skybox/alt2/left.tga");

    _modernShaders = defaultModernShaders;
};

CSkyboxBuilder::~CSkyboxBuilder() {

}

CSkybox *CSkyboxBuilder::build() {
    return new CSkybox(this->_sideSize, this->_faces, this->_modernShaders);
}

CSkyboxBuilder &CSkyboxBuilder::setSideSize(const float sideSize) {
    this->_sideSize = sideSize;
    return *this;
}

CSkyboxBuilder &CSkyboxBuilder::setFaces(vector<const GLchar *> *faces) {
    this->_faces = faces;
    return *this;
}

CSkyboxBuilder &CSkyboxBuilder::setModernShaders(const bool modernShaders) {
    this->_modernShaders = modernShaders;
    return *this;
}