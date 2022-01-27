/**
 * @file Binary_tree.h
 * @author Moskovchuk Nikita
 * @brief Binary tree
 * @date 2022-01-04
 *
 * @copyright Copyright (c) 2021
 */

#pragma once
#include <iostream>

/**
 * @brief Стуктура узла, содержащегося в дереве
 * @tparam Key Ключ для поиска
 * @tparam Value Значение, хранящееся в дереве
*/
template <typename Key, typename Value>
struct Node {

    std::pair<Key, Value> info; ///< Пара ключ-значение
    Node* left; ///< Указатель на левое поддерево
    Node* right; ///< Указатель на правое поддерево
    Node* parent; ///< Указатель на родительский узел
    Node* next; ///< Указатель на следующий узел при обходе

     /**
     * @brief Конструктор узла дерева
     * @param info Пара ключ-значение
     * @param parent Указатель на родительский узел (по умолчанию nullptr)
    */
    Node(const std::pair<Key, Value>& info, Node* parent = nullptr) : 
            info(info), 
            left(nullptr), 
            right(nullptr), 
            parent(parent),
            next(nullptr) 
    { }
};


/**
 * @brief Класс итератор для бинарного дерева
 * @tparam Key Ключ для поиска
 * @tparam Value Значение, хранящееся в дереве
*/
template <typename Key, typename Value>
class Iterator {
    Node<Key, Value>* ptr; ///< Указатель на текущий узел

public:
    /**
     * @brief Конструктор от указателя на узел
     * @param ptr Указатель на узел дерева
    */
    Iterator(Node<Key, Value>* ptr = nullptr) : ptr(ptr) {}
    
    /**
     * @brief Конструктор от другого итератора
     * @param iter Итератор для копирования
    */
    Iterator(const Iterator& iter) : ptr(iter.ptr) {}

    /**
     * @brief Оператор * для итератора
     * @return Ссылка на пару ключ-значение
    */
    std::pair<Key, Value>& operator* () {
        return ptr->info;
    }

    /**
     * @brief Оператор -> для итератора
     * @return Указатель на пару ключ-значение
    */
    std::pair<Key, Value>* operator->() {
        return &(ptr->info);
    }

    /**
     * @brief Оператор сравнения на равенство двух итераторов
     * @param iter Итератор для сравнения
     * @return true Итераторы указывают на один узел
     * @return false Итераторы указывают на разные узлы
     */
    bool operator==(const Iterator& iter) const {
        return ptr == iter.ptr;
    }

    /**
     * @brief Оператор сравнения на неравенство двух итераторов
     * @param iter Итератор для сравнения
     * @return true Итераторы указывают на разные узлы
     * @return false Итераторы указывают на один узел
     */
    bool operator!=(const Iterator& iter) const {
        return ptr != iter.ptr;
    }

    /**
     * @brief Оператор инкрементирования итератора
     * @return Iterator& Указатель на итератор
     */
    Iterator operator++() {
        ptr = ptr->next;
        return *this;
    }
};


/**
 * @brief Класс бинарное дерево
 * @tparam Key Ключ для поиска
 * @tparam Value Значение, хранящееся в дереве
*/
template <typename Key, typename Value>
class Binary_tree {
public:
    friend class Iterator<Key, Value>;
    using iterator = Iterator<Key, Value>; ///< Итератор бинарного дерева
    using Node = Node<Key, Value>; ///< Узел бинарного дерева

private:
    Node* first; ///< Указатель на первый узел при обходе
    Node* root; ///< Указатель на корень дерева
    size_t size; ///< Количество элементов в дереве

private:
    /**
     * @brief Служебная рекурсия функция для вывода элементов (обход дерева)
     * @param out Поток вывода
     * @param current Текущий узел рекурсии
     */
    void _show_elements(std::ostream& out, Node* current) const;

    /**
     * @brief Служебная функция поиска элемента в таблице
     * @param k Ключ для поиска
     * @return Node* Указатель на найденный узел 
     * @return nullptr Узла с данным ключом не существует
     */
    Node* _find(const Key& k) const;
    
    /**
     * @brief Служебная рекурсивная функция очистки дерева
     * @param node Текущий узел рекурсии
     */
    void _clear(Node* node);

