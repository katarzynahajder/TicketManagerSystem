#pragma once

// ==============================================
// Klasa statyczna przechowuj¹ca dane zalogowanego u¿ytkownika.
// Umo¿liwia globalny dostêp do loginu u¿ytkownika z ró¿nych widoków aplikacji.
// ==============================================

using namespace System;

ref class Session sealed
{
    public:
        static String^ Username = nullptr;
};