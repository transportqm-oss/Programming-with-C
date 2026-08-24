#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_BOOKS 1000
#define MAX_LOANS 3000
#define TITLE_LEN 120
#define AUTHOR_LEN 100
#define CATEGORY_LEN 60
#define NAME_LEN 100
#define DATE_LEN 11

#define BOOK_FILE "books.dat"
#define LOAN_FILE "loans.dat"

typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    char category[CATEGORY_LEN];
    int year;
    int quantity;
    int available;
    int borrowCount;
} Book;

typedef struct {
    int id;
    int bookId;
    char borrower[NAME_LEN];
    char borrowDate[DATE_LEN];
    char returnDate[DATE_LEN];
    int returned; /* 0 = borrowing, 1 = returned */
} Loan;

Book books[MAX_BOOKS];
Loan loans[MAX_LOANS];

int bookCount = 0;
int loanCount = 0;

/* =========================
   Utility functions
   ========================= */

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void readLine(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);

        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        } else {
            clearInputBuffer();
        }
    }
}

int readInt(const char *prompt) {
    char line[100];
    char *end;
    long value;

    while (1) {
        readLine(prompt, line, sizeof(line));

        value = strtol(line, &end, 10);

        while (isspace((unsigned char)*end)) {
            end++;
        }

        if (line[0] != '\0' && *end == '\0') {
            return (int)value;
        }

        printf("Invalid number. Please try again.\n");
    }
}

int readPositiveInt(const char *prompt) {
    int value;

    do {
        value = readInt(prompt);

        if (value < 0) {
            printf("Value must be >= 0.\n");
        }
    } while (value < 0);

    return value;
}

void pauseScreen(void) {
    char temp[4];
    printf("\nPress Enter to continue...");
    fgets(temp, sizeof(temp), stdin);
}

void getCurrentDate(char date[DATE_LEN]) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    if (t != NULL) {
        strftime(date, DATE_LEN, "%Y-%m-%d", t);
    } else {
        strcpy(date, "0000-00-00");
    }
}

int equalsIgnoreCaseChar(char a, char b) {
    return tolower((unsigned char)a) == tolower((unsigned char)b);
}

int containsIgnoreCase(const char *text, const char *keyword) {
    size_t textLen = strlen(text);
    size_t keyLen = strlen(keyword);
    size_t i, j;

    if (keyLen == 0) {
        return 1;
    }

    if (keyLen > textLen) {
        return 0;
    }

    for (i = 0; i <= textLen - keyLen; i++) {
        for (j = 0; j < keyLen; j++) {
            if (!equalsIgnoreCaseChar(text[i + j], keyword[j])) {
                break;
            }
        }

        if (j == keyLen) {
            return 1;
        }
    }

    return 0;
}

/* =========================
   File persistence
   ========================= */

void saveBooks(void) {
    FILE *file = fopen(BOOK_FILE, "wb");

    if (file == NULL) {
        printf("Warning: Could not save books.\n");
        return;
    }

    fwrite(&bookCount, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), bookCount, file);

    fclose(file);
}

void saveLoans(void) {
    FILE *file = fopen(LOAN_FILE, "wb");

    if (file == NULL) {
        printf("Warning: Could not save loans.\n");
        return;
    }

    fwrite(&loanCount, sizeof(int), 1, file);
    fwrite(loans, sizeof(Loan), loanCount, file);

    fclose(file);
}

void saveAll(void) {
    saveBooks();
    saveLoans();
}

void loadBooks(void) {
    FILE *file = fopen(BOOK_FILE, "rb");

    if (file == NULL) {
        bookCount = 0;
        return;
    }

    if (fread(&bookCount, sizeof(int), 1, file) != 1) {
        bookCount = 0;
        fclose(file);
        return;
    }

    if (bookCount < 0 || bookCount > MAX_BOOKS) {
        bookCount = 0;
        fclose(file);
        return;
    }

    fread(books, sizeof(Book), bookCount, file);
    fclose(file);
}

void loadLoans(void) {
    FILE *file = fopen(LOAN_FILE, "rb");

    if (file == NULL) {
        loanCount = 0;
        return;
    }

    if (fread(&loanCount, sizeof(int), 1, file) != 1) {
        loanCount = 0;
        fclose(file);
        return;
    }

    if (loanCount < 0 || loanCount > MAX_LOANS) {
        loanCount = 0;
        fclose(file);
        return;
    }

    fread(loans, sizeof(Loan), loanCount, file);
    fclose(file);
}

/* =========================
   Book helpers
   ========================= */

int findBookIndexById(int id) {
    int i;

    for (i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            return i;
        }
    }

    return -1;
}

int getNextBookId(void) {
    int maxId = 0;
    int i;

    for (i = 0; i < bookCount; i++) {
        if (books[i].id > maxId) {
            maxId = books[i].id;
        }
    }

    return maxId + 1;
}

