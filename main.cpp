#include <iostream>

class childComponentA;
class childComponentB;

class visitor {
    public:
        virtual void visitChildA(const childComponentA* elem) const = 0;
        virtual void visitChildB(const childComponentB* elem) const = 0;
};

class component {
    public:
        virtual ~component() {}
        virtual void accept(visitor* visitor) const = 0;
};

class childComponentA: public component {
    public:
        void accept(visitor* visitor) const override {
            visitor->visitChildA(this);
        }

        std::string methodA() const {
            return "hey from A";
        }
};

class childComponentB: public component {
    public:
        void accept(visitor* visitor) const override {
            visitor->visitChildB(this);
        }

        std::string methodB() const {
            return "hey from B";
        }
};

class childVisitorA: public visitor {
    public:
        void visitChildA(const childComponentA* elem) const override {
            std::cout << elem->methodA() << " + visitor for A";
        }
        void visitChildB(const childComponentB* elem) const override {
            std::cout << elem->methodB() << " + visitor for B";
        }
};

class childVisitorB: public visitor {
    public:
        void visitChildB(const childComponentB* elem) const override {
            std::cout << elem->methodB() << " + visitor for B";
        }
        void visitChildA(const childComponentA* elem) const override {
            std::cout << elem->methodA() << " + visitor for A";
        }
};

int main() {
    // childComponentA* childA = new childComponentA;
    // childVisitorA* visitorA = new childVisitorA;
    // childA->accept(visitorA);
}