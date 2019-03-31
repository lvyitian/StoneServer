#include "../patched.h"

#include <minecraft/Level.h>
#include <minecraft/Minecraft.h>
#include <minecraft/MinecraftCommands.h>
#include <minecraft/ServerInstance.h>

#include <stone/server_hook.h>

#include <interface/locator.hpp>
#include <interface/player_list.h>

namespace {

SInstanceHook(void, _ZN27ServerLevelEventCoordinator20sendLevelAddedPlayerER5LevelR6Player, ServerLevelEventCoordinator, Level *level, Player *player) {
  using namespace interface;
  Locator<PlayerList>()->onPlayerAdded(*player);
  original(this, level, player);
}

SInstanceHook(void, _ZN20ServerNetworkHandler13_onPlayerLeftEP12ServerPlayerb, ServerLevelEventCoordinator, Player *player, bool opt) {
  using namespace interface;
  Locator<PlayerList>()->onPlayerRemoved(*player);
  original(this, player, opt);
}

static patched::details::RegisterPatchInit pinit([] {
  using namespace interface;
  Locator<PlayerList>().generate<>();
});

} // namespace