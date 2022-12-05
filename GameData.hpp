// !! means that the information has not been collected yet.
// Outdated. New roles added.
#pragma once

namespace roles {

	namespace goose {

		constexpr int Goose = 0x1;
		constexpr int Birdwatcher = 0x16;
		constexpr int Canadian = 0xD;
		constexpr int Detective = 0x14;
		constexpr int Gravy = 0x4;
		constexpr int Mechanic = 0xAF5;  // !!
		constexpr int Medium = 0x7;
		constexpr int Sherrif = 0xB;
		constexpr int Snoop = 0x5;
		constexpr int Tech = 0x6;
		constexpr int Vigilante = 0x8;
		constexpr int Celebrity = 0x1F;
		constexpr int Bodyguard = 0xCFC;  // !!
		constexpr int Politician = 0x1C;
		constexpr int Locksmith = 0xDBC;  // !!
		constexpr int Mortician = 0x1E;
		constexpr int Mimic = 0x13;
		constexpr int Lover = 0xF; // ¶ì

	}

	namespace duck {

		constexpr int Assassin = 0x17;
		constexpr int Duck = 0x2;
		constexpr int Cannibal = 0x9;
		constexpr int Professional = 0x11;
		constexpr int Silencer = 0xC;
		constexpr int Spy = 0x12;
		constexpr int Morphling = 0xA;
		constexpr int Hitman = 0xDEC;  // !!
		constexpr int Snitch = 0x1B;
		constexpr int Party = 0xEAC;  // !!
		constexpr int Demolitionist = 0x21;
		constexpr int Lover = 0xE; // Ñ¼

	}

	namespace Neutrality {

		constexpr int Pigeon = 0x15;
		constexpr int Vulture = 0x10;
		constexpr int Falcon = 0x18;
		constexpr int Dodo = 0x3;
		constexpr int NoRole = -1;

	}

	namespace halloween {

		constexpr int Villager = 0xEDF; // !!
		constexpr int Vampire = 0xEFF; // !!
		constexpr int Thrall = 0xFAF; // !!

	}

}

namespace colors { // enum must look cool~
	constexpr int red = 0;
	constexpr int blue = 1;
	constexpr int yellow = 2;
	constexpr int green = 3;
	constexpr int powerderPink = 4;
	constexpr int orange = 5;
	constexpr int paleBrown = 6;
	constexpr int white = 7;
	constexpr int darkGray = 8;
	constexpr int purple = 9;
	constexpr int lime = 10;
	constexpr int skyBlue = 11;
	constexpr int pink = 12;
	constexpr int gray = 13;
	constexpr int brown = 14;
	constexpr int darkNavy = 15;
	constexpr int olive = 16;
	constexpr int black = 17;
	constexpr int wineRed = 18;
	constexpr int beige = 19;
}

enum gameStateCode
{
	InLobby,
	Drafting,
	InGame,
	Opening, // Before Discussion
	Discussion,
	Voting,
	Waiting,
	Proceeding
};

enum gameRoleId
{
	None,
	Goose,
	Duck,
	Dodo,
	Bounty,
	Mechanic,
	Technician,
	Medium,
	Vigilante,
	Cannibal,
	Morphling,
	Sheriff,
	Silencer,
	Canadian,
	LoverDuck,
	LoverGoose,
	Vulture,
	Professional,
	Spy,
	Mimic,
	Detective,
	Pigeon,
	Birdwatcher,
	Assassin,
	Falcon,
	Hitman,
	Bodyguard,
	Snitch,
	Politician,
	Locksmith,
	Mortician,
	Celebrity,
	Party,
	Demolitionist,
	DuelingDodo,
	GHGoose,
	GHDuck,
	GHBounty,
	HNSGoose,
	HNSDuck,
	HNSBounty,
	DNDDuck,
	DNDFalcon,
	DNDVulture,
	DNDMorphling,
	FPGoose,
	ExploreGoose,
	TTVampire,
	TTPeasant,
	TTThrall,
	Spectator,
	IdentityThief,
	Adventurer,
	Avenger,
	Ninja,
	Undertaker,
	Snoop,
	Esper,
	Invisibility,
	Astral,
	Pelican,
	TTEThrall,
	TTMummy,
	SerialKiller,
	Engineer
};

