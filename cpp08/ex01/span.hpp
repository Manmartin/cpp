#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <climits>
# include <iostream>


class Span {
	private:
		unsigned int		_n;
		std::vector<int>	_v;

	public:
		Span( void );
		Span( Span const &ref );
		Span( unsigned int const n );
		~Span( void );

		Span	&operator=( Span const &ref );

		void	addNumber( unsigned int const x );
		void	betterAddNumber( unsigned int const init, unsigned int const n, unsigned int const m);
		template < typename Iterator >
			void	betterAddNumber( Iterator begin, Iterator end) {
				for (Iterator it = begin; it != end; it++)
					addNumber(*it);
			}

		int		shortestSpan( void );
		int		longestSpan( void );
		class	TooMuchNumbersException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class	NotEnoughNumbers: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
