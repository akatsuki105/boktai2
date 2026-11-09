	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _0817CE0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817CE10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0817CE14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _0817CDF2
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0817CDF2:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl Map_GetPathNodes
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817CE0C: .4byte 0x030046B8
_0817CE10: .4byte 0x000003FF
_0817CE14: .4byte 0x0203B400
