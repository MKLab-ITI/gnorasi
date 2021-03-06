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

#ifndef TGT_TEXTUREREADERTGA_H
#define TGT_TEXTUREREADERTGA_H

#include "tgt/texturereader.h"

namespace tgt {

///Texturereader to read compressed and uncompressed RGB and RGBA tga files.
///No external dependencies!
class TextureReaderTga : public TextureReader {
    static const std::string loggerCat_;
public:
    TextureReaderTga();
    virtual Texture* loadTexture(const std::string& filename, Texture::Filter filter, bool compress = false,
                                 bool keepPixels = false, bool createOGLTex = true, bool textureRectangle = false);
};


} // namespace tgt

#endif // TGT_TEXTUREREADERTGA_H
