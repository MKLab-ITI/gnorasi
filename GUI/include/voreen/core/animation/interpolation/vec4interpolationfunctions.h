/**********************************************************************
 *                                                                    *
 * Voreen - The Volume Rendering Engine                               *
 *                                                                    *
 * Created between 2005 and 2012 by The Voreen Team                   *
 * as listed in CREDITS.TXT <http://www.voreen.org>                   *
 *                                                                    *
 * This file is part of the Voreen software package. Voreen is free   *
 * software: you can redistribute it and/or modify it under the terms *
 * of the GNU General Public License version 2 as published by the    *
 * Free Software Foundation.                                          *
 *                                                                    *
 * Voreen is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the       *
 * GNU General Public License for more details.                       *
 *                                                                    *
 * You should have received a copy of the GNU General Public License  *
 * in the file "LICENSE.txt" along with this program.                 *
 * If not, see <http://www.gnu.org/licenses/>.                        *
 *                                                                    *
 * The authors reserve all rights not expressly granted herein. For   *
 * non-commercial academic use see the license exception specified in *
 * the file "LICENSE-academic.txt". To get information about          *
 * commercial licensing please contact the authors.                   *
 *                                                                    *
 **********************************************************************/

#ifndef VRN_VEC4INTERPOLATIONFUNCTIONS_H
#define VRN_VEC4INTERPOLATIONFUNCTIONS_H

#include "voreen/core/animation/interpolationfunction.h"

namespace voreen {

#ifdef DLL_TEMPLATE_INST
template class VRN_CORE_API InterpolationFunction<tgt::vec4>;
#endif

/**
 * This class VRN_CORE_API offers an interpolation function for vec4-values. Interpolation: focus on startvalue.
 */
class VRN_CORE_API Vec4StartInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4StartInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4-values. Interpolation: focus on endvalue.
 */
class VRN_CORE_API Vec4EndInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4EndInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4-values. Interpolation: bisection.
 */
class VRN_CORE_API Vec4StartEndInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4StartEndInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: linear.
 */
class VRN_CORE_API Vec4LinearInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4LinearInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quadratic (easing in).
 */
class VRN_CORE_API Vec4InQuadInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InQuadInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: cubicular (easing in).
 */
class VRN_CORE_API Vec4InCubicInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InCubicInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quartetic (easing in).
 */
class VRN_CORE_API Vec4InQuartInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InQuartInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quintic (easing in).
 */
class VRN_CORE_API Vec4InQuintInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InQuintInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: sineousidal (easing in).
 */
class VRN_CORE_API Vec4InSineInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InSineInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: exponential (easing in).
 */
class VRN_CORE_API Vec4InExponentInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InExponentInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: circular (easing in).
 */
class VRN_CORE_API Vec4InCircInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InCircInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quadratic (easing out).
 */
class VRN_CORE_API Vec4OutQuadInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutQuadInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: cubicular (easing out).
 */
class VRN_CORE_API Vec4OutCubicInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutCubicInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quartetic (easing out).
 */
class VRN_CORE_API Vec4OutQuartInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutQuartInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quintic (easing out).
 */
class VRN_CORE_API Vec4OutQuintInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutQuintInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: sineousidal (easing out).
 */
class VRN_CORE_API Vec4OutSineInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutSineInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: exponential (easing out).
 */
class VRN_CORE_API Vec4OutExponentInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutExponentInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: circular (easing out).
 */
class VRN_CORE_API Vec4OutCircInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutCircInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quadratic (easing in, then easing out).
 */
class VRN_CORE_API Vec4InOutQuadInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InOutQuadInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: cubicular (easing in, then easing out).
 */
class VRN_CORE_API Vec4InOutCubicInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InOutCubicInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quartetic (easing in, then easing out).
 */
class VRN_CORE_API Vec4InOutQuartInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InOutQuartInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quintic (easing in, then easing out).
 */
class VRN_CORE_API Vec4InOutQuintInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InOutQuintInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: sineousidal (easing in, then easing out).
 */
class VRN_CORE_API Vec4InOutSineInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InOutSineInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: exponential (easing in, then easing out).
 */
class VRN_CORE_API Vec4InOutExponentInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InOutExponentInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: circular (easing in, then easing out).
 */
class VRN_CORE_API Vec4InOutCircInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4InOutCircInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quadratic (easing out, then easing in).
 */
class VRN_CORE_API Vec4OutInQuadInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutInQuadInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: cubicular (easing out, then easing in).
 */
class VRN_CORE_API Vec4OutInCubicInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutInCubicInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quartetic (easing out, then easing in).
 */
class VRN_CORE_API Vec4OutInQuartInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutInQuartInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: quintic (easing out, then easing in).
 */
class VRN_CORE_API Vec4OutInQuintInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutInQuintInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: sineousidal (easing out, then easing in).
 */
class VRN_CORE_API Vec4OutInSineInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutInSineInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: exponential (easing out, then easing in).
 */
class VRN_CORE_API Vec4OutInExponentInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutInExponentInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

/**
 * This class VRN_CORE_API offers an interpolation function for vec4. Interpolation: circular (easing out, then easing in).
 */
class VRN_CORE_API Vec4OutInCircInterpolationFunction : public InterpolationFunction<tgt::vec4> {
public:
    Vec4OutInCircInterpolationFunction();
    InterpolationFunction<tgt::vec4>* clone() const;
    tgt::vec4 interpolate(tgt::vec4 startvalue, tgt::vec4 endvalue, float time) const;

    std::string getMode() const;
    std::string getIdentifier() const;
};

} // namespace voreen

#endif