    /**
     * @brief Служебная функция поиска узла, минимального относительно текущего (если дерево по возрастанию)
     * @param node Указатель на узел, относительно которого будет произведен поиск
     * @return Node* Указатель на найденный узел
     */
    Node* _find_minimal(Node* node) const;

    /**
     * @brief Служебная функция поиска узла, максимального относительно текущего (если дерево по возрастанию)
     * @param node Указатель на узел, относительно которого будет произведен поиск
     * @return Node* Указатель на найденный узел
     */
    Node* _find_maximal(Node* node) const;

    /**
     * @brief Служебная функция поиска узла, следующего за данным (если дерево по возрастанию)
     * @param node Указатель на узел, относительно которого будет произведен поиск
     * @return Node* Указатель на найденный узел
     */
    Node* _find_next(Node* node) const;

    /**
     * @brief Служебная функция поиска узла, за которым следует данный (если дерево по возрастанию)
     * @param node Указатель на узел, относительно которого будет произведен поиск
     * @return Node* Указатель на найденный узел
     */
    Node* _find_prev(Node* node) const;

public:
    /**
     * @brief Конструктор бинарного дерева
     */
    Binary_tree() : root(nullptr), first(nullptr), size(0) { }

    /**
     * @brief Деструктор бинарного дерева
     */
    ~Binary_tree() {
        if(root != nullptr)
            _clear(root);
    }

    /**
     * @brief Получить итератор на начало дерева
     * @return iterator итератор на первый узел дерева
     */
    iterator begin() const { return iterator(first); }
    /**
     * @brief Получить итератор на конец дерева
     * @return iterator итератор на последний узел дерева
     */
    iterator end() const { return iterator(nullptr); }
    
    /**
     * @brief Показать элементы дерева, используя обход дерева
     * @param out Поток вывода
     */
    void show_elements(std::ostream& out = std::cout) const;

    /**
     * @brief Показать элементы дерева, используя итератор
     * @param out Поток вывода
     */
    void show_it_elements(std::ostream& out = std::cout) const;

    /**
     * @brief Добавить пару ключ-значение в дерево
     * @param info Пара ключ-значение для вставки
     * \throw std::invalid_argument При повторении ключей
     */
    void add(const std::pair<Key, Value>& info);

    /**
     * @brief Добавить пару ключ-значение в дерево
     * @param key Ключ нового элемента
     * @param value Новый элемент
     * \throw std::invalid_argument При повторении ключей
     */
    void add(const Key& key, const Value& value) { add(std::make_pair(key, value)); }

    /**
     * @brief Поиск элемента в дереве
     * @param k Ключ для поиска
     * @return itearator Итератор на найденный узел
     * \throw std::out_of_range Данного ключа нет в дереве
     */
    iterator find(const Key& k) const;

    /**
     * @brief Проверить, есть ли элемент с данным ключом в дереве
     * @param k Ключ для поиска
     * @return true Элемент с данным ключом есть в дереве
     * @return false Элемента с данным ключом нет в дереве
     */
    bool key_exist(const Key& k) const { return (_find(k) != nullptr); }

    /**
     * @brief Удалить элемент с данным ключом
     * @param k Ключ элемента, который будет удалён
     * \throw std::out_of_range Данного ключа нет в дереве
     */
    void erase(const Key& k);

    /**
     * @brief Удалить все узлы из дерева
     */
    void clear();

    /**
     * @brief Получить количество элементов в дереве
     * @return size_t Количество элементов
     */
    size_t get_size() { return size; }
};




template<typename Key, typename Value>
void Binary_tree<Key, Value>::_show_elements(std::ostream& out, Node* current) const {
    if (current == nullptr) throw std::out_of_range();
    if (current->left != nullptr)
        _show_elements(out, current->left);

    out << "Key: " << current->info.first << std::endl << "Value: " << current->info.second << std::endl;

    if (current->right != nullptr)
        _show_elements(out, current->right);
}


template<typename Key, typename Value>
Node<Key, Value>* Binary_tree<Key, Value>::_find(const Key& k) const {
    Node* ptr = root;
    while (ptr != nullptr) {
        if (ptr->info.first == k)
            break;

        if (k < ptr->info.first)
            ptr = ptr->left;

        else
            ptr = ptr->right;
    }
    return ptr;
}

