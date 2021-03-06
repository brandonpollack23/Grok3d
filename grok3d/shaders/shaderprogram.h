/* Copyright (c) 2018 Brandon Pollack
* Contact @ grok3d@gmail.com
* This file is available under the MIT license included in the project
*/

#ifndef __SHADERPROGRAM__H
#define __SHADERPROGRAM__H

/** @file
 * This class manages compiling and lifetime of shaders*/

#include "grok3d/grok3d_types.h"

#include "grok3d/glad/glad/glad.h"

// TODO make shaderhandles work like texturehandles
/**
 * @brief A set of functions that manage lifetime of shaders and returns handles to them to unload
 *
 * @detail
 * All shaders need to be loaded and compiled at runtime due to different implementations of
 * openGL, this is super driver/card dependent.  these functions do that for you and allow you to
 * access them or unload them when you want with an id*/
namespace Grok3d::Shaders {
/** This is the shader ID number, also to be passed to OGL to use the shader*/
using GRK_ShaderID = GLuint;
using GRK_UniformID = GLuint;
using GRK_ShaderProgramID = GLuint;

class ShaderProgram {
 public:
  ShaderProgram(const char* vertexShader, const char* fragmentShader);

  auto GetId() const -> GRK_ShaderProgramID;
 protected:
  GRK_ShaderProgramID shaderProgramId_;
};

/** compiles the source of a shader program, and returns a handle*/
auto LoadShader(const char* shaderSource, ShaderType type) -> GRK_ShaderID;

/** compiles shader using a file as the source*/
auto LoadShaderFile(const char* shaderFile, ShaderType type) -> GRK_ShaderID;

/** Unloads a shader and frees the memory
 * @detail
 * It is worth noting that you need to call this explicitly when you're done with a shader,
 * otherwise it'll be kept around in memory in case you want to compile another program with
 * it, in other words shader management is your responsibility*/
auto UnloadShader(GRK_ShaderID id) -> GRK_Result;

/** Creates a linked shader program pipeline to be used when rendering*/
auto CreateShaderProgram(std::initializer_list<GRK_ShaderID> shaders) -> GRK_ShaderProgramID;

/** Unloads shader program and frees memory, once again this is the consumer's responsibility*/
auto GRK_UnloadShaderProgram(GRK_ShaderProgramID id) -> GRK_Result;
}

#endif
