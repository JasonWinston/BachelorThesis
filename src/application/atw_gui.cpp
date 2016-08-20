// author: dybisz

#include "atw_gui.h"

CAtwGui::CAtwGui(Settings &settings, CCustomCamera *camera)
        : _settings(settings), _camera(camera), _emptyBoxesOn(false) {
    _disturbanceHeight = _settings.manualDisturbanceStrength;
    _isRaining = _settings.rain;
    _rainIntensity = _settings.rainIntensity;
    _rainDropSize = _settings.rainStrength;
    _waterAnimation = _settings.animation;
    _lightOn = _settings.lightOn;
    _lightDirection = vec3
            {
                    _settings.lightDirectionX,
                    _settings.lightDirectionY,
                    _settings.lightDirectionZ
            };
    _modelBoxesOn = _settings.modelBoxes;
    _emptyBoxesOn = _settings.emptyBoxes;
    _kernelSize = _settings.manualDisturbanceKernel;
    _flatness = _settings.manualDisturbanceFlatness;
    _rainKernel = _settings.rainKernelSize;
    _rainFlatness = _settings.rainFlatness;
    _wavesOn = _settings.waves;
    _wavesAmplitude = _settings.wavesAmplitude;
    _wavesFrequency = _settings.wavesFrequency;
    _wavesResolutionX = _settings.wavesResolutionX;
    _wavesResolutionY = _settings.wavesResolutionY;
    _wavesChoppiness = _settings.wavesChoppiness;
}

void CAtwGui::initializeATW() {
    TwInit(TW_OPENGL, NULL);
    TwWindowSize(_settings.windowWidth, _settings.windowHeight);
}

void CAtwGui::initializeWaterBar() {
    _waterBar = CAtwBarBuilder()
            .setLabel("Water")
            .setPosition((int) _settings.guiMargin, (int) _settings.guiMargin)
            .setContained(true)
            .setColor(0, 128, 128)
            .setSize(240, 350)
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("animationOnOf")
            .setDataType(TW_TYPE_BOOL32)
            .setObservableData(&_waterAnimation)
            .setLabel("On / Off:")
            .setGroup("Animation")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("disturbanceStrength")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_disturbanceHeight)
            .setLabel("Strength:")
            .setStep(0.1)
            .setGroup("Manual_Disturbance")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("kernelSize")
            .setDataType(TW_TYPE_INT32)
            .setObservableData(&_kernelSize)
            .setLabel("Kernel:")
            .setStep(1)
            .setGroup("Manual_Disturbance")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("flatness")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_flatness)
            .setLabel("Flatness:")
            .setStep(0.1)
            .setGroup("Manual_Disturbance")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("isRaining")
            .setDataType(TW_TYPE_BOOL32)
            .setObservableData(&_isRaining)
            .setLabel("On / Off:")
            .setGroup("Rain")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("rainHeight")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_rainDropSize)
            .setLabel("Strength:")
            .setStep(0.1)
            .setGroup("Rain")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("rainKernelSize")
            .setDataType(TW_TYPE_INT32)
            .setObservableData(&_rainKernel)
            .setLabel("Kernel:")
            .setStep(1)
            .setGroup("Rain")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("rainFlatness")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_rainFlatness)
            .setLabel("Flatness:")
            .setStep(0.1)
            .setGroup("Rain")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("rainIntensity")
            .setDataType(TW_TYPE_INT32)
            .setObservableData(&_rainIntensity)
            .setLabel("Intensity:")
            .setStep(1.0)
            .setGroup("Rain")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("wavesOn")
            .setDataType(TW_TYPE_BOOL32)
            .setObservableData(&_wavesOn)
            .setLabel("On / Off:")
            .setGroup("Waves")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("wavesFrequency")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_wavesFrequency)
            .setLabel("Frequency:")
            .setStep(0.01)
            .setGroup("Waves")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("wavesAmplitude")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_wavesAmplitude)
            .setLabel("Amplitude:")
            .setStep(0.01)
            .setGroup("Waves")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("wavesChoppiness")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_wavesChoppiness)
            .setLabel("Choppiness:")
            .setStep(0.1)
            .setGroup("Waves")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("wavesResolutionX")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_wavesResolutionX)
            .setLabel("Resolution (X):")
            .setStep(0.01)
            .setGroup("Waves")
            .build();

    CAtwVarBuilder()
            .setOwner(_waterBar)
            .setId("wavesResolutionY")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_wavesResolutionY)
            .setLabel("Resolution (Y):")
            .setStep(0.01)
            .setGroup("Waves")
            .build();
}

