	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	mov sb, r1
	adds r7, r2, #0
	mov sl, r3
	ldr r0, _080A6348 @ =0x0000FD22
	bl Registry_Find
	mov r8, r0
	cmp r0, #0
	bne _080A6314
	b _080A640E
_080A6314:
	ldr r0, _080A634C @ =0x00001C1A
	bl GetParticleGroup
	adds r4, r0, #0
	mov r0, r8
	ldrh r1, [r0, #0x1c]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Particle_Add
	cmp r7, #0
	bne _080A6350
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x33
	bl Particle_SetFrame
	b _080A635C
	.align 2, 0
_080A6348: .4byte 0x0000FD22
_080A634C: .4byte 0x00001C1A
_080A6350:
	adds r2, r7, #0
	adds r2, #0x34
	adds r0, r5, #0
	adds r1, r4, #0
	bl Particle_SetFrame
_080A635C:
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	mov r0, sl
	cmp r0, #0
	bne _080A63DE
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080A639A
	cmp r1, #0
	blt _080A639A
	ldr r0, _080A63A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080A639A
	ldr r0, _080A63A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A63AC
_080A639A:
	movs r3, #0
	ldr r2, _080A63A8 @ =0x030046A4
	b _080A63BA
	.align 2, 0
_080A63A0: .4byte 0x030046A8
_080A63A4: .4byte 0x030046AC
_080A63A8: .4byte 0x030046A4
_080A63AC:
	ldr r2, _080A63C8 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_080A63BA:
	ldr r0, [r2]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A63CC
	movs r0, #0
	b _080A63D2
	.align 2, 0
_080A63C8: .4byte 0x030046A4
_080A63CC:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r0, r1, r0
_080A63D2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	adds r0, #0x80
	strh r0, [r5, #0x1a]
_080A63DE:
	movs r0, #1
	strb r0, [r5, #0xf]
	mov r1, sb
	cmp r1, #0
	beq _080A6406
	cmp r1, #1
	bne _080A63F2
	ldr r0, [r5]
	movs r1, #4
	b _080A6402
_080A63F2:
	mov r0, sb
	cmp r0, #2
	bne _080A63FE
	ldr r0, [r5]
	movs r1, #0xc
	b _080A6402
_080A63FE:
	ldr r0, [r5]
	movs r1, #8
_080A6402:
	orrs r0, r1
	str r0, [r5]
_080A6406:
	mov r1, r8
	ldrh r0, [r1, #0x1c]
	adds r0, #1
	strh r0, [r1, #0x1c]
_080A640E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
