#pragma once

#include <iostream>
#include <fstream>

struct Items {
	char Name[35];
	char myDate[8];
	char Section[10];
	int Count;

	bool operator==(Items const& item);

	friend std::istream& operator>>(std::istream& in, Items& item);
	friend std::ostream& operator<<(std::ostream& out, Items const& item);
};

struct Price {
	char Name[35];
	char myDate[8];
	double pr;

	bool operator==(Price const& price);

	friend std::istream& operator>>(std::istream& in, Price& price);
	friend std::ostream& operator<<(std::ostream& out, Price const& price);
};

struct Med {
	char Name[35];
	char myDate[8];
	char Section[10];
	double pr;
	int Count;

	bool operator==(Med const& med);

	friend std::istream& operator>>(std::istream& in, Med& med);
	friend std::ostream& operator<<(std::ostream& out, Med const& med);
};

class ABS_Med {
public:
	virtual void GetMeds(std::istream&) = 0;
	virtual void WriteMeds(std::ostream&) = 0;
	virtual void SortUp() = 0;
	virtual void PutMeds(std::ostream&) = 0;
	virtual int get_count() = 0;
};

class MB1 :public ABS_Med {
	int count = 0;
	Items *M = nullptr;

	static int comp(const void*, const void*);
public:
	MB1() = default;
	MB1(const MB1&) = delete;
	MB1(MB1&&) = delete;
	virtual ~MB1();

	void GetMeds(std::istream&) override;
	void WriteMeds(std::ostream&) override;
	void PutMeds(std::ostream&) override;
	void SortUp() override;
	
	Items& operator[](int const index);

	int get_count() override;
};

class MB2 :public ABS_Med {
	int count = 0;
	Price* M = nullptr;

	static int comp(const void*, const void*);
public:
	MB2() = default;
	MB2(const MB2&) = delete;
	MB2(MB2&&) = delete;
	virtual ~MB2();

	void GetMeds(std::istream&) override;
	void WriteMeds(std::ostream&) override;
	void PutMeds(std::ostream&) override;
	void SortUp() override;

	Price& operator[](int const index);

	int get_count() override;
};

class MB3 :public ABS_Med {
	int count = 0;
	Med* M = nullptr;

	static int comp(const void*, const void*);
	static int comp_date(const void*, const void*);
public:
	MB3() = default;
	MB3(const MB3&) = delete;
	MB3(MB3&&) = delete;
	virtual ~MB3();

	void GetMeds(std::istream&) override;
	void WriteMeds(std::ostream&) override;
	void PutMeds(std::ostream&) override;
	void SortUp() override;

	Med& operator[](int const index);

	int get_count() override;

	Med* find_date(char *key);

	void append(Med med);
};