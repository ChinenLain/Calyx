#include "clxpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Calyx {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}