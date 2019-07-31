        node* tmp = m_head;

        // смещаемся к следующему
        m_head = m_head->link;

        // удаляем предыдущее основание стека
        delete tmp;
    }
};

int main()
{
    Stack<int> stack; // создаем стек
----
    // записываем данные
    for(int i(-5); i <= 5; ++i) {
        try {
            stack.push(i);
        }
        catch(std::bad_alloc &e) {
            std::cerr << "Oops: " << e.what() <<std::endl;
            return 1;
        }
    }

    // выводим содержимое
    while(!stack.is_empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    return 0;
}