int getNextLoanId(void) {
    int maxId = 0;
    int i;

    for (i = 0; i < loanCount; i++) {
        if (loans[i].id > maxId) {
            maxId = loans[i].id;
        }
    }

    return maxId + 1;
}

int hasActiveLoanForBook(int bookId) {
    int i;

    for (i = 0; i < loanCount; i++) {
        if (loans[i].bookId == bookId && loans[i].returned == 0) {
            return 1;
        }
    }

    return 0;
}

void printBookHeader(void) {
    printf("\n%-5s %-30s %-22s %-15s %-6s %-8s %-10s\n",
           "ID", "Title", "Author", "Category", "Year", "Total", "Available");

    printf("-----------------------------------------------------------------------------------------------------\n");
}

void printBookRow(const Book *book) {
    printf("%-5d %-30.30s %-22.22s %-15.15s %-6d %-8d %-10d\n",
           book->id,
           book->title,
           book->author,
           book->category,
           book->year,
           book->quantity,
           book->available);
}

/* =========================
   Book management
   ========================= */

void addBook(void) {
    Book book;

    if (bookCount >= MAX_BOOKS) {
        printf("Book storage is full.\n");
        return;
    }

    printf("\n=== ADD BOOK ===\n");

    book.id = getNextBookId();

    readLine("Title: ", book.title, sizeof(book.title));
    readLine("Author: ", book.author, sizeof(book.author));
    readLine("Category: ", book.category, sizeof(book.category));

    book.year = readPositiveInt("Publication year: ");
    book.quantity = readPositiveInt("Quantity: ");
    book.available = book.quantity;
    book.borrowCount = 0;

    if (strlen(book.title) == 0 || strlen(book.author) == 0) {
        printf("Title and author cannot be empty.\n");
        return;
    }

    books[bookCount++] = book;
    saveBooks();

    printf("Book added successfully. Book ID = %d\n", book.id);
}

void listBooks(void) {
    int i;

    printf("\n=== BOOK LIST ===\n");

    if (bookCount == 0) {
        printf("No books found.\n");
        return;
    }

    printBookHeader();

    for (i = 0; i < bookCount; i++) {
        printBookRow(&books[i]);
    }

    printf("\nTotal book titles: %d\n", bookCount);
}

void viewBookDetails(void) {
    int id = readInt("Enter book ID: ");
    int index = findBookIndexById(id);

    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    printf("\n=== BOOK DETAILS ===\n");
    printf("ID           : %d\n", books[index].id);
    printf("Title        : %s\n", books[index].title);
    printf("Author       : %s\n", books[index].author);
    printf("Category     : %s\n", books[index].category);
    printf("Year         : %d\n", books[index].year);
    printf("Total copies : %d\n", books[index].quantity);
    printf("Available    : %d\n", books[index].available);
    printf("Borrowed now : %d\n", books[index].quantity - books[index].available);
    printf("Borrow count : %d\n", books[index].borrowCount);
}

void updateBook(void) {
    int id = readInt("Enter book ID to update: ");
    int index = findBookIndexById(id);
    char input[150];
    int currentBorrowed;
    int newQuantity;

    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    printf("\nLeave text fields empty to keep the current value.\n");

    printf("Current title: %s\n", books[index].title);
    readLine("New title: ", input, sizeof(input));
    if (strlen(input) > 0) {
        strncpy(books[index].title, input, TITLE_LEN - 1);
        books[index].title[TITLE_LEN - 1] = '\0';
    }

    printf("Current author: %s\n", books[index].author);
    readLine("New author: ", input, sizeof(input));
    if (strlen(input) > 0) {
        strncpy(books[index].author, input, AUTHOR_LEN - 1);
        books[index].author[AUTHOR_LEN - 1] = '\0';
    }

    printf("Current category: %s\n", books[index].category);
    readLine("New category: ", input, sizeof(input));
    if (strlen(input) > 0) {
        strncpy(books[index].category, input, CATEGORY_LEN - 1);
        books[index].category[CATEGORY_LEN - 1] = '\0';
    }

    printf("Current year: %d\n", books[index].year);
    readLine("New year (empty = keep): ", input, sizeof(input));
    if (strlen(input) > 0) {
        books[index].year = atoi(input);
    }

    currentBorrowed = books[index].quantity - books[index].available;

    printf("Current quantity: %d\n", books[index].quantity);
    readLine("New quantity (empty = keep): ", input, sizeof(input));

    if (strlen(input) > 0) {
        newQuantity = atoi(input);

        if (newQuantity < currentBorrowed) {
            printf("Cannot set quantity below currently borrowed copies (%d).\n",
                   currentBorrowed);
        } else {
            books[index].quantity = newQuantity;
            books[index].available = newQuantity - currentBorrowed;
        }
    }

    saveBooks();
    printf("Book updated successfully.\n");
}

