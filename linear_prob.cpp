    #include<iostream>
    using namespace std;
    #include<stdlib.h>  

    struct item 
    {
        int key;
        int value;
    }; 

    struct hashtable_item
    {  
        int flag;
        /*
         * flag = 0 : data does not exist
         * flag = 1 : data exists
         * flag = 2 : data existed at least once
        */   
        struct item *data;
    };

    struct hashtable_item *array;

    int size = 0;
    #define max 10

    void init_array()
    {
        int i;
        for (i = 0; i < max; i++) 
        {
    	  array[i].flag = 0;
    	  array[i].data = NULL;
        }
    }  
    /* to every key, it will generate a corresponding index */
    int hashcode(int key)
    {
        return (key % max);
    }
 
    void insert(int key, int value)
    {
        int index = hashcode(key);
        int i = index;
        struct item *new_item = (struct item*) malloc(sizeof(struct item));
        new_item->key = key;
        new_item->value = value;  
        /* probing through the array until we reach an empty space */
        while (array[i].flag == 1) 
        {   
    	if (array[i].data->key == key) 
            {    
    		/* case where already existing key matches the given key */
    		cout<<"\n Key already exists, hence updating its value \n";
    		array[i].data->value = value;
    		return;    
       	    }   
    	i = (i + 1) % max;
    	if (i == index) 
            {
    		cout<<"\n Hash table is full, cannot insert any more item \n";
    		return;
    	    }   
        }   

        array[i].flag = 1;
        array[i].data = new_item;
        size++;
        cout<<"\n Key ("<<key<<") has been inserted \n";   
    }  

    void remove_element(int key)
    {
        int index = hashcode(key);
        int  i = index;    
        /* probing through array until we reach an empty space where not even once an element had been present */
        while (array[i].flag != 0) 
        {    
    	if (array[i].flag == 1  &&  array[i].data->key == key ) 
            {    
    		// case when data key matches the given key
    		array[i].flag =  2;
    		array[i].data = NULL;
    		size--;
    		cout<<"\n Key ("<<key<<") has been removed \n";
    		return;    
            }
    	i = (i + 1) % max;
    	if (i == index)
            {
    		break;
    	    }
        }    
        cout<<"\n This key does not exist \n";    
    }

    void display()
    {
        int i;
        for (i = 0; i < max; i++)
        {
    	struct item *current = (struct item*) array[i].data;    
    	if (current == NULL)
            {
    	       cout<<"\n Array["<<i<<"] has no elements \n";
    	    }

    	else
            {
    	       cout<<"\n Array["<<i<<"] has elements -: \n  "<<current->key<<" (key) and "<<current->value<<"(value) ";
    	    }
        }    
    }    
 
    int size_of_hashtable()
    {
        return size;
    }     

    int main()
    {
    	int choice, key, value, n, c;   
    	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item*));
    	init_array();    
    	do 
        {
    		cout<<"Implementation of Hash Table in C with Linear Probing \n\n";
    		cout<<"MENU-: \n1.Inserting item in the Hashtable" 
                             "\n2.Removing item from the Hashtable" 
                             "\n3.Check the size of Hashtable"
                             "\n4.Display Hashtable"
    		 "\n\n Please enter your choice-:";    
    		cin>>choice;     
    		switch(choice) 
                {    
    		case 1:   
    		      cout<<"Inserting element in Hashtable\n";
    		      cout<<"Enter key and value-:\t";
    		      cin>>key>>value;
    		      insert(key, value);    
    		      break;     
    		case 2:    
    		      cout<<"Deleting in Hashtable \n Enter the key to delete-:";
    		      cin>>key;
    		      remove_element(key);    
    		      break;    
    		case 3:   
    		      n = size_of_hashtable();
    		      cout<<"Size of Hashtable is-:"<<n<<"\n";    
    		      break;    
    		case 4:     
    		      display();     
    		      break;    
    		default:    
    		       cout<<"Wrong Input\n";     
    		} 
   
    		cout<<"\n Do you want to continue-:(press 1 for yes)\t";
    		cin>>c;   
    	}while(c == 1);         
    }
