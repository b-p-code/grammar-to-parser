
void A() { 
if (tk.ID == a || tk.ID == b) {
tk = scanner();
B();
} else if (tk.ID == c) {
C();
}  else { error(); }
}
void B() { 
if (tk.ID == a) {
tk = scanner();
} else if (tk.ID == b) {
tk = scanner();
}  else { error(); }
}
void C() { 
if (tk.ID == c) {
tk = scanner();
B();
} else if (tk.ID == c) {
tk = scanner();
}  else { error(); }
}