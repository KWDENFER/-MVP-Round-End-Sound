/*
* Hello, dude! This is my include file and I use it to include 
* special functions in my projects.
* If you need one of my functions or this library is useful to you, 
* then you can copy this or that function or include this library is in your project.
*
* by: DENFER © 2020
*
* https://github.com/KWDENFER
* https://vk.com/denferez
* https://steamcommunity.com/id/denferez
* https://hlmod.ru/members/denfer.126978/
* https://forums.alliedmods.net/member.php?u=306308
*
*/

#if defined _denfer_included
 #endinput
#endif
#define _denfer_included

#define MAX_ENTITIES 4096
#define MAX_EDICTS 2048

/* *******************************************************
 *
 *   					CLIENT 
 *
 * ******************************************************** */
 
 /* *******************************************************		** ************************************************************ 
 *	Pre-cache the audio file and adds a file to the 			*	Проверяет, является ли игрок валидным (действительным).
 *	downloadables network string table.							*	
 *																*
 *	@param1	- Player index. 						 			*	@param1	- Индекс игрока.
 *																*
 *	@return - true if the player is on the server 				*	@return - истина, если игрок на сервере и валиден, иначе	
 *	and is valid, false otherwise.								*	ложь.
 * ******************************************************** 	* ********************************************************** */	
 stock bool IsValidClient(int client)
 {
	if(client <= 0 || client > MaxClients)
	{
		return false;
	}
	
	if(!IsClientInGame(client) || !IsClientAuthorized(client))
	{
		return false;
	}
	
	return true;
 }
 
 /* *******************************************************		** ************************************************************ 
 *	Checks if the player is not a bot (not a fake player). 		*	Проверяет, является ли игрок не ботов (не фейковый игрок).
 *																*													
 *	@param1	- Player index. 						 			*	@param1	- Индекс игрока.
 *																*
 *	@return - true if the player is a bot and is valid,  		*	@return - истина, если игрок бот и валиден, иначе	
 *	false otherwise.											*	ложь.
 * ******************************************************** 	* ********************************************************** */	
 
 stock bool IsBotClient(int client)
 {
	if(IsFakeClient(client) || IsClientSourceTV(client) || IsClientReplay(client))
	{
		return true;
	}
	
	return false;
 }

/* *******************************************************
 *
 *   					SOUND 
 *
 * ******************************************************** */
 
 /* *******************************************************		** ************************************************************ 
 *	Pre-cache the audio file and adds a file to the 			*	Предварительно кэшируйте аудифайл и добавляйте файл 
 *	downloadables network string table.							*	в таблицу строк (Network String Table) загружаемых файлов.
 *																*
 *	String tables are a very simple and efficient				*	Строковые таблицы - это очень простой и эффективный 								
 *	way to transmit larger blocks of text strings 				*	способ передачи определенных ресурсов (звуковые файлы, 
 *	(material or resource names etc).							*	материалы, модели и т.д.).
 *																*
 *	@param1	- The path to the sound file. Path must 			*	@param1	- Путь к звуковому файлу. Путь должен начинаться 
 *	start after "sound/...".									*	после "sound/...".	
 *																*
 *	@return - none.												*	@return - ничего не возвращает.	
 *																*
 * ******************************************************** 	* ********************************************************** */	
stock void PrecacheAndDownloadSoundFile(const char[] path) 
{
	if(strlen(path) == 0)
	{
		LogError("You specified an empty path to the sound file! * Вы указали пустой путь к звуковому файлу! *");
		return;
	}
	
	char buffer[PLATFORM_MAX_PATH];
	PrecacheSound(path, true);
	Format(buffer, sizeof(buffer), "sound/%s", path);
	AddFileToDownloadsTable(buffer);
}