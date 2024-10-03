Monopoly Board

[Overview]
This project implements the board game called Monopoly with real-estate being the theme, it uses property, rent,
estate value, and color as the data, designed to perform insertions, deletions, and searches on a circular linked
list. This program is written in C++ and can be executed from JetBrain's CLion IDE.

[How to Run the Code]
Prerequisites:
    1.) To run the code, you will need a C++ compiler such as Clang or G++.
    2.) An IDE such as CLion, Eclipse, or Visual Studio will do.
Instructions:
    To run this code on CLion, you only need to click green run button near the top-right corner of your IDE. You may
    also need to add the file as an executable in CMakeLists.txt file.

[Operations]
    1. insertAtHead()
        Description: A generic function that takes any data type and adds that data to the front of the list. The
        function first creates a new node with that new data as its data and also has a nextNode pointer that points
        to the previous head. Lastly, it updates the head pointer as well as the tail's nextNode pointer to point to
        the new node.

        Time Complexity:
            Best case: O(1) since it has head and tail pointers, it does not need to search for anything.
            Worst case: O(1) since it has head and tail pointers, it does not need to search for anything.

    2. insertAtTail()
        Description: A generic function that takes any data type and adds that data to the end of the list. The
        function first creates a new node with that new data as its data and also has a nextNode pointer that
        points to the current head. Lastly, it updates the previous tail's nextNode pointer as well as the tail
        pointer to point to the new node.

        Time Complexity:
            Best case: O(1) since it has head and tail pointers, it does not need to search for anything.
            Worst case: O(1) since it has head and tail pointers, it does not need to search for anything.

    3. insertAtPosition()
        Description: A generic function that takes any data type as well as an integer to represent the position of
        where to put the new data. If position is less than one, the function displays an error. If the position is
        one, the function uses the insertAtHead(). If the position integer is neither, the function proceeds to
        traverse the list, stopping one node behind the target position. The new node's nextNode pointer is then
        updated to point the currentNode's nextNode pointer. And the currentNode then points to the new node. If
        the position is greater than the list's length + 1, an error is displayed.

        Time Complexity:
            Best case: O(1) because the function will just use insertAtHead() if position is one.
            Worst case: O(N) since the function has to search for a specific position.

    4. deleteAtHead():
        Description: Deletes the first node of the list. The function first checks if the list is empty and displays
        an error if so. If the list only has one node, the head and tail pointers are both updated to nullptr and the
        previous head is deleted. If the list has more than one node, the function then updates the head pointer and
        the tail node to point to the current head's next node. Lastly, the previous head is then deleted.

        Time Complexity:
            Best case: O(1) since the function only needs to update pointers and does not search for anything.
            Worst case: O(1) since the function only needs to update pointers and does not search for anything.

    5. deleteAtTail():
        Description: Deletes the last node of the list. The function first checks if the list is empty and displays
        an error if so. If the list only has one node, the head and tail pointers are both updated to nullptr and the
        previous head is deleted. If the list has more than one node, the function has to search for the node before
        the tail node. That node is then updated to point to the current head node and the tail pointer now points to
        the new tail node.

        Time Complexity:
            Best case: O(1) since the function only needs to update pointers and does not search for anything.
            Worst case: O(N) because the function needs to search for the node before the tail node.

    6. deleteAtPosition():
        Description: Takes an int to represent the position to delete. If the position is less than one,
        an error is displayed. If the function is one, the function just deletes the head. If not, the function
        traverses the list and stops one node before the target position. That node is then updated to point the
        target node's next node and the target node is deleted. If the position is greater than the list's length,
        an error is displayed.

        Time Complexity:
            Best case: O(1) if the position is one and only needs to delete the head.
            Worst case: O(N) since the function might need to search for the node before the target node or if the
            target node does not exist.

    7. search():
        Description: A generic function that takes any data type and returns true if the data already exists in the
        list and false if not. The function first checks if the list is empty and displays an error if so. If the list
        is not empty, it traverses the list and uses the data's built-in isEqual() method to find a node with the same
        data.

        Time complexity:
            Best case: O(1) if the list empty, the function does not search for anything
            Worst case: O(N) since the function has to traverse the whole list to find the node with a specific data.

    8. printList():
        Description: Prints the data of each node in the list. If the list empty, the function display an error. If not,
        the function traverses the whole list and uses the data's built-in print() method to display the data.

        Time complexity:
            Best case: O(1) if the list empty, the function only displays an error.
            Worst case: O(N) since the function might need to traverse the whole list to display each node's data.