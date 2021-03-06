/********************************************************************************
 *                                                                              *
 * GNORASI - The Knowlegde-Based Remote Sensing Engine                          *
 *                                                                              *
 * Language:  C++                                                               *
 *                                                                              *
 * Copyright (c) Ioannis Tsampoulatidis <itsam@iti.gr>. All rights reserved. 	*
 * Copyright (c) Informatics and Telematics Institute                           *
 *	  Centre for Research and Technology Hellas. All rights reserved.           *
 * Copyright (c) National Technical University of Athens. All rights reserved.	*
 *                                                                              *
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

#include "itiotbimagevectorchannelprovider.h"

using namespace itiviewer;

ItiOtbImageVectorChannelProvider::ItiOtbImageVectorChannelProvider(VectorImageModel *m, QObject *parent) :
    m_pVectorImageModel(m), ItiOtbImageChannelProvider(parent)
{
    connect(m_pVectorImageModel,SIGNAL(changed()),this,SLOT(onModelJChanged()));
}

void ItiOtbImageVectorChannelProvider::onModelJChanged(){
    parse();
}

//!
void ItiOtbImageVectorChannelProvider::parse(){

    unsigned int currentIndex = 0;
    const DefaultImageType* image =  m_pVectorImageModel->GetOutput(currentIndex);
    if(!image)
        return;

    unsigned int ncpp = image->GetNumberOfComponentsPerPixel();
    for(int i = 0; i < ncpp; i++)
        m_channelList << i;

    emit channelsChanged();

}
