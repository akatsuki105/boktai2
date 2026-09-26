	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r2, #0
	ldr r0, _080DA760 @ =0x000009FC
	add r0, r8
	mov sb, r0
_080DA74E:
	movs r1, #1
	lsls r1, r2
	mov r3, sb
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080DA764
	movs r0, #1
	b _080DA766
	.align 2, 0
_080DA760: .4byte 0x000009FC
_080DA764:
	movs r0, #0
_080DA766:
	adds r7, r2, #1
	cmp r0, #0
	beq _080DA7AE
	movs r0, #0x9a
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r0, #0x5c
	mov r1, r8
	adds r5, r1, r0
	movs r6, #0
	adds r4, r5, #0
	adds r4, #0x88
_080DA77E:
	adds r0, r5, #0
	adds r0, #0x38
	ldrb r0, [r0]
	asrs r0, r6
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080DA794
	adds r0, r4, #0
	bl Particle_Remove
_080DA794:
	adds r4, #0x28
	adds r6, #1
	cmp r6, #2
	ble _080DA77E
	adds r0, r5, #0
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DA7AE
	adds r0, r5, #0
	adds r0, #0x5c
	bl AuxSprite_Remove
_080DA7AE:
	adds r2, r7, #0
	cmp r2, #7
	ble _080DA74E
	movs r1, #0
	ldr r0, _080DA7C8 @ =0x0300015C
	str r1, [r0]
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DA7C8: .4byte 0x0300015C
