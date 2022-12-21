
void S() { 
if (tk.ID == thisTK || tk.ID == thatTK) {
R();
} else if (tk.ID == hiTK) {
Q();
}  else { error(); }
}
void R() { 
if (tk.ID == thisTK) {
tk = scanner();
} else if (tk.ID == thatTK) {
tk = scanner();
}  else { error(); }
}
void Q() { 
if (tk.ID == hiTK) {
tk = scanner();
R();
} else if (tk.ID == hiTK) {
tk = scanner();
}  else { error(); }
}