#include <stdio.h>
#include <vector>

template <typename AGenericType>

class AClassTemplate {
  std::vector<AGenericType> a_vector_attribute_of_a_generic_type;

  AClassTemplate(){};
  AClassTemplate(std::vector<AGenericType> a_vector_attribute) {

    a_vector_attribute_of_a_generic_type = std::move(a_vector_attribute);
  }

  AGenericType *find(AGenericType an_element) {

    for (auto an_element_of_the_vector =
             a_vector_attribute_of_a_generic_type.begin();
         an_element_of_the_vector != a_vector_attribute_of_a_generic_type.end();
         ++an_element_of_the_vector) {
      if (*an_element_of_the_vector == an_element) {

        return (&*an_element_of_the_vector);
      }
    }
    return (NULL);
  }

  void insert(AGenericType an_element) {

    for (auto an_element_of_the_vector =
             a_vector_attribute_of_a_generic_type.begin();
         an_element_of_the_vector != a_vector_attribute_of_a_generic_type.end();
         ++an_element_of_the_vector) {
      if (*an_element_of_the_vector == an_element) {
        a_vector_attribute_of_a_generic_type.erase(an_element_of_the_vector);
        break;
      }
    }
  }

  friend int main(int argc, char **argv);
};

int main(int argc, char **argv) {
  AClassTemplate<int> type_int;
  int an_element;
  setbuf(stdout, NULL);

  printf("Find: %d\n", *type_int.find(an_element));
  type_int.insert(an_element);
  for (auto an_element_of_the_vector =
           type_int.a_vector_attribute_of_a_generic_type.begin();
       an_element_of_the_vector !=
       type_int.a_vector_attribute_of_a_generic_type.end();
       ++an_element_of_the_vector) {
    printf("Insert/remove an element of the vector: %d\n",
           *an_element_of_the_vector);
  }

  AClassTemplate<double> type_double;
  printf("Find: %f\n", *type_double.find((double)an_element));
  type_double.insert((double)an_element);
  for (auto an_element_of_the_vector =
           type_double.a_vector_attribute_of_a_generic_type.begin();
       an_element_of_the_vector !=
       type_double.a_vector_attribute_of_a_generic_type.end();
       ++an_element_of_the_vector) {
    printf("Insert/remove an element of the vector: %f\n",
           *an_element_of_the_vector);
  }

  return (0);
}
