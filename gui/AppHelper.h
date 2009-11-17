/* -*-c++-*-
 
 This file is part of the IC reverse engineering tool degate.
 
 Copyright 2008, 2009 by Martin Schobert
 
 Degate is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.
 
 Degate is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with degate. If not, see <http://www.gnu.org/licenses/>.
 
*/

#ifndef __APPHELPER_H__
#define __APPHELPER_H__

#include <boost/format.hpp>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#include <Project.h>
#include <ProjectExporter.h>

/**
 * Get date and time as a string that can be used to generate file names.
 */

std::string get_date_and_time_as_file_prefix();


/**
 * Autosave a project.
 * @param project Shared pointer to the project.
 * @parem interval Minimum time in seconds.
 * @return Returns true if the project was saved. Returns false, if there
 *   is nothing to save.
 */

bool autosave_project(degate::Project_shptr project, unsigned int interval = 5 * 60);

#endif