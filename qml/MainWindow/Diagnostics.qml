/*
 * Copyright (c) 2015-2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

import QtQuick 2.0
import QtQuick.Layouts 1.0

import "../Widgets"
import "../Globals.js" as Globals

RowLayout {
    spacing: Globals.spacing

    //
    // Update widgets according to DS events
    //
    Connections {
        target: DriverStation
        onRamUsageChanged: ram.text = usage + "%"
        onCpuUsageChanged: cpu.text = usage + "%"
        onCanUsageChanged: cpu.text = usage + "%"
        onDiskUsageChanged: disk.text = usage + "%"
        
        onFmsCommunicationsChanged: {
            fms.checked = DriverStation.connectedToFMS()
        }

        onRadioCommunicationsChanged: {
            radio.checked = DriverStation.connectedToRadio()
        }

        onRobotCommunicationsChanged: {
            robot.checked = DriverStation.connectedToRobot()
        }
    }

    //
    // Network Diagnostics & reboot/restart buttons
    //
    ColumnLayout {
        Layout.fillHeight: true
        spacing: Globals.spacing
        Layout.maximumWidth: Globals.scale (240)

        Label {
            font.bold: true
            text: qsTr ("Network Diagnostics") + ":"
        }

        ColumnLayout {
            Layout.fillHeight: true
            spacing: Globals.scale (1)

            Checkbox {
                id: fms
                enabled: false
                text: qsTr ("FMS")
            }

            Checkbox {
                id: robot
                enabled: false
                text: qsTr ("Robot")
            }

            Checkbox {
                id: radio
                enabled: false
                text: qsTr ("Bridge/Radio")
            }
        }

        Item {
            Layout.fillHeight: true
        }

        ColumnLayout {
            spacing: Globals.scale (-1)

            Button {
                Layout.fillWidth: true
                text: qsTr ("Reboot RIO")
                onClicked: DriverStation.rebootRobot()
            }

            Button {
                Layout.fillWidth: true
                text: qsTr ("Restart Code")
                onClicked: DriverStation.restartRobotCode()
            }
        }
    }

    Item {
        Layout.fillWidth: true
    }

    //
    // Robot information & system monitor
    //
    ColumnLayout {
        Layout.fillHeight: true
        spacing: Globals.spacing

        Label {
            font.bold: true
            text: qsTr ("Robot Information") + ":"
        }

        Grid {
            columns: 2
            Layout.fillHeight: true
            rowSpacing: Globals.scale (1)
            columnSpacing: Globals.spacing

            Label {
                text: qsTr ("CPU Usage")
            }

            Label {
                id: cpu
                text: Globals.invalidStr
            }

            Label {
                text: qsTr ("RAM Usage")
            }

            Label {
                id: ram
                text: Globals.invalidStr
            }

            Label {
                text: qsTr ("Disk Usage")
            }

            Label {
                id: disk
                text: Globals.invalidStr
            }

            Label {
                text: qsTr ("CAN Utilization")
            }

            Label {
                id: can
                text: Globals.invalidStr
            }
        }
    }

    Item {
        Layout.fillWidth: true
    }
}
