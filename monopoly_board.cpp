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
        if(other.propertyName == this->propertyName
        && other.propertyColor == this->propertyColor
        && other.value == this->value
        && other.rent == this->rent) {
            return true;
        }
        return false;
    }
    void print() {
    /*Define Print Here*/
    cout << "[Name: " + propertyName << ", Color: " + propertyColor << ", Value: " << value << ", Rent: " << rent << "] \n";
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
    void insertAtHead(T newData) {
        Node<T>* newNode = new Node<T>(newData);

        // Empty list
        if(headNode == nullptr) {
            headNode = newNode;
            tailNode = newNode;
            newNode->nextNode = newNode;
            return;
        }

        // Not empty
        Node<T>* tempNode = headNode;
        headNode = newNode;
        headNode->nextNode = tempNode;
        tailNode->nextNode = headNode;
    }

    void insertAtTail(T newData) {
        Node<T>* newNode = new Node<T>(newData);

        // Empty list
        if(headNode == nullptr) {
            headNode = newNode;
            tailNode = newNode;
            newNode->nextNode = newNode;
            return;
        }

        // Not empty
        tailNode->nextNode = newNode;
        tailNode = newNode;
        newNode->nextNode = headNode;
    }

    void insertAtPosition(T newData, int position) {
       Node<T>* newNode = new Node<T>(newData);

       // Invalid position
       if(position < 1) {
           cout << "Invalid position" << endl;
           return;
       }

       // Insert at head
       if(position == 1) {
           if(headNode == nullptr) {
               headNode = newNode;
               tailNode = newNode;
               newNode->nextNode = newNode;
               return;
           }
           Node<T>* tempNode = headNode;
           headNode = newNode;
           headNode->nextNode = tempNode;
           tailNode->nextNode = headNode;
           return;
       }

       // Empty list
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
       newNode->nextNode = currentNode->nextNode;
       currentNode->nextNode = newNode;
       if(newNode->nextNode == headNode) {
           tailNode = newNode;
       }
    }

    void deleteAtHead() {
        // Empty list
        if(headNode == nullptr) {
            cout << "Can't delete head of empty list" << endl;
            return;
        }

        // List only has one element
        if(headNode == tailNode) {
            Node<T>* temp = headNode;
            headNode = nullptr;
            tailNode = nullptr;
            delete temp;
            return;
        }

        Node<T>* temp = headNode;
        headNode = headNode->nextNode;
        tailNode->nextNode = headNode;
        delete temp;
    }

    void deleteAtTail() {
        // List is empty
        if(headNode == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        // List only has one element
        if(headNode == tailNode) {
            Node<T>* temp = headNode;
            headNode = nullptr;
            tailNode = nullptr;
            delete temp;
            return;
        }

        Node<T>* temp = tailNode;
        Node<T>* currentNode = headNode;
        while(currentNode->nextNode != tailNode) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = headNode;
        tailNode = currentNode;
        delete temp;
    }

    void deleteAtPosition(int position) {
        // Invalid position
        if(position < 1) {
            cout << "Invalid position" << endl;
            return;
        }

        // Empty list
        if(headNode == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        // Delete at head
        if(position == 1) {
            deleteAtHead();
            return;
        }

        Node<T>* currentNode = headNode;
        for(int i = 0; i < position - 2; i++) {
            currentNode = currentNode->nextNode;
            if(currentNode == tailNode) {
                cout << "Invalid position" << endl;
                return;
            }
        }

        // Delete at tail
        if(currentNode->nextNode == tailNode) {
            deleteAtTail();
            return;
        }

        Node<T>* temp = currentNode->nextNode;
        currentNode->nextNode = currentNode->nextNode->nextNode;
        delete temp;
    }

    int search(T value) {
        if(headNode == nullptr) {
            cout << "Can't search empty list" <<endl;
            return 0;
        }

        Node<T>* currentNode = headNode;
        int count = 1;
        do {
            if(currentNode->data.isEqual(value)) {
                return count;
            }
            currentNode = currentNode->nextNode;
            count++;
        } while(currentNode != headNode);
        cout << "Property not found in list" << endl;
        return 0;
    }

    void printList() {
        if (headNode == nullptr) {
            cout << "Can't print empty list" << endl;
            return;
        }

        Node<T>* currentNode = headNode;
        do {
            currentNode->data.print();
            currentNode = currentNode->nextNode;
        } while(currentNode != headNode);
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
    MonopolyBoard house("house", "white", 500, 100);
    MonopolyBoard apartment("apartment", "pink", 400, 50);
    MonopolyBoard hotel("hotel", "gray", 2000, 300);
    MonopolyBoard park("park", "green", 1500, 200);
    MonopolyBoard pool("pool", "blue", 200, 15);

    // Insert elements at the end
    list.insertAtTail(house);
    list.insertAtTail(apartment);
    list.insertAtTail(hotel);
    list.insertAtTail(park);
    list.insertAtPosition(pool, 5);
    list.deleteAtPosition(5);
    list.printList();
    cout << list.search(hotel) <<endl;

    //Optional Basic Tasks
    list.reverseCLList();
    list.sortCLList();
    list.printHeadNode();
    list.printLastNode();
    list.isListEmpty();
    list.countNodes();
    //Optional Advanced Tasks
    list.convertCLList();
    list.updateNodeValue();
    list.displaySpecificColorNode();
    list.mergeCLList();
    return 0;
}