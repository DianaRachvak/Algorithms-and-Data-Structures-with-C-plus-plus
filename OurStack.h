//implementing our own stack class usinga vector
#ifndef ourStack_h
#define ourStack_h

#incude <vector>

using namespace std;

template<class> elemType;
class OurStack{
    vector<ElemType> data;

    public:
        void push(const ElemType& value)
        {
           data.push_back(value);
        }

        ElemType& top()
        {
            if (empty())
                throw string ("Error. Empty stack.");
            return data.back();
        }

        void pop()
        {
            if(empty())
                throw string ("Erroe. Empty stack");
            data.pop_back();
        }

        int size() { return data.empty(); }

        bool empty() { return data.empty(); }

};
#endif
