#include <cstdlib>

template <class RecordType> 
class table
{
public:
  // MEMBER CONSTANT 
  static const std::size_t CAPACITY = 811;
  // CONSTRUCTOR
  table( );
  // MODIFICATION MEMBER FUNCTIONS
  void insert(const RecordType& entry);
  void remove(int key);
  // CONSTANT MEMBER FUNCTIONS
  bool is_present(int key) const;
  void find(int key, bool& found, RecordType& result) const; 
  std::size_t size( ) const { return used; }
private:
  // MEMBER CONSTANTS 
  static const int NEVER_USED = -1;
  static const int PREVIOUSLY_USED = -2;
  // MEMBER VARIABLES
  RecordType data[CAPACITY];
  std::size_t used;
  // HELPER FUNCTIONS
  std::size_t hash(int key) const;
  std::size_t next_index(std::size_t index) const;
  void find_index(int key, bool& found, std::size_t& index) const; 
  bool never_used(std::size_t index) const;
  bool is_vacant(std::size_t index) const;
};

template <class RecordType>
void table<RecordType>:: insert(const RecordType& entry)
{
  bool already_present;
  std::size_t index; 
  
  assert(entry.key >= 0);

  find_index(entry.key, already_present, index);
  
  if (!already_present)
  {
    assert(size( ) < CAPACITY); 
    index = hash(entry.key); 
    while (!is_vacant(index))
      index = next_index(index);
     ++used;
  }
  data[index] = entry;
}

template <class RecordType>
void table<RecordType>:: remove(int key)
{
  bool found; 
  std::size_t index; 
  
  assert(key >= 0);
  
  find_index(key, found, index); 
  if (found)
  {
    data[index].key = PREVIOUSLY_USED;
    --used; 
  }
}

template <class RecordType>
const std::size_t table<RecordType>::CAPACITY;
template <class RecordType>
const int table<RecordType>::NEVER_USED; 
template <class RecordType>
const int table<RecordType>::PREVIOUSLY_USED;

template <class RecordType>
table<RecordType>:: table()
{
  std::size_t i;
  used = 0;
  for (i = 0; i < CAPACITY; ++i)
    data[i].key = NEVER_USED; 
}    

template <class RecordType>
bool table<RecordType>:: is_present(int key) const
{
  bool found;
  std::size_t index;
  assert(key >= 0);
  find_index(key, found, index);
  return found;
}

template <class RecordType>
void table<RecordType>:: find(int key, bool& found, RecordType& result) const
{
  std::size_t index;
  assert(key >= 0); 
  find_index(key, found, index); 
  if (found)
    result = data[index];
}

template <class RecordType>
inline std::size_t table<RecordType>::hash(int key) const
{
  return (key % CAPACITY);
}

template <class RecordType>
inline std::size_t table<RecordType>::next_index(std::size_t index) const
{
  return ((index + 1) % CAPACITY);
}

template <class RecordType>
void table<RecordType>:: find_index(int key, bool& found, std::size_t& i) const
{
  std::size_t count; 

  count = 0;
  i = hash(key);
  while((count < CAPACITY) && (!never_used(i)) && (data[i].key != key)) 
  {
    ++count;
    i = next_index(i);
  }
  found = (data[i].key == key);
}

template <class RecordType>
inline bool table<RecordType>:: never_used(std::size_t index) const
{
  return data[index].key == NEVER_USED);
}

template <class RecordType>
inline bool table<RecordType>:: is_vacant(std::size_t index) const
{
  return (data[index].key < 0);
}