void CAtwGui::initializeSceneBar() {
    _sceneBar = CAtwBarBuilder()
            .setLabel("Scene")
            .setPosition
                    (
                            _settings.windowWidth - 195 - _settings.guiMargin,
                            0 + _settings.guiMargin
                    )
            .setContained(true)
            .setColor(0, 128, 128)
            .setSize(240, 470)
            .setRefresh(0.1)
            .build();

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("windowWidth")
            .setDataType(TW_TYPE_INT32)
            .setObservableData(&_settings.windowWidth)
            .setLabel("Width")
            .setGroup("Window")
            .setReadOnly(true)
            .build();

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("windowHeight")
            .setDataType(TW_TYPE_INT32)
            .setObservableData(&_settings.windowHeight)
            .setLabel("Height")
            .setGroup("Window")
            .setReadOnly(true)
            .build();

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("emptyBoxesOnOff")
            .setDataType(TW_TYPE_BOOL32)
            .setObservableData(&_modelBoxesOn)
            .setLabel("Empty Boxes On / Off")
            .setGroup("Bounding")
            .build();

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("modelBoxesOnOff")
            .setDataType(TW_TYPE_BOOL32)
            .setObservableData(&_emptyBoxesOn)
            .setLabel("Model Boxes On / Off")
            .setGroup("Bounding2")
            .build();


    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("lightOnOff")
            .setDataType(TW_TYPE_BOOL32)
            .setObservableData(&_lightOn)
            .setLabel("On / Off")
            .setGroup("Light")
            .build();

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("direction")
            .setDataType(TW_TYPE_DIR3F)
            .setObservableData(&_lightDirection)
            .setLabel("Direction")
            .setGroup("Light")
            .setOpened(true)
            .setShowVal(true)
            .build();

    TwStructMember pointMembers[] = {
            {"X", TW_TYPE_FLOAT, offsetof(vec3, x), "step=0.1"},
            {"Y", TW_TYPE_FLOAT, offsetof(vec3, y), "step=0.1"},
            {"Z", TW_TYPE_FLOAT, offsetof(vec3, z), "step=0.1"}
    };
    TwType pointType = TwDefineStruct("POINT", pointMembers, 3, sizeof(vec3),
                                      NULL, NULL);

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("cameraPos")
            .setDataType(pointType)
            .setObservableData(&_camera->_position)
            .setLabel("Position")
            .setGroup("Position")
            .build();

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("horizontalAngle")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_camera->_horizontalAngle)
            .setLabel("Horizontal")
            .setGroup("Angle")
            .build();

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("verticalAngle")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_camera->_verticalAngle)
            .setLabel("Vertical")
            .setGroup("Angle")
            .build();

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("fovAngle")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_camera->_fov)
            .setLabel("FoV")
            .setGroup("Angle")
            .build();

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("movementSpeed")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_camera->_movementSpeed)
            .setLabel("Movement")
            .setGroup("Speed")
            .build();

    CAtwVarBuilder()
            .setOwner(_sceneBar)
            .setId("angularSpeed")
            .setDataType(TW_TYPE_FLOAT)
            .setObservableData(&_camera->_angularSpeed)
            .setLabel("Angular")
            .setStep(0.01)
            .setGroup("Speed")
            .build();

    TwDefine("Scene/cameraPos opened=true");
    TwDefine("Scene/cameraPos group=Camera");
    TwDefine("Scene/Angle group=Camera");
    TwDefine("Scene/Speed group=Camera");
}

void CAtwGui::initializeControlsBar() {
    int width = 240;
    int height = 105;
    _controlsBar = CAtwBarBuilder()
            .setLabel("Controls")
            .setSize(width, height)
            .setContained(true)
            .setPosition(
                    (int) (_settings.windowWidth - 195 - _settings.guiMargin),
                    (int) (_settings.windowHeight - _settings.guiMargin -
                           height))
            .setAlpha(0)
            .setFontsize(1)
            .setColor(0, 128, 128)
            .build();

    CAtwButtonBuilder()
            .setOwner(_controlsBar)
            .setLabel("W, S, A, D  - move around")
            .build();

    CAtwButtonBuilder()
            .setOwner(_controlsBar)
            .setLabel("Z, X         - move up / down")
            .build();

    CAtwButtonBuilder()
            .setOwner(_controlsBar)
            .setLabel("LMB         - disturb water")
            .build();

    CAtwButtonBuilder()
            .setOwner(_controlsBar)
            .setLabel("RMB         - look around")
            .build();
}

void CAtwGui::terminateATW() {
    TwTerminate();
}

float CAtwGui::getDisturbanceHeight() {
    return _disturbanceHeight;
}

int CAtwGui::getKernelSize() {
    return _kernelSize;
}

float CAtwGui::getFlatness() {
    return _flatness;
}

bool CAtwGui::getIsRaining() {
    return _isRaining;
}

int CAtwGui::getRainingIntensity() {
    return _rainIntensity;
}

float CAtwGui::getRainDropSize() {
    return _rainDropSize;
}

vec3 &CAtwGui::getLightDirection() {
    return _lightDirection;
}

bool CAtwGui::getWaterAnimation() {
    return _waterAnimation;
}

bool CAtwGui::getLightOn() {
    return _lightOn;
}

bool CAtwGui::getModelBoxesOn() {
    return _modelBoxesOn;
}

bool CAtwGui::getEmptyBoxesOn() {
    return _emptyBoxesOn;
}

int   CAtwGui::getRainKernel() {
    return _rainKernel;
}

float CAtwGui::getRainFlatness() {
    return _rainFlatness;
}

bool CAtwGui::getWavesOn() {
    return _wavesOn;
}

float CAtwGui::getWavesAmplitude() {
    return _wavesAmplitude;
}

float CAtwGui::getWavesFrequency() {
    return _wavesFrequency;
}

float CAtwGui::getWavesChoppiness() {
    return _wavesChoppiness;
}

float CAtwGui::getWavesResolutionX() {
    return _wavesResolutionX;
}

float CAtwGui::getWavesResolutionY() {
    return _wavesResolutionY;
}