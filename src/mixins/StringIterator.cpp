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

#include "StringIterator.h"
#include "../constants/String.h"
#include "../constants/Char.h"
#include <cstddef>

StringIterator::StringIterator() : _index(0) {
    _string = std::string();
}

StringIterator::StringIterator(std::string const & s) : _index(0) {
    _string = std::string(s);
}

StringIterator::StringIterator(std::string const * s) : _index(0) {
    _string = (s == NULL) ? String::Empty : std::string(*s);
}

StringIterator::~StringIterator() {
}

void StringIterator::Reset(std::string const & s) {
    _index = 0;
    _string = std::string(s);
}

bool StringIterator::HasNext() const {
    return _index < _string.length();
}

char StringIterator::Next() {
    return HasNext() ? _string[_index++] : Char::Empty;
}

int StringIterator::Index() const {
    return _index;
}
