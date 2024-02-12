all: main.o Player.o Player_Referance.o Cell.o Field.o Point.o Negative_Event.o Positive_Event.o Move_Event.o Field_builder.o Game.o Read_Command.o Render.o Listener.o Terminal_Command.o Key_Not_Trigger_Message.o Key_Trigger_Message.o Lose_Message.o New_Message.o Win_Message.o Message_Interface.o OutputInterface.o FileOutput.o ConsoleOutput.o LogOutput.o
	g++ main.o Player.o Player_Referance.o Cell.o Field.o Point.o Negative_Event.o Positive_Event.o Move_Event.o Field_builder.o Game.o Read_Command.o Render.o Listener.o Terminal_Command.o Key_Not_Trigger_Message.o Key_Trigger_Message.o Lose_Message.o New_Message.o Win_Message.o Message_Interface.o OutputInterface.o FileOutput.o ConsoleOutput.o LogOutput.o -o main
all: Lose_Message.o
main.o: main.cpp
	g++ -c main.cpp
Player.o: player/Player/Player.cpp
	g++ -c  player/Player/Player.cpp
Player_Referance.o: player/Player_Referance/Player_Referance.cpp
	g++ -c player/Player_Referance/Player_Referance.cpp
Cell.o: field/Cell/Cell.cpp
	g++ -c field/Cell/Cell.cpp
Field.o: field/Field/Field.cpp
	g++ -c field/Field/Field.cpp
Point.o: field/Point/Point.cpp
	g++ -c field/Point/Point.cpp
Negative_Event.o: interface/Negative_Event/Negative_Event.cpp
	g++ -c interface/Negative_Event/Negative_Event.cpp
Positive_Event.o: interface/Positive_Event/Positive_Event.cpp
	g++ -c interface/Positive_Event/Positive_Event.cpp
Move_Event.o: interface/Move_Event/Move_Event.cpp
	g++ -c interface/Move_Event/Move_Event.cpp
Field_builder.o: field/Field_Builder/Field_builder.cpp
	g++ -c field/Field_Builder/Field_builder.cpp
Game.o: game/Game/Game.cpp
	g++ -c game/Game/Game.cpp
Read_Command.o: game/Read_Command/Read_Command.cpp
	g++ -c game/Read_Command/Read_Command.cpp
Render.o: game/Draw_map/Render.cpp
	g++ -c game/Draw_map/Render.cpp
Listener.o: game/Tracking/Listener.cpp
	g++ -c game/Tracking/Listener.cpp
Terminal_Command.o: game/Terminal_Command/Terminal_Command.cpp
	g++ -c game/Terminal_Command/Terminal_Command.cpp
Key_Not_Trigger_Message.o: game/Message/Key_Not_Trigger_Message/Key_Not_Trigger_Message.cpp
	g++ -c game/Message/Key_Not_Trigger_Message/Key_Not_Trigger_Message.cpp
Key_Trigger_Message.o: game/Message/Key_Trigger_Message/Key_Trigger_Message.cpp
	g++ -c game/Message/Key_Trigger_Message/Key_Trigger_Message.cpp
Lose_Message.o: game/Message/Lose_Message/Lose_Message.cpp
	g++ -c game/Message/Lose_Message/Lose_Message.cpp
New_Message.o: game/Message/New_Message/New_Message.cpp
	g++ -c game/Message/New_Message/New_Message.cpp
Win_Message.o: game/Message/Win_Message/Win_Message.cpp
	g++ -c game/Message/Win_Message/Win_Message.cpp
Message_Interface.o: game/Message/Message_Interface/Message_Interface.cpp
	g++ -c game/Message/Message_Interface/Message_Interface.cpp

OutputInterface.o : game/Message/Output_Interfaces/OutputInterface.cpp
	g++ -c game/Message/Output_Interfaces/OutputInterface.cpp

FileOutput.o : game/Message/Output_Interfaces/FileOutput.cpp
	g++ -c game/Message/Output_Interfaces/FileOutput.cpp
ConsoleOutput.o : game/Message/Output_Interfaces/ConsoleOutput.cpp
	g++ -c game/Message/Output_Interfaces/ConsoleOutput.cpp

LogOutput.o : game/Message/LogOutput.cpp
	g++ -c game/Message/LogOutput.cpp