/*
*  Managers.PlayerManagers.PlayerRolesManager

public enum GCKOOHMKNFO : short
{
	// Token: 0x040014DC RID: 5340
	[Token(Token = "0x40014DC")]
	None,
	// Token: 0x040014DD RID: 5341
	[Token(Token = "0x40014DD")]
	Goose,
	// Token: 0x040014DE RID: 5342
	[Token(Token = "0x40014DE")]
	Duck,
	// Token: 0x040014DF RID: 5343
	[Token(Token = "0x40014DF")]
	Dodo,
	// Token: 0x040014E0 RID: 5344
	[Token(Token = "0x40014E0")]
	Bounty,
	// Token: 0x040014E1 RID: 5345
	[Token(Token = "0x40014E1")]
	Mechanic,
	// Token: 0x040014E2 RID: 5346
	[Token(Token = "0x40014E2")]
	Technician,
	// Token: 0x040014E3 RID: 5347
	[Token(Token = "0x40014E3")]
	Medium,
	// Token: 0x040014E4 RID: 5348
	[Token(Token = "0x40014E4")]
	Vigilante,
	// Token: 0x040014E5 RID: 5349
	[Token(Token = "0x40014E5")]
	Cannibal,
	// Token: 0x040014E6 RID: 5350
	[Token(Token = "0x40014E6")]
	Morphling,
	// Token: 0x040014E7 RID: 5351
	[Token(Token = "0x40014E7")]
	Sheriff,
	// Token: 0x040014E8 RID: 5352
	[Token(Token = "0x40014E8")]
	Silencer,
	// Token: 0x040014E9 RID: 5353
	[Token(Token = "0x40014E9")]
	Canadian,
	// Token: 0x040014EA RID: 5354
	[Token(Token = "0x40014EA")]
	LoverDuck,
	// Token: 0x040014EB RID: 5355
	[Token(Token = "0x40014EB")]
	LoverGoose,
	// Token: 0x040014EC RID: 5356
	[Token(Token = "0x40014EC")]
	Vulture,
	// Token: 0x040014ED RID: 5357
	[Token(Token = "0x40014ED")]
	Professional,
	// Token: 0x040014EE RID: 5358
	[Token(Token = "0x40014EE")]
	Spy,
	// Token: 0x040014EF RID: 5359
	[Token(Token = "0x40014EF")]
	Mimic,
	// Token: 0x040014F0 RID: 5360
	[Token(Token = "0x40014F0")]
	Detective,
	// Token: 0x040014F1 RID: 5361
	[Token(Token = "0x40014F1")]
	Pigeon,
	// Token: 0x040014F2 RID: 5362
	[Token(Token = "0x40014F2")]
	Birdwatcher,
	// Token: 0x040014F3 RID: 5363
	[Token(Token = "0x40014F3")]
	Assassin,
	// Token: 0x040014F4 RID: 5364
	[Token(Token = "0x40014F4")]
	Falcon,
	// Token: 0x040014F5 RID: 5365
	[Token(Token = "0x40014F5")]
	Hitman,
	// Token: 0x040014F6 RID: 5366
	[Token(Token = "0x40014F6")]
	Bodyguard,
	// Token: 0x040014F7 RID: 5367
	[Token(Token = "0x40014F7")]
	Snitch,
	// Token: 0x040014F8 RID: 5368
	[Token(Token = "0x40014F8")]
	Politician,
	// Token: 0x040014F9 RID: 5369
	[Token(Token = "0x40014F9")]
	Locksmith,
	// Token: 0x040014FA RID: 5370
	[Token(Token = "0x40014FA")]
	Mortician,
	// Token: 0x040014FB RID: 5371
	[Token(Token = "0x40014FB")]
	Celebrity,
	// Token: 0x040014FC RID: 5372
	[Token(Token = "0x40014FC")]
	Party,
	// Token: 0x040014FD RID: 5373
	[Token(Token = "0x40014FD")]
	Demolitionist,
	// Token: 0x040014FE RID: 5374
	[Token(Token = "0x40014FE")]
	DuelingDodo,
	// Token: 0x040014FF RID: 5375
	[Token(Token = "0x40014FF")]
	GHGoose,
	// Token: 0x04001500 RID: 5376
	[Token(Token = "0x4001500")]
	GHDuck,
	// Token: 0x04001501 RID: 5377
	[Token(Token = "0x4001501")]
	GHBounty,
	// Token: 0x04001502 RID: 5378
	[Token(Token = "0x4001502")]
	HNSGoose,
	// Token: 0x04001503 RID: 5379
	[Token(Token = "0x4001503")]
	HNSDuck,
	// Token: 0x04001504 RID: 5380
	[Token(Token = "0x4001504")]
	HNSBounty,
	// Token: 0x04001505 RID: 5381
	[Token(Token = "0x4001505")]
	DNDDuck,
	// Token: 0x04001506 RID: 5382
	[Token(Token = "0x4001506")]
	DNDFalcon,
	// Token: 0x04001507 RID: 5383
	[Token(Token = "0x4001507")]
	DNDVulture,
	// Token: 0x04001508 RID: 5384
	[Token(Token = "0x4001508")]
	DNDMorphling,
	// Token: 0x04001509 RID: 5385
	[Token(Token = "0x4001509")]
	FPGoose,
	// Token: 0x0400150A RID: 5386
	[Token(Token = "0x400150A")]
	ExploreGoose,
	// Token: 0x0400150B RID: 5387
	[Token(Token = "0x400150B")]
	TTVampire,
	// Token: 0x0400150C RID: 5388
	[Token(Token = "0x400150C")]
	TTPeasant,
	// Token: 0x0400150D RID: 5389
	[Token(Token = "0x400150D")]
	TTThrall,
	// Token: 0x0400150E RID: 5390
	[Token(Token = "0x400150E")]
	Spectator,
	// Token: 0x0400150F RID: 5391
	[Token(Token = "0x400150F")]
	IdentityThief,
	// Token: 0x04001510 RID: 5392
	[Token(Token = "0x4001510")]
	Adventurer,
	// Token: 0x04001511 RID: 5393
	[Token(Token = "0x4001511")]
	Avenger,
	// Token: 0x04001512 RID: 5394
	[Token(Token = "0x4001512")]
	Ninja,
	// Token: 0x04001513 RID: 5395
	[Token(Token = "0x4001513")]
	Undertaker,
	// Token: 0x04001514 RID: 5396
	[Token(Token = "0x4001514")]
	Snoop,
	// Token: 0x04001515 RID: 5397
	[Token(Token = "0x4001515")]
	Esper,
	// Token: 0x04001516 RID: 5398
	[Token(Token = "0x4001516")]
	Invisibility,
	// Token: 0x04001517 RID: 5399
	[Token(Token = "0x4001517")]
	Astral,
	// Token: 0x04001518 RID: 5400
	[Token(Token = "0x4001518")]
	Pelican,
	// Token: 0x04001519 RID: 5401
	[Token(Token = "0x4001519")]
	TTEThrall,
	// Token: 0x0400151A RID: 5402
	[Token(Token = "0x400151A")]
	TTMummy

*/