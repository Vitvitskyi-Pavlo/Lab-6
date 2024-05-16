// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №6. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>
#include <string>
using namespace std;


// Task 1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Базовий клас з віртуальним успадкуванням
class BaseVirtual {
public:
    int a;
    virtual void foo() {}
};

// Базовий клас без віртуального успадкування
class BaseNonVirtual {
public:
    int b;
};

// Клас, який успадковує BaseVirtual
class DerivedVirtual : public BaseVirtual {
public:
    int c;
};

// Клас, який успадковує BaseNonVirtual
class DerivedNonVirtual : public BaseNonVirtual {
public:
    int d;
};

void Task1() {
    BaseVirtual baseVirtual;
    DerivedVirtual derivedVirtual;
    BaseNonVirtual baseNonVirtual;
    DerivedNonVirtual derivedNonVirtual;

    cout << "Size of BaseVirtual object: " << sizeof(baseVirtual) << endl;
    cout << "Size of DerivedVirtual object: " << sizeof(derivedVirtual) << endl;
    cout << "Size of BaseNonVirtual object: " << sizeof(baseNonVirtual) << endl;
    cout << "Size of DerivedNonVirtual object: " << sizeof(derivedNonVirtual) << endl;
}




// Task 2 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// Абстрактний базовий клас чотирикутник
class Quadrilateral {
public:
    // Віртуальна функція для обчислення площі
    virtual double calculateArea() const = 0;

    // Віртуальна функція для обчислення периметру
    virtual double calculatePerimeter() const = 0;
};

// Клас квадрат
class Square : public Quadrilateral {
private:
    double side; // Сторона квадрата

public:
    // Конструктор
    Square(double s) : side(s) {}

    // Реалізація віртуальної функції для обчислення площі
    double calculateArea() const override {
        return side * side;
    }

    // Реалізація віртуальної функції для обчислення периметру
    double calculatePerimeter() const override {
        return 4 * side;
    }
};

// Клас прямокутник
class Rectangle : public Quadrilateral {
private:
    double length; // Довжина прямокутника
    double width;  // Ширина прямокутника

public:
    // Конструктор
    Rectangle(double l, double w) : length(l), width(w) {}

    // Реалізація віртуальної функції для обчислення площі
    double calculateArea() const override {
        return length * width;
    }

    // Реалізація віртуальної функції для обчислення периметру
    double calculatePerimeter() const override {
        return 2 * (length + width);
    }
};

// Клас паралелограм
class Parallelogram : public Quadrilateral {
private:
    double base;    // Основа паралелограма
    double height;  // Висота паралелограма
    double side;    // Сторона паралелограма

public:
    // Конструктор
    Parallelogram(double b, double h, double s) : base(b), height(h), side(s) {}

    // Реалізація віртуальної функції для обчислення площі
    double calculateArea() const override {
        return base * height;
    }

    // Реалізація віртуальної функції для обчислення периметру
    double calculatePerimeter() const override {
        return 2 * (base + side);
    }
};

// Клас трапеція
class Trapezoid : public Quadrilateral {
private:
    double base1;   // Перша основа трапеції
    double base2;   // Друга основа трапеції
    double height;  // Висота трапеції
    double side1;   // Перша бічна сторона трапеції
    double side2;   // Друга бічна сторона трапеції

public:
    // Конструктор
    Trapezoid(double b1, double b2, double h, double s1, double s2) : base1(b1), base2(b2), height(h), side1(s1), side2(s2) {}

    // Реалізація віртуальної функції для обчислення площі
    double calculateArea() const override {
        return (base1 + base2) * height / 2;
    }

    // Реалізація віртуальної функції для обчислення периметру
    double calculatePerimeter() const override {
        return base1 + base2 + side1 + side2;
    }
};

void Task2() {
    // Створення об'єктів
    Square square(5);
    Rectangle rectangle(4, 6);
    Parallelogram parallelogram(3, 4, 5); // Паралелограм з основою 3, висотою 4 і стороною 5
    Trapezoid trapezoid(4, 6, 5, 3, 3);  // Трапеція з основами 4 і 6, висотою 5, і бічними сторонами 3 і 3

    // Виведення площі та периметру квадрата
    cout << "Квадрат:" << endl;
    cout << "Площа: " << square.calculateArea() << endl;
    cout << "Периметр: " << square.calculatePerimeter() << endl;

    // Виведення площі та периметру прямокутника
    cout << "\nПрямокутник:" << endl;
    cout << "Площа: " << rectangle.calculateArea() << endl;
    cout << "Периметр: " << rectangle.calculatePerimeter() << endl;

    // Виведення площі та периметру паралелограма
    cout << "\nПаралелограм:" << endl;
    cout << "Площа: " << parallelogram.calculateArea() << endl;
    cout << "Периметр: " << parallelogram.calculatePerimeter() << endl;

    // Виведення площі та периметру трапеції
    cout << "\nТрапеція:" << endl;
    cout << "Площа: " << trapezoid.calculateArea() << endl;
    cout << "Периметр: " << trapezoid.calculatePerimeter() << endl;
}


// Task 3 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Батьківський клас "Людина"
class Person {
protected:
    string name;

public:
    Person(const string& n) : name(n) {}

    virtual ~Person() {}

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
    }
};

// Клас "Батько", що успадковується від "Людини"
class Father : public Person {
protected:
    int age;

public:
    Father(const string& n, int a) : Person(n), age(a) {}

    virtual ~Father() {}

    virtual void displayInfo() const override {
        cout << "I'мя: " << name << ", Вiк: " << age << endl;
    }
};

// Клас "Мати", що успадковується від "Людини"
class Mother : public Person {
protected:
    string occupation;

public:
    Mother(const string& n, const string& occ) : Person(n), occupation(occ) {}

    virtual ~Mother() {}

    virtual void displayInfo() const override {
        cout << "I'мя: " << name << ", Рiд занять: " << occupation << endl;
    }
};

// Клас "Дочка", що успадковується від "Батька" та "Матері"
class Daughter : public Father, public Mother {
public:
    Daughter(const string& n, int a, const string& occ) : Father(n, a), Mother(n, occ) {}

    // Переозначення функції displayInfo
    void displayInfo() const override {
        cout << "І'мя: " << Father::name << ", Вiк: " << Father::age << ", Рiд занять: " << Mother::occupation << endl;
    }
};

void Task3() {
    Father father("Василь", 38);
    Mother mother("Марія", "Пекар");
    Daughter daughter("Марта", 15, "Школяр");

    cout << "Тато: " << endl;
    father.displayInfo();

    cout << "\nМама: " << endl;
    mother.displayInfo();

    cout << "\nДочка: " << endl;
    daughter.displayInfo();
}

int main() {
    int TaskN;
    setlocale(LC_CTYPE, "ukr");

    do {
        cout << "\n\nВведiть свiй вибiр: ";
        cin >> TaskN;

        switch (TaskN) {
        case 1:
             Task1();
            break;
        case 2:
             Task2();
            break;
        case 3:
            Task3();
            break;
        case 0:
            cout << "Вихiд з програми\n";
            break;
        default:
            cout << "Невiрний вибiр! Будь ласка, введiть число вiд 0 до 3.\n";
        }
    } while (TaskN != 0);

    return 0;
}
