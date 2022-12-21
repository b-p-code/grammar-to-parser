
void A() { 
if (tk.ID == a || tk.ID == b || tk.ID == c) {
B();
C();
} else if (tk.ID == d || tk.ID == e) {
D();
E();
}  else { return; }
}
void B() { 
if (tk.ID == a) {
if (tk.ID == a) {
tk = scanner();
} else { error(); }
} else if (tk.ID == b) {
if (tk.ID == b) {
tk = scanner();
} else { error(); }
}  else if (tk.ID == c) {
C();
}  else { error(); }
}
void C() { 
if (tk.ID == f) {
if (tk.ID == f) {
tk = scanner();
} else { error(); }
} else { error(); }
}
void D() { 
if (tk.ID == d) {
if (tk.ID == d) {
tk = scanner();
} else { error(); }
} else if (tk.ID == e) {
if (tk.ID == e) {
tk = scanner();
} else { error(); }
}  else { error(); }
}
void E() { 
if (tk.ID == g) {
if (tk.ID == g) {
tk = scanner();
} else { error(); }
} else { error(); }
}