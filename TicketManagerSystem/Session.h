#pragma once

// ==============================================
// Klasa statyczna przechowująca dane zalogowanego użytkownika.
// Umożliwia globalny dostęp do loginu użytkownika z różnych widoków aplikacji.
// ==============================================

using namespace System;

ref class Session sealed
{
    public:
        static String^ Username = nullptr;
};