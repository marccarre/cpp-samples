/*
 * Copyright (C) 2012, Marc CARRE.
 * All rights reserved.
 * Contact: carre.marc@gmail.com
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "FunctionalIterator.h"
#include "StringIterator.h"

template<class AbstractIterator, class T>
FunctionalIterator<AbstractIterator, T>::FunctionalIterator() {
}

template<class AbstractIterator, class T>
FunctionalIterator<AbstractIterator, T>::~FunctionalIterator() {
}

template<class AbstractIterator, class T>
template<class FuncType>
void FunctionalIterator<AbstractIterator, T>::ForEach(FuncType f) {
    while(AbstractIterator::HasNext())
        f(AbstractIterator::Next());
}

typedef StringIterator::T Type;
template class FunctionalIterator<StringIterator, Type>;
template void FunctionalIterator<StringIterator, Type>::ForEach<void(*)(Type const&)>(void(*)(Type const&));
