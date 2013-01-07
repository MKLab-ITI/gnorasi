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

#ifndef itiotbAbstractModel_h
#define itiotbAbstractModel_h

//
// Qt includes (sorted by alphabetic order)
//// Must be included before system/custom includes.
#include <QtCore>

//
// System includes (sorted by alphabetic order)

//
// ITK includes (sorted by alphabetic order)

//
// OTB includes (sorted by alphabetic order)

//
// Monteverdi includes (sorted by alphabetic order)

//#include "mvdTypes.h"

//
// External classes pre-declaration.
namespace
{
}

namespace itiviewer
{
//
// Internal classes pre-declaration.

/** \class AbstractModel
 *
 */
class AbstractModel :
    public QObject
{
  Q_OBJECT

//
// Public methods.
public:

  /** Destructor */
  virtual ~AbstractModel();

//
// SIGNALS.
signals:

//
// Protected methods.
protected:
  /** Constructor */
  AbstractModel( QObject* parent = NULL );

//
// Protected attributes.
protected:

//
// Private methods.
private:


//
// Private attributes.
private:

//
// SLOTS.
private slots:
};

} // end namespace itiviewer

#endif // itiotbAbstractModel_h
