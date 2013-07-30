/********************************************************************************
 *                                                                              *
 * GNORASI - The Knowlegde-Based Remote Sensing Engine                          *
 *                                                                              *
 * Language:  C++                                                               *
 *                                                                              *
 * Copyright (c) ALTEC SA - www.altec.gr - All rights reserved.                 *
 * Copyright (c) ALTEC SA - www.altec.gr - All rights reserved.                 *
 * Copyright (c) ALTEC SA - www.altec.gr - All rights reserved.                 *
 *                                                                              *
 * This file is part of the GNORASI software package. GNORASI is free           *
 * software: you can redistribute it and/or modify it under the terms           *
 * of the GNU General Public License version 2 as published by the              *
 * Free Software Foundation.                                                    *
 *                                                                              *
 * GNORASI is distributed in the hope that it will be useful,                   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of               *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                 *
 * GNU General Public License for more details.                                 *
 *                                                                              *
 * You should have received a copy of the GNU General Public License            *
 * in the file "LICENSE.txt" along with this program.                           *
 * If not, see <http://www.gnu.org/licenses/>.                                  *
 *                                                                              *
 ********************************************************************************/

#ifndef OTBMNFIMAGEFILTERPROCESSOR_H
#define OTBMNFIMAGEFILTERPROCESSOR_H

#include "otbimagefilterprocessor.h"
#include "otbVectorImage.h"
#include "modules/otb/ports/otbvectorimageport.h"
#include "otbLocalActivityVectorImageFilter.h"
#include "voreen/core/properties/boolproperty.h"
#include "voreen/core/properties/intproperty.h"
#include "otbTransform.h"
#include "otbMNFImageFilter.h"

namespace voreen {

class OTBMNFImageFilterProcessor : public OTBImageFilterProcessor
{
public:
    OTBMNFImageFilterProcessor();

    virtual ~OTBMNFImageFilterProcessor();

    virtual Processor* create() const;

    virtual std::string getCategory() const { return "Basic Filters"; }
    virtual std::string getClassName() const { return "MNF Image Filter"; }
    virtual CodeState getCodeState() const { return CODE_STATE_EXPERIMENTAL;}//STABLE, TESTING, EXPERIMENTAL

    virtual std::string getProcessorInfo() const;

//    typedef otb::VectorImage<double, 2> VectorImageType;

    //typedef otb::LocalActivityVectorImageFilter<VectorImageType, VectorImageType> NoiseFilterType;
    //typedef otb::MNFImageFilter<VectorImageType, VectorImageType, NoiseFilterType, otb::Transform::FORWARD> FilterType;

    //FilterType::Pointer filter;

protected:

    virtual void setDescriptions() {
    setDescription("processor.");
    }
    void process();
    virtual void initialize() throw (tgt::Exception);
    virtual void deinitialize() throw (tgt::Exception);

//    virtual void bypass(OTBVectorImagePort *inport, OTBVectorImagePort *outport); ///< Passes the image from inport to outport without changes.

private:

//    OTBVectorImagePort inPort_;
//    OTBVectorImagePort outPort_;

//    BoolProperty normalization_;
//    IntProperty numberOfPrincipalComponentsReq_;
//    IntProperty radius_;

    static const std::string loggerCat_; ///< category used in logging
};

} // namespace

#endif // OTBMNFIMAGEFILTERPROCESSOR_H
