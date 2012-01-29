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

#ifndef NODE_H_
#define NODE_H_

template<class T>
class Node {
    public:
        Node(T const & content);
        Node(T const & content, Node<T> * next);
        virtual ~Node();

        T const & Content() const;
        bool HasNext() const;
        Node<T> * Next() const;
        void SetNext(Node<T> * next);
        int Length();

        bool HasCycle();
        int GetIndexNodeCycle();
        int GetLengthCycle();
        void CheckAndBreakCycle();

        bool HasCycleBruteForce();

    protected:
        T _content;
        Node<T> * _next;
        bool _hasCycle;
        int _indexCycle;
        int _lengthCycle;

        void InitDataMembers(T const & content, Node<T> * next);
        bool HasCycleTortoiseAndHare(Node<T> **tortoise, Node<T> **hare);
        int FindIndexNodeClosingCycle(Node<T> ** tortoise, Node<T> ** hare);
        int CalculateLenghtCycle(Node<T> ** tortoise, Node<T> ** hare);
        void BreakCycle();
};

#endif /* NODE_H_ */
