/*
 @licstart  The following is the entire license notice for the JavaScript code in this file.

 The MIT License (MIT)

 Copyright (C) 1997-2020 by Dimitri van Heesch

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute,
 sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or
 substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 @licend  The above is the entire license notice for the JavaScript code in this file
*/
var NAVTREE =
[
  [ "Studentu rezultatu analizes programa", "index.html", [
    [ "Studentų rezultatų analizės programa (v0.4)", "md__r_e_a_d_m_e.html", [
      [ "Programos struktūra", "md__r_e_a_d_m_e.html#autotoc_md1", null ],
      [ "Sugeneruoti duomenų failai", "md__r_e_a_d_m_e.html#autotoc_md2", null ],
      [ "1 tyrimas – failų generavimo sparta, kai ND kiekis = 3", "md__r_e_a_d_m_e.html#autotoc_md3", null ],
      [ "2 tyrimas – duomenų apdorojimo sparta, kai ND kiekis = 3 ir rušiuojama pagal rezultatą", "md__r_e_a_d_m_e.html#autotoc_md4", null ],
      [ "Rezultatų analizė", "md__r_e_a_d_m_e.html#autotoc_md5", null ],
      [ "Rezultatų nuotraukos", "md__r_e_a_d_m_e.html#autotoc_md6", null ],
      [ "Konteinerių testavimas", "md__r_e_a_d_m_e.html#autotoc_md7", null ],
      [ "Visi konteineriai buvo tikrinami tais pačiais programos sugeneruotais failais ir rušiuoji pagal vidurkį, ir buvo įvertintas jų darbo laikas.", "md__r_e_a_d_m_e.html#autotoc_md8", null ],
      [ "Vector", "md__r_e_a_d_m_e.html#autotoc_md9", null ],
      [ "Deque", "md__r_e_a_d_m_e.html#autotoc_md10", null ],
      [ "List", "md__r_e_a_d_m_e.html#autotoc_md11", null ],
      [ "Rezultatai", "md__r_e_a_d_m_e.html#autotoc_md12", null ],
      [ "1 Strategija", "md__r_e_a_d_m_e.html#autotoc_md13", null ],
      [ "Vector skirstymas", "md__r_e_a_d_m_e.html#autotoc_md14", null ],
      [ "Deque skirstymas", "md__r_e_a_d_m_e.html#autotoc_md15", null ],
      [ "List skirstymas", "md__r_e_a_d_m_e.html#autotoc_md16", null ],
      [ "Rezultatai", "md__r_e_a_d_m_e.html#autotoc_md17", null ],
      [ "2 Strategija", "md__r_e_a_d_m_e.html#autotoc_md18", null ],
      [ "Vector skirstymas", "md__r_e_a_d_m_e.html#autotoc_md19", null ],
      [ "Deque skirtstymas", "md__r_e_a_d_m_e.html#autotoc_md20", [
        [ "List skirstymas", "md__r_e_a_d_m_e.html#autotoc_md21", null ],
        [ "3 Strategija", "md__r_e_a_d_m_e.html#autotoc_md22", null ],
        [ "Vector skirstymas (buvo pasiimtas 1 strategijos budas ir panaudotas copy_if)", "md__r_e_a_d_m_e.html#autotoc_md23", null ],
        [ "Deque skirstymas (buvo pasiimtas 1 strategijos budas ir panaudotas copy_if)", "md__r_e_a_d_m_e.html#autotoc_md24", null ],
        [ "List skirstymas (buvo pasiimtas 1 strategijos būdas ir panaudotas copy_if)", "md__r_e_a_d_m_e.html#autotoc_md25", null ],
        [ "v.pradine release", "md__r_e_a_d_m_e.html#autotoc_md26", null ],
        [ "v0.1", "md__r_e_a_d_m_e.html#autotoc_md27", null ],
        [ "v0.2", "md__r_e_a_d_m_e.html#autotoc_md28", null ],
        [ "v0.3", "md__r_e_a_d_m_e.html#autotoc_md29", null ],
        [ "v0.4", "md__r_e_a_d_m_e.html#autotoc_md30", null ],
        [ "v1.0", "md__r_e_a_d_m_e.html#autotoc_md31", null ],
        [ "Kompiliavimas ir paleidimas", "md__r_e_a_d_m_e.html#autotoc_md32", [
          [ "Naudojant Makefile", "md__r_e_a_d_m_e.html#autotoc_md33", null ]
        ] ],
        [ "Kompiliuoti terminale:", "md__r_e_a_d_m_e.html#autotoc_md34", null ],
        [ "Svarbu: norint kompiliuoti deque ar list failą, privalote pakeisti konteinerio tipą į atitinkamą isvestis.h ir isvesti.cpp failuose!!!", "md__r_e_a_d_m_e.html#autotoc_md35", null ],
        [ "Class ir Struct palyginimas", "md__r_e_a_d_m_e.html#autotoc_md36", null ],
        [ "Struct", "md__r_e_a_d_m_e.html#autotoc_md37", null ],
        [ "Class", "md__r_e_a_d_m_e.html#autotoc_md38", null ],
        [ "Optimizavimo flagų palyginimas", "md__r_e_a_d_m_e.html#autotoc_md39", [
          [ "Failas: studentai1000000.txt", "md__r_e_a_d_m_e.html#autotoc_md40", null ],
          [ "Failas: studentai100000.txt", "md__r_e_a_d_m_e.html#autotoc_md41", null ]
        ] ],
        [ "v1.2", "md__r_e_a_d_m_e.html#autotoc_md42", [
          [ "Rule of Five realizacija", "md__r_e_a_d_m_e.html#autotoc_md43", null ],
          [ "Duomenų įvestis", "md__r_e_a_d_m_e.html#autotoc_md44", null ],
          [ "Duomenų išvestis", "md__r_e_a_d_m_e.html#autotoc_md45", null ],
          [ "Perkrauti operatoriai", "md__r_e_a_d_m_e.html#autotoc_md46", null ]
        ] ],
        [ "v1.5", "md__r_e_a_d_m_e.html#autotoc_md47", [
          [ "Abstrakti klasė Zmogus", "md__r_e_a_d_m_e.html#autotoc_md48", null ]
        ] ],
        [ "v2.0", "md__r_e_a_d_m_e.html#autotoc_md49", null ]
      ] ]
    ] ],
    [ "Classes", "annotated.html", [
      [ "Class List", "annotated.html", "annotated_dup" ],
      [ "Class Index", "classes.html", null ],
      [ "Class Hierarchy", "hierarchy.html", "hierarchy" ],
      [ "Class Members", "functions.html", [
        [ "All", "functions.html", null ],
        [ "Functions", "functions_func.html", null ],
        [ "Variables", "functions_vars.html", null ],
        [ "Related Symbols", "functions_rela.html", null ]
      ] ]
    ] ],
    [ "Files", "files.html", [
      [ "File List", "files.html", "files_dup" ],
      [ "File Members", "globals.html", [
        [ "All", "globals.html", null ],
        [ "Functions", "globals_func.html", null ]
      ] ]
    ] ]
  ] ]
];

var NAVTREEINDEX =
[
"annotated.html"
];

var SYNCONMSG = 'click to disable panel synchronization';
var SYNCOFFMSG = 'click to enable panel synchronization';
var LISTOFALLMEMBERS = 'List of all members';