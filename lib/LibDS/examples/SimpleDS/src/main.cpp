/*
 * Copyright (C) 2015-2016 Alex Spataru <alex_spataru@outlook>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <LibDS.h>
#include <EventLogger.h>
#include <DriverStation.h>

#include "Window.h"
#include "VirtualJoystick.h"

int main (int argc, char* argv[])
{
    QApplication app (argc, argv);

    /* Initialize the Driver Station */
    DriverStation::getInstance()->start();
    DSEventLogger::getInstance()->start();

    /* Initialize the main window */
    Window window;
    window.show();

    /* Initialize the virtual joystick */
    VirtualJoystick joystick;
    Q_UNUSED (joystick);

    /* Connect to the FRC Simulator */
    DriverStation::getInstance()->setCustomRobotAddress ("127.0.0.1");

    return app.exec();
}
