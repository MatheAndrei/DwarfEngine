cmake_minimum_required(VERSION 3.24.2)
project(DwarfEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(DwarfEngine
        src/main.cpp
        ${PROJECT_SOURCE_DIR}/deps/glad/src/glad.c
        ${PROJECT_SOURCE_DIR}/deps/fmt/src/format.cc
        src/DwarfEngine.h src/core/Application.cpp src/core/Application.h src/core/Window.cpp src/core/Window.h src/core/Logger.cpp src/core/Logger.h src/core/Event.h src/renderer/Renderer.cpp src/renderer/Renderer.h src/renderer/VertexBuffer.cpp src/renderer/VertexBuffer.h src/renderer/IndexBuffer.cpp src/renderer/IndexBuffer.h src/renderer/VertexArray.cpp src/renderer/VertexArray.h src/renderer/VertexBufferLayout.cpp src/renderer/VertexBufferLayout.h src/renderer/OpenGLContext.cpp src/renderer/OpenGLContext.h src/renderer/Shader.cpp src/renderer/Shader.h src/core/FileManager.cpp src/core/FileManager.h src/renderer/OpenGLThings.h src/input/Input.cpp src/input/Input.h src/scene/Scene.cpp src/scene/Scene.h src/sandbox/MainScene.cpp src/sandbox/MainScene.h src/event/Event.cpp src/event/Event.h src/components/Camera.cpp src/components/Camera.h src/components/Transform.cpp src/components/Transform.h src/sandbox/Box.cpp src/sandbox/Box.h)

#target_link_libraries(DwarfEngine PRIVATE opengl32)

target_include_directories(DwarfEngine PRIVATE ${PROJECT_SOURCE_DIR}/deps/glfw/include)

if (UNIX)
    target_link_libraries(DwarfEngine PRIVATE ${PROJECT_SOURCE_DIR}/deps/glfw/lib/libglfw3_linux.a)
endif(UNIX)
if (WIN32)
    target_link_libraries(DwarfEngine PRIVATE ${PROJECT_SOURCE_DIR}/deps/glfw/lib/glfw3-win64.lib)
endif(WIN32)

target_include_directories(DwarfEngine PRIVATE ${PROJECT_SOURCE_DIR}/deps/glad/include)

target_include_directories(DwarfEngine PRIVATE ${PROJECT_SOURCE_DIR}/deps/fmt/include)

target_include_directories(DwarfEngine PRIVATE ${PROJECT_SOURCE_DIR}/deps)
