#include "./adts/linked_list.cpp"
#include <iostream>

int main()
{

  List<int> *l = new LinkedList<int>();
  for (int i = 0; i < 10; i++)
  {
    l->add(i);
  }

  Iterator<int> *it = l->iterator();
  while (it->hasNext())
  {
    int x = it->next();
    std::cout << x << std::endl;
  }
}
