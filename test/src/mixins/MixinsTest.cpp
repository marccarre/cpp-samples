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

#include "gtest/gtest.h"
#include "mixins/AbstractIterator.h"
#include "mixins/FunctionalIterator.h"
#include "mixins/StringIterator.h"
#include "../utilities/OutRedirector.cpp"
#include <string>
#include <iostream>

namespace {
    template<class Outputable>
    void WriteAndAddSpace(const Outputable& o) {
       std::cout << o << ' ';
    }

    typedef FunctionalIterator<StringIterator, StringIterator::T> Iterator;


    TEST(MixinsTest, PrintStringByCombiningIterators) {
        Iterator iterator;
        iterator.Reset("mixins");

        OutRedirector redirector; // Capture what's printed via std::cout
        iterator.ForEach(&WriteAndAddSpace<Iterator::T>);

        EXPECT_EQ("m i x i n s ", redirector.ToString());
    }
}
