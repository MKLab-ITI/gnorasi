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

#include "tgt/event/eventlistener.h"

#include "tgt/event/event.h"
#include "tgt/event/keyevent.h"
#include "tgt/event/mouseevent.h"
#include "tgt/event/timeevent.h"
#include <typeinfo>

namespace tgt {

EventListener::EventListener() {
    eventTypes_ = Event::ALLEVENTTYPES;
}

EventListener::~EventListener() {
}

void EventListener::onEvent(Event* e) {
    /*
        since we already checked which type we have we can safely use
        the faster static_cast (rl)
    */
    if (typeid(*e) == typeid(MouseEvent)) {
        MouseEvent* me = static_cast<MouseEvent*>(e);
        if (me->action() == MouseEvent::PRESSED)
            mousePressEvent(me);
        else if (me->action() == MouseEvent::RELEASED)
            mouseReleaseEvent(me);
        else if (me->action() == MouseEvent::MOTION)
            mouseMoveEvent(me);
        else if (me->action() == MouseEvent::DOUBLECLICK)
            mouseDoubleClickEvent(me);
        else if (me->action() == MouseEvent::WHEEL)
            wheelEvent(me);
    }
    else if (typeid(*e) == typeid(KeyEvent)) {
        keyEvent(static_cast<KeyEvent*>(e));
    }
    else if (typeid(*e) == typeid(TimeEvent)) {
        timerEvent(static_cast<TimeEvent*>(e));
    }
}

void EventListener::setEventTypes(int eventTypes){
    eventTypes_ = eventTypes;
}

int EventListener::getEventTypes() const{
    return eventTypes_;
}

void EventListener::mousePressEvent(MouseEvent* e) {
    e->ignore();
}

void EventListener::mouseReleaseEvent(MouseEvent* e) {
    e->ignore();
}

void EventListener::mouseMoveEvent(MouseEvent* e) {
    e->ignore();
}

void EventListener::mouseDoubleClickEvent(MouseEvent* e) {
    e->ignore();
}

void EventListener::wheelEvent(MouseEvent* e) {
    e->ignore();
}

void EventListener::timerEvent(TimeEvent* e) {
    e->ignore();
}

void EventListener::keyEvent(KeyEvent* e) {
    e->ignore();
}

} // namespace tgt
