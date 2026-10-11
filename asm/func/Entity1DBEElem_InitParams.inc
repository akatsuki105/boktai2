	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r2, #0
	ldr r2, [sp, #0x18]
	adds r0, #0xe0
	movs r5, #0
	movs r4, #0
	strh r1, [r0]
	subs r0, #4
	strb r3, [r0]
	adds r0, #6
	strh r4, [r0]
	adds r0, #3
	strb r5, [r0]
	subs r0, #6
	strb r5, [r0]
	subs r0, #2
	mov r1, sp
	ldrb r1, [r1, #0x14]
	strb r1, [r0]
	adds r0, #9
	strb r2, [r0]
	lsls r2, r2, #0x18
	cmp r2, #0
	beq _0809FD22
	adds r0, r6, #0
	bl GetMapAreaAt
	adds r1, r7, #0
	adds r1, #0xe8
	strh r0, [r1]
_0809FD22:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
