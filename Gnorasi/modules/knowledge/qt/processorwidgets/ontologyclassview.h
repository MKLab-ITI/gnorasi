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

#ifndef VRN_ONTOLOGYCLASSVIEW_H
#define VRN_ONTOLOGYCLASSVIEW_H

#include <QtGui/QTreeView>

class ClassDescriptionDialog;

namespace voreen {

class OntologyClassView : public QTreeView{
    Q_OBJECT

public:

    OntologyClassView(QWidget *parent = 0);

//    ClassDescriptionWidget* classDescriptionWidget() { return m_pClassDescriptionWidget; }

public slots:
    void onNameValidationError();

signals:
    void nameValidationError();

protected:
    void contextMenuEvent(QContextMenuEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);


public slots:
    void onAddChildClass();
    void onRemoveCurrentClass();
    void onAddSiblingClass();
    void changeClassColor();

private:
    QString getUniqueNameFromIndex(const QModelIndex& );


};

} // end of namespace voreen

#endif // VRN_ONTOLOGYCLASSVIEW_H
