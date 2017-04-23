#ifndef BPLUS_H
#define BPLUS_H
extern "C" {

    // TYPES.

    typedef struct record {
        int usn;
        char name[50];
        float cgpa;

    } record;


    typedef struct node {
        void ** pointers;
        int * keys;
        struct node * parent;
        bool is_leaf;
        int num_keys;
        struct node * next;
    } node;




    // PROTOTYPES.


    void enqueue( node * new_node );
    node * dequeue( void );
    int height( node * root );
    int path_to_root( node * root, node * child );
    void save_leaves( node * root, char* fileuri);
    node* load_leaves(node* root, char* fileuri);
    void print_tree( node * root );
    void find_and_print(node * root, int key, bool verbose);
    void find_and_print_range(node * root, int range1, int range2, bool verbose);
    int find_range( node * root, int key_start, int key_end, bool verbose,
                    int returned_keys[], void * returned_pointers[]);
    node * find_leaf( node * root, int key, bool verbose );
    record * find_record( node * root, int key, bool verbose );
    int cut( int length );

    // Insertion.

    record * make_record(int value, char* name, float cgpa );
    node * make_node( void );
    node * make_leaf( void );
    int get_left_index(node * parent, node * left);
    node * insert_into_leaf( node * leaf, int key, record * pointer );
    node * insert_into_leaf_after_splitting(node * root, node * leaf, int key,
                                            record * pointer);
    node * insert_into_node(node * root, node * parent,
                            int left_index, int key, node * right);
    node * insert_into_node_after_splitting(node * root, node * parent,
                                            int left_index,
                                            int key, node * right);
    node * insert_into_parent(node * root, node * left, int key, node * right);
    node * insert_into_new_root(node * left, int key, node * right);
    node * start_new_tree(int key, record * pointer);
    node * insert( node * root, int key, int value, char* name, float cgpa );
    void update_record(node *root, int key, char *newname, float newcgpa);
    record** array_record( node* root );
    node* run_multiple_query(node* root, char* query);

// Deletion.

    int get_neighbor_index( node * n );
    node * adjust_root(node * root);
    node * merge_nodes(node *root, node *n, node *neighbor,
                       int neighbor_index, int k_prime);
    node * redistribute_nodes(node * root, node * n, node * neighbor,
                              int neighbor_index,
                              int k_prime_index, int k_prime);
    node * delete_entry( node * root, node * n, int key, void * pointer );
    node* delete_node(node* root, int key);

}
#endif
