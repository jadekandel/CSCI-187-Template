#include "counter.h"

#include <algorithm>

Counter::Counter(QString name, int maximum)
    : m_name(std::move(name)), m_maximum(maximum) {}

QString Counter::name() const { return m_name; }

int Counter::value() const { return m_value; }

int Counter::maximum() const { return m_maximum; }

void Counter::add(int amount) {
    m_value = std::clamp(m_value + amount, 0, m_maximum);
}
