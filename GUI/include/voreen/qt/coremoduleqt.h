/**********************************************************************
 *                                                                    *
 * Voreen - The Volume Rendering Engine                               *
 *                                                                    *
 * Created between 2005 and 2012 by The Voreen Team                   *
 * as listed in CREDITS.TXT <http://www.voreen.org>                   *
 *                                                                    *
 * This file is part of the Voreen software package. Voreen is free   *
 * software: you can redistribute it and/or modify it under the terms *
 * of the GNU General Public License version 2 as published by the    *
 * Free Software Foundation.                                          *
 *                                                                    *
 * Voreen is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the       *
 * GNU General Public License for more details.                       *
 *                                                                    *
 * You should have received a copy of the GNU General Public License  *
 * in the file "LICENSE.txt" along with this program.                 *
 * If not, see <http://www.gnu.org/licenses/>.                        *
 *                                                                    *
 * The authors reserve all rights not expressly granted herein. For   *
 * non-commercial academic use see the license exception specified in *
 * the file "LICENSE-academic.txt". To get information about          *
 * commercial licensing please contact the authors.                   *
 *                                                                    *
 **********************************************************************/

#ifndef VRN_COREMODULE_QT_H
#define VRN_COREMODULE_QT_H

#include "voreen/qt/voreenmoduleqt.h"

namespace voreen {

/**
 * Registers core Qt resources at runtime.
 *
 * This is actually a pseudo module, since it is an integral part
 * of the Voreen core and cannot be excluded from the build process.
 * It has been introduced to handle Qt runtime resources of the core and
 * the modules in a consistent manner.
 */
class CoreModuleQt : public VoreenModuleQt {

public:
    CoreModuleQt();

protected:
    static const std::string loggerCat_;
};

} // namespace

#endif // VRN_COREMODULE_QT_H
