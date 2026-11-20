#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template <typename... Ts>
ostream &operator<<(ostream &os, const tuple<Ts...> &t) {
    os << '(';
    apply([&](const auto &...args) {
        size_t i = 0;
        ((os << (i++ ? ", " : "") << args), ...);
    }, t);
    return os << ')';
}

template <typename T, typename = enable_if_t<!is_same_v<T, string>>,
          typename = decltype(begin(declval<T>()))>
ostream &operator<<(ostream &os, const T &v) {
    os << '{';
    bool first = true;
    for (const auto &x : v) {
        if (!first) os << ", ";
        first = false;
        os << x;
    }
    return os << '}';
}

inline void dbg_out() { cerr << "\033[0m\n"; }

template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    if (sizeof...(T)) cerr << " |";
    dbg_out(T...);
}

#define dbg(...)                                                               \
    cerr << "\033[1;31m[DBG]\033[0m \033[34m" << __func__ << ":" << __LINE__  \
         << "\033[0m [" << #__VA_ARGS__ << "] =\033[33m",                       \
        dbg_out(__VA_ARGS__)
