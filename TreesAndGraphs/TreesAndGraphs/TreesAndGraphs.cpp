#include <iostream>
#include <list>
#include <Vector>
#include "Trees.h" 
#include "Graphs.h"
#include <ctime>



int main()
{
    
    int TreeOrGraph;
    cout << "do you want to see the tree[1] or graph[2]?";
    cin >> TreeOrGraph;

    if (TreeOrGraph == 1) {
        srand(time(0));
        Tree myTree;

        TreeNode* randomNode = myTree.createRandomNode(myTree.root);
        myTree.root->children.push_back(randomNode);

        myTree.generateRandomTree(myTree.root, 0, 5);
        myTree.printTree(myTree.root, 0);

        TreeNode* randomTreeNode = myTree.getRandomNode(myTree.root);

        myTree.preorderTraversal(myTree.root);

        //print size
        myTree.printTreeSize(myTree.root);

        //print root
        TreeNode* rootNode = myTree.getRoot();
        cout << "Root Node's Data: " << rootNode->data << endl;


        //print parent of node
        cout << "Parent of this Node is: ";
        myTree.parentOfNode(randomTreeNode);

        //print children of node
        myTree.childrenOfNode(randomTreeNode);
        vector<TreeNode*> rootChildren = myTree.childrenOfNode(randomTreeNode);
        cout << "Children of Node with data " << randomTreeNode->data << ": ";
        for (const auto& child : rootChildren) {
            cout << child->data << " ";
        }
        cout << endl;

        //print height
        int height = myTree.getHeight(myTree.root);
        cout << "Height of the tree is: " << height << endl;


        //check if its empty
        myTree.printisEmpty();

        //check if a node has a parent, if it doesnt its root.
        myTree.printRootStatus(randomNode);

        //check if a node has a child, if not its a leaf
        myTree.printLeafStatus(randomNode);

        //check depth
        int depth = myTree.getDepthOfNode(myTree.root, randomTreeNode);
        cout << "Depth of the node: " << depth << endl;

        int nodeToDelete;
        cout << "Enter the node to delete: ";
        cin >> nodeToDelete;
        myTree.deleteNode(myTree.root, nodeToDelete);

        cout << "Tree after deletion: " << endl;
        myTree.printTree(myTree.root, 0);
    }
    else if (TreeOrGraph == 2) {

        //decide number of vertices
        int numVertices;
        cout << "Enter the number of vertices: ";
        cin >> numVertices;
        Graph graph(numVertices);

        //decide edges
        int maxEdgeWeight;
        cout << "Enter the maximum edge weight: ";
        cin >> maxEdgeWeight;

        //generate tree
        graph.generateRandomGraph(maxEdgeWeight);

        int numVerticesGraph = graph.getNumVertices();
        int numEdges = graph.getNumEdges();
        int sizeV = graph.size();
        cout << "Number of Vertices: " << numVerticesGraph << endl;
        cout << "Number of Edges: " << numEdges << endl;
        cout << "The size is: " << sizeV << endl;
        graph.printIsEmpty();

        /*int startVertex;
        cout << "Enter the starting vertex for DFS: ";
        cin >> startVertex;

        vector<bool> visited(numVertices, false);
        graph.DFS(startVertex, visited);*/
        //my DFS does not work and it says i get a breakpoint whenever i type in startVertex 
        //i have tried everything i can imagine but it doesnt work so i just have to deliver it like this
        
        //if you want to delete or insert node
        int choice;
        while (true) {
            cout << "Options:" << endl;
            cout << "1. Delete a node and its edges" << endl;
            cout << "2. Insert a new node with edges" << endl;
            cout << "3. Print Graph" << endl;
            cout << "4. Quit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                int nodeToDelete;
                cout << "Enter the node to delete: ";
                cin >> nodeToDelete;
                graph.deleteNode(nodeToDelete);
            }
            else if (choice == 2) {
                int newNode;
                cout << "Enter the new node: ";
                cin >> newNode;

                int connectedNode;
                cout << "Enter the node to which the new node is connected: ";
                cin >> connectedNode;

                
                if (connectedNode < 1 || connectedNode > numVertices) {
                    cout << "Invalid node to connect to. Aborting insertion." << endl;
                }
                else {
                    vector<int> connectedNodes = { connectedNode };
                    graph.insertNodeWithEdges(newNode, connectedNodes);
                }
            }
            else if (choice == 3) {
                int numVerticesGraph = graph.size();
                int numEdges = graph.getNumEdges();
                graph.generateRandomGraph(maxEdgeWeight);
                if (graph.isEmpty()) {
                    cout << "The graph is empty." << endl;
                }
            }
            else if (choice == 4) {
                break; 
                }
            else {
                cout << "Invalid choice. Please select a valid option." << endl;
            }
        }
    }



    return 0;
}



