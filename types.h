#pragma once

#include <NvFlex.h>
#include <NvFlexExt.h>
#include <NvFlexDevice.h>

#include "GarrysMod/Lua/Interface.h"

struct float4 {
    float x, y, z, w;
};

struct float3 {
    float x, y, z;
};

struct Particle {
    float4 pos;
    float3 vel;
};

struct Prop {
    NvFlexBuffer* verts;
    NvFlexBuffer* indices;
    NvFlexTriangleMeshId meshID;
    
    float4 pos;
    float4 lastPos;

    float4 ang;
    float4 lastAng;

    int ID;
};


class flexAPI {
public:
    NvFlexLibrary* flexLibrary;
    NvFlexSolver* flexSolver;

    NvFlexBuffer* particleBuffer;
    NvFlexBuffer* velocityBuffer;
    NvFlexBuffer* phaseBuffer;
    NvFlexBuffer* activeBuffer;

    NvFlexBuffer* geometryBuffer;
    NvFlexBuffer* geoFlagsBuffer;
    NvFlexBuffer* geoPosBuffer;
    NvFlexBuffer* geoQuatBuffer;

    NvFlexBuffer* geoPrevPosBuffer;
    NvFlexBuffer* geoPrevQuatBuffer;

    NvFlexParams* flexParams;
    NvFlexSolverDesc flexSolverDesc;

    void addParticle(Vector pos, Vector vel);
    void calcMesh(GarrysMod::Lua::ILuaBase* LUA, const float* minFloat, const float* maxFloat, size_t tableLen, Prop* p);
    void flexSolveThread();
};

