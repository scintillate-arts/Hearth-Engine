/* Copyright (c) 2020-2021 Simular Games, LLC.
 * -------------------------------------------------------------------------------------------------
 *
 * MIT License
 * -------------------------------------------------------------------------------------------------
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 * associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 * -------------------------------------------------------------------------------------------------
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
 * NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#pragma once
#include "../IntTypes.hpp"

namespace htl {

  template<typename TType>
  struct RemoveExtent
  { using Type = TType; };

  template<typename TType, size_t TArraySize>
  struct RemoveExtent<TType[TArraySize]>
  { using Type = TType; };

  template<typename TType>
  struct RemoveExtent<TType[]>
  { using Type = TType; };

  template<typename TType>
  struct RemoveAllExtents
  { using Type = TType; };

  template<typename TType, size_t TArraySize>
  struct RemoveAllExtents<TType[TArraySize]>
  { using Type = typename RemoveAllExtents<TType>::Type; };

  template<typename TType>
  struct RemoveAllExtents<TType[]>
  { using Type = typename RemoveAllExtents<TType>::Type; };

  template<typename TType>
  using RemoveExtent_T = typename RemoveExtent<TType>::Type;

  template<typename TType>
  using RemoveAllExtents_T = typename RemoveAllExtents<TType>::Type;

}
