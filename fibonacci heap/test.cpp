#include"fibonacci_heap.cpp"

#include<string>
#include<iostream>

string accepted = "accpeted";
string wrong    = "wrong anwser";
bool anwser     = true;
int total       = 1000;

void print_judge(string text) {
    string res = anwser ? accepted : wrong;
    cout << text << ": " << res << endl;
    anwser = true;
}

void test_constructor() {
    fibonacci_heap<int> f;
    if (!f.empty()) anwser = false;
    if (f.size() != 0) anwser = false;
    print_judge("Constructor");
}

void test_one_insert() {
    fibonacci_heap<int> f;

    f.insert(10,1);

    if (f.empty()) anwser = false;
    if (f.size() != 1) anwser = false;

    fibonacci_heap<int>::FH_handle handle = f.min();
    pair<int, double> data = *handle;

    if (data.first != 10) anwser = false;
    if (data.second != 1.0) anwser = false;
    print_judge("One insert");
}

void test_some_insert() {
    fibonacci_heap<int> f;

    f.insert(10,1);
    f.insert(23,21);
    f.insert(121,11);
    f.insert(2134,4);

    if (f.empty()) anwser = false;
    if (f.size() != 4) anwser = false;

    fibonacci_heap<int>::FH_handle handle = f.min();
    pair<int, double> data = *handle;

    if (data.first != 10) anwser = false;
    if (data.second != 1.0) anwser = false;
    print_judge("Some inserts");
}

void test_extract_min() {
    fibonacci_heap<int> f;
    vector<pair<int, double> > v;

    v.push_back(make_pair(10,1.0));
    v.push_back(make_pair(14, 2.0));
    v.push_back(make_pair(5, 3.0));
    v.push_back(make_pair(15, 4.0));
    v.push_back(make_pair(28, 5.0));

    f.insert(10,1.0);
    f.insert(5,3.0);
    f.insert(28,5.0);
    f.insert(15,4.0);
    f.insert(14,2.0);

    int i = 0;

    while (f.size() > 0) {
        fibonacci_heap<int>::FH_handle handle = f.min();
        pair<int, double> data = *handle;

        if (data.first != v[i].first) anwser = false;
        if (data.second != v[i].second) anwser = false;

        f.extract_min();

        i++;
    }

    print_judge("Extract min");
}

void test_extract_insert() {
    fibonacci_heap<int> f;
    fibonacci_heap<int>::FH_handle handle;
    pair<int, double> data1;
    pair<int, double> data2;

    for(int i = 0; i < 5; i++) {
        f.insert(i,i);
    }

    int size = f.size();
    for (int i = 0; i < size; i++) {
        handle = f.min();
        data1 = *handle;
        f.extract_min();
        handle = f.min();
        data2 = *handle;
        if (data2.second < data1.second) anwser = false;
    }

    for(int i = 5; i < 10; i++) {
        f.insert(i,i);
    }

    size = f.size();
    for (int i = 0; i < size; i++) {
        handle = f.min();
        data1 = *handle;
        f.extract_min();
        handle = f.min();
        data2 = *handle;
        if (data2.second < data1.second) anwser = false;
    }

    print_judge("Extract min insert");
}

int key(int i) {
	return total * ((i * i - 100 * i) % total) + i;
}

void test_stress() {
    bool anwser1 = true; // debugging
    fibonacci_heap<int> f;
    fibonacci_heap<int>::FH_handle handle;

    // Insert
    for (int i = 0; i < total; i++) {
	    if (f.size() != i) anwser = false;
	    f.insert(i,key(i));
    }
    if (f.size() != total) anwser1 = false;

    // Remove number for even i
    for (int i = 0; i < total; i++) {
	    if (i % 2 == 0) {
	    	handle = f.min();
            pair<int, double> data = *handle;
	    	f.extract_min();
            handle = f.min();
            pair<int, double> new_data = *handle;
            if (data.second > new_data.second) anwser1 = false;
	    }
    }
    if (f.size() != total / 2) anwser1 = false;

    // Remove number for odd i
    for (int i = 0; i < total; i++) {
	    if (i % 2 == 1) {
	    	handle = f.min();
            pair<int, double> data = *handle;
	    	f.extract_min();
            handle = f.min();
            pair<int, double> new_data = *handle;
            if (data.second > new_data.second) anwser1 = false;
	    }
    }
    if (f.size() != 0) anwser1 = false;

    anwser = anwser1;
    print_judge("Stress");
}

int main() {
    test_constructor();
    test_one_insert();
    test_some_insert();
    test_extract_min();
    test_extract_insert();
    test_stress();
}