#include "protocol.h"
#include "protocol_items.h"

Event_ConnectionStateChanged::Event_ConnectionStateChanged(int _playerId, bool _connected)
	: GameEvent("connection_state_changed", _playerId)
{
	insertItem(new SerializableItem_Bool("connected", _connected));
}
Event_Say::Event_Say(int _playerId, const QString &_message)
	: GameEvent("say", _playerId)
{
	insertItem(new SerializableItem_String("message", _message));
}
Event_Leave::Event_Leave(int _playerId)
	: GameEvent("leave", _playerId)
{
}
Event_GameClosed::Event_GameClosed(int _playerId)
	: GameEvent("game_closed", _playerId)
{
}
Event_GameHostChanged::Event_GameHostChanged(int _playerId)
	: GameEvent("game_host_changed", _playerId)
{
}
Event_Kicked::Event_Kicked(int _playerId)
	: GameEvent("kicked", _playerId)
{
}
Event_Shuffle::Event_Shuffle(int _playerId)
	: GameEvent("shuffle", _playerId)
{
}
Event_RollDie::Event_RollDie(int _playerId, int _sides, int _value)
	: GameEvent("roll_die", _playerId)
{
	insertItem(new SerializableItem_Int("sides", _sides));
	insertItem(new SerializableItem_Int("value", _value));
}
Event_MoveCard::Event_MoveCard(int _playerId, int _cardId, const QString &_cardName, const QString &_startZone, int _position, int _targetPlayerId, const QString &_targetZone, int _x, int _y, int _newCardId, bool _faceDown)
	: GameEvent("move_card", _playerId)
{
	insertItem(new SerializableItem_Int("card_id", _cardId));
	insertItem(new SerializableItem_String("card_name", _cardName));
	insertItem(new SerializableItem_String("start_zone", _startZone));
	insertItem(new SerializableItem_Int("position", _position));
	insertItem(new SerializableItem_Int("target_player_id", _targetPlayerId));
	insertItem(new SerializableItem_String("target_zone", _targetZone));
	insertItem(new SerializableItem_Int("x", _x));
	insertItem(new SerializableItem_Int("y", _y));
	insertItem(new SerializableItem_Int("new_card_id", _newCardId));
	insertItem(new SerializableItem_Bool("face_down", _faceDown));
}
Event_FlipCard::Event_FlipCard(int _playerId, const QString &_zone, int _cardId, const QString &_cardName, bool _faceDown)
	: GameEvent("flip_card", _playerId)
{
	insertItem(new SerializableItem_String("zone", _zone));
	insertItem(new SerializableItem_Int("card_id", _cardId));
	insertItem(new SerializableItem_String("card_name", _cardName));
	insertItem(new SerializableItem_Bool("face_down", _faceDown));
}
Event_DestroyCard::Event_DestroyCard(int _playerId, const QString &_zone, int _cardId)
	: GameEvent("destroy_card", _playerId)
{
	insertItem(new SerializableItem_String("zone", _zone));
	insertItem(new SerializableItem_Int("card_id", _cardId));
}
Event_AttachCard::Event_AttachCard(int _playerId, const QString &_startZone, int _cardId, int _targetPlayerId, const QString &_targetZone, int _targetCardId)
	: GameEvent("attach_card", _playerId)
{
	insertItem(new SerializableItem_String("start_zone", _startZone));
	insertItem(new SerializableItem_Int("card_id", _cardId));
	insertItem(new SerializableItem_Int("target_player_id", _targetPlayerId));
	insertItem(new SerializableItem_String("target_zone", _targetZone));
	insertItem(new SerializableItem_Int("target_card_id", _targetCardId));
}
Event_CreateToken::Event_CreateToken(int _playerId, const QString &_zone, int _cardId, const QString &_cardName, const QString &_color, const QString &_pt, const QString &_annotation, bool _destroyOnZoneChange, int _x, int _y)
	: GameEvent("create_token", _playerId)
{
	insertItem(new SerializableItem_String("zone", _zone));
	insertItem(new SerializableItem_Int("card_id", _cardId));
	insertItem(new SerializableItem_String("card_name", _cardName));
	insertItem(new SerializableItem_String("color", _color));
	insertItem(new SerializableItem_String("pt", _pt));
	insertItem(new SerializableItem_String("annotation", _annotation));
	insertItem(new SerializableItem_Bool("destroy_on_zone_change", _destroyOnZoneChange));
	insertItem(new SerializableItem_Int("x", _x));
	insertItem(new SerializableItem_Int("y", _y));
}
Event_DeleteArrow::Event_DeleteArrow(int _playerId, int _arrowId)
	: GameEvent("delete_arrow", _playerId)
{
	insertItem(new SerializableItem_Int("arrow_id", _arrowId));
}
Event_SetCardAttr::Event_SetCardAttr(int _playerId, const QString &_zone, int _cardId, const QString &_attrName, const QString &_attrValue)
	: GameEvent("set_card_attr", _playerId)
{
	insertItem(new SerializableItem_String("zone", _zone));
	insertItem(new SerializableItem_Int("card_id", _cardId));
	insertItem(new SerializableItem_String("attr_name", _attrName));
	insertItem(new SerializableItem_String("attr_value", _attrValue));
}
Event_SetCardCounter::Event_SetCardCounter(int _playerId, const QString &_zone, int _cardId, int _counterId, int _counterValue)
	: GameEvent("set_card_counter", _playerId)
{
	insertItem(new SerializableItem_String("zone", _zone));
	insertItem(new SerializableItem_Int("card_id", _cardId));
	insertItem(new SerializableItem_Int("counter_id", _counterId));
	insertItem(new SerializableItem_Int("counter_value", _counterValue));
}
Event_SetCounter::Event_SetCounter(int _playerId, int _counterId, int _value)
	: GameEvent("set_counter", _playerId)
{
	insertItem(new SerializableItem_Int("counter_id", _counterId));
	insertItem(new SerializableItem_Int("value", _value));
}
Event_DelCounter::Event_DelCounter(int _playerId, int _counterId)
	: GameEvent("del_counter", _playerId)
{
	insertItem(new SerializableItem_Int("counter_id", _counterId));
}
Event_SetActivePlayer::Event_SetActivePlayer(int _playerId, int _activePlayerId)
	: GameEvent("set_active_player", _playerId)
{
	insertItem(new SerializableItem_Int("active_player_id", _activePlayerId));
}
Event_SetActivePhase::Event_SetActivePhase(int _playerId, int _phase)
	: GameEvent("set_active_phase", _playerId)
{
	insertItem(new SerializableItem_Int("phase", _phase));
}
Event_DumpZone::Event_DumpZone(int _playerId, int _zoneOwnerId, const QString &_zone, int _numberCards)
	: GameEvent("dump_zone", _playerId)
{
	insertItem(new SerializableItem_Int("zone_owner_id", _zoneOwnerId));
	insertItem(new SerializableItem_String("zone", _zone));
	insertItem(new SerializableItem_Int("number_cards", _numberCards));
}
Event_StopDumpZone::Event_StopDumpZone(int _playerId, int _zoneOwnerId, const QString &_zone)
	: GameEvent("stop_dump_zone", _playerId)
{
	insertItem(new SerializableItem_Int("zone_owner_id", _zoneOwnerId));
	insertItem(new SerializableItem_String("zone", _zone));
}
Event_RemoveFromList::Event_RemoveFromList(const QString &_list, const QString &_userName)
	: GenericEvent("remove_from_list")
{
	insertItem(new SerializableItem_String("list", _list));
	insertItem(new SerializableItem_String("user_name", _userName));
}
Event_ServerMessage::Event_ServerMessage(const QString &_message)
	: GenericEvent("server_message")
{
	insertItem(new SerializableItem_String("message", _message));
}
Event_ServerShutdown::Event_ServerShutdown(const QString &_reason, int _minutes)
	: GenericEvent("server_shutdown")
{
	insertItem(new SerializableItem_String("reason", _reason));
	insertItem(new SerializableItem_Int("minutes", _minutes));
}
Event_ConnectionClosed::Event_ConnectionClosed(const QString &_reason)
	: GenericEvent("connection_closed")
{
	insertItem(new SerializableItem_String("reason", _reason));
}
Event_Message::Event_Message(const QString &_senderName, const QString &_receiverName, const QString &_text)
	: GenericEvent("message")
{
	insertItem(new SerializableItem_String("sender_name", _senderName));
	insertItem(new SerializableItem_String("receiver_name", _receiverName));
	insertItem(new SerializableItem_String("text", _text));
}
Event_GameJoined::Event_GameJoined(int _gameId, const QString &_gameDescription, int _hostId, int _playerId, bool _spectator, bool _spectatorsCanTalk, bool _spectatorsSeeEverything, bool _resuming)
	: GenericEvent("game_joined")
{
	insertItem(new SerializableItem_Int("game_id", _gameId));
	insertItem(new SerializableItem_String("game_description", _gameDescription));
	insertItem(new SerializableItem_Int("host_id", _hostId));
	insertItem(new SerializableItem_Int("player_id", _playerId));
	insertItem(new SerializableItem_Bool("spectator", _spectator));
	insertItem(new SerializableItem_Bool("spectators_can_talk", _spectatorsCanTalk));
	insertItem(new SerializableItem_Bool("spectators_see_everything", _spectatorsSeeEverything));
	insertItem(new SerializableItem_Bool("resuming", _resuming));
}
Event_UserLeft::Event_UserLeft(const QString &_userName)
	: GenericEvent("user_left")
{
	insertItem(new SerializableItem_String("user_name", _userName));
}
Event_LeaveRoom::Event_LeaveRoom(int _roomId, const QString &_playerName)
	: RoomEvent("leave_room", _roomId)
{
	insertItem(new SerializableItem_String("player_name", _playerName));
}
Event_RoomSay::Event_RoomSay(int _roomId, const QString &_playerName, const QString &_message)
	: RoomEvent("room_say", _roomId)
{
	insertItem(new SerializableItem_String("player_name", _playerName));
	insertItem(new SerializableItem_String("message", _message));
}
Context_ReadyStart::Context_ReadyStart()
	: GameEventContext("ready_start")
{
}
Context_Concede::Context_Concede()
	: GameEventContext("concede")
{
}
Context_DeckSelect::Context_DeckSelect(const QString &_deckHash)
	: GameEventContext("deck_select")
{
	insertItem(new SerializableItem_String("deck_hash", _deckHash));
}
Context_UndoDraw::Context_UndoDraw()
	: GameEventContext("undo_draw")
{
}
Context_MoveCard::Context_MoveCard()
	: GameEventContext("move_card")
{
}
Context_Mulligan::Context_Mulligan(int _number)
	: GameEventContext("mulligan")
{
	insertItem(new SerializableItem_Int("number", _number));
}
void ProtocolItem::initializeHashAuto()
{
	itemNameHash.insert("game_eventconnection_state_changed", Event_ConnectionStateChanged::newItem);
	itemNameHash.insert("game_eventsay", Event_Say::newItem);
	itemNameHash.insert("game_eventleave", Event_Leave::newItem);
	itemNameHash.insert("game_eventgame_closed", Event_GameClosed::newItem);
	itemNameHash.insert("game_eventgame_host_changed", Event_GameHostChanged::newItem);
	itemNameHash.insert("game_eventkicked", Event_Kicked::newItem);
	itemNameHash.insert("game_eventshuffle", Event_Shuffle::newItem);
	itemNameHash.insert("game_eventroll_die", Event_RollDie::newItem);
	itemNameHash.insert("game_eventmove_card", Event_MoveCard::newItem);
	itemNameHash.insert("game_eventflip_card", Event_FlipCard::newItem);
	itemNameHash.insert("game_eventdestroy_card", Event_DestroyCard::newItem);
	itemNameHash.insert("game_eventattach_card", Event_AttachCard::newItem);
	itemNameHash.insert("game_eventcreate_token", Event_CreateToken::newItem);
	itemNameHash.insert("game_eventdelete_arrow", Event_DeleteArrow::newItem);
	itemNameHash.insert("game_eventset_card_attr", Event_SetCardAttr::newItem);
	itemNameHash.insert("game_eventset_card_counter", Event_SetCardCounter::newItem);
	itemNameHash.insert("game_eventset_counter", Event_SetCounter::newItem);
	itemNameHash.insert("game_eventdel_counter", Event_DelCounter::newItem);
	itemNameHash.insert("game_eventset_active_player", Event_SetActivePlayer::newItem);
	itemNameHash.insert("game_eventset_active_phase", Event_SetActivePhase::newItem);
	itemNameHash.insert("game_eventdump_zone", Event_DumpZone::newItem);
	itemNameHash.insert("game_eventstop_dump_zone", Event_StopDumpZone::newItem);
	itemNameHash.insert("generic_eventremove_from_list", Event_RemoveFromList::newItem);
	itemNameHash.insert("generic_eventserver_message", Event_ServerMessage::newItem);
	itemNameHash.insert("generic_eventserver_shutdown", Event_ServerShutdown::newItem);
	itemNameHash.insert("generic_eventconnection_closed", Event_ConnectionClosed::newItem);
	itemNameHash.insert("generic_eventmessage", Event_Message::newItem);
	itemNameHash.insert("generic_eventgame_joined", Event_GameJoined::newItem);
	itemNameHash.insert("generic_eventuser_left", Event_UserLeft::newItem);
	itemNameHash.insert("room_eventleave_room", Event_LeaveRoom::newItem);
	itemNameHash.insert("room_eventroom_say", Event_RoomSay::newItem);
	itemNameHash.insert("game_event_contextready_start", Context_ReadyStart::newItem);
	itemNameHash.insert("game_event_contextconcede", Context_Concede::newItem);
	itemNameHash.insert("game_event_contextdeck_select", Context_DeckSelect::newItem);
	itemNameHash.insert("game_event_contextundo_draw", Context_UndoDraw::newItem);
	itemNameHash.insert("game_event_contextmove_card", Context_MoveCard::newItem);
	itemNameHash.insert("game_event_contextmulligan", Context_Mulligan::newItem);
}
