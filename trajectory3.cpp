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

            pointToSend.Position.CartesianPosition.X = -0.454752f;
            pointToSend.Position.CartesianPosition.Y =  -0.0278665f;
            pointToSend.Position.CartesianPosition.Z = 0.0392537f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.0287f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0548117f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.70602f;
            pointToSend.Position.Fingers.Finger1 = 12;
            pointToSend.Position.Fingers.Finger2 = 12;
            pointToSend.Position.Fingers.Finger3 = 18;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.454826f;
            pointToSend.Position.CartesianPosition.Y =  -0.028015f;
            pointToSend.Position.CartesianPosition.Z = 0.0393979f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.02851f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0550984f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.70575f;
            pointToSend.Position.Fingers.Finger1 = 2700;
            pointToSend.Position.Fingers.Finger2 = 2706;
            pointToSend.Position.Fingers.Finger3 = 2706;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.44142f;
            pointToSend.Position.CartesianPosition.Y =  -0.0263139f;
            pointToSend.Position.CartesianPosition.Z = 0.421096f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.02337f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0545057f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.70476f;
            pointToSend.Position.Fingers.Finger1 = 2892;
            pointToSend.Position.Fingers.Finger2 = 2910;
            pointToSend.Position.Fingers.Finger3 = 2904;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.311433f;
            pointToSend.Position.CartesianPosition.Y =  0.366153f;
            pointToSend.Position.CartesianPosition.Z = 0.482745f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.11308f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.117881f;
            pointToSend.Position.CartesianPosition.ThetaZ = 2.63384f;
            pointToSend.Position.Fingers.Finger1 = 2892;
            pointToSend.Position.Fingers.Finger2 = 2910;
            pointToSend.Position.Fingers.Finger3 = 2904;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.297526f;
            pointToSend.Position.CartesianPosition.Y =  0.384226f;
            pointToSend.Position.CartesianPosition.Z = 0.0495854f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.12419f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.121337f;
            pointToSend.Position.CartesianPosition.ThetaZ = 2.68145f;
            pointToSend.Position.Fingers.Finger1 = 2892;
            pointToSend.Position.Fingers.Finger2 = 2910;
            pointToSend.Position.Fingers.Finger3 = 2904;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.297526f;
            pointToSend.Position.CartesianPosition.Y =  0.384226f;
            pointToSend.Position.CartesianPosition.Z = 0.0495854f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.12419f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.121337f;
            pointToSend.Position.CartesianPosition.ThetaZ = 2.68145f;
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



