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

#ifndef STRINGITERATOR_H_
#define STRINGITERATOR_H_

#include "AbstractIterator.h"
#include <string>

class StringIterator : public AbstractIterator<char>{
    public:
        typedef char T;

        StringIterator();
        StringIterator(std::string const & s);
        StringIterator(std::string const * s);
        virtual ~StringIterator();
        void Reset(std::string const & s);
        int Index() const;

        virtual bool HasNext() const;
        virtual char Next();

    protected:
        std::string _string;
        unsigned int _index;
};

#endif /* STRINGITERATOR_H_ */
