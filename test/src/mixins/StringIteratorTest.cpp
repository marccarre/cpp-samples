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
#include "mixins/StringIterator.h"
#include <cstddef>

namespace {
    TEST(StringIteratorTest, IteratorStartsWithFirstCharAndHasOtherElementsAfterFirstOne) {
        StringIterator iterator = StringIterator("string");

        EXPECT_TRUE(iterator.HasNext());
        EXPECT_EQ(0, iterator.Index());

        EXPECT_EQ('s', iterator.Next());

        EXPECT_TRUE(iterator.HasNext());
        EXPECT_EQ(1, iterator.Index());
    }

    TEST(StringIteratorTest, IteratorDoesntHaveAnyOtherElementAfterLastChar) {
        StringIterator iterator = StringIterator("string");

        EXPECT_TRUE(iterator.HasNext());
        EXPECT_EQ(0, iterator.Index());

        EXPECT_EQ('s', iterator.Next());
        EXPECT_EQ('t', iterator.Next());
        EXPECT_EQ('r', iterator.Next());
        EXPECT_EQ('i', iterator.Next());
        EXPECT_EQ('n', iterator.Next());

        EXPECT_TRUE(iterator.HasNext());
        EXPECT_EQ('g', iterator.Next());
        EXPECT_FALSE(iterator.HasNext());
        EXPECT_EQ(6, iterator.Index());
    }

    TEST(StringIteratorTest, ResetAssignNewStringAndReinitializePositionOfTheIterator) {
        StringIterator iterator = StringIterator("abc");

        EXPECT_EQ('a', iterator.Next());
        EXPECT_EQ('b', iterator.Next());
        EXPECT_EQ('c', iterator.Next());
        EXPECT_FALSE(iterator.HasNext());
        EXPECT_EQ(3, iterator.Index());

        iterator.Reset("def");

        EXPECT_EQ('d', iterator.Next());
        EXPECT_EQ('e', iterator.Next());
        EXPECT_EQ('f', iterator.Next());
        EXPECT_FALSE(iterator.HasNext());
        EXPECT_EQ(3, iterator.Index());
    }

    TEST(StringIteratorTest, NullStringDoesntIterate) {
        StringIterator iterator = StringIterator(NULL);
        EXPECT_FALSE(iterator.HasNext());
        EXPECT_EQ('\0', iterator.Next());
        EXPECT_EQ(0, iterator.Index());
    }

    TEST(StringIteratorTest, EmptyStringDoesntIterate) {
        StringIterator iterator = StringIterator("");
        EXPECT_FALSE(iterator.HasNext());
        EXPECT_EQ('\0', iterator.Next());
        EXPECT_EQ(0, iterator.Index());
    }
}
