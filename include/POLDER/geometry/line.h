/*
 * Copyright (C) 2011-2012 Morwenn
 *
 * POLDER is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * POLDER is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _POLDER_GEOMETRY_LINE_H
#define _POLDER_GEOMETRY_LINE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cstdlib>
#include <POLDER/geometry/direction.h>
#include <POLDER/geometry/limits.h>
#include <POLDER/geometry/point.h>


namespace polder
{
namespace geometry
{


// Forward declaration
template<size_t N> class Vector;


/**
 * @brief Geometric Line
 *
 * In geometry a Line is often defined by a straight
 * object passing by two given points. There are many
 * ways to define a Line. In POLDER, the Lines are
 * defined by a Point and a Direction.
 */
template<size_t N>
class Line
{
    public:

        ////////////////////////////////////////////////////////////
        // Constructors
        ////////////////////////////////////////////////////////////

        /**
         * Default constructor
         */
        Line() = default;

        /**
         * Copy constructor
         */
        Line(const Line<N>& other) = default;

        /**
         * @brief Construct a Line passing by two points
         *
         * @param P1 First point
         * @param P2 Second point
         */
        Line(const Point<N>& P1, const Point<N>& P2);

        /**
         * @brief Constructs a line with a point and a vector
         *
         * @param P Point the line passes through
         * @param V Vector giving the direction of the line
         */
        Line(const Point<N>& P, const Vector<N>& V);

        /**
         * @brief Constructs a line with a point and a direction
         *
         * @param P Point the line passes through
         * @param D Direction of the line
         */
        Line(const Point<N>& P, const Direction<N>& D);


        ////////////////////////////////////////////////////////////
        // Elements accessor
        ////////////////////////////////////////////////////////////

        /**
         * @brief Returns the direction of the line
         * @return Direction of the line
         */
        Direction<N> direction() const;

        ////////////////////////////////////////////////////////////
        // Operators
        ////////////////////////////////////////////////////////////

        /**
         * Copy assignement operator
         */
        Line<N>& operator=(const Line<N>& other);

        /**
         * @brief Compares strict equality between two lines
         *
         * @param other Right operand (Line)
         * @return True if the lines are equal
         */
        bool operator==(const Line<N>& other) const;

        /**
         * @brief Compares strict inequality between two lines
         *
         * @param other Right operand (Line)
         * @return True if the lines are not equal
         */
        bool operator!=(const Line<N>& other) const;


        ////////////////////////////////////////////////////////////
        // Miscellaneous functions
        ////////////////////////////////////////////////////////////

        /**
         * @brief Checks whether a point belongs to the line
         *
         * @param P Some point
         * @return True if \a P belongs to the line
         */
        bool includes(const Point<N>& P) const;

        /**
         * @brief Returns an arbitrary point belonging to the line
         *
         * @warning For now, this function always returns the same point.
         * However, it could be improved so that it returns different
         * point given a parameter.
         *
         * @return Some point belonging to the line
         */
        Point<N> point() const;

    private:

        // Member data
        Point<N> P;     /**< Some point contained in the line */
        Direction<N> D; /**< Direction of the line */

};

#include <POLDER/geometry/line.inl>

// Define commonly-used types
typedef Line<2> Line2d;
typedef Line<3> Line3d;


} // namespace geometry
} // namespace polder


#endif // _POLDER_GEOMETRY_LINE_H
