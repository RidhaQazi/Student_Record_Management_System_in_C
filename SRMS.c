#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Student {   //Student Details
        int sid;
        char name[30];
        int age;
        char gender;
        char course[50];
        float cgpa;
        char email[40];
        char phone[15];

};

void add_student();     // functions used in student record mangement
void modify_student();
void display_students();
void search_student();
void delete_student();

int duplicate_sid(int sid);
int valid_age(int age);
int valid_gender(char g);
int valid_email(char *email);
int valid_phone(char *phone);



int main() {

        int choice;

        while(1) {
                printf("\nStudent Record Management System Menue \n\n");
                printf("1. Add Student \n");
                printf("2. Modify Student \n");
                printf("3. Display All Students \n");
                printf("4. Search a Student \n");
                printf("5. Delete Student \n");
                printf("6. Exit program \n");
                printf("\nEnter Choice: ");
                scanf("%d", &choice);

                switch(choice) {
                        case 1 :
                                add_student();
                                break;
                        case 2 :
                                modify_student();
                                break;
                        case 3 :
                                display_students();
                                break;
                        case 4 :
                                search_student();
                                break;
                        case 5 :
                                delete_student();
                                break;
                        case 6 :
                                printf("Exiting Program...\n");
                                return(0);
                        default :
                                printf("\n Invalid Choice! Enter Your Choice Again.. \n");
                }
        }

        return 0;
}



//validation functions

int duplicate_sid(int id) {

        struct Student std;

        FILE *fptr = fopen("StudentRecord.dat", "rb");
        if (!fptr) return 0;

        while(fread(&std, sizeof(std), 1, fptr)) {
                if (std.sid == id) {
                        fclose(fptr);
                        return 1;
                }
        }

        fclose(fptr);

        return 0;
}

int valid_age(int age) {
        return age > 3;
}


int valid_gender(char gender) {

        gender = toupper(gender);

        return gender == 'M' || gender == 'F';
}


int valid_email(char *email) {

        char *dot = strrchr(email, '.');
        char *at = strchr(email, '@');

        return (at && dot && at != email && dot > at);
}


int valid_phone(char *phone) {

        int count = 0;

        for (int i = 0; phone[i] != '\0'; i++) {
                if (isdigit(phone[i])) {
                        count ++;
                }
        }

        return count >= 10;
}



//main functions

void add_student(){

        struct Student std;

        FILE *fptr;                                         // making a file pointer
        fptr = fopen("StudentRecord.dat", "ab");            // opening a file 

        if (fptr == NULL) {                                 // checking if file opened without error or not
                printf("File can't open \n");
                return;
        }


        int duplicate;
        do {
                printf("\nEnter Student SID : ");                     // entering data of student
                scanf("%d", &std.sid);  

                duplicate = duplicate_sid(std.sid);
                if (duplicate) {
                        printf ("SID Already Exists! \n");
                } 

        } while (duplicate);   
        getchar();                                     


        printf("Enter Student Name : ");
        fgets(std.name, sizeof(std.name), stdin);
        

        int v_age;
        do {
                printf("Enter Student Age : ");
                scanf("%d", &std.age);

                v_age = valid_age(std.age);
                if(!v_age) {
                        printf("Enter Valid Age \n");
                }

        } while(!v_age);
        getchar();

        
        int v_gender;
        do {
                printf("Enter Student Gender (M/F): ");
                scanf(" %c", &std.gender);
                getchar();

                v_gender = valid_gender(std.gender);
                if(!v_gender) {
                        printf("Invalid Gender! \n");
                }

        }while(!v_gender);


        printf("Enter Student Course : ");
        fgets(std.course, sizeof(std.course), stdin);
        

        printf("Enter Student CGPA : ");
        scanf("%f", &std.cgpa);
        getchar();

        
        int v_email;
        do {
                printf("Enter Student Email : ");
                fgets(std.email, sizeof(std.email), stdin);

                v_email = valid_email(std.email);
                if(!v_email) {
                        printf("Invalid Email! \n");
                }

        } while(!v_email);
        

        int v_phone;
        do {
                printf("Enter Student Phone no.  : ");
                fgets(std.phone, sizeof(std.phone), stdin);

                v_phone = valid_phone(std.phone);
                if(!v_phone) {
                        printf("Phone no. must have atleast 10 digits ! \n");
                }

        } while(!v_phone);
        

        fwrite(&std, sizeof(std), 1 , fptr);                   // writing data to file
        fclose(fptr);                                          // closing file

        printf("\nRecord Successfully Added.... \n\n");

}


