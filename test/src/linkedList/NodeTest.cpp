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
#include "linkedList/Node.h"
#include <cstddef>

namespace {
    class NodeTest : public ::testing::Test {
        protected:
            virtual void SetUp() {
                _listNoLoop = new Node<int> (1, new Node<int> (2, new Node<int> (3, new Node<int> (4))));
                _listWithLoop = new Node<int> (1, new Node<int> (2, new Node<int> (3, CreateCycle())));
            }

            Node<int> * CreateCycle() {
                Node<int> * sixthNode = new Node<int> (6);
                Node<int> * fourthNode = new Node<int> (4, new Node<int> (5, sixthNode));
                Node<int> * seventhNode = new Node<int> (7, fourthNode);
                sixthNode->SetNext(seventhNode);
                return fourthNode;
            }

            virtual void TearDown() {
                delete (_listNoLoop);
                delete (_listWithLoop);
            }

            Node<int> * _listNoLoop;
            Node<int> * _listWithLoop;
    };

    TEST(NodeTestSimple, IsNotLinkedInitially) {
        Node<int> * singleNode = new Node<int> (1);

        EXPECT_FALSE(singleNode->HasNext());
        EXPECT_EQ(NULL, singleNode->Next());
        EXPECT_EQ(1, singleNode->Content());
        EXPECT_EQ(1, singleNode->Length());

        delete (singleNode);
    }

    TEST(NodeTestSimple, IsLinked) {
        Node<int> * tailNode = new Node<int> (2);
        Node<int> * headNode = new Node<int> (1, tailNode);

        EXPECT_EQ(2, headNode->Length()) << "List is made of two elements, and therefore should have a length of two." ;

        EXPECT_TRUE(headNode->HasNext()) << "Head node should point to some other node.";
        EXPECT_EQ(tailNode, headNode->Next()) << "Head node should actually point to tail node.";
        EXPECT_EQ(1, headNode->Content());

        EXPECT_FALSE(tailNode->HasNext()) << "Tail node should point to nothing.";
        EXPECT_EQ(NULL, tailNode->Next()) << "Tail node should therefore point to NULL.";
        EXPECT_EQ(2, tailNode->Content());

        delete (headNode);
    }

    TEST_F(NodeTest, ShouldHaveNoLoop) {
        EXPECT_EQ(4, _listNoLoop->Length()) <<"List is made of four elements, and therefore should have a length of four.";
        EXPECT_FALSE(_listNoLoop->HasCycle());
        EXPECT_EQ(-1, _listNoLoop->GetIndexNodeCycle());
        EXPECT_EQ(-1, _listNoLoop->GetLengthCycle());
    }

    TEST_F(NodeTest, ShouldHaveALoopTortoiseAndHare) {
        EXPECT_TRUE(_listWithLoop->HasCycle());
        EXPECT_EQ(3, _listWithLoop->GetIndexNodeCycle());
        EXPECT_EQ(4, _listWithLoop->GetLengthCycle());
    }

    TEST_F(NodeTest, ShouldHaveALoopBruteForce) {
        EXPECT_TRUE(_listWithLoop->HasCycleBruteForce());
        EXPECT_EQ(3, _listWithLoop->GetIndexNodeCycle());
        EXPECT_EQ(4, _listWithLoop->GetLengthCycle());
    }

    TEST_F(NodeTest, ShouldBreakExistingLoop) {
        _listWithLoop->CheckAndBreakCycle();
        EXPECT_FALSE(_listWithLoop->HasCycle());
        EXPECT_EQ(-1, _listWithLoop->GetIndexNodeCycle());
        EXPECT_EQ(-1, _listWithLoop->GetLengthCycle());
    }
}
