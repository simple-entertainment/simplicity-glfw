/*
 * Copyright © 2015 Simple Entertainment Limited
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <GL/glew.h>

#include <simplicity/logging/Logs.h>
#include <simplicity/messaging/Messages.h>
#include <simplicity/messaging/Subject.h>
#include <simplicity/Simplicity.h>

#include "../input/GLFWInputEvents.h"
#include "GLFWEngine.h"

using namespace std;

namespace simplicity
{
	namespace glfw
	{
		void onError(int error, const char* description)
		{
			Logs::error("simplicity::glfw", "GLFW error (%i): %s", error, description);
		}

		void onWindowClose(GLFWwindow* window)
		{
			Simplicity::stop();
		}

		GLFWEngine::GLFWEngine(const string& title) :
			fullscreen(false),
			height(600),
			mouseCaptured(false),
			title(title),
			width(800),
			window(nullptr)
		{
			glfwSetErrorCallback(onError);

			if (!glfwInit())
			{
				return;
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

			window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(window);

			glfwSetCursorPosCallback(window, fireMouseMoveEvent);
			glfwSetKeyCallback(window, fireKeyboardButtonEvent);
			glfwSetMouseButtonCallback(window, fireMouseButtonEvent);
			glfwSetWindowCloseCallback(window, onWindowClose); // TODO this should really fire an event?

			glewExperimental = GL_TRUE;
			glewInit();

			// Sometimes glewInit() gives false negatives. Lets clear the OpenGL error so it doesn't confuse us
			// elsewhere.
			glGetError();
		}

		void GLFWEngine::advance()
		{
			glfwPollEvents();

			// The window may have been closed by one of the events just processed.
			// We need to handle this case more gracefully as other engines may try to use OpenGL after this has
			// happened...
			if (Simplicity::getState() == Simplicity::State::STOPPING)
			{
				return;
			}

			glfwSwapBuffers(window);
		}

		void GLFWEngine::captureMouse()
		{
			if (mouseCaptured)
			{
				return;
			}

			mouseCaptured = true;
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}

		int GLFWEngine::getHeight() const
		{
			return height;
		}

		int GLFWEngine::getWidth() const
		{
			return width;
		}

		bool GLFWEngine::isFullscreen() const
		{
			return fullscreen;
		}

		bool GLFWEngine::isMouseCaptured() const
		{
			return mouseCaptured;
		}

		bool GLFWEngine::onMouseMove(const Message& message)
		{
			const MouseMoveEvent* event = static_cast<const MouseMoveEvent*>(message.body);
			xMouse = event->x;
			yMouse = event->y;

			return false;
		}

		void GLFWEngine::onPlay()
		{
			Messages::registerRecipient(Subject::MOUSE_MOVE, bind(&GLFWEngine::onMouseMove, this,
				placeholders::_1));
		}

		void GLFWEngine::onStop()
		{
			Messages::deregisterRecipient(Subject::MOUSE_MOVE, bind(&GLFWEngine::onMouseMove, this,
				placeholders::_1));

			glfwDestroyWindow(window);
			glfwTerminate();
		}

		void GLFWEngine::releaseMouse()
		{
			if (!mouseCaptured)
			{
				return;
			}

			mouseCaptured = false;
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}

		void GLFWEngine::setFullscreen(bool fullscreen)
		{
			this->fullscreen = fullscreen;
		}

		void GLFWEngine::setHeight(int height)
		{
			this->height = height;
		}

		void GLFWEngine::setWidth(int width)
		{
			this->width = width;
		}
	}
}
