#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int key;
    Node **forward;
    Node(int, int);
};

Node::Node(int key, int level)
{
    this->key = key;
    forward = new Node*[level+1];
    memset(forward, 0, sizeof(Node*)*(level+1));
};


class Skip_list
{

    int maxlvl;
    float fra;
    int level;
    Node *header;
public:
    Skip_list(int, float);
    int randomLevel();
    Node* createNode(int, int);
    void insert(int);
    void deleteEle(int);
    void search(int);
    void display();
};



Skip_list::Skip_list(int maxlvl, float fra)
{
    this->maxlvl = maxlvl;
    this->fra = fra;
    level = 0;
    header = new Node(-1, maxlvl);
};

int Skip_list::randomLevel()
{
    float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while(r < fra && lvl < maxlvl)
    {
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
};


Node* Skip_list::createNode(int key, int level)
{
    Node *n = new Node(key, level);
    return n;
};

//Insertion
void Skip_list::insert(int key)
{
    Node *curr = header;
    Node *update[maxlvl+1];
    memset(update, 0, sizeof(Node*)*(maxlvl+1));
    for(int i = level; i >= 0; i--)
    {
        while(curr->forward[i] != NULL && curr->forward[i]->key < key)
        {
            curr = curr->forward[i];
        }
        update[i] = curr;
    }
    curr = curr->forward[0];

    if (curr == NULL || curr->key != key)
    {

        int rlevel = randomLevel();

        if(rlevel > level)
        {
            for(int i=level+1;i<rlevel+1;i++)
                update[i] = header;


            level = rlevel;
        }

        Node* n = createNode(key, rlevel);
        for(int i=0;i<=rlevel;i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }

    }
};

// Deletion
void Skip_list::deleteEle(int key)
{
    Node *curr = header;

    Node *update[maxlvl+1];
    memset(update, 0, sizeof(Node*)*(maxlvl+1));
    for(int i = level; i >= 0; i--)
    {
        while(curr->forward[i] != NULL  && curr->forward[i]->key < key)
            curr = curr->forward[i];
        update[i] = curr;
    }
    curr = curr->forward[0];


    if(curr != NULL and curr->key == key)
    {

        for(int i=0;i<=level;i++)
        {

            if(update[i]->forward[i] != curr)
                break;

            update[i]->forward[i] = curr->forward[i];
        }


        while(level>0 &&
              header->forward[level] == 0)
            level--;
         cout<<" Key---> "<<key<<" is successfully deleted\n";
    }
};

// Searching
void Skip_list::search(int key)
{
    Node *curr = header;

    for(int i = level; i >= 0; i--)
    {
        while(curr->forward[i] && curr->forward[i]->key < key)
            curr = curr->forward[i];

    }

    curr = curr->forward[0];
    if(curr and curr->key == key)
        cout<<" Key---> "<<key<<" is found\n";
    else
        cout<<"Key Not found"<<"\n";
};


void Skip_list::display()
{
    cout<<"\nSkip List elements:"<<"\n";
    for(int i=0;i<=level;i++)
    {
        Node *node = header->forward[i];
        cout<<"Level "<<i<<": ";
        while(node != NULL)
        {
            cout<<node->key<<" ";
            node = node->forward[i];
        }
        cout<<"\n";
    }
};

  int main()
{



    srand((unsigned)time(0));
    int max_lvl, n,i;
    cout<<"Enter maximum level you want to create skip list:";
    cin>>max_lvl;
    Skip_list list(max_lvl, 0.5);
    int ch,ele,key;
	cout<<"Enter 1: insert ,2: search ,3: delete,4: display : ";
	cin>>ch;
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:cout<<"Enter the number of elements to be inserted:";
		    cin>>n;
		    cout<<"Enter the element to be inserted: ";
		    for(i=0;i<n;i++)
		    {
	 		cin>>ele;
			list.insert(ele);
		    }
			break;
		case 2:cout<<"Enter the Key to be searched: ";
	 		cin>>key;
			list.search(key);
			break;
		case 3:cout<<"Enter the element to be deleted: ";
	 		cin>>ele;
			list.deleteEle(ele);
			break;
		case 4:list.display();
		default:break;
	}
	cout<<"Enter 1: insert ,2: search ,3: delete,4: display : ";
	cin>>ch;
	}

}
