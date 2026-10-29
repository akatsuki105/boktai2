	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r7, #0
	mov r4, r8
	adds r4, #0x1c
	mov r6, r8
	adds r6, #0x88
	adds r5, r4, #0
_081F263C:
	movs r1, #1
	lsls r1, r7
	mov r2, r8
	ldr r0, [r2, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _081F264E
	movs r0, #1
	b _081F2650
_081F264E:
	movs r0, #0
_081F2650:
	cmp r0, #0
	beq _081F2688
	ldrh r1, [r6]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081F2674
	ldr r1, [r4]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F2688
	adds r0, r1, #0
	bl AuxSprite_Remove
	ldr r0, [r4]
	bl Free
	b _081F2688
_081F2674:
	ldr r1, [r5]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F2688
	adds r0, r1, #0
	bl Particle_Remove
	ldr r0, [r5]
	bl Free
_081F2688:
	adds r4, #0x78
	adds r6, #0x78
	adds r5, #0x78
	adds r7, #1
	cmp r7, #0x17
	ble _081F263C
	movs r1, #0
	ldr r0, _081F26A8 @ =0x030001EC
	str r1, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F26A8: .4byte 0x030001EC
