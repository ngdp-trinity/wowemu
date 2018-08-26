﻿#include "ScriptMgr.h"
#include "Creature.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "WorldSession.h"

class MultivendorExample : public CreatureScript
{
public:
    MultivendorExample() : CreatureScript("MultivendorExample") {}

    struct MultivendorAI : public ScriptedAI
    {
        MultivendorAI(Creature* creature) : ScriptedAI(creature) {}

        bool GossipHello(Player* player) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "TrainerTest 2489", GOSSIP_SENDER_MAIN, 2489);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "TrainerTest 2704", GOSSIP_SENDER_MAIN, 2704);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, me);
            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            player->GetSession()->SendTrainerList(me->GetGUID(), action);
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new MultivendorAI(creature);
    }
};

void AddSC_Multivendor()
{
    new MultivendorExample();
}
