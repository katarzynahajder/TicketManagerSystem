#pragma once

// ==============================================
// Klasa statyczna przechowuj�ca dane zalogowanego u�ytkownika.
// Umo�liwia globalny dost�p do loginu u�ytkownika z r�nych widok�w aplikacji.
// ==============================================

using namespace System;

ref class Session sealed
{
    public:
        static String^ Username = nullptr;
};