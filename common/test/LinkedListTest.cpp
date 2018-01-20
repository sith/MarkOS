//
// Created by Oleksandra Baukh on 1/8/18.
//

#include "LinkedListTest.h"


TEST(LinkedListTest, addElement) {
    LinkedList<int> list;
    int five = 5;
    list.add(&five);
    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(*list.get(0), five);

    int seven = 7;
    list.add(&seven);
    ASSERT_EQ(*list.get(0), five);
    ASSERT_EQ(*list.get(1), seven);
    ASSERT_EQ(list.size(), 2);
}

TEST(LinkedListTest, indexOutOfBounds) {
    LinkedList<int> list;
    int e = 5;
    list.add(&e);

    ASSERT_EQ(list.get(1), nullptr);
}

TEST(LinkedListTest, removeElement) {
    LinkedList<int> list;
    int five = 5;
    list.add(&five);
    ASSERT_EQ(*list.get(0), five);
    list.remove(list.size() - 1);
    ASSERT_EQ(list.size(), 0);
    ASSERT_EQ(list.get(0), nullptr);
}


TEST(LinkedListTest, iterator) {

    LinkedList<int> list;
    int two = 2;
    list.add(&two);
    int four = 4;
    list.add(&four);
    int five = 5;
    list.add(&five);
    int six = 6;
    list.add(&six);

    Iterator<int> &iterator = list.iterator();
    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), two);
    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), four);
    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), five);
    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), six);
    ASSERT_FALSE(iterator.hasNext());


}
