#include <list>
#include <stdio.h>
#include <stdlib.h>

class Node {
  int value;
  Node *next;
  Node *prev;

  Node(int value) { (*this).value = value; }

  friend void print_out_values_of_connected_nodes_in_forward(
      std::list<Node> connected_nodes);
  friend void backward_order(std::list<Node> connected_nodes);
  friend void a();
  friend void insertNode(Node *&head, Node *&tail, Node *priorNode,
                         Node *newNode);
  friend void deleteNode(Node *&head, Node *&tail, Node *delNote);
  friend void b();
  friend void c();
  friend void
  a_function_to_sort_elements_of_the_linked_list_in_ascending_order_using_bubble_sort(
      std::list<Node> &elements_of_the_linked_list);
  friend void d();
};

void print_out_values_of_connected_nodes_in_forward(
    std::list<Node> connected_nodes) {
  for (std::list<Node>::iterator node = connected_nodes.begin();
       node != connected_nodes.end(); ++node) {
    printf("%d ", (*node).value);
  }
}

void backward_order(std::list<Node> connected_nodes) {
  for (std::list<Node>::reverse_iterator node = connected_nodes.rbegin();
       node != connected_nodes.rend(); ++node) {
    printf("%d ", (*node).value);
  }
}

void a() {
  std::list<Node> a_doubly_linked_list;

  a_doubly_linked_list.push_back(Node(8));
  a_doubly_linked_list.push_back(Node(5));
  a_doubly_linked_list.push_back(Node(3));
  a_doubly_linked_list.push_back(Node(6));

  setbuf(stdout, NULL);

  puts("Print out values of connected nodes in forward: ");
  print_out_values_of_connected_nodes_in_forward(a_doubly_linked_list);
  putchar('\n');
  puts("and backward orders: ");
  backward_order(a_doubly_linked_list);
  putchar('\n');
}

void insertNode(Node *&head, Node *&tail, Node *priorNode, Node *newNode) {

  if (priorNode == NULL) {
    (*newNode).next = head;
    head = newNode;
  } else {
    (*newNode).prev = priorNode;
    (*priorNode).next = newNode;
    if (priorNode == tail) {
      tail = newNode;
    }
  }
}

void deleteNode(Node *&head, Node *&tail, Node *delNote) {
  Node *a_node = head;

  while (a_node != NULL) {
    if ((*a_node).value == (*delNote).value) {
    };
    a_node = (*a_node).next;
  }
}

void b() {
  std::list<Node> the_list;
  Node a_new_node_with_value_100(100);
  Node another_one_with_value_200(200);
  Node the_node_of_value_5(5);

  the_list.push_back(Node(5));
  the_list.push_back(Node(8));
  the_list.push_back(Node(5));
  the_list.push_back(Node(3));
  the_list.push_back(Node(6));
  the_list.push_back(Node(5));

  Node *the_head = &the_list.front();
  Node *the_tail = &the_list.back();

  insertNode(the_head, the_tail, NULL, &a_new_node_with_value_100);
  the_head = &the_list.front();
  the_tail = &the_list.back();

  Node *priorNode = &(*(std::next(the_list.begin(), 3)));

  insertNode(the_head, the_tail, priorNode, &another_one_with_value_200);
  the_head = &the_list.front();
  the_tail = &the_list.back();
  deleteNode(the_head, the_tail, &the_node_of_value_5);
  puts("Print out values to check:");
  print_out_values_of_connected_nodes_in_forward(the_list);
  putchar('\n');
}

void a_function_to_swap_two_nodes(Node *node_one, Node *node_two) {
  Node *their_positions;

  their_positions = node_one;
  node_one = node_two;
  node_two = their_positions;
}

void c() {
  std::list<Node> two_nodes;

  two_nodes.push_back(Node(atoi("value")));
  two_nodes.push_back(Node(atoi("value")));
  a_function_to_swap_two_nodes(&two_nodes.front(), &two_nodes.back());
  print_out_values_of_connected_nodes_in_forward(two_nodes);
  putchar('\n');
}

void a_function_to_sort_elements_of_the_linked_list_in_ascending_order_using_bubble_sort(
    std::list<Node> &elements_of_the_linked_list) {
  unsigned char sort;

  do {
    sort = 0;
    for (std::list<Node>::iterator element =
             elements_of_the_linked_list.begin();
         element != elements_of_the_linked_list.end(); ++element) {
      if ((*std::next(element)).value > (*element).value) {
        std::swap((*element).value, (*std::next(element)).value);
        sort = true;
      }
    }
  } while (sort);
}

void d() {
  std::list<Node> the_linked_list;

  a_function_to_sort_elements_of_the_linked_list_in_ascending_order_using_bubble_sort(
      the_linked_list);
  print_out_values_of_connected_nodes_in_forward(the_linked_list);
  putchar('\n');
}

int main(int argc, char **argv) {

  a();
  b();
  c();
  d();

  return (0);
}
