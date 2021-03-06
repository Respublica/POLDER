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

constexpr unsigned long long int factorial(unsigned long long int N) noexcept
{
    return (N > 1) ? N * meta::factorial(N - 1) : 1;
}

constexpr unsigned long long int stirling(unsigned long long int N)
{
    return (unsigned long long int) (sqrt(M_2PI*N) * pow((N/M_E), N));
}
