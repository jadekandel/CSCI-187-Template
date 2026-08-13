// This is an EXAMPLE model class showing how to use Qt types (QString) in a
// plain C++ class that has nothing to do with widgets or the GUI. Delete
// this file (and counter.cpp) once you have your own model classes.

#pragma once

#include <QString>

class Counter {
public:
    Counter(QString name, int maximum);

    QString name() const;
    int value() const;
    int maximum() const;

    // Adds amount to the current value, clamped to [0, maximum].
    void add(int amount);

private:
    QString m_name;
    int m_maximum;
    int m_value = 0;
};
