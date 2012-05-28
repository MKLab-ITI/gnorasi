/**********************************************************************
 *                                                                    *
 * GNORASI - The Knowlegde-Based Remote Sensing Engine                *
 *                                                                    *
 **********************************************************************/

#include "otbmodule.h"
//#include "processors/dummysegmentationprocessor.h"
#include "processors/ImageIO/otbimagereaderprocessor.h"
#include "processors/ImageIO/otbimagewriterprocessor.h"
#include "processors/BasicFilters/otbconvolutionimagefilterprocessor.h"

namespace voreen {

OTBModule::OTBModule() 
    : VoreenModule()
{
    // module name to be used in the GUI
    setName("Orfeo Toolbox");
    
    // module description file
    setXMLFileName("otb/otbmodule.xml");

    // each module processor needs to be registered
    //addProcessor(new DummySegmentationProcessor());
    addProcessor(new OTBImageReaderProcessor());
    addProcessor(new OTBImageWriterProcessor());
    addProcessor(new OTBConvolutionImageFilterProcessor());
}

} // namespace
