	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081982A4 @ =0x00000C5C
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08198268
	adds r0, r4, #0
	bl _call_via_r1
_08198268:
	ldr r0, _081982A8 @ =0x00000C28
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08198276
	subs r0, #1
	strh r0, [r1]
_08198276:
	ldr r1, _081982AC @ =0x00000C38
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0819829E
	adds r0, r4, #0
	bl _call_via_r1
	movs r1, #0xc4
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08198298
	adds r0, r4, #0
	bl _call_via_r1
_08198298:
	adds r0, r4, #0
	bl FUN_081963c0
_0819829E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081982A4: .4byte 0x00000C5C
_081982A8: .4byte 0x00000C28
_081982AC: .4byte 0x00000C38
