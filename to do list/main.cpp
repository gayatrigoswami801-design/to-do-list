#include <iostream>
#include <vector>

using namespace std;

struct Task
{
    string name;
    bool completed;
};

vector<Task> tasks;

void addTask()
{
    Task newTask;

    cin.ignore();

    cout << "Enter task: ";

    getline(cin, newTask.name);

    newTask.completed = false;

    tasks.push_back(newTask);

    cout << "Task added successfully!" << endl;
}

void viewTasks()
{
    if(tasks.empty())
    {
        cout << "No tasks available!" << endl;
        return;
    }

    cout << endl;

    for(int i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". ";

        cout << tasks[i].name;

        if(tasks[i].completed)
            cout << " [Completed]";
        else
            cout << " [Pending]";

        cout << endl;
    }

    cout << endl;
}

void completeTask()
{
    int taskNumber;

    viewTasks();

    cout << "Enter task number to mark complete: ";

    cin >> taskNumber;

    if(taskNumber > 0 && taskNumber <= tasks.size())
    {
        tasks[taskNumber - 1].completed = true;

        cout << "Task marked as completed!" << endl;
    }
    else
    {
        cout << "Invalid task number!" << endl;
    }
}

void deleteTask()
{
    int taskNumber;

    viewTasks();

    cout << "Enter task number to delete: ";

    cin >> taskNumber;

    if(taskNumber > 0 && taskNumber <= tasks.size())
    {
        tasks.erase(tasks.begin() + taskNumber - 1);

        cout << "Task deleted successfully!" << endl;
    }
    else
    {
        cout << "Invalid task number!" << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << endl;

        cout << "===== TO-DO LIST =====" << endl;

        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task Complete" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                completeTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 5);

    return 0;
}