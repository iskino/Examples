// сборка: g++ -std=c++11 stack.cxx -o stack

#include <stdexcept>
#include <exception>
#include <iostream>
 
// шаблон стека на основе односвязного списка
template<class Type>
class Stack 
{
public:
    typedef Type value_type; 		  // тип значения
    typedef value_type& value_ref; 	  // ссылка на элемент
    typedef const value_type& value_cref; // константная ссылка

private:
    // структура, представ. узел, хранит данные с указателем на след.узел"
    struct Node 
    {
        value_type value; 	// данные
        Node* link;  		// указатель на следующий узел
        
	// конструктор, используемый по умолчанию
        Node(): value(0), link(nullptr) {};
        
	// конструктор, с передав. параметрами
        Node(value_cref val, node* prev): value(val), link(prev) {};
    };

    Node*  m_head; // Основание стека

public:
    // конструктор, используемый по умолчанию
    Stack(): m_head(nullptr), m_size(0) {};
    
    // деструктор
    ~Stack() { clear(); }
    
    // проверка на отсутствие узлов
    bool is_empty() const { return nullptr == m_head; }
    
    // очистка стека
    void clear() 
    {
        while(!is_empty()) {
            Node* tmp = m_head;
            m_head = m_head->link;
            
	    delete tmp;
        }
    }

    // возвращает значение на вершине стека
    value_ref top() const 
    {
        if(is_empty())
            throw std::runtime_error("stack is empty");
	return m_head->value;
    }

    // добавление элемента в стек
    void push(value_cref value) 
    {
        // создаем новый узел
        Node* tmp = new Node(value, m_head); // при нехватке памяти
                                             // будет выброшено исключение std::bad_alloc
        
	// запоминаем новое основание стека
        m_head = tmp;
    }

    // удаляет верхний элемент стека
    void pop() 
    {
        if(is_empty())
            throw std::runtime_error("stack is empty");
        
	// запоминаем основание стека
        Node* tmp = m_head;

        // смещаемся к следующему узлу стека
        m_head = m_head->link;

        // удаляем старое основание стека
        delete tmp;
    }
};

int main() 
{
    // создаем экземпляр стека
    Stack<int> stack;
    
    // записываем данные в стек
    for(int i = -5; i <= 5; ++i) 
    {
        try 
        {
            stack.push(i);
        }
        catch(std::bad_alloc &e) 
 	{
            std::cerr << "Oops: " << e.what() <<std::endl;
            return 1;
        }
    }

    // выводим содержимое стека
    while(!stack.is_empty()) 
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
 
   return 0;
}
