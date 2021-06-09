#ifndef _VECTOR_H_
#define _VECTOR_H_
template<typename T>class Vector
{
    public:
        Vector();
        void push_back(T source);                        //push_back
        void push_front(T source);                       //push_front
        T& operator[](int index);                        //operator[]
        void pop_back();                                 // pop_back
        Vector<T>& operator=(const Vector<T>& other);       //operator =
        int length();                                      //size
        void erase(int index);                                   // erase
        Vector(const Vector& rhs);                         // copy ctor
        ~Vector();                                       //destructor
    private:
        T* arr;
        int capacity;
        int size;

};



template<typename T>
Vector<T>::Vector(){                  //dif. ctor
    capacity = 1;
    size = 0;
    arr = new T[capacity];
}
template<typename T>  
void Vector<T>::push_back(T value){    //push_back
    if(size==capacity){ 
        capacity *= 2;
        T* tmp = new T[capacity];
        for(int i = 0; i < size; ++i){
            tmp[i] = arr[i];
        }


        delete[] arr;
        arr = tmp;
    }
    arr[size++] = value;
    
}
template<typename T>
void Vector<T>::push_front(T value){    //push_front
    if(size == capacity){
        capacity*=2;
    }
    T* tmp = new T[capacity];
    tmp[0] = value;
    for(int i = 0; i < size; ++i){
        tmp[i + 1] = arr[i];
    }
    delete[]arr;
    arr = tmp;
    ++size;

}

template<typename T>
T& Vector<T>::operator[](int index){     //operator[]
    return arr[index];
}

template<typename T>
void Vector<T>::pop_back(){              // pop_back
    --size;
}
template<typename T>
int Vector<T>::length(){                      //size
    return size;
}

template<typename T>                   
Vector<T>& Vector<T>::operator=(const Vector<T>& other){  //operator =
    if(this == &other){
        return * this;
    }
    delete[] arr;
    capacity = other.capacity;
    size = other.size;
    arr = new T[capacity];
    for(int i = 0; i < size; ++i){
        arr[i] = other.arr[i];
    }
    return *this;
}
template<typename T>
Vector<T>::Vector(const Vector<T>& rhs){                 //copy ctor
    delete[] arr;
    capacity = rhs.capacity;
    size = rhs.size;
    arr = new T[capacity];
    for(int i = 0; i < size; ++i){
        arr[i] = rhs.arr[i];
    }
}
template<typename T>
Vector<T>::~Vector(){
    delete[]arr;
    arr = nullptr;
}
template <typename T>
void Vector<T>::erase(int index){
    if(index < 0 || index >= size){ 
        exit();
    }
    else{
        for(int i = index; i < size - 1 ; ++i){
            arr[i] = arr[i + 1];
            --size;
        }

    }

}

#endif






