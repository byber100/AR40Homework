// GameMap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using KeyType = int;
using DataType = int;

struct GamePair
{
    KeyType first;
    DataType second;
};

GamePair make_gamePair(const KeyType& _Key, const DataType& _Data)
{
    return GamePair{ _Key,_Data };
}

class GameMap
{
private:
    class MapNode
    {
    public:
        GamePair Pair_;

        MapNode* Parent_;
        MapNode* LeftChild_;
        MapNode* RightChild_;

    public:
        void FirstOrder()
        {
            std::cout << Pair_.first << std::endl;
            if (nullptr != LeftChild_)
            {
                LeftChild_->FirstOrder();
            }
            if (nullptr != RightChild_)
            {
                RightChild_->FirstOrder();
            }
        }

        void MidOrder()
        {
            if (nullptr != LeftChild_)
            {
                LeftChild_->MidOrder();
            }
            std::cout << Pair_.first << std::endl;
            if (nullptr != RightChild_)
            {
                RightChild_->MidOrder();
            }
        }

        void LastOrder()
        {
            if (nullptr != LeftChild_)
            {
                LeftChild_->LastOrder();
            }
            if (nullptr != RightChild_)
            {
                RightChild_->LastOrder();
            }
            std::cout << Pair_.first << std::endl;
        }

    public:
        MapNode()
            :Parent_(nullptr)
            ,LeftChild_(nullptr)
            ,RightChild_(nullptr)
        {}

        ~MapNode()
        {
            
        }
    public:
        bool Insert(const GamePair& _Pair)
        {
            GamePair ThisPair = Pair_;

            if (Pair_.first > _Pair.first)
            {
                if (nullptr == LeftChild_)
                {
                    LeftChild_ = new MapNode();
                    LeftChild_->Pair_ = _Pair;
                    LeftChild_->Parent_ = this;
                    return true;
                }

                return LeftChild_->Insert(_Pair);
            }

            else if (Pair_.first < _Pair.first)
            {
                if (nullptr == RightChild_)
                {
                    RightChild_ = new MapNode();
                    RightChild_->Pair_ = _Pair;
                    RightChild_->Parent_ = this;
                    return true;
                }

                return RightChild_->Insert(_Pair);
            }

            return false;
        }

    };

public:
    MapNode* RootNode_;

    bool insert(const GamePair& _Pair)
    {
        if (nullptr == RootNode_)
        {
            RootNode_ = new MapNode();
            RootNode_->Pair_ = _Pair;
            return true;
        }

        return RootNode_->Insert(_Pair);
    }

    void FirstOrder() {
        RootNode_->FirstOrder();
    }

    void MidOrder() {
        RootNode_->MidOrder();
    }

    void LastOrder() {
        RootNode_->LastOrder();
    }

    GameMap()
        :RootNode_(nullptr)
    {}

    ~GameMap()
    {
        if (nullptr != RootNode_)
        {
            delete RootNode_;
            RootNode_ = nullptr;
        }
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        GameMap GMap;

        GMap.insert(make_gamePair(10, 10));
        GMap.insert(make_gamePair(10, 1));
        GMap.insert(make_gamePair(10, 2));
        GMap.insert(make_gamePair(5, 1));
        GMap.insert(make_gamePair(7, 1));
        GMap.insert(make_gamePair(1, 1));
        GMap.insert(make_gamePair(20, 1));
        GMap.insert(make_gamePair(25, 1));
        GMap.insert(make_gamePair(17, 1));

        std::cout << "전위 순회" << std::endl;
        GMap.FirstOrder();
        std::cout << std::endl;
        std::cout << "중위 순회" << std::endl;
        GMap.MidOrder();
        std::cout << std::endl;
        std::cout << "후위 순회" << std::endl;
        GMap.LastOrder();
        std::cout << std::endl;
    }
}