template<typename Key, typename Value>
void Binary_tree<Key, Value>::_clear(Node* node) {
    size = 0;

    first = nullptr;
    root = nullptr;

    if (node->left != nullptr)
        _clear(node->left);
    if (node->right != nullptr)
        _clear(node->right);

    delete node;
}



template<typename Key, typename Value>
Node<Key, Value>* Binary_tree<Key, Value>::_find_minimal(Node* node) const {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template<typename Key, typename Value>
Node<Key, Value>* Binary_tree<Key, Value>::_find_maximal(Node* node) const {
    while (node->right != nullptr)
        node = node->right;
    return node;
}



template<typename Key, typename Value>
Node<Key, Value>* Binary_tree<Key, Value>::_find_next(Node* node) const {
    if (node->right != nullptr)
        return _find_minimal(node->right);

    Node* ptr;
    ptr = node->parent;
    while (ptr != nullptr && node == ptr->right) {
        node = ptr;
        ptr = ptr->parent;
    }
    return ptr;
}

template<typename Key, typename Value>
Node<Key, Value>* Binary_tree<Key, Value>::_find_prev(Node* node) const {
    if (node->left != nullptr)
        return _find_maximal(node->left);

    Node* ptr;
    ptr = node->parent;
    while (ptr != nullptr && node == ptr->left) {
        node = ptr;
        ptr = ptr->parent;
    }
    return ptr;
}



template<typename Key, typename Value>
void Binary_tree<Key, Value>::show_elements(std::ostream& out) const {
    if (size == 0) out << "Empty" << std::endl;
    _show_elements(out, root);
}

template<typename Key, typename Value>
void Binary_tree<Key, Value>::show_it_elements(std::ostream& out) const {
    if (size == 0) out << "Empty" << std::endl;

    iterator it = begin();
    while (it != end()) {
        out << "Key: " << it->first << std::endl << "Value: " << it->second << std::endl;
        ++it;
    }
}



template<typename Key, typename Value>
void Binary_tree<Key, Value>::add(const std::pair<Key, Value>& info) {
    if (root == nullptr) {
        size = 1;
        root = new Node(info);
        first = root;
        return;
    }

    Node* ptr = root;
    Node* parent = nullptr;

    while (ptr != nullptr) {
        if (info.first == ptr->info.first) {
            throw std::invalid_argument("Key repeats");
        }

        parent = ptr;
        if (info.first < ptr->info.first) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }

    Node* new_node = new Node(info, parent);

    if (new_node->info.first < parent->info.first)
        parent->left = new_node;

    else parent->right = new_node;

    new_node->next = _find_next(new_node);

    Node* prev = _find_prev(new_node);
    if (prev != nullptr) prev->next = new_node;
    else first = new_node;

    size += 1;
}



template<typename Key, typename Value>
Iterator<Key, Value> Binary_tree<Key, Value>::find(const Key& k) const {
    Node* node = _find(k);
    if (node == nullptr) throw std::out_of_range("Key doesn't exist in table");

    return iterator(node);
}



template<typename Key, typename Value>
void Binary_tree<Key, Value>::erase(const Key& k) {
    Node* node = _find(k);
    if (node == nullptr) throw std::out_of_range("Key doesn't exist in table");

    Node* to_delete;
    Node* parent;
    Node* child;

    if (node->left == nullptr || node->right == nullptr)
        to_delete = node;
    else
        to_delete = _find_next(node);


    Node* prev = _find_prev(to_delete);
    if (prev != nullptr)
        prev->next = to_delete->next;
    else
        first = to_delete->next;


    if (to_delete->left != nullptr)
        child = to_delete->left;
    else
        child = to_delete->right;


    parent = to_delete->parent;
    if (child != nullptr)
        child->parent = parent;
    if (parent == nullptr)
        root = child;

    else {
        if (parent->left == to_delete)
            parent->left = child;
        else
            parent->right = child;
    }

    //move
    if (to_delete != node) {
        node->info = to_delete->info;
    }


    size -= 1;
    delete to_delete;
}

template<typename Key, typename Value>
void Binary_tree<Key, Value>::clear() {
    _clear(root);
    root = nullptr;
    size = 0;
}
