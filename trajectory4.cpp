#define UNICODE
#include "KinovaTypes.h"
#include <iostream>
#include <windows.h>
#include "CommunicationLayer.h"
#include "CommandLayer.h"
#include <conio.h>

using namespace std;

HINSTANCE commandLayer_handle;
int(*MyInitAPI)();
int(*MyCloseAPI)();
int(*MySendBasicTrajectory)(TrajectoryPoint command);
int(*MyGetDevices)(KinovaDevice devices[MAX_KINOVA_DEVICE], int &result);
int(*MySetActiveDevice)(KinovaDevice device);
int(*MyMoveHome)();
int(*MyInitFingers)();
int(*MyGetCartesianCommand)(CartesianPosition &);

int main(){
    CartesianPosition currentCommand;
    int programResult = 0;

    commandLayer_handle = LoadLibraryA("CommandLayerWindows.dll");

    MyInitAPI = (int(*)()) GetProcAddress(commandLayer_handle, "InitAPI");
    MyCloseAPI = (int(*)()) GetProcAddress(commandLayer_handle, "CloseAPI");
    MyMoveHome = (int(*)()) GetProcAddress(commandLayer_handle, "MoveHome");
    MyInitFingers = (int(*)()) GetProcAddress(commandLayer_handle, "InitFingers");
    MyGetDevices = (int(*)(KinovaDevice devices[MAX_KINOVA_DEVICE],
                           int &result)) GetProcAddress(commandLayer_handle, "GetDevices");
    MySetActiveDevice = (int(*)(KinovaDevice devices)) GetProcAddress(commandLayer_handle,
                                                                      "SetActiveDevice");
    MySendBasicTrajectory = (int(*)(TrajectoryPoint)) GetProcAddress(commandLayer_handle,
                                                                     "SendBasicTrajectory");
    MyGetCartesianCommand = (int(*)(CartesianPosition &)) GetProcAddress(commandLayer_handle,
                                                                         "GetCartesianCommand");

    if ((MyInitAPI == NULL) || (MyCloseAPI == NULL) || (MySendBasicTrajectory == NULL) ||
        (MyGetDevices == NULL) || (MySetActiveDevice == NULL) || (MyGetCartesianCommand == NULL) ||
        (MyMoveHome == NULL) || (MyInitFingers == NULL)){

        cout << "init error/n";
        programResult = 0;
    }
    else{

        cout << "initialization complete" << endl;

        int result = (*MyInitAPI)();
        CartesianPosition currentCommand;
        KinovaDevice list[MAX_KINOVA_DEVICE];
        int devicesCount = MyGetDevices(list, result);

        for (int i = 0; i < devicesCount; i++) {
            cout << "robot found: " << list[i].SerialNumber << endl;
            MySetActiveDevice(list[i]);

            MyInitFingers();
            TrajectoryPoint pointToSend;
            pointToSend.InitStruct();

            pointToSend.Position.Type = CARTESIAN_POSITION;

            pointToSend.Position.CartesianPosition.X = -0.347789;
            pointToSend.Position.CartesianPosition.Y =  -0.0608023;
            pointToSend.Position.CartesianPosition.Z = 0.322818;
            pointToSend.Position.CartesianPosition.ThetaX = 3.02347;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0553457;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.63013;
            pointToSend.Position.Fingers.Finger1 = 6;
            pointToSend.Position.Fingers.Finger2 = 6;
            pointToSend.Position.Fingers.Finger3 = 6;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.441201f;
            pointToSend.Position.CartesianPosition.Y =  -0.0383698f;
            pointToSend.Position.CartesianPosition.Z = 0.144426f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.02574f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0484515f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.7055f;
            pointToSend.Position.Fingers.Finger1 = 6;
            pointToSend.Position.Fingers.Finger2 = 6;
            pointToSend.Position.Fingers.Finger3 = 6;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.441161f;
            pointToSend.Position.CartesianPosition.Y =  -0.0383888f;
            pointToSend.Position.CartesianPosition.Z = 0.144424f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.02574f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0484303f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.70545f;
            pointToSend.Position.Fingers.Finger1 = 3624;
            pointToSend.Position.Fingers.Finger2 = 3642;
            pointToSend.Position.Fingers.Finger3 = 3630;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.445808f;
            pointToSend.Position.CartesianPosition.Y =  -0.035763f;
            pointToSend.Position.CartesianPosition.Z = 0.499108f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.0305f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0534655f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.70958f;
            pointToSend.Position.Fingers.Finger1 = 3624;
            pointToSend.Position.Fingers.Finger2 = 3642;
            pointToSend.Position.Fingers.Finger3 = 3630;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.428812f;
            pointToSend.Position.CartesianPosition.Y =  0.379871f;
            pointToSend.Position.CartesianPosition.Z = 0.453828f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.10163f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.123777f;
            pointToSend.Position.CartesianPosition.ThetaZ = 2.514f;
            pointToSend.Position.Fingers.Finger1 = 3624;
            pointToSend.Position.Fingers.Finger2 = 3642;
            pointToSend.Position.Fingers.Finger3 = 3630;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.441637f;
            pointToSend.Position.CartesianPosition.Y =  0.380375f;
            pointToSend.Position.CartesianPosition.Z = 0.148355f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.10294f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.117223f;
            pointToSend.Position.CartesianPosition.ThetaZ = 2.49875f;
            pointToSend.Position.Fingers.Finger1 = 3624;
            pointToSend.Position.Fingers.Finger2 = 3642;
            pointToSend.Position.Fingers.Finger3 = 3630;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.441637f;
            pointToSend.Position.CartesianPosition.Y =  0.380375f;
            pointToSend.Position.CartesianPosition.Z = 0.148355f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.10294f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.117223f;
            pointToSend.Position.CartesianPosition.ThetaZ = 2.49875f;
            pointToSend.Position.Fingers.Finger1 = 6;
            pointToSend.Position.Fingers.Finger2 = 6;
            pointToSend.Position.Fingers.Finger3 = 6;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.347789;
            pointToSend.Position.CartesianPosition.Y =  -0.0608023;
            pointToSend.Position.CartesianPosition.Z = 0.322818;
            pointToSend.Position.CartesianPosition.ThetaX = 3.02347;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0553457;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.63013;
            pointToSend.Position.Fingers.Finger1 = 6;
            pointToSend.Position.Fingers.Finger2 = 6;
            pointToSend.Position.Fingers.Finger3 = 6;
            MySendBasicTrajectory(pointToSend);
        }


        cout << endl;
        result = (*MyCloseAPI)();
        programResult = 1;
    }

    FreeLibrary(commandLayer_handle);
    return programResult;
}

