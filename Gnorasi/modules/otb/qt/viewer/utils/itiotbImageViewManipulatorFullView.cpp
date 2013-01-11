/*=========================================================================

  Program:   Monteverdi2
  Language:  C++


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See Copyright.txt for details.

  Monteverdi2 is distributed under the CeCILL licence version 2. See
  Licence_CeCILL_V2-en.txt or
  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt for more details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "itiotbImageViewManipulatorFullView.h"

//
// Qt includes (sorted by alphabetic order)
//// Must be included before system/custom includes.

//
// System includes (sorted by alphabetic order)

//
// ITK includes (sorted by alphabetic order)

//
// OTB includes (sorted by alphabetic order)

//
// Monteverdi includes (sorted by alphabetic order)

using namespace itiviewer;
/*
  TRANSLATOR mvd::ImageViewManipulator

  Necessary for lupdate to be aware of C++ namespaces.

  Context comment for translator.
*/

/*****************************************************************************/
ImageViewManipulatorFullView
::ImageViewManipulatorFullView( QObject* parent ) :
  QObject( parent ),
  m_NavigationContext(),
  m_MouseContext()
{
  // TODO: Remove later because initialized in struct's default constructor and resizeEvent().
  this->InitializeContext(1,1);
}

/*****************************************************************************/
ImageViewManipulatorFullView
::~ImageViewManipulatorFullView()
{
}

/*******************************************************************************/
void
ImageViewManipulatorFullView
::InitializeContext(int width, int height)
{
  ImageRegionType::SizeType  initialSize;
  initialSize[0] = width;
  initialSize[1] = height;

  // initialize with the given size
  m_NavigationContext.m_ViewportImageRegion.SetSize(initialSize);
}

/******************************************************************************/
void
ImageViewManipulatorFullView
::mousePressEvent(QMouseEvent * event)
{
  // Update the context with the pressed position
  m_MouseContext.x = event->x();
  m_MouseContext.y = event->y();

  // Update the context with the pressed position for the mouseMoveEvent
  m_MouseContext.xMove = event->x();
  m_MouseContext.yMove = event->y();
}

/******************************************************************************/
void
ImageViewManipulatorFullView
::mouseMoveEvent( QMouseEvent * event)
{
  // Update the mouse context
  m_MouseContext.dx = -event->x() + m_MouseContext.xMove;
  m_MouseContext.dy = -event->y() + m_MouseContext.yMove;

  // Update the navigation context
  ImageRegionType & currentRegion = m_NavigationContext.m_ViewportImageRegion;

  // Apply the offset to the (start) index of the stored region
  ImageRegionType::OffsetType offset;
  offset[0] = m_MouseContext.dx;
  offset[1] = m_MouseContext.dy;
 
  // Apply the offset to the (start) index of the stored region
  IndexType    index = currentRegion.GetIndex() + offset;
  currentRegion.SetIndex(index);

  // Constraint the region to the largestPossibleRegion
  this->ConstrainRegion(currentRegion, m_NavigationContext.m_ModelImageRegion);

  // Update the position of the first press to take into account the
  // last drag
  m_MouseContext.xMove -=  m_MouseContext.dx;
  m_MouseContext.yMove -=  m_MouseContext.dy;
}

/******************************************************************************/
void
ImageViewManipulatorFullView
::mouseReleaseEvent(  QMouseEvent * event)
{
  //TODO: Implement mouseReleaseEvent.
  //std::cout <<" Not Implemented yet ..." << std::endl;
}

/******************************************************************************/
void ImageViewManipulatorFullView
::resizeEvent( QResizeEvent * event )
{
  // Update the navigation context
  ImageRegionType & currentRegion = m_NavigationContext.m_ViewportImageRegion;

  // Get the new widget size
  ImageRegionType::SizeType size;
  size[0] = event->size().width();
  size[1] = event->size().height();
 
  // Update the stored region with the new size
  currentRegion.SetSize(size);

  // Constraint this region to the LargestPossibleRegion
  this->ConstrainRegion(currentRegion, m_NavigationContext.m_ModelImageRegion);
}

/******************************************************************************/
void
ImageViewManipulatorFullView
::ConstrainRegion( ImageRegionType& region, const ImageRegionType& largest)
{
  ImageRegionType::SizeType zeroSize;
  zeroSize.Fill(0);
  
  if (largest.GetSize() != zeroSize)
    {
    // Else we can constrain it
    IndexType                     index = region.GetIndex();
    ImageRegionType::SizeType size = region.GetSize();

    // If region is larger than big, then crop
    if (region.GetSize()[0] > largest.GetSize()[0])
      {
      size[0] = largest.GetSize()[0];
      }
    if (region.GetSize()[1] > largest.GetSize()[1])
      {
      size[1] = largest.GetSize()[1];
      }

    // Else we can constrain it
    // For each dimension
    for (unsigned int dim = 0; dim < ImageRegionType::ImageDimension; ++dim)
      {
      // push left if necessary
      if (region.GetIndex()[dim] < largest.GetIndex()[dim])
        {
        index[dim] = largest.GetIndex()[dim];
        }
      // push right if necessary
      if (index[dim] + size[dim] >= largest.GetIndex()[dim] + largest.GetSize()[dim])
        {
        index[dim] = largest.GetIndex()[dim] + largest.GetSize()[dim] - size[dim];
        }
      }
    region.SetSize(size);
    region.SetIndex(index);
    }
}

/*****************************************************************************/
/* SLOTS                                                                     */
/*****************************************************************************/

/*****************************************************************************/

