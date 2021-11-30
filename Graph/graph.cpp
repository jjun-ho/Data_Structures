
#include <cassert>
#include <cstdlib>
#include <set>

template <class Item>
class graph
{
  public:
    // MEMBER CONSTANTS
    static const std::size_t MAXIMUM = 20;
    // CONSTRUCTOR
    graph( ) { many_vertices = 0; }
    // MODIFICATION MEMBER FUNCTIONS
    void add_vertex(const Item& label);
    void add_edge(std::size_t source, std::size_t target);
    void remove_edge(std::size_t source, std::size_t target); 
    Item& operator [ ] (std::size_t vertex);
    // CONSTANT MEMBER FUNCTIONS
    std::size_t size( ) const { return many_vertices; }
    bool is_edge(std::size_t source, std::size_t target) const; 
    std::set<std::size_t> neighbors(std::size_t vertex) const;
    Item operator[ ] (std::size_t vertex) const;
  private:
    bool edges[MAXIMUM][MAXIMUM];
    Item labels[MAXIMUM]; 
    std::size_t many_vertices;
};

template <class Item>
const std::size_t graph<Item>::MAXIMUM;

template <class Item>
void graph<Item>::add_edge(std::size_t source, std::size_t target)
{
  assert(source < size( )); 
  assert(target < size( )); 
  edges[source][target] = true;
}

template <class Item>
void graph<Item>::add_vertex(const Item& label)
{
  std::size_t new_vertex_number; 
  std::size_t other_number;

  assert(size( ) < MAXIMUM);
  new_vertex_number = many_vertices;
  ++many_vertices;
  for (other_number = 0; other_number < many_vertices; ++other_number) 
  {
    edges[other_number][new_vertex_number] = false;
    edges[new_vertex_number][other_number] = false;
  }
  labels[new_vertex_number] = label; 
}

template <class Item>
bool graph<Item>::is_edge(std::size_t source, std::size_t target) const
{
  assert(source < size( )); 
  assert(target < size( )); 
  return edges[source][target];
}

template <class Item>
Item& graph<Item>::operator[ ] (std::size_t add_vertex)
{
  assert(vertex < size( ));
  return labels[vertex];
}

template <class Item>
Item graph<Item>::operator[ ] (std::size_t add_vertex) const
{
  assert(vertex < size( ));
  return labels[vertex];
}

template <class Item>
std::set<std::size_t> graph<Item>::neighbors(std::size_t vertex) const
{
  std::set<std::size_t> answer; 
  std::size_t i;
  
  assert(vertex < size( ));
  
  for (i = 0; i < size( ); ++i) 
  {
    if (edges[vertex][i]) 
      answer.insert(i);
  }
  return answer;
}

template <class Item>
void graph<Item>::remove_edge(std::size_t source, std::size_t target)
{
  assert(source < size( )); 
  assert(target < size( )); 
  edges[source][target] = false;
}

