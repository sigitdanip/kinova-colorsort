//
// Created by HP on 19/08/2022.
//

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

            pointToSend.Position.CartesianPosition.X = -0.452077f;
            pointToSend.Position.CartesianPosition.Y =  -0.0276739f;
            pointToSend.Position.CartesianPosition.Z = 0.0195328f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.03237f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0581954f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.75858f;
            pointToSend.Position.Fingers.Finger1 = 6;
            pointToSend.Position.Fingers.Finger2 = 6;
            pointToSend.Position.Fingers.Finger3 = 6;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.451933f;
            pointToSend.Position.CartesianPosition.Y =  -0.0277337f;
            pointToSend.Position.CartesianPosition.Z = 0.0193019f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.03216f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0576614f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.75862f;
            pointToSend.Position.Fingers.Finger1 = 4692;
            pointToSend.Position.Fingers.Finger2 = 4692;
            pointToSend.Position.Fingers.Finger3 = 4698;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.454745f;
            pointToSend.Position.CartesianPosition.Y =  -0.0271961f;
            pointToSend.Position.CartesianPosition.Z = 0.4094f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.03056f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.0571124f;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.75533f;
            pointToSend.Position.Fingers.Finger1 = 4692;
            pointToSend.Position.Fingers.Finger2 = 4692;
            pointToSend.Position.Fingers.Finger3 = 4698;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.318125f;
            pointToSend.Position.CartesianPosition.Y =  0.17776f;
            pointToSend.Position.CartesianPosition.Z = 0.411733f;
            pointToSend.Position.CartesianPosition.ThetaX = 3.08112f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.113288f;
            pointToSend.Position.CartesianPosition.ThetaZ = 2.32908f;
            pointToSend.Position.Fingers.Finger1 = 4692;
            pointToSend.Position.Fingers.Finger2 = 4692;
            pointToSend.Position.Fingers.Finger3 = 4698;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.136317f;
            pointToSend.Position.CartesianPosition.Y =  0.366047f;
            pointToSend.Position.CartesianPosition.Z = 0.0222958f;
            pointToSend.Position.CartesianPosition.ThetaX = -3.12016f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.121413f;
            pointToSend.Position.CartesianPosition.ThetaZ = 2.94992f;
            pointToSend.Position.Fingers.Finger1 = 4692;
            pointToSend.Position.Fingers.Finger2 = 4692;
            pointToSend.Position.Fingers.Finger3 = 4698;
            MySendBasicTrajectory(pointToSend);

            pointToSend.Position.CartesianPosition.X = -0.136317f;
            pointToSend.Position.CartesianPosition.Y =  0.366047f;
            pointToSend.Position.CartesianPosition.Z = 0.0222958f;
            pointToSend.Position.CartesianPosition.ThetaX = -3.12016f;
            pointToSend.Position.CartesianPosition.ThetaY = -0.121413f;
            pointToSend.Position.CartesianPosition.ThetaZ = 2.94992f;
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


