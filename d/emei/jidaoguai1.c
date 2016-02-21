// Room: /d/emei/jiudaoguai1.c 峨嵋派 九十九道拐1

inherit ROOM;

void create()
{
	set("short", "九十九道拐");
	set("long", @LONG
这里是瀑布上方一道窄窄的山梁，浑然天成。石梁上面人工
凿出一格格阶梯。边上钉了几棵木桩，绕上粗长的麻绳作为扶手。
瀑布在脚下奔腾而过，在不远的山脚下汇成一个深潭。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"qianfodian",
		"westup" : __DIR__"jiudaoguai2",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



