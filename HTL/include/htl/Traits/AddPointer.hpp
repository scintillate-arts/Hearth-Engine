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
#include "Disjunction.hpp"
#include "IsReferenceable.hpp"
#include "IsVoid.hpp"
#include "RemoveReference.hpp"

namespace htl::detail {

  template<typename TType, bool = Disjunction_V<IsReferenceable<TType>, IsVoid<TType>>>
  struct AddPointerHelper
  { using Type = TType; };

  template<typename TType>
  struct AddPointerHelper<TType, true>
  { using Type = RemoveReference_T<TType>*; };

}

namespace htl {

  template<typename TType>
  struct AddPointer
    : detail::AddPointerHelper<TType>
  { };

  template<typename TType>
  using AddPointer_T = typename AddPointer<TType>::Type;

}