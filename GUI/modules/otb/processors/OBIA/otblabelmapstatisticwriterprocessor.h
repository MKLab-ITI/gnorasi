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

#ifndef VRN_OTBLABELMAPSTATISTICSWRITERPROCESSOR_H
#define VRN_OTBLABELMAPSTATISTICSWRITERPROCESSOR_H

#include "voreen/core/processors/processor.h"
#include "voreen/core/properties/filedialogproperty.h"
#include "voreen/core/properties/buttonproperty.h"
#include "voreen/core/properties/stringproperty.h"
#include "../../ports/otblabelmapport.h"
#include "voreen/core/ports/textport.h"
#include "otbAttributesMapLabelObjectWithClassLabel.h"
#include "itkLabelMap.h"

namespace voreen {

class OTBLabelMapStatisticsWriterProcessor : public Processor {
public:
    OTBLabelMapStatisticsWriterProcessor();
    virtual Processor* create() const;

    virtual std::string getClassName() const { return "Object Properties To CSV Converter"; }
    virtual std::string getCategory() const  { return "OBIA"; }
    virtual CodeState getCodeState() const   { return CODE_STATE_TESTING; } //STABLE, TESTING, EXPERIMENTAL
    virtual std::string getProcessorInfo() const;
    
    virtual bool isEndProcessor() const;
    virtual bool isReady() const;
    
     /**
     * Saves the CSV string.
     *
     * @note The processor must have been initialized
     *       before calling this function.
     */
    void saveCSV();
    
    /**
     * Clears the loaded image. Processor needs to be initialized when calling this function.
     */
    void clearCSV();
    
    /// sets the link to the TextData object after calling the processor (outport data actually)
    void setTextDataOut(std::string);
    /// returns the link to the TextData object (inport data actually...)
    const std::string getTextData() const;
    

protected:
    virtual void process();
    virtual void initialize() throw (VoreenException);
    virtual void deinitialize() throw (VoreenException);

private:
    bool hasFileName;
  
    OTBLabelMapPort inPort_;
    TextPort outPort_;
    
    std::string pTextDataOut_;
    
    FileDialogProperty CSVFile_;  ///< Path of the saved image file.
    ButtonProperty clearFile_;      ///< Executes clearImage().
    ButtonProperty saveButton_;    ///< saves the image.
    
    static const std::string loggerCat_; ///< category used in logging
};

} // namespace

#endif // VRN_OTBLABELMAPSTATISTICSWRITERPROCESSOR_H
