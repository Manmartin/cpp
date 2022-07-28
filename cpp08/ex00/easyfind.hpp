#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template < typename T >
typename T::iterator    easyfind( T &cont, int x ) {
    return find(cont.begin(), cont.end(), x);
}

#endif
