//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------

WScript.LoadScriptFile("../UnitTestFramework/known_globals.js");

for (a in this) {
    if (isKnownGlobal(a))
        continue;
    WScript.Echo(a);
}


const x = 10;
WScript.Echo(x);
{
    const x = 20;
    WScript.Echo(x);
}
WScript.Echo(x);



for (a in this) {
    if (isKnownGlobal(a))
        continue;
    WScript.Echo(a);
}

