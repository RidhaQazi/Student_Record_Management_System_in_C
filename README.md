# Student_Record_Management_System_in_C

COMPANY: SNESTRON SYSTEMS PRIVATE LIMITED

NAME: RIDHA QAZI

INTERN ID: ST4WFE100

DOMAIN: C PROGRAMMING

DURATION: 4 WEEKS


The Student Record Management System is a console-based application developed in the C programming language. It is designed to help manage and organize student data efficiently through various operations such as adding, modifying, displaying, searching, and deleting student records. This project served as an opportunity to apply core concepts of C such as structures, file handling, loops, conditionals, and function modularity. The program was developed using Visual Studio Code as the editor and compiled using the GCC compiler on a Windows operating system.

The system is built around a Student structure that stores information such as the student ID (SID), name, age, gender, course, CGPA, email, and phone number. The program maintains all student records in a binary file named StudentRecord.dat, ensuring data persistence across sessions. The user is presented with a menu that allows them to perform the desired operation. Each operation is encapsulated in its own function for clarity and maintainability. The “Add Student” functionality includes comprehensive input validation to ensure that all entered data is valid and unique. The system checks whether the SID is already in use, whether the entered age is valid, and whether the gender is correctly specified as 'M' or 'F'. Email addresses are validated to ensure they contain both '@' and '.' characters in appropriate positions. Phone numbers are accepted only if they contain at least 10 digits.

While modifying records, the program allows the user to update all fields except the SID, and it ensures the same validation checks are applied. Similarly, the delete operation safely removes a record by copying all non-matching records to a temporary file and renaming it, ensuring the deleted data is effectively removed without corrupting the rest of the data. Display and search functions help in viewing all or specific student records, making the system useful for both administrators and users.

Throughout the project, I tested the application with various valid and invalid inputs to confirm the robustness of the validation logic. One of the key highlights of this program is its resilience; instead of terminating on incorrect input, it prompts the user to re-enter the data until it meets the specified validation rules. This user-friendly approach improves the reliability and usability of the program.

Developing this project enhanced my practical understanding of file operations in C, the use of structures for complex data handling, and writing clean, modular code with effective input validation. It also introduced me to real-world programming challenges such as ensuring data consistency, avoiding duplication, and building an interactive and error-tolerant interface. This foundational experience in C programming has prepared me for more advanced topics in software development, including databases, memory management, and data structures.


##Output

![Image](https://github.com/user-attachments/assets/c1bfc58b-7f54-4a39-94ef-3b1a35f13fc7)

![Image](https://github.com/user-attachments/assets/d140c694-0b19-47e7-a199-302b65586a6f)

![Image](https://github.com/user-attachments/assets/3581b28b-9563-4486-ad69-720708d3916d)