void deleteBook(void) {
    int id = readInt("Enter book ID to delete: ");
    int index = findBookIndexById(id);
    int i;
    char confirm[10];

    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    if (hasActiveLoanForBook(id)) {
        printf("Cannot delete this book because it has active loans.\n");
        return;
    }

    printf("Delete \"%s\"? (y/n): ", books[index].title);
    fgets(confirm, sizeof(confirm), stdin);

    if (tolower((unsigned char)confirm[0]) != 'y') {
        printf("Delete cancelled.\n");
        return;
    }

    for (i = index; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }

    bookCount--;
    saveBooks();

    printf("Book deleted successfully.\n");
}

void searchBooks(void) {
    char keyword[120];
    int i;
    int found = 0;

    printf("\n=== SEARCH BOOKS ===\n");
    readLine("Enter title, author or category keyword: ",
             keyword,
             sizeof(keyword));

    if (strlen(keyword) == 0) {
        printf("Keyword cannot be empty.\n");
        return;
    }

    printBookHeader();

    for (i = 0; i < bookCount; i++) {
        if (containsIgnoreCase(books[i].title, keyword) ||
            containsIgnoreCase(books[i].author, keyword) ||
            containsIgnoreCase(books[i].category, keyword)) {

            printBookRow(&books[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching books found.\n");
    }
}

int compareBookTitle(const void *a, const void *b) {
    const Book *bookA = (const Book *)a;
    const Book *bookB = (const Book *)b;
    const char *p1 = bookA->title;
    const char *p2 = bookB->title;

    while (*p1 && *p2) {
        char c1 = (char)tolower((unsigned char)*p1);
        char c2 = (char)tolower((unsigned char)*p2);

        if (c1 != c2) {
            return c1 - c2;
        }

        p1++;
        p2++;
    }

    return (unsigned char)*p1 - (unsigned char)*p2;
}

void sortBooksByTitle(void) {
    if (bookCount <= 1) {
        printf("Not enough books to sort.\n");
        return;
    }

    qsort(books, bookCount, sizeof(Book), compareBookTitle);
    saveBooks();

    printf("Books sorted by title successfully.\n");
}

/* =========================
   Borrow / return
   ========================= */

void borrowBook(void) {
    int bookId;
    int index;
    Loan loan;

    if (loanCount >= MAX_LOANS) {
        printf("Loan storage is full.\n");
        return;
    }

    printf("\n=== BORROW BOOK ===\n");

    bookId = readInt("Enter book ID: ");
    index = findBookIndexById(bookId);

    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    if (books[index].available <= 0) {
        printf("No available copy of this book.\n");
        return;
    }

    loan.id = getNextLoanId();
    loan.bookId = bookId;

    readLine("Borrower name: ", loan.borrower, sizeof(loan.borrower));

    if (strlen(loan.borrower) == 0) {
        printf("Borrower name cannot be empty.\n");
        return;
    }

    getCurrentDate(loan.borrowDate);
    strcpy(loan.returnDate, "-");
    loan.returned = 0;

    loans[loanCount++] = loan;

    books[index].available--;
    books[index].borrowCount++;

    saveAll();

    printf("Borrow successful.\n");
    printf("Loan ID: %d\n", loan.id);
    printf("Book: %s\n", books[index].title);
    printf("Borrower: %s\n", loan.borrower);
    printf("Borrow date: %s\n", loan.borrowDate);
}

void returnBook(void) {
    int loanId = readInt("Enter loan ID to return: ");
    int i;
    int bookIndex;

    for (i = 0; i < loanCount; i++) {
        if (loans[i].id == loanId) {
            if (loans[i].returned) {
                printf("This loan has already been returned.\n");
                return;
            }

            loans[i].returned = 1;
            getCurrentDate(loans[i].returnDate);

            bookIndex = findBookIndexById(loans[i].bookId);

            if (bookIndex != -1 &&
                books[bookIndex].available < books[bookIndex].quantity) {
                books[bookIndex].available++;
            }

            saveAll();

            printf("Book returned successfully.\n");
            printf("Return date: %s\n", loans[i].returnDate);
            return;
        }
    }

    printf("Loan ID not found.\n");
}

void listActiveLoans(void) {
    int i;
    int found = 0;
    int bookIndex;

    printf("\n=== ACTIVE LOANS ===\n");
    printf("%-8s %-8s %-30s %-25s %-12s\n",
           "Loan ID", "Book ID", "Book", "Borrower", "Borrow Date");

    printf("------------------------------------------------------------------------------------------\n");

    for (i = 0; i < loanCount; i++) {
        if (loans[i].returned == 0) {
            bookIndex = findBookIndexById(loans[i].bookId);

            printf("%-8d %-8d %-30.30s %-25.25s %-12s\n",
                   loans[i].id,
                   loans[i].bookId,
                   bookIndex != -1 ? books[bookIndex].title : "[Deleted book]",
                   loans[i].borrower,
                   loans[i].borrowDate);

            found = 1;
        }
    }

    if (!found) {
        printf("No active loans.\n");
    }
}

void listLoanHistory(void) {
    int i;
    int bookIndex;

    printf("\n=== LOAN HISTORY ===\n");

    if (loanCount == 0) {
        printf("No loan history.\n");
        return;
    }

    printf("%-8s %-8s %-25s %-20s %-12s %-12s %-10s\n",
           "Loan ID",
           "Book ID",
           "Book",
           "Borrower",
           "Borrowed",
           "Returned",
           "Status");

    printf("-------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < loanCount; i++) {
        bookIndex = findBookIndexById(loans[i].bookId);

        printf("%-8d %-8d %-25.25s %-20.20s %-12s %-12s %-10s\n",
               loans[i].id,
               loans[i].bookId,
               bookIndex != -1 ? books[bookIndex].title : "[Deleted book]",
               loans[i].borrower,
               loans[i].borrowDate,
               loans[i].returnDate,
               loans[i].returned ? "Returned" : "Borrowing");
    }
}

/* =========================
   Statistics
   ========================= */

void showStatistics(void) {
    int totalCopies = 0;
    int totalAvailable = 0;
    int activeLoans = 0;
    int returnedLoans = 0;
    int i;
    int mostBorrowedIndex = -1;

    for (i = 0; i < bookCount; i++) {
        totalCopies += books[i].quantity;
        totalAvailable += books[i].available;

        if (mostBorrowedIndex == -1 ||
            books[i].borrowCount > books[mostBorrowedIndex].borrowCount) {
            mostBorrowedIndex = i;
        }
    }

    for (i = 0; i < loanCount; i++) {
        if (loans[i].returned) {
            returnedLoans++;
        } else {
            activeLoans++;
        }
    }

    printf("\n=== LIBRARY STATISTICS ===\n");
    printf("Book titles          : %d\n", bookCount);
    printf("Total book copies    : %d\n", totalCopies);
    printf("Available copies     : %d\n", totalAvailable);
    printf("Borrowed copies      : %d\n", totalCopies - totalAvailable);
    printf("Active loans         : %d\n", activeLoans);
    printf("Returned loans       : %d\n", returnedLoans);
    printf("All loan transactions: %d\n", loanCount);

    if (mostBorrowedIndex != -1) {
        printf("Most borrowed book   : %s (%d times)\n",
               books[mostBorrowedIndex].title,
               books[mostBorrowedIndex].borrowCount);
    }
}

/* =========================
   Menu
   ========================= */

void showMenu(void) {
    printf("\n");
    printf("====================================================\n");
    printf("           LIBRARY BOOK MANAGEMENT SYSTEM\n");
    printf("====================================================\n");
    printf(" 1. Add book\n");
    printf(" 2. List all books\n");
    printf(" 3. View book details\n");
    printf(" 4. Update book\n");
    printf(" 5. Delete book\n");
    printf(" 6. Search books\n");
    printf(" 7. Sort books by title\n");
    printf(" 8. Borrow book\n");
    printf(" 9. Return book\n");
    printf("10. List active loans\n");
    printf("11. Loan history\n");
    printf("12. Statistics\n");
    printf(" 0. Save and exit\n");
    printf("====================================================\n");
}

int main(void) {
    int choice;

    loadBooks();
    loadLoans();

    do {
        showMenu();
        choice = readInt("Choose an option: ");

        switch (choice) {
            case 1:
                addBook();
                pauseScreen();
                break;

            case 2:
                listBooks();
                pauseScreen();
                break;

            case 3:
                viewBookDetails();
                pauseScreen();
                break;

            case 4:
                updateBook();
                pauseScreen();
                break;

            case 5:
                deleteBook();
                pauseScreen();
                break;

            case 6:
                searchBooks();
                pauseScreen();
                break;

            case 7:
                sortBooksByTitle();
                pauseScreen();
                break;

            case 8:
                borrowBook();
                pauseScreen();
                break;

            case 9:
                returnBook();
                pauseScreen();
                break;

            case 10:
                listActiveLoans();
                pauseScreen();
                break;

            case 11:
                listLoanHistory();
                pauseScreen();
                break;

            case 12:
                showStatistics();
                pauseScreen();
                break;

            case 0:
                saveAll();
                printf("Data saved. Goodbye!\n");
                break;

            default:
                printf("Invalid option.\n");
                pauseScreen();
        }

    } while (choice != 0);

    return 0;
}
