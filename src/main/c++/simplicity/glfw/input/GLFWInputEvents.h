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
#ifndef GLFWINPUTEVENTS_H_
#define GLFWINPUTEVENTS_H_

#include <GLFW/glfw3.h>

#include <simplicity/input/KeyboardButtonEvent.h>
#include <simplicity/input/MouseButtonEvent.h>
#include <simplicity/input/MouseMoveEvent.h>

namespace simplicity
{
	namespace glfw
	{
		void fireKeyboardButtonEvent(GLFWwindow* window, int key, int scancode, int action, int mods);

		void fireMouseButtonEvent(GLFWwindow* window, int button, int action, int mods);

		void fireMouseMoveEvent(GLFWwindow* window, double x, double y);

		KeyboardButtonEvent getKeyboardButtonEvent(int key);

		KeyboardButtonEvent getKeyboardSpecialButtonEvent(int key);
	}
}

#endif /* GLFWINPUTEVENTS_H_ */
