/*
 * The Driver Station Library (LibDS)
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

#ifndef _LIB_DS_EVENTS_H
#define _LIB_DS_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sds.h>
#include <stdint.h>

#include "DS_Types.h"

/**
 * \brief The types of events that can be delivered.
 */
typedef enum {
    DS_NULL_EVENT               = 0x00,
    DS_FMS_COMMS_CHANGED        = 0x01,
    DS_RADIO_COMMS_CHANGED      = 0x03,
    DS_JOYSTICK_COUNT_CHANGED   = 0x05,
    DS_NETCONSOLE_NEW_MESSAGE   = 0x06,
    DS_ROBOT_ENABLED_CHANGED    = 0x07,
    DS_ROBOT_MODE_CHANGED       = 0x09,
    DS_ROBOT_REBOOTED           = 0x0a,
    DS_ROBOT_COMMS_CHANGED      = 0x0b,
    DS_ROBOT_CODE_CHANGED       = 0x0d,
    DS_ROBOT_CODE_RESTARTED     = 0x10,
    DS_ROBOT_VOLTAGE_CHANGED    = 0x11,
    DS_ROBOT_CAN_UTIL_CHANGED   = 0x12,
    DS_ROBOT_CPU_INFO_CHANGED   = 0x13,
    DS_ROBOT_RAM_INFO_CHANGED   = 0x14,
    DS_ROBOT_DISK_INFO_CHANGED  = 0x15,
    DS_ROBOT_STATION_CHANGED    = 0x16,
    DS_ROBOT_ESTOP_CHANGED      = 0x17,
    DS_STATUS_STRING_CHANGED    = 0x18,
} DS_EventType;

/**
 * \brief FMS event fields
 */
typedef struct {
    DS_EventType type;  /**< Event type */
    int connected;      /**< Set to \c 1 if FMS is connected */
} DS_FMSEvent;

/**
 * \brief Radio event fields
 */
typedef struct {
    DS_EventType type;  /**< Event type */
    int connected;      /**< Set to \c 1 if radio is connected */
} DS_RadioEvent;

/**
 * \brief Robot event fields
 */
typedef struct {
    DS_EventType type;  /**< Event type */
    int code;            /**< Set to \c 1 if robot code is loaded */
    int enabled;         /**< Set to \c 1 if the robot is enabled */
    int can_util;        /**< Represents the robot's CAN utilization */
    int cpu_usage;       /**< Represents the CPU usage (from 0 to 100) */
    int ram_usage;       /**< Represents the RAM usage (from 0 to 100) */
    int estopped;        /**< Set to \c 1 if robot is emergency stopped */
    int connected;       /**< Set to \c 1 if robot is connected */
    int disk_usage;      /**< Represents the disk usage (from 0 to 100) */
    float voltage;      /**< Holds the current robot voltage */
    DS_ControlMode mode; /**< Represents the current control mode */
} DS_RobotEvent;

/**
 * \brief Joystick event fields
 */
typedef struct {
    DS_EventType type;  /**< Event type */
    int count;          /**< Holds the new joystick count */
} DS_JoystickEvent;

/**
 * \brief NetConsole event fields
 */
typedef struct {
    DS_EventType type;  /**< Event type */
    sds message;        /**< Holds the received message */
} DS_NetConsoleEvent;

/**
 * \brief General event structure
 */
typedef union {
    DS_EventType type;             /**< Event type */
    DS_FMSEvent fms;               /**< FMS event data */
    DS_RobotEvent robot;           /**< Robot event data */
    DS_RadioEvent radio;           /**< Radio event data */
    DS_JoystickEvent joystick;     /**< Joystick event data */
    DS_NetConsoleEvent netconsole; /**< NetConsole event data */
} DS_Event;

extern void Events_Init();
extern void Events_Close();
extern void DS_AddEvent (DS_Event* event);
extern int DS_PollEvent (DS_Event* event);

#ifdef __cplusplus
}
#endif

#endif