void modify_student(){

        struct Student std;

        FILE *fptr;
        fptr = fopen("StudentRecord.dat", "rb+");

        if (fptr == NULL) {                                 
                printf("File can't open \n");
                return;
        }

        int id, found = 0;

        printf("\n Enter Sid of Student to be modified \n");         
        scanf("%d", &id);

        while(fread(&std, sizeof(std), 1, fptr)) {                   //for finding the student
                if (std.sid == id) {
                        fseek(fptr, -sizeof(std), SEEK_CUR);
                        getchar();

                        printf("Enter new details of %d student ", std.sid);     //modifying the details


                        printf("\n Enter Student Name : ");
                        fgets(std.name, sizeof(std.name), stdin);
                        

                        int v_age;
                        do {
                                printf("Enter Student Age : ");
                                scanf("%d", &std.age);

                                v_age = valid_age(std.age);
                                if(!v_age) {
                                        printf("Enter Valid Age \n");
                                }

                        } while(!v_age);
                        getchar();

                        
                        int v_gender;
                        do {
                                printf("Enter Student Gender (M/F): ");
                                scanf(" %c", &std.gender);
                                getchar();

                                v_gender = valid_gender(std.gender);
                                if(!v_gender) {
                                        printf("Invalid Gender! \n");
                                }

                        }while(!v_gender);

                        
                        printf("Enter Student Course : ");
                        fgets(std.course, sizeof(std.course), stdin);
                        

                        printf("Enter Student CGPA : ");
                        scanf("%f", &std.cgpa);
                        getchar();
                        

                        int v_email;
                        do {
                                printf("Enter Student Email : ");
                                fgets(std.email, sizeof(std.email), stdin);

                                v_email = valid_email(std.email);
                                if(!v_email) {
                                        printf("Invalid Email! \n");
                                }

                        } while(!v_email);
                        

                        int v_phone;
                        do {
                                printf("Enter Student Phone no.  : ");
                                fgets(std.phone, sizeof(std.phone), stdin);

                                v_phone = valid_phone(std.phone);
                                if(!v_phone) {
                                        printf("Phone no. must have atleast 10 digits ! \n");
                                }

                        } while(!v_phone);


                        fwrite(&std, sizeof(std), 1 , fptr);                   
                        printf("Record Successfully Modified.... \n");

                        found = 1;
                        break;
                }
        }
        
        if (!found) {
                printf("\nStudent record for sid %d not found! \n", id);
        }

        fclose(fptr);

}


void display_students() {

        struct Student std;

        FILE *fptr;
        fptr = fopen("StudentRecord.dat", "rb");

        if (fptr == NULL) {
                printf("File Empty!! \n ");
                return;
        }

        printf("Student Records : \n");      

        while (fread(&std, sizeof(std), 1 , fptr) > 0 ) {           //displaying all records
                printf("\nStudent SID :       %d \n", std.sid);
                printf("Student Name :      %s", std.name);
                printf("Student Age :       %d \n", std.age);
                printf("Student Gender :    %c \n", std.gender);
                printf("Student Course :    %s", std.course);
                printf("Student CGPA :      %.2f \n", std.cgpa);
                printf("Student Email :     %s", std.email);
                printf("Student Phone no.:  %s \n", std.phone);
                printf("\n---------------------------------------\n");
        }

        fclose(fptr);
}

void search_student() {

        struct Student std;

        FILE *fptr;
        fptr = fopen("StudentRecord.dat", "rb");

        if (fptr == NULL) {                                 
                printf("File can't open \n");
                return;
        }

        int id, found = 0;

        printf("\nEnter Sid of Student to be found \n");
        scanf("%d", &id);

        while(fread(&std, sizeof(std), 1, fptr)) {             //finding student then displaying its records
                if (std.sid == id) {
                        printf("\nRecord of Student with Sid %d : \n", std.sid);
                        printf("Student Name :      %s", std.name);
                        printf("Student Age :       %d \n", std.age);
                        printf("Student Gender :    %c \n", std.gender);
                        printf("Student Course :    %s", std.course);
                        printf("Student CGPA :      %.2f \n", std.cgpa);
                        printf("Student Email :     %s", std.email);
                        printf("Student Phone no.:  %s \n", std.phone);

                        found =1;
                        break;
                }
        }  
        
        if (!found) {
                printf("Student record for sid %d not found! \n", id);
        }

        fclose(fptr);

}

void delete_student(){

        struct Student std;

        FILE *fptr;
        fptr = fopen("StudentRecord.dat", "rb");
        FILE *tptr;
        tptr = fopen("TemporaryFile.dat", "wb");


        if (fptr == NULL || tptr == NULL) {                                 
                printf("File can't open \n");
                return;
        }

        int id, found = 0;

        printf("\nEnter Sid of Student to be Deleted \n");
        scanf("%d", &id);

        while(fread(&std, sizeof(std), 1, fptr)) {             //finding student

                if (std.sid == id) {                           //skip student record if found and not copy it to another file
                        found = 1;
                        continue;
                }

                fwrite(&std, sizeof(std), 1, tptr);             //copy all records to temporary file
                
        }

        fclose(fptr);
        fclose(tptr);

        remove("StudentRecord.dat");                               //delete old file
        rename("TemporaryFile.dat", "StudentRecord.dat");          //rename new file

        if (!found) {
                printf("\nStudent record for sid %d not found! \n", id);
        }

        else {
                printf("\nStudent record for sid %d successfully deleted! \n", id);
        }
}