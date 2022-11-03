// Speller Program
// Week 5 
// Alexander Torjyan 28

// defines node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[HASHTABLE_SIZE];


int hash_index(char *hash_this)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(hash_this); i < n; i++)
    {
        hash = (hash << 2) ^ hash_this[i];
    }
    return hash % HASHTABLE_SIZE;
}

// Understands the words in the dictionary
int word_count = 0;

// Memory loading if false it will return 
bool load(const char *dictionary)
{
   // dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
       
        node *new_node = malloc(sizeof(node));
        
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        // changes words in node
        strcpy(new_node->word, word);

        // Initialize the calculations
        int h = hash_index(new_node->word);

      
        node *head = hashtable[h];

        // Create new node at begingin of the list
        if (head == NULL)
        {
            hashtable[h] = new_node;
            word_count++;
        }
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
            word_count++;
        }
    }
    fclose(file);
    return true;
}


bool check(const char *word)
{
    int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    
    word_copy[n] = '\0';
    // Initializes index for hashed word
    int h = hash_index(word_copy);
  
    node *cursor = hashtable[h];
    // CHange curser location to the place of the head
    while (cursor != NULL)
    {
        
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            return true;
        }
        
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Reurns the number of words in the dictionary
unsigned int size(void)
{
    return word_count;
}

bool unload(void)
{
    node *head = NULL;
    node *cursor = head;
    // freeing linked lists
    while (cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return true;
}
