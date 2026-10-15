	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldrh r0, [r6, #0x20]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r3, [r5, #6]
	movs r0, #3
	ands r0, r3
	cmp r0, #0
	bne _08019438
	adds r0, r5, #0
	adds r0, #8
	ldr r1, [r6, #0x28]
	ldrh r2, [r6, #0x26]
	lsrs r3, r3, #2
	movs r4, #1
	ands r3, r4
	adds r2, r2, r3
	bl Particle_SetFrame
_08019438:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	ldrh r0, [r5, #2]
	ldrh r1, [r6, #0x22]
	cmp r0, r1
	blo _0801945E
	movs r0, #0
	strb r0, [r5]
	ldr r0, [r5, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #8]
	ldrh r1, [r6, #0x24]
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #4
	strh r0, [r5, #6]
_0801945E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
