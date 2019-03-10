#include <iostream>

class number_sequence final
{
	int *arr_;
	int count_;
	int size_;

public:
	explicit number_sequence(const int size) : size_(size) {
		this->size_ = size;
		arr_ = new int[size];
		count_ = 0;
	}

	virtual ~number_sequence() {
		delete[] arr_;
	}

	number_sequence(number_sequence const& source) {
		size_ = source.size_;
		count_ = source.count_;
		arr_ = new int[size_];
		for (auto i = 0; i < count_; i++)
			arr_[i] = source.arr_[i];

	}

	number_sequence(number_sequence&& source) noexcept
	{
		size_ = source.size_;
		count_ = source.count_;
		arr_ = source.arr_;
		source.arr_ = nullptr;
	}

	void append(int value) {
		if (count_ + 1 > size_)
			throw std::exception("You have entered an extra element");
		arr_[count_] = value;
		count_++;
	}

	double mean() const
	{
		auto sum = 0;
		for (auto i = 0; i < count_; i++)
			sum += arr_[i];
		const auto ave = (double)sum / count_;
		return ave;
	}

	int min() const
	{
		auto min = arr_[0];
		for (auto i = 1; i < count_; i++) {
			if (arr_[i] < min)
				min = arr_[i];
		}
		return min;
	}

	int max() const
	{
		auto max = arr_[0];
		for (auto i = 1; i < count_; i++) {
			if (arr_[i] > max)
				max = arr_[i];
		}
		return max;
	}

	int sum() const
	{
		auto sum = 0;
		for (auto i = 0; i < count_; i++)
			sum += arr_[i];
		return sum;
	}

	friend std::istream& operator>>(std::istream& in, number_sequence& r);
	friend std::ostream& operator<<(std::ostream& out, const number_sequence& r);
};

int main()
{
	auto l = 0;

	std::cout << "What size of array do you want? ";
	std::cin >> l;
	number_sequence seq(l);

	std::cin >> seq;
	std::cout << seq;

	std::cout << std::endl <<  "Average = " << seq.mean() << std::endl;
	std::cout << "Min = " << seq.min() << std::endl;
	std::cout << "Max = " << seq.max() << std::endl;
	std::cout << "Sum = " << seq.sum() << std::endl << std::endl;;

	system("pause");
	return 0;
}

std::ostream& operator<<(std::ostream& out, const number_sequence& r)
{
	out << "Sequence: ";
	for (auto i = 0; i < r.count_; i++)
	{
		out << r.arr_[i] << " ";
	}

	return out;
}

std::istream& operator>>(std::istream& in, number_sequence& r)
{
	char token[32], *ptr;

	for (auto i = 0;; i++)
	{
		std::cout << "Enter the " << i + 1 << " element(if you want to stop, enter 's'): ";
		in >> token;
		if (strcmp(token, "s") == NULL) 
		{
			break;
		}
		try
		{
			r.append(strtol(token, &ptr, 10));
		}
		catch (const std::exception &ex)
		{
			std::cout << "You have an error: " << ex.what() << std::endl;
			break;
		}
	}

	return in;
}