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
#include "patterns/singleton/Singleton.h"

namespace {
    TEST(SingletonTest, SingletonProvidesAccessToAnUniqueInstance) {
        Singleton * first = Singleton::Instance();
        Singleton * second = Singleton::Instance();
        EXPECT_EQ(first, second);
    }
}
