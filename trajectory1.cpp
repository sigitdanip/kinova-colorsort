
//
// Created by sigit dani perkasa on 18/08/2022.
//
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

            pointToSend.Position.CartesianPosition.X = -0.439335f;
            pointToSend.Position.CartesianPosition.Y =  -0.0462809f;
            pointToSend.Position.CartesianPosition.Z = 0.00398391f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.0294f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0572126f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.69029f;
            pointToSend.Position.Fingers.Finger1 = 6;
            pointToSend.Position.Fingers.Finger2 = 6;
            pointToSend.Position.Fingers.Finger3 = -6;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.439346f;
            pointToSend.Position.CartesianPosition.Y =  -0.0462834f;
            pointToSend.Position.CartesianPosition.Z = 0.00399023f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.02939f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0572358f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.69028f;
            pointToSend.Position.Fingers.Finger1 = 4950;
            pointToSend.Position.Fingers.Finger2 = 5040;
            pointToSend.Position.Fingers.Finger3 = 5040;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.441901f;
            pointToSend.Position.CartesianPosition.Y =  -0.0466988f;
            pointToSend.Position.CartesianPosition.Z = 0.367537f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.03063f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0562862f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.69072f;
            pointToSend.Position.Fingers.Finger1 = 4950;
            pointToSend.Position.Fingers.Finger2 = 5040;
            pointToSend.Position.Fingers.Finger3 = 5040;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.397083f;
            pointToSend.Position.CartesianPosition.Y =  0.144269f;
            pointToSend.Position.CartesianPosition.Z = 0.403757f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.06642f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.102865f;
            pointToSend.Position.CartesianPosition.ThetaZ = 2.14633f;
            pointToSend.Position.Fingers.Finger1 = 4950;
            pointToSend.Position.Fingers.Finger2 = 5040;
            pointToSend.Position.Fingers.Finger3 = 5040;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.00367075f;
            pointToSend.Position.CartesianPosition.Y =  0.354934f;
            pointToSend.Position.CartesianPosition.Z = 0.405655f;
            pointToSend.Position.CartesianPosition.ThetaX = -3.07247f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.108987f;
            pointToSend.Position.CartesianPosition.ThetaZ = -2.90889f;
            pointToSend.Position.Fingers.Finger1 = 4950;
            pointToSend.Position.Fingers.Finger2 = 5040;
            pointToSend.Position.Fingers.Finger3 = 5040;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.0269588f;
            pointToSend.Position.CartesianPosition.Y =  0.355977f;
            pointToSend.Position.CartesianPosition.Z = 0.0168743f;
            pointToSend.Position.CartesianPosition.ThetaX = -3.08175f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.111764f;
            pointToSend.Position.CartesianPosition.ThetaZ = -2.98356f;
            pointToSend.Position.Fingers.Finger1 = 4950;
            pointToSend.Position.Fingers.Finger2 = 5040;
            pointToSend.Position.Fingers.Finger3 = 5040;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.0269588f;
            pointToSend.Position.CartesianPosition.Y =  0.355977f;
            pointToSend.Position.CartesianPosition.Z = 0.0168743f;
            pointToSend.Position.CartesianPosition.ThetaX = -3.08175f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.111764f;
            pointToSend.Position.CartesianPosition.ThetaZ = -2.98356f;
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


