/*
 * Copyright (C) 2011 Morwenn
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
#ifndef _POLDER_RECURSION_ARRAY_H
#define _POLDER_RECURSION_ARRAY_H

////////////////////////////////////////////////////////////
/// Headers
////////////////////////////////////////////////////////////
#include <cassert>
#include <initializer_list>
#include <vector>


namespace polder
{


// Recursion array class
template<typename T>
class RecursionArray
{

    public:

        // An empty RecursionArray can not be instanced
        RecursionArray() = delete;

        // The object is not copiable
        RecursionArray(const RecursionArray&) = delete;
        RecursionArray& operator=(const RecursionArray&) = delete;

        inline T operator()(size_t i)
        {
            return self(i);
        }

    protected:

        // Initializer_list constructor
        // Should be the only way instance a RecursionArray
        RecursionArray(const std::initializer_list<T>& vals)
        {
            for (const T& value: vals)
            {
                values.push_back(value);
            }
        }

        // Equivalent of operator()
        T self(size_t i)
        {
            assert(i >= 0);
            while (values.size() <= i)
            {
                values.push_back(function(values.size()));
            }
            return values[i];
        }

        constexpr inline size_t size() const
        {
            return values.size();
        }

        // To make recursion_array an abstract class
        virtual T function(size_t i) = 0;

    private:

        // Member data
        std::vector<T> values;
};


} // namespace polder


#endif // _POLDER_RECURSION_ARRAY_H