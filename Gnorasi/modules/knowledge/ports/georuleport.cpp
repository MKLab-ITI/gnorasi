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

#include "georuleport.h"
#include "voreen/core/datastructures/rendertarget.h"
#include "voreen/core/processors/renderprocessor.h"

namespace voreen {

const std::string GeoRulePort::loggerCat_("voreen.GeoRulePort");

GeoRulePort::GeoRulePort(PortDirection direction, const std::string& name,
                   bool allowMultipleConnections, Processor::InvalidationLevel invalidationLevel)
    : Port(name, direction, allowMultipleConnections, invalidationLevel)
{
}

GeoRulePort::~GeoRulePort() {
}

void GeoRulePort::setData(const std::string& data) {
    tgtAssert(isOutport(), "called setData on inport!");
    portData_ = data;
    invalidate();
}

std::string GeoRulePort::getData() const {
    if (isOutport())
        return portData_;
    else {
        for (size_t i = 0; i < connectedPorts_.size(); ++i) {
            if (!connectedPorts_[i]->isOutport())
                continue;

            GeoRulePort* p = static_cast< GeoRulePort* >(connectedPorts_[i]);
            if (p)
                return p->getData();
        }
    }
    return "";
}

std::vector<std::string> GeoRulePort::getAllData() const {
    if (isOutport()) {
        std::vector<std::string> allData;
        allData.push_back(portData_);
        return allData;
    }
    else {
        std::vector<std::string> allData;
        for (size_t i = 0; i < connectedPorts_.size(); ++i) {
            if (connectedPorts_[i]->isOutport() == false)
                continue;
            GeoRulePort* p = static_cast<GeoRulePort*>(connectedPorts_[i]);
            allData.push_back(p->getData());
        }
        return allData;
    }
}

std::vector<const GeoRulePort*> GeoRulePort::getConnected() const {
    std::vector<const GeoRulePort*> ports;
    for (size_t i = 0; i < connectedPorts_.size(); ++i) {
        GeoRulePort* p = static_cast<GeoRulePort*>(connectedPorts_[i]);

        ports.push_back(p);
    }
    return ports;
}

bool GeoRulePort::isReady() const {
    return Port::isReady();
}

bool GeoRulePort::hasData() const {
    return true;
}

tgt::col3 GeoRulePort::getColorHint() const {
    return tgt::col3(165, 42, 42); //brown
}

} // namespace
