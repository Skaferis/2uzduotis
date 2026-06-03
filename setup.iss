#define MyAppName "Studentu rezultatu analizes programa"
#define MyAppVersion "3.0"
#define MyAppPublisher "VU"
#define MyAppExeName "vector.exe"

[Setup]
AppId={{A1F9A08E-1B71-4C5C-9845-MYKOLAS-JOVAISA}}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\VU\Mykolas-Jovaisa
DefaultGroupName=VU\Mykolas-Jovaisa
OutputDir=installer_output
OutputBaseFilename=Setup
Compression=lzma
SolidCompression=yes
WizardStyle=modern
PrivilegesRequired=admin
UninstallDisplayName={#MyAppName}
UninstallDisplayIcon={app}\{#MyAppExeName}

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "Sukurti nuoroda darbalaukyje"; GroupDescription: "Papildomos nuorodos:"; Flags: unchecked

[Files]
Source: "vector.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "studentai10000.txt"; DestDir: "{app}"; Flags: ignoreversion skipifsourcedoesntexist
Source: "studentai100000.txt"; DestDir: "{app}"; Flags: ignoreversion skipifsourcedoesntexist
Source: "README.md"; DestDir: "{app}"; Flags: ignoreversion skipifsourcedoesntexist

[Icons]
Name: "{group}\Studentu programa"; Filename: "{app}\{#MyAppExeName}"; WorkingDir: "{app}"
Name: "{group}\README"; Filename: "{app}\README.md"; WorkingDir: "{app}"; Flags: createonlyiffileexists
Name: "{autodesktop}\Studentu programa"; Filename: "{app}\{#MyAppExeName}"; WorkingDir: "{app}"; Tasks: desktopicon

[Registry]
Root: HKLM; Subkey: "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers"; ValueType: string; ValueName: "{app}\{#MyAppExeName}"; ValueData: "RUNASADMIN"; Flags: uninsdeletevalue

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "Paleisti programa"; Flags: nowait postinstall skipifsilent
