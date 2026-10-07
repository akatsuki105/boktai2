	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldrh r0, [r4, #0x2e]
	adds r2, r0, #1
	strh r2, [r4, #0x2e]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08084A00
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x36]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r4, #0x34]
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r4, #0x36]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bne _080849F2
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #4
	bl Particle_SetFrame
_080849F2:
	ldrh r0, [r4, #0x2e]
	cmp r0, #0xa
	bne _08084A0C
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	b _08084A08
_08084A00:
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4]
	movs r1, #1
_08084A08:
	orrs r0, r1
	str r0, [r4]
_08084A0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
