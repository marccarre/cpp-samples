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

#include "Node.h"
#include <cstddef>
#include <iostream>
#include <set>

template<class T>
Node<T>::Node(T const & content) {
    InitDataMembers(content, NULL);
}

template<class T>
Node<T>::Node(T const & content, Node<T> * next) {
    InitDataMembers(content, next);
}

template<class T>
void Node<T>::InitDataMembers(T const & content, Node<T> * next) {
    _content = content;
    _next = next;
    _hasCycle = false;
    _indexCycle = -1;
    _lengthCycle = -1;
}

template<class T>
Node<T>::~Node() {
    //T content = _content;
    //std::cout << "Deleting node containing '" << content << "'." << std::endl;

    if (HasCycle()) {
        //std::cout << "List contains a cycle of length " << _lengthCycle << " at node #" << _indexCycle << ", breaking it..." << std::endl;
        BreakCycle();
    }

    if (_next != NULL)
        delete (_next);

    //std::cout << "Deleted node containing '" << content << "'." << std::endl;
}

template<class T>
void Node<T>::CheckAndBreakCycle() {
    if (!HasCycle())
        return;
    BreakCycle();
}

template<class T>
void Node<T>::BreakCycle() {
    // Keep address of node closing the cycle:
    Node<T> * badNode = this;
    int index = 0;
    while (index != _indexCycle) {
        badNode = badNode->Next();
        ++index;
    }

    // Go to the last node of the cycle:
    Node<T> * lastNode = badNode;
    while (lastNode->Next() != badNode) {
        lastNode = lastNode->Next();
    }

    // Finally, break the cycle and reinit state:
    lastNode->SetNext(NULL);
    _hasCycle = false;
    _indexCycle = -1;
    _lengthCycle = -1;
}

template<class T>
T const & Node<T>::Content() const {
    return _content;
}

template<class T>
bool Node<T>::HasNext() const {
    return (_next != NULL);
}

template<class T>
Node<T> * Node<T>::Next() const {
    if (this == NULL)
        return NULL;
    return _next;
}

template<class T>
void Node<T>::SetNext(Node<T> * next) {
    _next = next;
}

template<class T>
int Node<T>::Length() {
    if (HasCycle())
        return -1;

    Node<T> * node = this;
    int length = 0;
    while (node != NULL) {
        node = node->Next();
        ++length;
    }

    return length;
}

template<class T>
bool Node<T>::HasCycle() {
    Node<T> * tortoise = NULL;
    Node<T> * hare = NULL;

    _hasCycle = HasCycleTortoiseAndHare(&tortoise, &hare);
    if (!_hasCycle)
        return false;

    _indexCycle = FindIndexNodeClosingCycle(&tortoise, &hare);
    _lengthCycle = CalculateLenghtCycle(&tortoise, &hare);
    return true;
}

template<class T>
bool Node<T>::HasCycleBruteForce() {
    std::set<Node<T> *> seenNodes;
    seenNodes.insert(this);
    Node<T> * current = this->Next();

    while ((current != NULL) && (!seenNodes.count(current))) {
        seenNodes.insert(current);
        current = current->Next();
    }

    _hasCycle = (current != NULL);
    if (!_hasCycle)
        return false;

    // Find position of the node closing the cycle:
    Node<T> * temp = this;
    int index = 0;
    while (temp != current) {
        temp = temp->Next();
        ++index;
    }
    _indexCycle = index;

    // Calculate the length of the cycle:
    temp = current->Next();
    int length = 1;
    while (temp != current) {
        temp = temp->Next();
        ++length;
    }
    _lengthCycle = length;

    return true;
}

template<class T>
int Node<T>::GetIndexNodeCycle() {
    return _indexCycle;
}

template<class T>
int Node<T>::GetLengthCycle() {
    return _lengthCycle;
}

template<class T>
bool Node<T>::HasCycleTortoiseAndHare(Node<T> **tortoise, Node<T> **hare) {
    (*tortoise) = this->Next(); // Memory = 1, Cost = 1, Times = 1
    (*hare) = this->Next()->Next(); // Memory = 1, Cost = 1, Times = 1

    while ((*tortoise) != (*hare)) { // Memory = 0, Cost = 1, Times = n
        (*tortoise) = (*tortoise)->Next(); // Memory = 0, Cost = 1, Times = n
        (*hare) = (*hare)->Next()->Next(); // Memory = 0, Cost = 2, Times = n
    }

    return ((*hare) != NULL);// Memory = 0, Cost = 1, Times = 1
}

template<class T>
int Node<T>::FindIndexNodeClosingCycle(Node<T> **tortoise, Node<T> **hare) {
    if ((*tortoise) != (*hare))
        HasCycleTortoiseAndHare(tortoise, hare);

    (*tortoise) = this;
    int index = 0;

    while (*tortoise != *hare) {
        (*tortoise) = (*tortoise)->Next();
        (*hare) = (*hare)->Next();
        ++index;
    }

    return index;
}

template<class T>
int Node<T>::CalculateLenghtCycle(Node<T> **tortoise, Node<T> **hare) {
    if ((*tortoise) != (*hare)) {
        HasCycleTortoiseAndHare(tortoise, hare);
        FindIndexNodeClosingCycle(tortoise, hare);
    }

    (*hare) = (*tortoise)->Next();
    int lenght = 1;

    while ((*tortoise) != (*hare)) {
        (*hare) = (*hare)->Next();
        ++lenght;
    }

    return lenght;
}

template class Node<int> ;
