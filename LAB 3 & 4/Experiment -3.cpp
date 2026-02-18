#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

node* head1 = NULL;
node* head2 = NULL;
node* headR = NULL;

node* insertEnd(node* head, int data) {
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
        return temp;

    node* t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = temp;
    return head;
}

node* createNumber(const char s[]) {
    node* head = NULL;
    for (int i = 0; s[i] != '\0'; i++)
        head = insertEnd(head, s[i] - '0');
    return head;
}

void print(node* head) {
    if (head == NULL) return;
    print(head->next);
    cout << head->data;
}

node* add(node* a, node* b) {
    node* res = NULL;
    int carry = 0;

    while (a || b || carry) {
        int sum = carry;
        if (a) { sum += a->data; a = a->next; }
        if (b) { sum += b->data; b = b->next; }

        res = insertEnd(res, sum % 10);
        carry = sum / 10;
    }
    return res;
}

node* subtract(node* a, node* b) {
    node* res = NULL;
    int borrow = 0;

    while (a) {
        int diff = a->data - borrow - (b ? b->data : 0);
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else borrow = 0;

        res = insertEnd(res, diff);
        a = a->next;
        if (b) b = b->next;
    }
    return res;
}

node* multiply(node* a, node* b) {
    node* result = NULL;
    int shift = 0;

    for (node* pb = b; pb; pb = pb->next) {
        node* temp = NULL;

        for (int i = 0; i < shift; i++)
            temp = insertEnd(temp, 0);

        int carry = 0;
        for (node* pa = a; pa; pa = pa->next) {
            int prod = pa->data * pb->data + carry;
            temp = insertEnd(temp, prod % 10);
            carry = prod / 10;
        }

        if (carry)
            temp = insertEnd(temp, carry);

        result = add(result, temp);
        shift++;
    }
    return result;
}

node* power(node* base, int exp) {
    node* result = NULL;
    result = insertEnd(result, 1);

    while (exp--)
        result = multiply(result, base);

    return result;
}

int main() {
    head1 = createNumber("123");
    head2 = createNumber("45");

    cout << "Addition: ";
    headR = add(head1, head2);
    print(headR);

    cout << "\nSubtraction: ";
    headR = subtract(head1, head2);
    print(headR);

    cout << "\nMultiplication: ";
    headR = multiply(head1, head2);
    print(headR);

    cout << "\nPower (123^3): ";
    headR = power(head1, 3);
    print(headR);

    return 0;
}
