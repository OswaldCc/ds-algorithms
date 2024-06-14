class DynamicArray {
private:
    int* data;
    size_t current_size;
    size_t current_capacity;

    void resize(size_t new_capacity) {
        int* new_data = new int[new_capacity];
        for (size_t i = 0; i < current_size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        current_capacity = new_capacity;
    }

public:
    DynamicArray(size_t initial_capacity = 4)
        : data(new int[initial_capacity]), current_size(0), current_capacity(initial_capacity) {}

    ~DynamicArray() {
        delete[] data;
    }

    size_t size() const {
        return current_size;
    }

    size_t capacity() const {
        return current_capacity;
    }

    void push_back(int value) {
        if (current_size == current_capacity) {
            resize(current_capacity * 2);
        }
        data[current_size++] = value;
    }

    void pop_back() {
        if (current_size == 0) {
            throw std::out_of_range("Array is empty");
        }
        --current_size;
    }

    int& operator[](size_t index) {
        if (index >= current_size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const int& operator[](size_t index) const {
        if (index >= current_size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

int main() {
    DynamicArray arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    std::cout << "Array elements: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.pop_back();

    std::cout << "Array elements after pop_back: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array size: " << arr.size() << std::endl;
    std::cout << "Array capacity: " << arr.capacity() << std::endl;

    return 0;
}