#include <iostream>
#include <concepts>
using namespace std;

template<integral T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}
    
    ~SinglyLinkedList() {
        clear();
    }
    
    // 先頭に要素を追加
    void pushFront(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    // 末尾に要素を追加
    void pushBack(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }
    
    // 先頭から要素を削除
    void popFront() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }
    
    // 要素を検索
    bool find(const T& value) const {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    // リストを表示
    void display() const {
        Node* current = head;
        cout << "Singly Linked List: ";
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
    
    // メモリを解放
    void clear() {
        while (head) {
            popFront();
        }
    }
    
    int getSize() const { return size; }
    bool isEmpty() const { return head == nullptr; }
};


// ===== デモ用のメイン関数 =====
int main() {
    cout << "=== 連結リストのデモンストレーション ===\n\n";
    
    // 単方向連結リストのテスト
    cout << "1. 単方向連結リスト\n";
    SinglyLinkedList<int> sll;
    sll.pushBack(1);
    sll.pushBack(2);
    sll.pushBack(3);
    sll.pushFront(0);
    sll.display();
    cout << "要素数: " << sll.getSize() << "\n";
    cout << "2を検索: " << (sll.find(2) ? "見つかりました" : "見つかりません") << "\n\n";
    
    return 0;
}