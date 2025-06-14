typedef unsigned long int size_;

#define STR struct str

typedef struct str {
  union {
    char *c_str;
    char *data;
  };
  size_ alloced;
  size_ is_free;
  
  /* ASSIGN */
  STR   (*assign_line)   (struct str *, const char *);
  STR   (*assign_char)   (struct str *, size_, int);
  STR   (*assign_substr) (struct str *, const char *, size_, size_);

  /* STRING */
  STR   (*emstr)         (struct str *restrict);
  STR   (*newstr)        (struct str *restrict, const char *restrict);
  STR   (*strchs)        (struct str *self, size_, int); /* LIKE string(size_t, char) FROM C++ */
  STR   (*newnstr)       (struct str *, const char *, size_);

  /* INSERT */
  STR   (*insert)        (struct str *, const char *, size_);
  STR   (*insertn)       (struct str *, const char *, size_, size_);
  STR   (*insert_char)   (struct str *, const char, size_);

  /* ERASE */
  STR   (*erase_sub)     (struct str *, size_ st, size_ end);
  STR   (*erase_s)       (struct str *, const char *);
  STR   (*erase_ch)      (struct str *, int, size_);
  STR   (*pop_back)      (struct str *restrict);

  /* APPEND */
  STR   (*append)        (struct str *restrict, const char *restrict);

  /* REPLACE */
  STR   (*replace)       (struct str *, size_, size_, const char *);
  STR   (*replace_py)    (struct str *, const char *, const char *, size_);

  /* OTHER */
  size_ (*len)           (struct str *restrict);
  STR   (*push_back)     (struct str *, int ch);
  char *(*back)          (struct str *restrict);
  char *(*front)         (struct str *restrict);
  int   (*empty)         (struct str *restrict);
  size_ (*size)          (struct str *restrict);
  size_ (*count_ch)      (struct str *, int);
  size_ (*count)         (struct str *, const char *);
  char  (*find_first_of) (struct str *, const char *, size_);
  char  (*find_last_of)  (struct str *, const char *, size_);
  STR   (*substr)        (struct str *restrict, size_, size_);
  STR   (*find)          (struct str *, const char *, size_, size_);

  /* FREE */
  size_  (*free_str)     (struct str *restrict);
} str;



/* TODO
  ELEMENT ACCESS
char& at(size_t pos);
const char& at(size_t pos) const;
const char* data() const noexcept;

  CAPACITY
void reserve(size_t n = 0);
size_t capacity() const noexcept;
void shrink_to_fit();

  MODIFIERS
string& append(const string& str, size_t subpos, size_t sublen);
string& append(const char* s, size_t n);
string& append(size_t n, char c);
template <class InputIterator> string& append(InputIterator first, InputIterator last);
template <class InputIterator> void insert(iterator p, InputIterator first, InputIterator last);
string& replace(size_t pos, size_t len, const string& str);
string& replace(iterator i1, iterator i2, const string& str);
string& replace(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen);
string& replace(size_t pos, size_t len, const char* s);
string& replace(iterator i1, iterator i2, const char* s);
string& replace(size_t pos, size_t len, const char* s, size_t n);
string& replace(iterator i1, iterator i2, const char* s, size_t n);
string& replace(size_t pos, size_t len, size_t n, char c);
string& replace(iterator i1, iterator i2, size_t n, char c);
template <class InputIterator> string& replace(iterator i1, iterator i2, InputIterator first, InputIterator last);
void pop_back();

  STRING OPERATIONS
const char* data() const noexcept;
size_t copy(char* s, size_t len, size_t pos = 0) const;
size_t find(const string& str, size_t pos = 0) const noexcept;
size_t find(const char* s, size_t pos = 0) const;
size_t find(const char* s, size_t pos, size_t n) const;
size_t find(char c, size_t pos = 0) const noexcept;
size_t rfind(const string& str, size_t pos = npos) const noexcept;
size_t rfind(const char* s, size_t pos = npos) const;
size_t rfind(const char* s, size_t pos, size_t n) const;
size_t rfind(char c, size_t pos = npos) const noexcept;
size_t find_first_of(char c, size_t pos = 0) const noexcept;
size_t find_last_of(const string& str, size_t pos = npos) const noexcept;
size_t find_last_of(const char* s, size_t pos, size_t n) const;
size_t find_last_of(char c, size_t pos = npos) const noexcept;
size_t find_first_not_of(const string& str, size_t pos = 0) const noexcept;
size_t find_first_not_of(const char* s, size_t pos = 0) const;
size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
size_t find_first_not_of(char c, size_t pos = 0) const noexcept;
size_t find_last_not_of(const string& str, size_t pos = npos) const noexcept;
size_t find_last_not_of(const char* s, size_t pos = npos) const;
size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
size_t find_last_not_of(char c, size_t pos = npos) const noexcept;
int compare(size_t pos, size_t len, const string& str) const;
int compare(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen) const;
int compare(const char* s) const;
int compare(size_t pos, size_t len, const char* s) const;
int compare(size_t pos, size_t len, const char* s, size_t n) const;

NUMERIC CONVERSIONS (C++11 AND LATER)
int stoi(const string& str, size_t* idx = 0, int base = 10);
long stol(const string& str, size_t* idx = 0, int base = 10);
unsigned long stoul(const string& str, size_t* idx = 0, int base = 10);
long long stoll(const string& str, size_t* idx = 0, int base = 10);
unsigned long long stoull(const string& str, size_t* idx = 0, int base = 10);
float stof(const string& str, size_t* idx = 0);
double stod(const string& str, size_t* idx = 0);
long double stold(const string& str, size_t* idx = 0);

# MAIN FUNCTION GOTTED
string to_string(float val);
string to_string(double val);
string to_string(long double val);
*/
