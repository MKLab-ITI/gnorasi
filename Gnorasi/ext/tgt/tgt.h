/***********************************************************************************
 *                                                                                 *
 * Voreen - The Volume Rendering Engine                                            *
 *                                                                                 *
 * Copyright (C) 2005-2012 University of Muenster, Germany.                        *
 * Visualization and Computer Graphics Group <http://viscg.uni-muenster.de>        *
 * For a list of authors please refer to the file "CREDITS.txt".                   *
 *                                                                                 *
 * This file is part of the Voreen software package. Voreen is free software:      *
 * you can redistribute it and/or modify it under the terms of the GNU General     *
 * Public License version 2 as published by the Free Software Foundation.          *
 *                                                                                 *
 * Voreen is distributed in the hope that it will be useful, but WITHOUT ANY       *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR   *
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.      *
 *                                                                                 *
 * You should have received a copy of the GNU General Public License in the file   *
 * "LICENSE.txt" along with this file. If not, see <http://www.gnu.org/licenses/>. *
 *                                                                                 *
 * For non-commercial academic use see the license exception specified in the file *
 * "LICENSE-academic.txt". To get information about commercial licensing please    *
 * contact the authors.                                                            *
 *                                                                                 *
 ***********************************************************************************/

#ifndef TGT_TGT_H
#define TGT_TGT_H

//Used Libs
#include "tgt/tgt_gl.h"

//Basics
#include "tgt/types.h"
#include "tgt/singleton.h"
#include "tgt/assert.h"
#include "tgt/init.h"

//Math
#include "tgt/vector.h"
#include "tgt/matrix.h"
#include "tgt/quaternion.h"
#include "tgt/plane.h"
#include "tgt/spline.h"
#include "tgt/bounds.h"
#include "tgt/frustum.h"

//Interaction
//#include "glcanvas.h"
// FIXME: include glcanvas and guiapplication, include glut/qt/sdl-canvas/application/libs depending on macros
#include "tgt/mouse.h"
#include "tgt/camera.h"
#include "tgt/navigation/navigation.h"

//Renderable
#include "tgt/renderable.h"
#include "tgt/quadric.h"
#include "tgt/skybox.h"
#include "tgt/curve.h"

//Light and Material
#include "tgt/light.h"
#include "tgt/material.h"

//Hardware Detection
#include "tgt/gpucapabilities.h"

//Managers
#include "tgt/manager.h"
#include "tgt/tesselator.h"
#include "tgt/texturemanager.h"
#include "tgt/shadermanager.h"
#include "tgt/modelmanager.h"

//Utils
#include "tgt/tesselator.h"
#include "tgt/stopwatch.h"
#include "tgt/framecounter.h"
#include "tgt/vertex.h"
#include "tgt/quadtree.h"

#endif //TGT_TGT_H
