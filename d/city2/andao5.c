
inherit ROOM;

void create()
{
	set("short", "��ػᰵ��");
	set("long", @LONG
�ص���һƬ��ڣ������ķ���������˷���������ʲôҲ����
����ֻ���ڵص���Ϲ����ײ�������ƺ�����ԼԼ����˵������ֻһ
�����û���ˡ���ʹ����ҡ��ҡͷ���ܻ����⵽���ǲ��ǻþ�����
�����Ѿ���·�ˡ�
LONG
	);

	set("exits", ([
		"south" : __FILE__,
		"north" : __DIR__"andao4",
		"east" : __FILE__,
		"west" : __DIR__"andao7",
	]));

	setup();
	replace_program(ROOM);
}
