
void A() { 
if (tk.ID == a) {
if (tk.ID == a) {
tk = scanner();
B();
} else { error(); }
} else if (tk.ID == c) {
C();
}  else { error(); }
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
}  else { error(); }
}
void C() { 
if (tk.ID == c) {
if (tk.ID == c) {
tk = scanner();
B();
} else { error(); }
} else if (tk.ID == c) {
if (tk.ID == c) {
tk = scanner();
} else { error(); }
}  else { error(); }
}