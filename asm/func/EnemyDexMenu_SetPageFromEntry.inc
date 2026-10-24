	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r5, #0
	movs r0, #0x26
	add r0, r8
	mov sb, r0
	mov r7, sb
	mov r6, r8
	adds r6, #0x25
_0820CC48:
	ldrb r4, [r7]
	adds r0, r5, #0
	bl EnemyDex_GetPageStart
	cmp r4, r0
	bge _0820CC62
	subs r0, r5, #1
	strb r0, [r6]
	ldrb r0, [r6]
	bl EnemyDex_GetPageStart
	ldrb r1, [r7]
	b _0820CC78
_0820CC62:
	adds r5, #1
	cmp r5, #8
	ble _0820CC48
	mov r1, r8
	adds r1, #0x25
	movs r0, #8
	strb r0, [r1]
	bl EnemyDex_GetPageStart
	mov r2, sb
	ldrb r1, [r2]
_0820CC78:
	subs r1, r1, r0
	mov r0, r8
	adds r0, #0x48
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
