#include <iostream>
#include <string>
#include <iomanip> // For making the output look like a real table

using namespace std;

// This function replaces the massive if-else blocks. 
// It calculates the grade and status for ANY subject passed to it.
void displaySubjectResult(string sName, double marks, int total) {
    double percentage = (marks / total) * 100;
    string grade, status;

    if (percentage >= 80) { grade = "A+"; status = "PASS"; }
    else if (percentage >= 75) { grade = "A";  status = "PASS"; }
    else if (percentage >= 70) { grade = "B+"; status = "PASS"; }
    else if (percentage >= 65) { grade = "B";  status = "PASS"; }
    else if (percentage >= 60) { grade = "C";  status = "PASS"; }
    else if (percentage >= 50) { grade = "D";  status = "PASS"; }
    else { grade = "F"; status = "FAIL"; }

    // setw(n) aligns the text into neat columns
    cout << left << setw(15) << sName 
         << setw(10) << total 
         << setw(12) << marks 
         << fixed << setprecision(2) << setw(10) << percentage 
         << setw(10) << grade 
         << status << endl;
}

void generateReport() {
    string name, s1, s2, s3, s4, s5;
    double m1, m2, m3, m4, m5;
    int t1, t2, t3, t4, t5;

    cin.ignore();
    cout << "\n--- Enter Student Name: ";
    getline(cin, name);

    // Manual input for 5 subjects (Keeping it simple as requested)
    cout << "Subject 1 Name: "; getline(cin, s1);
    cout << "Total Marks & Obtained: "; cin >> t1 >> m1; cin.ignore();

    cout << "Subject 2 Name: "; getline(cin, s2);
    cout << "Total Marks & Obtained: "; cin >> t2 >> m2; cin.ignore();

    cout << "Subject 3 Name: "; getline(cin, s3);
    cout << "Total Marks & Obtained: "; cin >> t3 >> m3; cin.ignore();

    cout << "Subject 4 Name: "; getline(cin, s4);
    cout << "Total Marks & Obtained: "; cin >> t4 >> m4; cin.ignore();

    cout << "Subject 5 Name: "; getline(cin, s5);
    cout << "Total Marks & Obtained: "; cin >> t5 >> m5; cin.ignore();

    // Final Calculations
    double totalObtained = m1 + m2 + m3 + m4 + m5;
    int totalMax = t1 + t2 + t3 + t4 + t5;
    double finalPercent = (totalObtained / totalMax) * 100;

    // --- REPORT CARD DISPLAY ---
    cout << "\n" << string(70, '=') << endl;
    cout << " STUDENT REPORT CARD: " << name << endl;
    cout << string(70, '-') << endl;
    cout << left << setw(15) << "Subject" << setw(10) << "Max" << setw(12) << "Obtained" 
         << setw(10) << " %" << setw(10) << "Grade" << "Status" << endl;
    cout << string(70, '-') << endl;

    // Reusing the function for each subject
    displaySubjectResult(s1, m1, t1);
    displaySubjectResult(s2, m2, t2);
    displaySubjectResult(s3, m3, t3);
    displaySubjectResult(s4, m4, t4);
    displaySubjectResult(s5, m5, t5);

    cout << string(70, '-') << endl;
    cout << "GRAND TOTAL: " << totalObtained << "/" << totalMax 
         << " | Final Percentage: " << finalPercent << "%" << endl;
    cout << string(70, '=') << endl << endl;
}

int main() {
    int choice;
    do {
        cout << "1. Create New Result\n0. Exit\nSelection: ";
        cin >> choice;
        if (choice == 1) generateReport();
    } while (choice != 0);
    
    return 0;
}
