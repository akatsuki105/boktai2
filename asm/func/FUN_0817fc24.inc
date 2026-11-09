	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0817FC3C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FC40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817FC42
	.align 2, 0
_0817FC3C: .4byte 0x0000046D
_0817FC40:
	movs r0, #0
_0817FC42:
	cmp r0, #0
	beq _0817FC6E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r1, _0817FC7C @ =0x0000089C
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x9e
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0817FC80 @ =0x000001DF
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl Enemy_SetEmote
_0817FC6E:
	adds r0, r4, #0
	movs r1, #0x17
	bl Enemy_PlayAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817FC7C: .4byte 0x0000089C
_0817FC80: .4byte 0x000001DF
