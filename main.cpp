//Course info : Topics Artificial Intelligence
//Student : Mahsa Fazli 

#include <iostream>
using namespace std;

int main()
{
    // Actual environment (The current condition of the Rooms)
    bool roomA_dirty = true;
    bool roomB_dirty = true;

    // Agent's current location
    char location = 'B';

    // Agent's memory
    // U = Unknown, D = Dirty, C = Clean
    char memoryA = 'U';
    char memoryB = 'U';

    cout << "Vacuum Agent started!" << endl;

    while (memoryA != 'C' || memoryB != 'C')
    {
        // ---------- Whatever happens in Room A ----------
        if (location == 'A')
        {
            cout << "\nVacuum is in Room A." << endl;

            // The current condition of Room A preceived by agent's sensor
            if (roomA_dirty == true)
            {
                cout << "Sensor: Room A is dirty." << endl;
                memoryA = 'D';
                cout << "Action: Cleaning Room A..." << endl;
                roomA_dirty = false;
                memoryA = 'C';

                cout << "Room A is clean now!" << endl;
            }
            else
            {
                cout << "Sensor: Room A is clean." << endl;
                memoryA = 'C';
            }

            // Go to B if B is not known to be clean
            if (memoryB != 'C')
            {
                cout << "Action: Moving to Room B..." << endl;
                location = 'B';
            }
        }

        // ---------- Whatever happens in Room B ----------
        else if (location == 'B')
        {
            cout << "\nVacuum is in Room B." << endl;

            // The current condition of Room B preceived by agent's sensor
            if (roomB_dirty == true)
            {
                cout << "Sensor: Room B is dirty." << endl;
                memoryB = 'D';
                cout << "Action: Cleaning Room B..." << endl;
                roomB_dirty = false;
                memoryB = 'C';
                cout << "Room B is clean now!" << endl;
            }

            else
            {
                cout << "Sensor: Room B is clean." << endl;
                memoryB = 'C';
            }

            // Go to A if A is not known to be clean , particularly for when the agent starts at Room B and hasn't any memory about Room A
            if (memoryA != 'C')
            {
                cout << "Action: Moving to Room A..." << endl;
                location = 'A';
            }
        }
    }

    cout << "\nGoal achieved: Both rooms are clean!" << endl;

    return 0;
}
