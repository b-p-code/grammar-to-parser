
void S() { 
if (tk.ID == thisTK || tk.ID == thatTK) {
R();
} else if (tk.ID == hiTK) {
Q();
}  else { error(); }
}
void R() { 
if (tk.ID == thisTK) {
if (tk.ID == thisTK) {
tk = scanner();
} else { error(); }
} else if (tk.ID == thatTK) {
if (tk.ID == thatTk) {
tk = scanner();
} else { error(); }
}  else { error(); }
}
void Q() { 
if (tk.ID == hiTK) {
if (tk.ID == hiTK) {
tk = scanner();
R();
} else { error(); }
} else if (tk.ID == hiTK) {
if (tk.ID == hiTK) {
tk = scanner();
} else { error(); }
}  else { error(); }
}