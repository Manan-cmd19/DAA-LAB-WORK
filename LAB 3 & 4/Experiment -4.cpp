#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;



struct node
{
    string name;
    int x, y;
    node* next;
};

node* createnode(string name, int x, int y)
{
    node* newnode = new node();
    newnode->name = name;
    newnode->x = x;
    newnode->y = y;
    newnode->next = NULL;
    return newnode;
}

node* insert_city(node* head, string name, int x, int y)
{
    node* newnode = createnode(name, x, y);
    newnode->next = head;
    return newnode;
}

node* name_delete(node* head, string name)
{
    node* temp = head;
    node* prev = NULL;

    while (temp)
    {
        if (temp->name == name)
        {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

node* name_search(node* head, string name)
{
    node* temp = head;

    while (temp)
    {
        if (temp->name == name)
        {
            cout << "Found: " << temp->name << " "
                 << temp->x << "," << temp->y << endl;
            return temp;
        }
        temp = temp->next;
    }

    cout << "Not Found" << endl;
    return NULL;
}

void distance_ll(node* head, int x, int y, double d)
{
    while (head)
    {
        double dist = sqrt(pow(head->x - x, 2) + pow(head->y - y, 2));
        if (dist <= d)
            cout << head->name << " "
                 << head->x << "," << head->y << endl;
        head = head->next;
    }
}

void display_ll(node* head)
{
    while (head)
    {
        cout << head->name << " "
             << head->x << "," << head->y << endl;
        head = head->next;
    }
}


#define MAX 1000

struct city
{
    string name;
    int x, y;
};

void insert_array(city arr[], int& n, string name, int x, int y)
{
    if (n < MAX)
    {
        arr[n].name = name;
        arr[n].x = x;
        arr[n].y = y;
        n++;
    }
}

void delete_array(city arr[], int& n, string name)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].name == name)
        {
            for (int j = i; j < n - 1; j++)
                arr[j] = arr[j + 1];
            n--;
            return;
        }
    }
}

void search_array(city arr[], int n, string name)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].name == name)
        {
            cout << "Found: " << arr[i].name << " "
                 << arr[i].x << "," << arr[i].y << endl;
            return;
        }
    }
    cout << "Not Found" << endl;
}

void distance_array(city arr[], int n, int x, int y, double d)
{
    for (int i = 0; i < n; i++)
    {
        double dist = sqrt(pow(arr[i].x - x, 2) + pow(arr[i].y - y, 2));
        if (dist <= d)
            cout << arr[i].name << " "
                 << arr[i].x << "," << arr[i].y << endl;
    }
}

void display_array(city arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i].name << " "
             << arr[i].x << "," << arr[i].y << endl;
}



void timee(clock_t start, clock_t end)
{
    cout << "Time: "
         << double(end - start) * 1000000 / CLOCKS_PER_SEC
         << " microsec" << endl;
}



int main()
{
    clock_t s, e;


    cout << "Array Form" << endl;
    city arr[MAX];
    int n = 0;

    s = clock();
    insert_array(arr, n, "Gujarat", 10, 20);
    insert_array(arr, n, "Assam", 30, 40);
    insert_array(arr, n, "Bombay", 15, 25);
    insert_array(arr, n, "Kerela", 20, 25);
    insert_array(arr, n, "Banglore", 25, 30);
    e = clock();
    timee(s, e);

    s = clock();
    display_array(arr, n);
    e = clock();
    timee(s, e);

    s = clock();
    search_array(arr, n, "Delhi");
    e = clock();
    timee(s, e);

    s = clock();
    delete_array(arr, n, "Bombay");
    e = clock();
    timee(s, e);

    s = clock();
    distance_array(arr, n, 20, 20, 15);
    e = clock();
    timee(s, e);

    cout << "\nAfter Deletion (Array)" << endl;
    display_array(arr, n);

    /* ---------- LINKED LIST FORM ---------- */
    cout << "\nLinked List Form" << endl;
    node* head = NULL;

    s = clock();
    head = insert_city(head, "Gujarat", 10, 20);
    head = insert_city(head, "Assam", 30, 40);
    head = insert_city(head, "Bombay", 15, 25);
    head = insert_city(head, "Kerela", 20, 25);
    head = insert_city(head, "Banglore", 25, 30);
    e = clock();
    timee(s, e);

    s = clock();
    display_ll(head);
    e = clock();
    timee(s, e);

    s = clock();
    name_search(head, "Delhi");
    e = clock();
    timee(s, e);

    s = clock();
    head = name_delete(head, "Bombay");
    e = clock();
    timee(s, e);

    s = clock();
    distance_ll(head, 20, 20, 15);
    e = clock();
    timee(s, e);

    cout << "\nAfter Deletion (Linked List)" << endl;
    display_ll(head);

    return 0;
}