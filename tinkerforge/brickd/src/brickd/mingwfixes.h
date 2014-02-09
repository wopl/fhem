/*
 * brickd
 * Copyright (C) 2013 Matthias Bolte <matthias@tinkerforge.com>
 *
 * mingwfixes.h: Fixes for problems with the MinGW headers and libs
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BRICKD_MINGWFIXES_H
#define BRICKD_MINGWFIXES_H

#ifdef __MINGW32__

#include <time.h>

#ifndef PROCESS_QUERY_LIMITED_INFORMATION
	#define PROCESS_QUERY_LIMITED_INFORMATION 0x1000
#endif

struct tm *localtime_r(const time_t *timep, struct tm *result);

#endif // __MINGW32__

#endif // BRICKD_MINGWFIXES_H
