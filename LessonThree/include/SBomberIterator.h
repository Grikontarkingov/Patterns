#pragma once

#include <vector>
#include <memory>
#include "Bomb.h"

template<typename T, typename U>
class ISBomberIterator {
public:
    ~ISBomberIterator() = default;
    virtual U* Get() const = 0;
    virtual void Next() = 0;
    virtual bool isDone() const = 0;
};

template<typename T, typename U>
class SBomberIterator : public ISBomberIterator<T, U>{
public:
    typedef typename std::vector<T*>::iterator iter_type;

    SBomberIterator(std::vector<T*>& data) : pData(data) {
        m_it = pData.begin();

        FindObj();
    }

    U* Get() const override {
        return pObj;
    }
    void Next() override {
        ++m_it;

        FindObj();
    }
    bool isDone() const override {
        return m_it >= pData.end();
    }

private:
    void FindObj() {
        while(!(isDone())){
            pObj = dynamic_cast<U*>(*m_it);
            if(pObj != nullptr){
                break;
            }
            else{
                ++m_it;
            }
        }
    }

    std::vector<T*>& pData;
    iter_type m_it;

    U* pObj;
};
