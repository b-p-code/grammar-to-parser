
void A() { 
if (tk.ID == a || tk.ID == b || tk.ID == c) {
B();
} else if (tk.ID == d || tk.ID == e) {
D();
}  else { return; }
}
void B() { 
if (tk.ID == a) {
tk = scanner();
} else if (tk.ID == b) {
tk = scanner();
}  else if (tk.ID == c) {
C();
}  else { error(); }
}
void C() { 
if (tk.ID == f) {
tk = scanner();
} else { error(); }
}
void D() { 
if (tk.ID == d) {
tk = scanner();
} else if (tk.ID == e) {
tk = scanner();
}  else { error(); }
}
void E() { 
if (tk.ID == g) {
tk = scanner();
} else { error(); }
}