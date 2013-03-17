/********************************************************************************
 *                                                                    		*
 * GNORASI - The Knowlegde-Based Remote Sensing Engine                		*
 * 								      		*
 * Language:  C++						      		*
 * 										*
 * Copyright (c) Angelos Tzotsos <tzotsos@gmail.com>. All rights reserved. 	*
 * Copyright (c) National Technical University of Athens. All rights reserved.	*
 * Copyright (c) Informatics and Telematics Institute				*
 *	  Centre for Research and Technology Hellas. All rights reserved.	*
 * Copyright (c) ALTEC SA - www.altec.gr - All rights reserved.			*
 * 										*
 *                                                                    		*
 * This file is part of the GNORASI software package. GNORASI is free  		*
 * software: you can redistribute it and/or modify it under the terms 		*
 * of the GNU General Public License version 2 as published by the    		*
 * Free Software Foundation.                                          		*
 *                                                                    		*
 * GNORASI is distributed in the hope that it will be useful,          		*
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     		*
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the       		*
 * GNU General Public License for more details.                       		*
 *                                                                    		*
 * You should have received a copy of the GNU General Public License  		*
 * in the file "LICENSE.txt" along with this program.                 		*
 * If not, see <http://www.gnu.org/licenses/>.                        		*
 *                                                                    		*
 ********************************************************************************/

#include "otbmodule.h"

#include "processors/ImageIO/otbimagereaderprocessor.h"
#include "processors/ImageIO/otblabelimagereaderprocessor.h"
#include "processors/ImageIO/otbvectorimagereaderprocessor.h"
#include "processors/ImageIO/otbimagewriterprocessor.h"
#include "processors/ImageIO/otblabelimagewriterprocessor.h"
#include "processors/ImageIO/otbcsvwriterprocessor.h"
#include "processors/ImageIO/otbcsvreaderprocessor.h"
#include "processors/BasicFilters/otbconvolutionimagefilterprocessor.h"
#include "processors/BasicFilters/otbfftconvolutionimagefilterprocessor.h"
#include "processors/BasicFilters/otbcannyedgedetectionimagefilterprocessor.h"
#include "processors/BasicFilters/otbgradientanisotropicdiffusionfilterprocessor.h"
#include "processors/BasicFilters/otbmeanimagefilterprocessor.h"
#include "processors/BasicFilters/otbmedianimagefilterprocessor.h"
#include "processors/BasicFilters/otbsobelimagefilterprocessor.h"
#include "processors/BasicFilters/otbbinarythresholdfilterprocessor.h"
#include "processors/BasicFilters/otbbinarydilatefilterprocessor.h"
#include "processors/BasicFilters/otbgrayscaledilatefilterprocessor.h"
#include "processors/BasicFilters/otbbinaryerodefilterprocessor.h"
#include "processors/BasicFilters/otbgrayscaleerodefilterprocessor.h"
#include "processors/BasicFilters/otbbinaryopeningfilterprocessor.h"
#include "processors/BasicFilters/otbgrayscaleopeningfilterprocessor.h"
#include "processors/BasicFilters/otbbinaryclosingfilterprocessor.h"
#include "processors/BasicFilters/otbgrayscaleclosingfilterprocessor.h"
#include "processors/BasicFilters/otbdiscretegaussianimagefilterprocessor.h"
#include "processors/BasicFilters/otbleeimagefilterprocessor.h"
#include "processors/BasicFilters/otbscalarimagetotexturesfilterprocessor.h"
#include "processors/BasicFilters/otbgradientmagnitudeimagefilterprocessor.h"
#include "processors/OBIA/otblabelimagetolabelmapprocessor.h"
#include "processors/OBIA/otbshapeattributeslabelmapprocessor.h"
#include "processors/OBIA/otbbandstatisticsattributeslabelmapprocessor.h"
#include "processors/OBIA/otbstatisticsattributeslabelmapprocessor.h"
#include "processors/OBIA/otblabelmapstatisticwriterprocessor.h"
#include "processors/OBIA/otbobjectclassificationtolabelmapprocessor.h"
#include "processors/OBIA/otblabelmaptoclassimageprocessor.h"
#include "processors/Radiometry/otbndviprocessor.h"
#include "processors/Radiometry/otbmsaviprocessor.h"
#include "processors/Radiometry/otbndwiprocessor.h"
#include "processors/Radiometry/otbvectorimagebandmathprocessor.h"
#include "processors/Radiometry/otbtwoimagebandmathprocessor.h"
#include "processors/Radiometry/otbbayesianfusionfilterprocessor.h"
#include "processors/Radiometry/otblaindviprocessor.h"
#include "processors/ImageIO/otbimagetovectorimagecastprocessor.h"
#include "processors/ImageIO/otbvectorimagewriterprocessor.h"
#include "processors/FeatureExtraction/otbimagetosurfkeypointsetfilterprocessor.h"
#include "processors/FeatureExtraction/otbimagetosiftkeypointsetfilterprocessor.h"
#include "processors/FeatureExtraction/otblineratiodetectorimagefilterprocessor.h"
#include "processors/FeatureExtraction/otblinesegmentdetectorprocessor.h"
#include "processors/FeatureExtraction/otbroadextractionprocessor.h"
#include "processors/Segmentation/otbmeanshiftimagesegmentationprocessor.h"
#include "processors/Segmentation/otbwatershedsegmentationfilterprocessor.h"
#include "processors/Segmentation/otblaplaciansegmentationlevelsetimagefilterprocessor.h"


