#include <bits/stdc++.h>
using namespace std;

//A node in the hashtable
struct Node
{
    string word;
    Node *next;
};

const int N = 26; //no of buckets in hash table

Node *table[N]; // create a hashtable with 26 empty buckets

int Hash(string word)
{
    return (word[0] - 'a');
}

void insert(string word)
{
    int index = Hash(word);

    Node *tmp = new Node();
    tmp->word = word;
    tmp->next = NULL;

    if (table[index] == NULL)
    {
        table[index] = tmp;
        return;
    }
    else
    {
        tmp->next = table[index];
        table[index] = tmp;
    }
}

//returns true if word in dictionary else false
void search(string word)
{
    int index = Hash(word);

    Node *tmp = table[index];
    while (tmp != NULL)
    {
        if (tmp->word.compare(word) == 0)
        {
            cout << "Word found!" << endl;
            return;
        }
        else
            tmp = tmp->next;
    }
    cout << "Not found!" << endl;
    return;
}

void Delete(string word)
{
    int index = Hash(word);

    Node *tmp = table[index];
    Node *prev = NULL;
    while (tmp != NULL)
    {
        if (tmp->word.compare(word) == 0)
        {
            if (prev == NULL)
                table[index] = tmp->next;
            else
                prev->next = tmp->next;
            cout << "Successfully deleted : " << word;
            free(tmp);
            return;
        }

        prev = tmp;
        tmp = tmp->next;
    }
    cout << word << " not found";
    return;
}

void print()
{
    for (int i = 0; i < 26; i++)
    {
        if (table[i] == NULL)
            continue;
        Node *tmp = table[i];
        while (tmp != NULL)
        {
            cout << tmp->word << "   ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

int main()
{
    while (true)
    {
        string s;
        int n;
        cout << endl
             << "1: insert    2:delete    3: search    4:print   5:exit   :";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the word to be inserted:  ";
            cin >> s;
            insert(s);
            break;
        case 2:
            cout << "Enter the word to be deleted: ";
            cin >> s;
            Delete(s);
            break;
        case 3:
            cout << "Enter the word to be searched :";
            cin >> s;
            search(s);
            break;
        case 4:
            print();
            break;
        case 5:
            exit(0);
        default:
            continue;
        }
    }
}
