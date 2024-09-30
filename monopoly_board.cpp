#include <iostream>
#include <string>
using namespace std;

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolyBoard() {}

    MonopolyBoard(string propertyName,string propertyColor,int value, int rent){
    /*Define overloaded constructor here*/
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }
    bool isEqual(MonopolyBoard other) {
    /*Define is equal here*/
    return true;
    }
    void print() {
    /*Define Print Here*/
    cout << "Name: " + propertyName << ", Color: " + propertyColor << ", Value: " << value << ", Rent: " << rent << endl;
    }
};

// Template Node class
template <typename T> class Node {
public:
    T data;
    Node* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// Template LinkedList class
template <typename T> class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;
public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
    }

    // Mandatory Tasks
    void insertAtHead(Node<T> newNode) {
        // Empty list
        if(headNode == nullptr) {
            headNode = &newNode;
            tailNode = &newNode;
            newNode.nextNode = &newNode;
            return;
        }

        // Not empty
        Node<T>* tempNode = headNode;
        headNode = &newNode;
        headNode->nextNode = tempNode;
        tailNode->nextNode = headNode;
    }

    void insertAtTail(Node<T> newNode) {
        // Empty list
        if(headNode == nullptr) {
            headNode = &newNode;
            tailNode = &newNode;
            newNode.nextNode = &newNode;
            return;
        }

        // Not empty
        tailNode->nextNode = &newNode;
        tailNode = &newNode;
        newNode.nextNode = headNode;
    }

    void insertAtPosition(Node<T> newNode, int position) {
       if(position < 1) {
           cout << "Invalid position" << endl;
           return;
       }

       // Insert at head
       if(position == 1) {
           if(headNode == nullptr) {
               headNode = &newNode;
               tailNode = &newNode;
               newNode.nextNode = &newNode;
               return;
           }
           Node<T>* tempNode = headNode;
           headNode = &newNode;
           headNode->nextNode = tempNode;
           tailNode->nextNode = headNode;
           return;
       }

       if(headNode == nullptr) {
           cout << "Invalid position" << endl;
           return;
       }

       Node<T>* currentNode = headNode;
       for(int i = 0; i < position - 2; i++) {
           currentNode = currentNode->nextNode;
           if(currentNode == headNode) {
               cout << "Invalid position" << endl;
               return;
           }
       }
       newNode.nextNode = currentNode->nextNode;
        currentNode->nextNode = &newNode;
    }

    void deleteAtHead() {
        cout<<"Delete at head unwritten"<<endl;
    }
    void deleteAtTail() {
        cout<<"Delete at Tail unwritten"<<endl;
    }
    void deleteAtPosition() {
        cout<<"Delete at Position unwritten"<<endl;
    }
    void search(T value) {
        cout<<"Search unwritten"<<endl;
    }

    void printList() {
        if (headNode == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }

        Node<T>* currentNode = headNode;
        do {
            currentNode->data.print();
            currentNode = currentNode->nextNode;
        } while (currentNode != headNode);
    }

    //Optional Tasks
    //Basic Funtions
    void reverseCLList() {
        cout << "Reverse List unwritten" << endl;
    } void sortCLList() {
        cout << "Sort List unwritten" << endl;
    } void printHeadNode() {
        cout << "Print Head Node unwritten" << endl;
    } void printLastNode() {
        cout << "Print Last Node unwritten" << endl;
    } void isListEmpty() {
        cout << "Is List Empty unwritten" << endl;
    }
    void countNodes() {
        cout << "Count Nodes unwritten" << endl;
    }

    //Optional Tasks
    // Advanced Functions
    void convertCLList() {
        cout << "Convert Circular List Unwritten." << endl;
    } void updateNodeValue() {
        cout << "update Node value unwritten" << endl;
    } void displaySpecificColorNode() {
        cout << "Display Specific color Node" << endl;
    } void mergeCLList() {
        cout << "Merge Circular Linked List Unwritten" << endl;
    }
};

// Main function to demonstrate the LinkedList class
int main() {
    // Create a LinkedList of Data objects
    CircularLinkedList<MonopolyBoard> list;
    Node<MonopolyBoard> node1(MonopolyBoard("house", "white", 500, 100));
    Node<MonopolyBoard> node2(MonopolyBoard("apartment", "pink", 400, 50));
    Node<MonopolyBoard> node3(MonopolyBoard("hotel", "gray", 2000, 300));
    Node<MonopolyBoard> node4(MonopolyBoard("park", "green", 1500, 200));
    Node<MonopolyBoard> node5(MonopolyBoard("pool", "blue", 200, 15));
    // Insert elements at the end
    list.insertAtTail(node1);
    list.insertAtTail(node2);
    list.insertAtTail(node3);
    list.insertAtHead(node5);
    list.insertAtPosition(node4, 4);
    list.printList();
//    list.deleteAtHead();
//    list.deleteAtTail();
//    list.deleteAtPosition();
//    //Optional Basic Tasks
//    list.reverseCLList();
//    list.sortCLList();
//    list.printHeadNode();
//    list.printLastNode();
//    list.isListEmpty();
//    list.countNodes();
//    //Optional Advanced Tasks
//    list.convertCLList();
//    list.updateNodeValue();
//    list.displaySpecificColorNode();
//    list.mergeCLList();
    return 0;
}