#include "processors/BasicFilters/otbconfusionmatrixcalculatorprocessor.h"
#include "processors/ChangeDetection/otbcbamichangedetectorprocessor.h"
#include "processors/ChangeDetection/otbmultialterationdetectorimagefilterprocessor.h"
#include "processors/Classification/otbkmeansimageclassificationfilterprocessor.h"
#include "processors/ImageAdministration/otbmultichannelextractroiprocessor.h"



#include "processors/Visualization/otbimageviewerprocessor.h"
//#include "processors/Geometry/otborthorectifyprocessor.h"

#ifdef WIN32

//#include "processors/Visualization/otbsimpleviewerprocessor.h"

#else

#include "processors/Visualization/otbsimpleviewerprocessor.h"

#endif

namespace voreen {

OTBModule::OTBModule(const std::string& moduleName) 
    : VoreenModule(moduleName)
{
    // module name to be used in the GUI
    setName("Orfeo Toolbox");
    
    // each module processor needs to be registered
    registerProcessor(new OTBImageReaderProcessor());
    registerProcessor(new OTBLabelImageReaderProcessor());
    registerProcessor(new OTBVectorImageReaderProcessor());
    registerProcessor(new OTBImageWriterProcessor());
    registerProcessor(new OTBImageToVectorImageCastProcessor());
    registerProcessor(new OTBVectorImageWriterProcessor());
#ifdef WIN32

    //registerProcessor(new OTBSimpleViewerProcessor());
#else

    registerProcessor(new OTBSimpleViewerProcessor());
#endif
    registerProcessor(new OTBLabelImageWriterProcessor());
    registerProcessor(new OTBCSVWriterProcessor());
    registerProcessor(new OTBCSVReaderProcessor());
    registerProcessor(new OTBConvolutionImageFilterProcessor());
    registerProcessor(new OTBCannyEdgeDetectionImageFilterProcessor());
    registerProcessor(new OTBMeanImageFilterProcessor());
    registerProcessor(new OTBBinaryThresholdFilterProcessor());
    registerProcessor(new OTBBinaryDilateFilterProcessor());
    registerProcessor(new OTBGrayscaleDilateFilterProcessor());
    registerProcessor(new OTBGrayscaleErodeFilterProcessor());
    registerProcessor(new OTBBinaryErodeFilterProcessor());
    registerProcessor(new OTBBinaryOpeningFilterProcessor());
    registerProcessor(new OTBGrayscaleOpeningFilterProcessor());
    registerProcessor(new OTBBinaryClosingFilterProcessor());
    registerProcessor(new OTBGrayscaleClosingFilterProcessor());
    registerProcessor(new OTBMedianImageFilterProcessor());
    registerProcessor(new OTBSobelImageFilterProcessor());
    registerProcessor(new OTBGradientAnisotropicDiffusionFilterProcessor());
    registerProcessor(new OTBMeanShiftSegmentationProcessor());
    registerProcessor(new OTBLabelImageToLabelMapProcessor());
    registerProcessor(new OTBShapeAttributesLabelMapProcessor());
    registerProcessor(new OTBBandStatisticsAttributesLabelMapProcessor());
    registerProcessor(new OTBStatisticsAttributesLabelMapProcessor());
    registerProcessor(new OTBLabelMapStatisticsWriterProcessor());
    registerProcessor(new OTBObjectClassificationToLabelMapProcessor());
    registerProcessor(new OTBLabelMapToClassImageProcessor());
    registerProcessor(new OTBNDVIProcessor());
    registerProcessor(new OTBMSAVIProcessor());
    registerProcessor(new OTBNDWIProcessor());
    registerProcessor(new OTBVectorImageBandMathProcessor());
    registerProcessor(new OTBTwoVectorImagesBandMathProcessor());
    registerProcessor(new OTBFFTConvolutionImageFilterProcessor());
    registerProcessor(new OTBConfusionMatrixCalculatorProcessor());
    registerProcessor(new OTBDiscreteGaussianImageFilterProcessor());
    registerProcessor(new OTBLeeImageFilterProcessor());
    registerProcessor(new OTBScalarImageToTexturesFilterProcessor());
    registerProcessor(new OTBBayesianFusionFilterProcessor());
    registerProcessor(new OTBImageToSURFKeyPointSetFilterProcessor());
    registerProcessor(new OTBGradientMagnitudeImageFilterProcessor());
    registerProcessor(new OTBLineRatioDetectorImageFilterProcessor());
    registerProcessor(new OTBLineSegmentDetectorProcessor());
    registerProcessor(new OTBWatershedSegmentationFilterProcessor());
    registerProcessor(new OTBCBAMIChangeDetectorProcessor());
    registerProcessor(new OTBMultiAlterationDetectorImageFilterProcessor());
    registerProcessor(new OTBKMeansImageClassificationFilterProcessor());
    registerProcessor(new OTBRoadExtractionProcessor());
    registerProcessor(new OTBMultiChannelExtractROIProcessor());
    registerProcessor(new OTBImageToSIFTKeyPointSetFilterProcessor());
    registerProcessor(new OTBLAINDVIProcessor());
    registerProcessor(new OTBLaplacianSegmentationLevelSetImageFilterProcessor());

    registerProcessor(new OTBImageViewerProcessor());
//    registerProcessor(new OTBOrthoRectifyProcessor());
}

} // namespace
