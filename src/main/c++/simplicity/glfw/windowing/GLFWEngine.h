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
#ifndef GLFWENGINE_H_
#define GLFWENGINE_H_

#include <GLFW/glfw3.h>

#include <simplicity/windowing/WindowEngine.h>

namespace simplicity
{
	namespace glfw
	{
		/**
		 * <p>
		 * A window engine that is ready to use with OpenGL.
		 * </p>
		 */
		class SIMPLE_API GLFWEngine : public WindowEngine
		{
			public:
				/**
				 * @param title The window title.
				 */
				GLFWEngine(const std::string& title);

				void advance() override;

				void captureMouse() override;

				int getHeight() const override;

				int getWidth() const override;

				bool isFullscreen() const override;

				bool isMouseCaptured() const override;

				void onPlay() override;

				void onStop() override;

				void releaseMouse() override;

				void setFullscreen(bool fullscreen) override;

				void setHeight(int height) override;

				void setWidth(int width) override;

			private:
				bool fullscreen;

				GLFWwindow* window;

				int height;

				bool mouseCaptured;

				std::string title;

				int width;
		};
	}
}

#endif /* GLFWENGINE_H_ */
