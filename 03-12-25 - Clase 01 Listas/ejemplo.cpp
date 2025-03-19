#include "./adts/linked_list.cpp"
#include "./adts/list.cpp"
#include <iostream>
#include <string>

int main() {
  std::string name;
  std::cin >> name;
  int age;
  std::cin >> age;
  std::cout << "Hello " << name << " you are " << age << " year old"
            << std::endl;

  List<int> *l = new LinkedList<int>();

  std::cout << "List size is " << l->size() << std::endl;
  std::cout << "Is list empty?" << std::endl;
  std::cout << l->isEmpty() << std::endl;

  l->add(4);
  l->add(3);
  std::cout << l->contains(4) << std::endl;
}
