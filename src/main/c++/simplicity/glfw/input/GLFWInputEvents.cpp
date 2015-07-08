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
#include <simplicity/messaging/Messages.h>
#include <simplicity/messaging/Subject.h>

#include "GLFWInputEvents.h"
#include "GLFWKeyboard.h"

using namespace std;

namespace simplicity
{
	namespace glfw
	{
		map<unsigned char, Keyboard::Button> glfwAsciiKeyboardButtonMap = createAsciiKeyboardButtonMap();

		map<int, Keyboard::Button> glfwSpecialKeyboardButtonMap = createSpecialKeyoardButtonMap();

		void fireKeyboardButtonEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (action == GLFW_REPEAT)
			{
				return;
			}

			KeyboardButtonEvent event = getKeyboardButtonEvent(key);

			if (action == GLFW_PRESS)
			{
				event.buttonState = Button::State::DOWN;
			}
			else
			{
				event.buttonState = Button::State::UP;
			}

			Messages::send(Message(Subject::KEYBOARD_BUTTON, &event));
		}

		void fireMouseButtonEvent(GLFWwindow* window, int button, int action, int mods)
		{
			MouseButtonEvent event;

			if (button == GLFW_MOUSE_BUTTON_MIDDLE)
			{
				event.button = Mouse::Button::MIDDLE;
			}
			else if (button == GLFW_MOUSE_BUTTON_LEFT)
			{
				event.button = Mouse::Button::LEFT;
			}
			else if (button == GLFW_MOUSE_BUTTON_RIGHT)
			{
				event.button = Mouse::Button::RIGHT;
			}

			if (action == GLFW_PRESS)
			{
				event.buttonState = Button::State::DOWN;
			}
			else
			{
				event.buttonState = Button::State::UP;
			}

			double x = 0.0;
			double y = 0.0;
			glfwGetCursorPos(window, &x, &y);
			event.x = static_cast<int>(x);
			event.y = static_cast<int>(y);

			Messages::send(Message(Subject::MOUSE_BUTTON, &event));
		}

		void fireMouseMoveEvent(GLFWwindow* window, double x, double y)
		{
			MouseMoveEvent event;
			event.x = static_cast<int>(x);
			event.y = static_cast<int>(y);

			Messages::send(Message(Subject::MOUSE_MOVE, &event));
		}

		KeyboardButtonEvent getKeyboardButtonEvent(int key)
		{
			KeyboardButtonEvent event;
			unsigned char character = static_cast<unsigned char>(key);

			map<unsigned char, Keyboard::Button>::iterator buttonPair = glfwAsciiKeyboardButtonMap.find(character);
			if (buttonPair != glfwAsciiKeyboardButtonMap.end())
			{
				event.button = buttonPair->second;
			}
			else
			{
				map<int, Keyboard::Button>::iterator buttonPair = glfwSpecialKeyboardButtonMap.find(key);
				if (buttonPair != glfwSpecialKeyboardButtonMap.end())
				{
					event.button = buttonPair->second;
				}
			}

			event.character = character;

			return event;
		}
	}
}
