#define NAME_CHAR_LIMIT 50

// Student structure
struct student_t {
    int album;
    char name[NAME_CHAR_LIMIT];
    int course_id;
    int grade;
};

// Function prototypes
void list_students(struct student_t *students, int count);
void add_student(struct student_t **students, int *count);
void delete_student(struct student_t *students, int *count);
void change_student(struct student_t *students, int count);