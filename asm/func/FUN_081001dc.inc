	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r5, r1, r2
	ldrh r0, [r5]
	cmp r0, #0
	beq _0810021C
	ldr r0, _08100224 @ =0x0000065B
	adds r4, r1, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r2, #2
	adds r6, r1, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	cmp r0, r1
	blo _0810021C
	ldrh r0, [r5]
	movs r1, #0
	bl Script_ExecById
	movs r1, #0
	movs r0, #0
	strh r0, [r5]
	strb r1, [r6]
	strb r1, [r4]
_0810021C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08100224: .4byte 0x0000065B
