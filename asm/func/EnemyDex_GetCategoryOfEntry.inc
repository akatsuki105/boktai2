	push {r4, lr}
	adds r4, r0, #0
	movs r0, #3
	bl EnemyDex_GetPageStart
	cmp r4, r0
	bge _0820CC9E
	movs r0, #0
	b _0820CCCA
_0820CC9E:
	movs r0, #4
	bl EnemyDex_GetPageStart
	cmp r4, r0
	bge _0820CCAC
	movs r0, #1
	b _0820CCCA
_0820CCAC:
	movs r0, #6
	bl EnemyDex_GetPageStart
	cmp r4, r0
	bge _0820CCBA
	movs r0, #2
	b _0820CCCA
_0820CCBA:
	movs r0, #8
	bl EnemyDex_GetPageStart
	cmp r4, r0
	blt _0820CCC8
	movs r0, #4
	b _0820CCCA
_0820CCC8:
	movs r0, #3
_0820CCCA:
	pop {r4}
	pop {r1}
	bx r1
