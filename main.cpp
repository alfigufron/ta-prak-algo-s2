#include <iostream>

using namespace std;

int option = 100, count = 0, selected_index;
float tasks[100], tests[100];
string students[100] = {};

int listData() {
  if (count > 0) {
    cout << "List Data\n\n";

    cout << "Index - Name - Task Score - Test Score - Avg\n";
    for (int i = 0; i < count; i++) {
      cout << i << " - " << students[i] << " - " << tasks[i] << " - " << tests[i] << " - " << (tasks[i]+tests[i]) / 2 << "\n";
    }
  } else {
    cout << "Empty Data";
  }

  cout << "\n\n";

  return 0;
}

int addData() {
  cout << "Add Data\n";

  cout << "Input Name : ";
  getline(cin >> ws, students[count]);

  cout << "Task Score : ";
  cin >> tasks[count];

  cout << "Test Score : ";
  cin >> tests[count];

  count++;

  system("cls");

  return 0;
}

int deleteData() {
  if (count > 0) {
    cout << "Delete Data\n\n";
    cout << "Input Index : ";
    cin >> selected_index;

    for (int i = selected_index; i < count - 1; i++) {
      students[i] = students[i+1];
      tasks[i] = tasks[i+1];
      tests[i] = tests[i+1];
    }

    count--;

    system("cls");
  } else {
    cout << "Empty Data";
  }

  cout << "\n\n";

  return 0;
}

int sortingData() {
  if (count > 0) {
    for (int i = 0; i < count; i++) {
      for (int j = i+1; j < count; j++) {
        int final_score_i = (tasks[i]+tests[i]) / 2;
        int final_score_j = (tasks[j]+tests[j]) / 2;

        if (final_score_j < final_score_i) {
          string temp_student = students[i];
          int temp_task = tasks[i];
          int temp_test = tests[i];

          students[i] = students[j];
          tasks[i] = tasks[j];
          tests[i] = tests[j];

          students[j] = temp_student;
          tasks[j] = temp_task;
          tests[j] = temp_test;
        }
      }
    }
  } else {
    cout << "Empty Data";
  }

  return 0;
}

int main() {
  while (option != 0) {
    cout << "Menu\n";
    cout << "0. Quit\n";
    cout << "1. List Data\n";
    cout << "2. Add Data\n";
    cout << "3. Delete Data\n";
    cout << "4. Sorting Data (Final Score)\n";

    cout << "Input Menu :";
    cin >> option;
    
    system("cls");

    switch (option) {
      case 1:
        listData();
        break;

      case 2:
        addData();
        break;

      case 3:
        deleteData();
        break;

      case 4:
        sortingData();
        break;
      
      default:
        cout << "Invalid Menu!\n\n";
        break;
    }
  }

  return 0;
}