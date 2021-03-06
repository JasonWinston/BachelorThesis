// author: dybisz

#include "glfw_renderer.h"
#include <time.h>
//#include <unistd.h>

CGLFWRenderer::CGLFWRenderer(Settings& settings) :
        _settings(settings),
        _camera(settings),
        _gui(settings, &_camera) {
    _initGLFW();
    _initWindow();
    _initInputOutput();
    _initGLEW();
    _initATWBar();
    _initCallbacks();
    _initRenderableObjects();
    _initGLGlobalSettings();
}

CGLFWRenderer::~CGLFWRenderer() {
    delete _inputOutput;
    delete _water;
    delete _skybox;
    delete _ship;
    _gui.terminateATW();
    glfwTerminate();
}

void CGLFWRenderer::runMainLoop() {
    vec3 forceMove(0.0, 0.0, 0.0);
    _inputOutput->setForceMove(&forceMove);
    do {
        /* ----- Calculate Time ----- */
        float deltaTime = _timer.tick();
        float renderTimeStart = (float) glfwGetTime();

        /* ----- Update Time ----- */
        _water->updateTime(deltaTime);
        _inputOutput->updateTime(deltaTime);

        /* ----- Update Waves ----- */
        _water->setWavesOn(_gui.getWavesOn());
        _water->setWavesAmplitude(_gui.getWavesAmplitude());
        _water->setWavesFrequency(_gui.getWavesFrequency());
        _water->setWavesChoppiness(_gui.getWavesChoppiness());
        _water->setWavesResolutionX(_gui.getWavesResolutionX());
        _water->setWavesResolutionY(_gui.getWavesResolutionY());

        /* ----- Camera Position ----- */
        _skybox->setCameraPosition(_camera.getPosition());
        _water->setCameraPosition(_camera.getPosition());

        /* ----- Light Direction ----- */
        _water->setLightDirections(_gui.getLightDirection());
        _ship->setDirectionalLight(_gui.getLightDirection());

        /* ----- Check Disturbance ----- */
        if (_inputOutput->isIntersectionRequested()) {
            vec2 viewportCoordinates =
                    _inputOutput->getIntersectionCoordinates();
            _water->areaIntersect(viewportCoordinates, _camera,
                                  _gui.getDisturbanceHeight(), _gui
                                          .getKernelSize(), _gui.getFlatness());
            _inputOutput->setIntersectionRequested(false);
        }

        /* ----- Check if Lights are On ----- */
        if(_gui.getLightOn() != _water->getLightOn()) {
            _water->setLightOn(_gui.getLightOn());
        }

        /* ----- Rain ----- */
        if (_gui.getIsRaining() && _gui.getWaterAnimation()) {
            for (int i = 0; i < _gui.getRainingIntensity(); i++) {
                int x = (int)
                        utils::randomInteger(50,
                                             _water->getVerticesPerSide() - 50);
                int y = (int) utils::randomInteger(50, _water->getVerticesPerSide() -
                                                       50);
                vec2 quadCoordinates(x, y);
                _water->pointIntersect(quadCoordinates, _gui.getRainDropSize()
                        ,_gui.getRainKernel(), _gui.getRainFlatness());

            }
        }

        /* ----- Ship Simulation Settings ----- */
        _gui.setMovementForce(forceMove);
        _ship->setMovementForce(forceMove);
        _ship->setComputationalGridVisibility(_gui.getGridVisibility());
        _ship->setModelLocalTranslation(_gui.getModelLocalTranslation());
        _ship->setModelScale(_gui.getModelScale());
        _ship->setModelLinearDamping(_gui.getLinearDamping());
        _ship->setModelAngularDamping(_gui.getAngularDamping());
//        if(forceMove.x > 0.0f) {
//            vec3 shipPosition = _ship->getShipPosition();
//            vec2 shipPositionOnGrid(shipPosition.x + 5.0f, shipPosition.z
//                                                           + 5.0f);
//            _water->strictWaterGridDisturbance(shipPositionOnGrid,
//                                  _gui.getDisturbanceHeight(), _gui
//                                          .getKernelSize(), _gui.getFlatness());
//        }


        /* ----- Check Stop Scene ----- */
        if (_gui.getWaterAnimation() != _water->getAnimation()) {
            _water->setAnimation(_gui.getWaterAnimation());
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        /* ----- Render Scene ----- */
        _skybox->render(&_camera.getViewMatrix()[0][0],
                        &_camera.getProjectionMatrix()[0][0]);

        _water->render(&_camera.getViewMatrix()[0][0],
                       &_camera.getProjectionMatrix()[0][0]);


        _ship->updateComputationalGrid(_water->getHeightfieldAsArray(),
                                       _settings.quads,
                                       _settings.quads, _settings.edgeSize);
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        _ship->render(&_camera.getViewMatrix()[0][0],
                      &_camera.getProjectionMatrix()[0][0]);
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        TwDraw();
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
    while (glfwGetKey(_window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(_window) == 0);
}

void CGLFWRenderer::_initGLFW() {
    if (!initGLFW()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
    }
}

void CGLFWRenderer::_initWindow() {
    _window = initGLFWWindow(_settings.windowWidth, _settings.windowHeight,
                             "Bachelor Thesis - Bartlomiej Dybisz",
                             _settings.fullScreen ? glfwGetPrimaryMonitor() : NULL);
}

void CGLFWRenderer::_initInputOutput() {
    _inputOutput = new CGLFWInputOutput(_window);
    _inputOutput->setCamera(&_camera);
}

void CGLFWRenderer::_initGLEW() {
    if(!utils::initGLEW()) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
    }
}

void CGLFWRenderer::_initATWBar() {
    _gui.initializeATW();
    _gui.initializeWaterBar();
    _gui.initializeShipBar();
    _gui.initializeSceneBar();
    _gui.initializeControlsBar();
}

void CGLFWRenderer::_initCallbacks() {
    glfwSetMouseButtonCallback(_window, CGLFWInputOutput::mouse_button_callback);
    glfwSetCursorPosCallback(_window, (GLFWcursorposfun) TwEventMousePosGLFW);
    glfwSetScrollCallback(_window, (GLFWscrollfun) TwEventMouseWheelGLFW);
    glfwSetKeyCallback(_window, (GLFWkeyfun) TwEventKeyGLFW);
    glfwSetCharCallback(_window, (GLFWcharfun) TwEventCharGLFW);
}

void CGLFWRenderer::_initRenderableObjects() {
    _skybox = CSkyboxBuilder()
            .setSideSize(_settings.edgeSize)
            .build();

    _water = CWaterBuilder()
            .setQuadsPerSide(_settings.quads)
            .setSideSize(_settings.edgeSize)
            .setBottomCorner(vec2(-_settings.edgeSize / 2.0,
                                  -_settings.edgeSize / 2.0))
            .setModernShaders(false)
            .setSkyboxId(_skybox->getCubemapId())
            .setViewport(_settings.windowWidth, _settings.windowHeight)
            .setAnimation(true)
            .setLightOn(false)
            .build();

    _ship = new CShipModel(_settings);
}

void CGLFWRenderer::_initGLGlobalSettings() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}