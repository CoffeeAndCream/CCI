#include <iostream>
#include <array>

class Tree{
    private:
        struct node{
            int data;
            node *left;
            node *right;

            node(int input){
                data = input;
                left = NULL;
                right = NULL;
            }
        }; node *root = NULL;
    public:
        node *insert(int arr[], int start, int end){
            if(end < start){
                return NULL;
            }
            int mid = (start+end) / 2;
            std::cout << "ARR[MID]: " << arr[mid] << std::endl;
            node *n = new node(arr[mid]);
            n->left = insert(arr, start, mid - 1);
            n->right = insert(arr, mid+1, end);
            return n;
        }

        node* search(int input){
            node *current = root;
            std::cout << "Visiting elements: ";
                
            while(current->data != input){
                
                if(current) {
                    std::cout<< " " << current->data;
                        
                    //go to left tree
                    if(current->data > input){
                        current = current->left;
                    }//else go to right tree
                    else {                
                        current = current->right;
                    }
                        
                    //not found
                    if(current == NULL){
                        return NULL;
                    }
                }			
            }
            return current;
        }
};

int main(){
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << "SIZE: " << size << std::endl;

    Tree a;
    a.insert(arr, 0, size -1);

    std::cout << std::endl;
    return 0;
}