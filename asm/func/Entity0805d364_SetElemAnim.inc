	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5, #6]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	add r4, sp, #4
	mov r3, sp
	adds r3, #5
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r3, #0
	cmp r0, #1
	bhi _0805BBDE
	movs r0, #1
	b _0805BBE0
_0805BBDE:
	movs r0, #0
_0805BBE0:
	strb r0, [r4]
	cmp r1, #1
	bls _0805BBEA
	movs r0, #1
	b _0805BBEC
_0805BBEA:
	movs r0, #0
_0805BBEC:
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r1, [r6, #0x40]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #4
	ldrb r3, [r3]
	ldrb r4, [r7]
	str r4, [sp]
	bl AuxAnim_SetAnim
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
