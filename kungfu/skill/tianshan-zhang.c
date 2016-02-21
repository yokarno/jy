// tianshan-zhang.c, based on dagou-bang.c
// by yucao
// Modified by Hop 97.01.05
// Added by Yzuo 97.04.08

inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ��һ�С����ӿ�����������$w�󿪴���ɨ��$n��$l",
	"force" : 80,
	"dodge": -3,
	"damage": 40,
	"lvl" : 1,
	"damage_type": "����"
]),
([	"action": "$N����$w������죬һ�С�ɽ����������$n��$l��ȥ",
	"force" : 140,
	"dodge": -5,
	"damage": 70,
	"lvl" : 13,
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ�С���ɽѩ��������$n��$l",
	"force" : 200,
	"dodge": -10,
	"damage": 100,
	"lvl" : 30,
	"damage_type": "����"
]),
([	"action": "$Nһ�С�������ѩ��������Ʈ�����ߣ�����$w����$n��$l",
	"force" : 240,
	"dodge": -30,
	"damage": 120,
	"lvl" : 45,
	"damage_type": "����"
]),
([	"action": "$Nʹһ�С��ع�õ硹������$w��һ���������$n��$l",
	"force" : 270,
	"dodge": -20,
	"damage": 130,
	"lvl" : 60,
	"damage_type": "����"
]),
([	"action": "$Nʹ���ġ���˪��Ӱ����$w������Ӱ��������$n��$l",
	"force" : 300,
	"dodge": -20,
	"damage": 130,
	"lvl" : 75,
	"damage_type": "����"
]),
([	"action": "$N��$wƾ��һָ��һ�С���ʯ���̡�����$n��$l",
	"force" : 320,
	"dodge": 20,
	"damage": 140,
	"lvl" : 90,
	"damage_type": "����"
]),
([	"action": "$N����һԾ������$wһ�С�������������׼$n��$lɨȥ",
	"force" : 340,
	"dodge": -40,
	"damage": 150,
	"lvl" : 105,
	"damage_type": "����"
]),
([	"action": "$N����$w�й�ֱ����һʽ�����ȳ��硹��׼$n��$l��ȥ",
	"force" : 350,
	"dodge": -40,
	"damage": 160,
	"lvl" : 120,
	"damage_type": "����"
]),
([	"action": "$Nһ�С����·ת����$w�����ػ���$n��$l��ȥ",
	"force" : 380,
	"dodge": -5,
	"damage": 180,
	"lvl" :  145,
	"damage_type": "����"
]),
});

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("tianshan-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
//        return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 80)
		return notify_fail("�������������\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("���������������ɽ�ȷ���\n");
	me->receive_damage("qi", 25);
	return 1;
}