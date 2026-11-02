	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _081EEA34 @ =0x030001D4
	ldr r7, [r0]
	cmp r7, #0
	bne _081EE9D6
	bl Entity081eeb28_Create
	adds r7, r0, #0
	cmp r7, #0
	beq _081EEA38
_081EE9D6:
	adds r0, r7, #0
	bl Entity081eeb28_AllocElem
	adds r6, r0, #0
	cmp r6, #0
	beq _081EEA38
	adds r1, r6, #0
	adds r1, #0x2a
	movs r0, #0
	movs r4, #1
	strb r4, [r1]
	strh r0, [r6, #0x28]
	strh r0, [r6, #0x2e]
	movs r0, #1
	mov r8, r0
	strh r4, [r6, #0x2c]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	ldrh r0, [r6, #0x1a]
	adds r0, #0x1e
	strh r0, [r6, #0x1a]
	ldr r1, [r7, #0x18]
	adds r0, r6, #0
	movs r2, #0
	bl Particle_Add
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r6, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r1, [r7, #0x18]
	adds r0, r6, #0
	movs r2, #0x34
	bl Particle_SetPose
	ldr r0, [r6]
	orrs r0, r4
	str r0, [r6]
	mov r0, r8
	strb r0, [r6, #0xf]
	adds r0, r6, #0
	b _081EEA3A
	.align 2, 0
_081EEA34: .4byte 0x030001D4
_081EEA38:
	movs r0, #0
_081EEA3A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
