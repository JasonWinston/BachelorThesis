//==============================================================================
// All parameters of the application are assumed to be passed via one object.
// Following structure fulfils this assumption, encapsulating all values that
// can be tweaked either dynamically, or before application run.
//==============================================================================
// author: dybisz
//------------------------------------------------------------------------------

#ifndef SETTINGS_STRUCT_H
#define SETTINGS_STRUCT_H

namespace utils {
    struct Settings {

//==============================================================================
// Scene Properties
//------------------------------------------------------------------------------
        bool  fullScreen;
        int   windowWidth;
        int   windowHeight;
        float edgeSize;
        int   quads;

//==============================================================================
// Simulation Properties
//------------------------------------------------------------------------------
        float linearDamping;
        float angularDamping;
        float modelLocalTranslationX;
        float modelLocalTranslationY;
        float modelLocalTranslationZ;
        float modelScale;
        bool  gridVisibility;
        float enginesPointX;
        float enginesPointY;
        float enginesPointZ;

//==============================================================================
// Light Properties
//------------------------------------------------------------------------------
        bool  lightOn;
        float lightDirectionX;
        float lightDirectionY;
        float lightDirectionZ;

//==============================================================================
// GUI Properties
//------------------------------------------------------------------------------
        float guiMargin;

//==============================================================================
// Camera Properties
//------------------------------------------------------------------------------
        float cameraStartPositionX;
        float cameraStartPositionY;
        float cameraStartPositionZ;
        float cameraHorizontalAngle;
        float cameraVerticalAngle;
        float cameraFov;
        float cameraMovementSpeed;
        float cameraAngularSpeed;

//==============================================================================
// Water Properties
//------------------------------------------------------------------------------
        bool  animation;
        float manualDisturbanceStrength;
        int   manualDisturbanceKernel;
        float manualDisturbanceFlatness;
        bool  rain;
        float rainStrength;
        int   rainIntensity;
        int   rainKernelSize;
        float rainFlatness;
        bool  waves;
        float wavesAmplitude;
        float wavesFrequency;
        float wavesChoppiness;
        float wavesResolutionX;
        float wavesResolutionY;
    };
}

#endif
