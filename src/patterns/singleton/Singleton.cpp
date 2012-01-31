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

#include "Singleton.h"

Singleton * Singleton::_instance = 0;
boost::mutex Singleton::_mutex;

Singleton::Singleton() {
    // Protected to avoid multiple instances to be created by client code.
}

Singleton * Singleton::Instance() {
    if (_instance == 0) {
        boost::mutex::scoped_lock lock(_mutex); // Thread-safe initialization of singleton.
        if (_instance == 0) {
            _instance = new Singleton();
        }
    }
    return _instance;
}
