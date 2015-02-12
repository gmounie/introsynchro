with Ada.Text_IO; use Ada.Text_IO;
with Ada.Real_Time; use Ada.Real_Time;

procedure startAda is
   task type Hello(I: Integer);
   task body Hello is
   begin
      Put_Line("Hello from " & Integer'Image(I));
      delay 5.0;
   end;
   C: array(0..9) of access Hello;
begin
   for I in 0..9 loop
      C(I) := new Hello(I);
   end loop;
   null;
end;
