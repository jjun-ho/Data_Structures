template <class Item>
class binary_tree_node
{
  private:
    Item data_field;
    binary_tree_node* left_field;
    binary_tree_node* right_field;
  public:
    binary_tree_node(const Item& init_data = Item(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL)
    {
      data_field = init_data;
      left_field = init_left;
      right_field = init_right;
    }
    Item& data() {return data_field;}
    binary_tree_node*& left( ) { return left_field; }
    binary_tree_node*& right( ) { return right_field; }
    void set_data(const Item& new_data) { data_field = new_data; }
    void set_left(binary_tree_node* new_left) { left_field = new_left; } 
    void set_right(binary_tree_node* new_right) { right_field = new_right; }
    const Item& data( ) const { return data_field; }
    const binary_tree_node* left( ) const { return left_field; }
    const binary_tree_node* right( ) const { return right_field; }
    bool is_leaf( ) const {return (left_field == NULL) && (right_field == NULL);}
};

template <class Item>
void tree_clear(binary_tree_node<Item>*& root_ptr)
{
  binary_tree_node<Item>* child;
  if (root_ptr != NULL)
  {
    child =  root_ptr -> left();
    tree_clear(child);
    child = root_ptr -> right();
    tree_clear(child);
    delete root_ptr;
    root_ptr = NULL;
  }
}

template <class Item>
binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr)
{
  binary_tree_node<Item> *l_ptr; binary_tree_node<Item> *r_ptr;
  if (root_ptr == NULL) return NULL;
  else
  {
    l_ptr = tree_copy( root_ptr->left( ) ); 
    r_ptr = tree_copy( root_ptr->right( ) ); 
      return new binary_tree_node<Item>(root_ptr->data( ), l_ptr, r_ptr);
  } 
}

