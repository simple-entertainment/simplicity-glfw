/*
 * Copyright © 2012 Simple Entertainment Limited
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
#include <GLFW/glfw3.h>

#include "GLFWKeyboard.h"

using namespace std;

namespace simplicity
{
	namespace glfw
	{
		map<int, Keyboard::Button> createSpecialKeyoardButtonMap()
		{
			map<int, Keyboard::Button> specialButtonMap;

			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F1, Keyboard::Button::F1));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F2, Keyboard::Button::F2));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F3, Keyboard::Button::F3));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F4, Keyboard::Button::F4));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F5, Keyboard::Button::F5));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F6, Keyboard::Button::F6));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F7, Keyboard::Button::F7));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F8, Keyboard::Button::F8));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F9, Keyboard::Button::F9));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F10, Keyboard::Button::F10));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F11, Keyboard::Button::F11));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_F12, Keyboard::Button::F12));

			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_DOWN, Keyboard::Button::ARROW_DOWN));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_LEFT, Keyboard::Button::ARROW_LEFT));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_RIGHT, Keyboard::Button::ARROW_RIGHT));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_UP, Keyboard::Button::ARROW_UP));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_DELETE, Keyboard::Button::DEL));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_END, Keyboard::Button::END));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_HOME, Keyboard::Button::HOME));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_INSERT, Keyboard::Button::INSERT));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_LEFT_ALT, Keyboard::Button::LEFT_ALT));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_LEFT_CONTROL, Keyboard::Button::LEFT_CTRL));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_LEFT_SHIFT, Keyboard::Button::LEFT_SHIFT));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_PAGE_DOWN, Keyboard::Button::PAGE_DOWN));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_PAGE_UP, Keyboard::Button::PAGE_UP));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_RIGHT_ALT, Keyboard::Button::RIGHT_ALT));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_RIGHT_CONTROL, Keyboard::Button::RIGHT_CTRL));
			specialButtonMap.insert(pair<int, Keyboard::Button>(GLFW_KEY_RIGHT_SHIFT, Keyboard::Button::RIGHT_SHIFT));

			return specialButtonMap;
		}
	}
}
