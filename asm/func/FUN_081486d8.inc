	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r4, #5]
	ldr r2, _0814874C @ =0x000001DF
	adds r0, r4, r2
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl Enemy_SetEmote
	adds r0, r4, #0
	bl Enemy_RunScript
	ldr r1, _0814874C @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08148712
	movs r0, #4
	adds r1, #0x43
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08148712:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0814874C: .4byte 0x000001DF
